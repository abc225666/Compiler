%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

#define MAX_LENGTH 257

#define NEW_VAL(T) ((T*)malloc(sizeof(T)))

typedef struct ids{
 	char id_name[MAX_LENGTH];
	int freq;
	struct ids *next;
} id;

extern int linenum;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[MAX_LENGTH];           /* declared in lex.l */


extern id* id_head;

extern int Opt_Source ;
extern int Opt_Token ;
extern int Opt_Statistic ;
extern int Opt_symbol ;

typedef enum
{
	KIND_FUNCTION,
	KIND_VARIABLE,
	KIND_PARAMETER,
	KIND_CONSTANT,
	KIND_CONST_VAL,
	KIND_RVAL,
	KIND_LVAL,
} enum_kind;

typedef enum
{
	RETURN_YES,
	RETURN_NO,
}	enum_return;


typedef enum
{
	FUNC_DECL,
	FUNC_DEF,
} enum_func;

typedef enum
{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_STRING,
	TYPE_BOOL,
	TYPE_VOID
} enum_type;

typedef enum
{
	NO_ERROR, //0
	ERROR_NON_CHECK, //1
	ERROR_ID_NO_FOUND,  //2
	ERROR_IDTYPE_NOT_MATCH, //3
	ERROR_TYPE_ERROR, //4
	ERROR_ID_KIND,  //5
	ERROR_FUNC_ARGU_NOT_MATCH, //6 
	ERROR_ARR_STEP, //7
	ERROR_ID_REDCLARED, //8
	ERROR_JUMP_STATMENT, //9
	ERROR_ASSIGN_CONST, //10
	ERROR_NO_BOOL, //11
	ERROR_FUNC_DEF_NOT_MATCH, //12
	ERROR_FUNC_REDEF, //13
	ERROR_ARR_NO_INT, //14
	ERROR_DEF_DECL_NOT_PAIR, //15
	ERROR_ARR_INITIAL,//16
	ERROR_RETURN_VOID_ERROR,//17
	ERROR_RETURN_IN_VOID,//18
	ERROR_RETURN_TYPE,//19
	ERROR_NO_RETURN,//20
} enum_error;

typedef struct S_invo_val
{
	char *name;
	int listc;
	void *listv;
} invo_val;

typedef struct S_const_val
{
	int kind;
	int type;
	void* value;
} const_val;

typedef struct S_id_val
{
	int kind;
	int type;
	void* list;
} id_val;

typedef struct S_arr_val
{
	int stepc;
	int* stepv;
} arr_val;

typedef struct S_argu_val
{
	char *name;
	id_val *val;
} argu_val;

typedef struct S_func_val
{
	int type;
	int argc;
	argu_val *argv;
} func_val;

typedef struct symbol_lists{
	char *name;
	id_val *val;
	struct symbol_lists *next;
} symbol_list;

typedef struct symbol_tables{
	symbol_list *s_list;
	symbol_list *s_index;
	int level;
	struct symbol_tables *next;

} symbol_table;

typedef struct S_decl_check
{
	char *name;
	int line;
	int isUsed;
	struct S_decl_check *next;
} decl_check;

int cur_level=0;

symbol_table* cur_table=NULL;
symbol_list* argu_table=NULL;
symbol_list* argu_table_index=NULL;
symbol_list* cur_argu_ptr=NULL;

decl_check *decl_stack=NULL;

int decl_build(char* name, void* my_val);
int def_build(char* name, void* my_val);

int isanyerr=0;
int func_type=0;
int isInLoop=0;

char* mergestring(char* a, char* b);

void add_newtable();
void add_id(char* name, void* my_val);
void add_newtable_with_argu(char* name);
void dump_cur_table();
void pop_cur_table();
void dump_error(int error);

int find_redclair(char* name);

int check_parameter(symbol_list* sym,invo_val *invo);
int check_step(symbol_list*sym,invo_val *invo);
arr_val* count_arr_ref(char* name);
symbol_list* find_symbol(char* name,int dump);
const_val *geneOneVal(const_val *a,int m_type);
const_val *geneValConstOne(const_val *a, const_val *b, int m_type);
const_val *geneValConst(const_val *a, const_val *b);
int check_and_set_scalar(const_val *a);
int check_type_three(const_val *a,const_val *b);
int check_type_one(const_val *a, const_val *b,int m_type);
int check_func_change(int assign,int from);
int is_const_var(char* name);



int yyerror( char *msg );
int main( int argc, char **argv );
int yylex();

%}

%union{
	char* str;
	void* v;
	int c_type;
	int return_type;
}

%token <str> VOID
%token <str> BASIC_TYPE
%token <str> ID
%token <str> INT_CONST
%token <str> FLOAT_CONST
%token <str> BOOL_CONST
%token <str> STRING_CONST
%token READ
%token PRINT
%token IF
%token ELSE
%token DO
%token WHILE
%token FOR
%token CONTINUE
%token BREAK
%token RETURN
%token CONST

%token OR
%token AND
%token LE
%token EQ
%token GE
%token NE

%type <v> int_value float_value string_value bool_value
%type <v> arr_step liter_const value_type 
%type <v> argu argu_list array_argu_step arr_init arr_argu_list
%type <v> expr expr_list func_invo arr_ref arr_ref_step var_ref simple_stat
%type <c_type> var_list basic void_reduce const_list

%type <return_type> for_stat while_stat jump_stat condition statement compound_list compound compound_in_argu_func

%left OR
%left AND
%right UNOT
%left '<' LE EQ GE '>' NE
%left '+' '-'
%left '*' '/' '%'
%right UMINUS

%%



program
: gvar_all_def func_def prog_content
| gvar_all_def func_def
| func_def prog_content
| func_def
;

prog_content
: prog_content var_def
| prog_content func_def
| prog_content func_decl
| var_def
| func_def
| func_decl
;

gvar_all_def 
: gvar_all_def var_def 
| gvar_all_def func_decl
| var_def
| func_decl
;

var_all_def
: var_def
;

func_def
: basic ID '(' argu_list argu ')' 
	{
		func_type = $1;
		argu_val *co=(argu_val*)$5;

		func_val *p_f = (func_val*)$4;
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func 
	{
		int hasreturn=$10;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	} 
	'}'
	{

		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| basic ID '(' argu ')'
	{
		func_type = $1;
		argu_val *co=(argu_val*)$4;

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{' 
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func 
	{
		int hasreturn=$9;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
	'}'
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| basic ID '(' ')' 
	{
		func_type = $1;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = $1;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{'
	{
		add_newtable();
	}
	compound_in_argu_func
	{
		int hasreturn=$8;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
	'}'
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| void_reduce ID '(' argu_list argu ')'
	{
		func_type = TYPE_VOID;
		argu_val *co=(argu_val*)$5;

		func_val *p_f = (func_val*)$4;
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func '}'
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| void_reduce ID '(' argu ')'
	{
		func_type = TYPE_VOID;
		argu_val *co=(argu_val*)$4;

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func '}'
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| void_reduce ID '(' ')'
	{
		func_type = TYPE_VOID;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = $1;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	'{'
	{
		add_newtable();
	}
	compound_in_argu_func '}'
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
;

compound
: '{'
	{ 
		add_newtable();
	}  
	compound_list '}' 
	{
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();

		$$ = $3;
	}
| '{'
	{
		add_newtable();
	} 
	'}'
	{
		$$ = RETURN_NO;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
;

statement
: compound
	{
		$$ = $1;
	}
| simple_stat
	{
		$$ = RETURN_NO;
	}
| condition
	{
		$$ = $1;
	}
| while_stat
	{
		$$ = RETURN_NO;
	}
| for_stat
	{
		$$ = RETURN_NO;
	}
| jump_stat
	{
		$$ = $1;
	}
| expr ';'
	{
		const_val* con=(const_val*)$1;
		check_and_set_scalar($1);

		$$ = RETURN_NO;
	}
;

compound_in_argu_func
: compound_list
	{
		$$ = $1;
	}
| %empty
	{
		$$ = RETURN_NO;
	}
;

compound_list
: compound_list var_all_def
	{
		$$ = $1;
	}
| compound_list statement
	{
		if($1==RETURN_YES || $2==RETURN_YES)
			$$ = RETURN_YES;
		else
			$$ = RETURN_NO;
	}
| statement
	{
		$$ = $1;
	}
| var_all_def 
	{
		$$ = RETURN_NO;
	}
;


func_decl
: basic ID '(' argu_list argu ')'
	{
		
		argu_val *co=(argu_val*)$5;

		func_val *p_f = (func_val*)$4;
		p_f->type=FUNC_DECL;
		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	} 
	';'
| basic ID '(' argu ')' 
	{
		argu_val *co=(argu_val*)$4;

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	} 
	';'
| basic ID '(' ')'
	{
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = $1;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	';'
| void_reduce ID '(' argu_list argu ')'
	{
		argu_val *co=(argu_val*)$5;

		func_val *p_f = (func_val*)$4;
		p_f->type=FUNC_DECL;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

	}
	';'
| void_reduce ID '(' argu ')'
	{
		argu_val *co=(argu_val*)$4;

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
		
	}
	';'
| void_reduce ID '(' ')'
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = $1;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);
	}
	';'
;


argu_list
: argu_list argu ','
	{
		func_val *p = (func_val*)$1;

		argu_val *co =(argu_val*)$2;

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		$$ = (void*)p;
	}
| argu ','
	{
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)$1;

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		$$ = (void*)p;
	}
;

argu
: basic ID 
	{
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup($2);
		
		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=$1;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;

		p->val->list=(void*)t;

		$$ = (void*)p;
	}
;


basic
: BASIC_TYPE
	{
		if(!strcmp($1,"bool"))
			$$ = TYPE_BOOL;
		else if(!strcmp($1,"int"))
			$$ = TYPE_INT;
		else if(!strcmp($1,"float"))
			$$ = TYPE_FLOAT;
		else if(!strcmp($1,"double"))
			$$ = TYPE_DOUBLE;
		else if(!strcmp($1,"string"))
			$$ = TYPE_STRING;
		else if(!strcmp($1,"boolean"))
			$$ = TYPE_BOOL;
	}
;

void_reduce
: VOID
	{
		$$ = TYPE_VOID;
	}
;



liter_const
: int_value
	{
		const_val *in = (const_val*)$1;
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		$$ = (void*)p;
	}
| '-' int_value 
	{
		const_val *in = (const_val*)$2;
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		$$ = (void*)p;
	}
| float_value 
	{
		const_val *in= (const_val*)$1;
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		$$ = (void*)p;
	}
| '-' float_value 
	{
		const_val *in= (const_val*)$2;
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(double*)p->list= -*((double*)p->list);
		$$ = (void*)p;
	}
| bool_value
	{
		const_val *in= (const_val*)$1;
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		$$ = (void*)p;
	}
| string_value
	{
		const_val *in= (const_val*)$1;
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		$$ = (void*)p;
	}
;


value_type
: int_value
	{
		const_val* p = (const_val*)$1;
		p->kind=KIND_CONST_VAL;
		$$ = (void*)p;
	}
| float_value
	{
		const_val* p = (const_val*)$1;
		p->kind=KIND_CONST_VAL;
		$$ = (void*)p;
	}
| bool_value 
	{
		const_val* p = (const_val*)$1;
		p->kind=KIND_CONST_VAL;
		$$ = (void*)p;
	}
| string_value 
	{
		const_val* p = (const_val*)$1;
		p->kind=KIND_CONST_VAL;
		$$ = (void*)p;
	}
;

int_value
: INT_CONST
	{
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi($1);
		p->value = (void*)val;
		p->type = TYPE_INT;
		$$ = (void*)p;
	}
;

float_value
: FLOAT_CONST
	{
		const_val *p = NEW_VAL(const_val);
		float *val = NEW_VAL(float);
		*val = (float)atof($1);
		p->value = (void*)val;
		p->type = TYPE_FLOAT;
		$$ = (void*)p;
	}
;

bool_value
: BOOL_CONST
	{
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup($1);
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		$$ = (void*)p;
	}
;

string_value
: STRING_CONST
	{
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup($1);
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		$$ = (void*)p;
	}
;




var_list
: var_list ID ','
	{
		$$ = $<c_type>0;
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = $<c_type>0;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
			add_id($2,(void*)p);
		else
			dump_error(result);
	}
| var_list ID '=' expr ','
	{
		$$ = $<c_type>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $<c_type>0;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair($2);

		if(result==NO_ERROR)
			add_id($2,(void*)p);
		else
			dump_error(result);
	}
| ID ','
	{
		$$ = $<c_type>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $<c_type>0;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
			add_id($1,(void*)p);
		else
			dump_error(result);
	}
| ID '=' expr ','
	{
		$$ = $<c_type>0;
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=$<c_type>0;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
			add_id($1,(void*)p);
		else
			dump_error(result);
	}
;

const_list
: const_list ID '=' liter_const ','
	{
		$$ = $<c_type>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = $<c_type>0;

		id_val *get_const=(id_val*)$4;
		p->list = get_const->list;

		int result= find_redclair($2);

		if(result==NO_ERROR)
			add_id($2,(void*)p);
		else
			dump_error(result);
	}
| ID '=' liter_const ','
	{
		$$ = $<c_type>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = $<c_type>0;

		id_val *get_const=(id_val*)$3;
		p->list = get_const->list;

		int result= find_redclair($1);

		if(result==NO_ERROR)
			add_id($1,(void*)p);
		else
			dump_error(result);
	}
;

var_def
: basic var_list ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $1;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair($3);

		if(result==NO_ERROR)
			add_id($3,(void*)p);
		else
			dump_error(result);
	}
| basic var_list ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $1;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($3);

		if(result==NO_ERROR)
			add_id($3,(void*)p);
		else
			dump_error(result);
	}
| basic ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $1;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
			add_id($2,(void*)p);
		else
			dump_error(result);
	}
| basic ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $1;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
			add_id($2,(void*)p);
		else
			dump_error(result);
	}

| basic var_list ID arr_step ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = $1;
		p->list = $4;

		int result= find_redclair($3);

		if(result==NO_ERROR)
			add_id($3,(void*)p);
		else
			dump_error(result);
	}
| CONST basic const_list ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = $2;

		id_val *get_const=(id_val*)$6;
		p->list = get_const->list;

		int result= find_redclair($4);

		if(result==NO_ERROR)
			add_id($4,(void*)p);
		else
			dump_error(result);
	}
| CONST basic  ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = $2;

		id_val *get_const=(id_val*)$5;
		p->list = get_const->list;


		int result= find_redclair($3);

		if(result==NO_ERROR)
			add_id($3,(void*)p);
		else
			dump_error(result);
	}
;


arr_argu_list
: arr_argu_list expr ','
	{
		invo_val *p=(invo_val*)$1;
		const_val *co=(const_val*)$2;

		p->listc+=1;
		const_val *q=(const_val*)p->listv;

		q=(const_val*)realloc(q,sizeof(const_val)*(p->listc));
		q[p->listc-1]=*co;

		p->listv=(void*)q;

		$$ = (void*)p;

	}
| expr ','
	{
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)$1;
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		$$ =(void*)p;
	}
;

expr
: expr '*' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		$$=(void*)output;
	}
| expr '/' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		$$=(void*)output;
	}
| expr '+' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		$$=(void*)output;
	}
| expr '-' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		$$=(void*)output;
	}
| expr '%' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_one(v1,v2,TYPE_INT))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_INT);
		$$=(void*)output;
	}
| expr '<' expr 
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr LE expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr '>' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr GE expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr EQ expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			if(!check_type_one(v1,v2,TYPE_BOOL))
				dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr NE expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_three(v1,v2))
		{
			if(!check_type_one(v1,v2,TYPE_BOOL))
				dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| '(' expr ')'
	{
		const_val *v1=(const_val*)$2;
		check_and_set_scalar(v1);
		$$ = $2;
	}
| '-' expr %prec UMINUS
	{
		const_val *v1=(const_val*)$2;
		const_val *output;
		check_and_set_scalar(v1);
		if(v1->type!=TYPE_INT && v1->type!=TYPE_DOUBLE && v1->type!=TYPE_FLOAT)
		{	
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneOneVal(v1,v1->type);
		$$=(void*)v1;

	}
| expr AND expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_one(v1,v2,TYPE_BOOL))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| expr OR expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_one(v1,v2,TYPE_BOOL))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_BOOL);
		$$=(void*)output;
	}
| '!' expr %prec UNOT
	{
		const_val *v1=(const_val*)$2;
		const_val *output;
		check_and_set_scalar(v1);
		if(v1->type!=TYPE_BOOL)
		{	
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneOneVal(v1,TYPE_BOOL);
		$$=(void*)v1;

	}
| value_type
	{
		$$ = $1;
	}
| ID
	{
		// same with array but step is 0
		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 0;

		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value= (void*)p;

		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;
			if(sym_id->kind==KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			q->type=sym_id->type;
			if(sym_id->kind==KIND_CONSTANT)
			{
				q->kind=KIND_CONST_VAL;
				q->value=sym_id->list;
			}
			else
			{
				check_step(sym,p);
				q->kind=KIND_RVAL;
				q->value= (void*)p;
			}
		}

		$$ = (void*)q;
	}
| func_invo
	{
		// check func id exist and argu form correct;
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}

		$$ = (void*)q;
	}
| arr_ref
	{
		// check arr id exist and dimention correct;
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_RVAL;
		q->type= TYPE_INT;
		q->value = (void*)p;

		if(sym!=NULL)
		{
			id_val* sym_id=(id_val*)sym->val;
			if(sym_id->kind==KIND_FUNCTION || sym_id->kind==KIND_CONSTANT)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_step(sym,p))
					dump_error(ERROR_ARR_STEP);
			}
			q->type=sym_id->type;
		}

		$$ = (void*)q;
	}
;

arr_ref
: ID arr_ref_step 
	{
		invo_val *p = (invo_val*)$2;
		p->name = strdup($1);
		
		$$ = (void*)p;
	}
;

arr_ref_step
: arr_ref_step '[' expr ']' 
	{
		invo_val *p=(invo_val*)$1;
		p->listc += 1;

		const_val *exp=$3;
		if(exp->type!=TYPE_INT)
			dump_error(ERROR_ARR_NO_INT);

		$$ =(void*)p;
	}
| '[' expr ']'
	{
		invo_val *p =NEW_VAL(invo_val);
		p->listc = 1;

		const_val *exp=$2;
		if(exp->type!=TYPE_INT)
			dump_error(ERROR_ARR_NO_INT);

		$$ = (void*)p;
	}
;

func_invo
: ID '(' expr_list expr ')'
	{
		invo_val *p = (invo_val*)$3;
		p->name=strdup($1);
		p->listc+=1;

		const_val *co=(const_val*)p->listv;
		co=(const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]= *((const_val*)$4);

		p->listv=(void*)co;
		

		$$ = (void*)p;

	}
| ID '(' expr ')'
	{
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)($3);

		$$ = (void*)p;

	}
| ID '(' ')'
	{
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 0;

		$$ = (void*)p;
	}
;

expr_list
: expr_list expr ','
	{
		invo_val *p = (invo_val*)$1;
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)$2);
		p->listv = (void*)co;

		$$ = (void*)p;
	}
| expr ','
	{
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)$1);

		p->listv=(void*)co;

		$$ = (void*)p;
	}
;

simple_stat
: var_ref '=' expr ';'
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
			{
				if(con->type==TYPE_INT || con->type==TYPE_DOUBLE || con->type==TYPE_FLOAT)
				{
					if(exp->type==TYPE_INT || exp->type==TYPE_DOUBLE || exp->type==TYPE_FLOAT)
					{
						if(con->type<exp->type)
							dump_error(ERROR_IDTYPE_NOT_MATCH);
					}
					else
						dump_error(ERROR_IDTYPE_NOT_MATCH);
				}
				else
					dump_error(ERROR_IDTYPE_NOT_MATCH);
				
			}
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| PRINT expr ';'
	{
		const_val* con=(const_val*)$2;
		check_and_set_scalar(con);
		
	}
| READ var_ref ';'
	{
		const_val* con=(const_val*)$2;
		check_and_set_scalar(con);
	}
;

var_ref
: ID
	{
		// same with array but step is 0

		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 0;

		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value= (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;
			if(sym_id->kind==KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			q->type=sym_id->type;
			if(sym_id->kind==KIND_CONSTANT)
			{
				q->kind=KIND_CONST_VAL;
				q->value=sym_id->list;
			}
			else
			{
				check_step(sym,p);
				q->kind=KIND_LVAL;
				q->value= (void*)p;
			}
		}

		$$ = (void*)q;
	}
| arr_ref
	{
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_LVAL;
		q->type= TYPE_INT;
		q->value = (void*)p;

		if(sym!=NULL)
		{
			id_val* sym_id=(id_val*)sym->val;
			if(sym_id->kind==KIND_FUNCTION || sym_id->kind==KIND_CONSTANT)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_step(sym,p))
					dump_error(ERROR_ARR_STEP);
			}
			q->type=sym_id->type;
		}

		$$ = (void*)q;
	}
;


condition
: IF '(' bool_expr ')' compound
	{
		$$ = $5;
	}
| IF '(' bool_expr ')' compound ELSE compound
	{
		if($5==RETURN_YES && $7==RETURN_YES)
			$$ = RETURN_YES;
		else
			$$ = RETURN_NO;
	}
;

bool_expr
: expr
	{
		const_val *con =(const_val*)$1;
		if(con->type!=TYPE_BOOL)
			dump_error(ERROR_NO_BOOL);
		else
		{
			check_and_set_scalar(con);
		}
	}
;

while_stat
: WHILE '(' bool_expr ')' { isInLoop+=1;} compound 
	{
		isInLoop-=1;
		$$ = $6;
	}
| DO {isInLoop+=1;} compound {isInLoop-=1;} WHILE '(' bool_expr ')' ';'
	{
		$$ = $3;
	}
;

for_stat
: FOR '(' init_expr ';' bool_expr ';' incr_expr ')' {isInLoop+=1;} compound 
	{
		isInLoop-=1;
		$$ = $10;
	}
| FOR '(' init_expr ';' ';' incr_expr ')' {isInLoop+=1;} compound
	{
		isInLoop-=1;
		$$ = $9;
	}
;

init_expr 
: init_expr_list var_ref '=' expr 
	{
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| init_expr_list func_invo
	{
		invo_val *p=(invo_val*)$2;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| func_invo
	{
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| var_ref '=' expr
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| %empty
;

init_expr_list 
: init_expr_list var_ref '=' expr ','
	{
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| init_expr_list func_invo ','
	{
		invo_val *p=(invo_val*)$2;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| func_invo ','
	{
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| var_ref '=' expr ','
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
;



incr_expr
: incr_expr_list var_ref '=' expr ','
	{
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| incr_expr_list func_invo
	{
		invo_val *p=(invo_val*)$2;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| var_ref '=' expr
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| func_invo
	{
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| %empty
;

incr_expr_list
: incr_expr_list var_ref '=' expr ','
	{
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| incr_expr_list func_invo ','
	{
		invo_val *p=(invo_val*)$2;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
| var_ref '=' expr ','
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;

		if(con->kind==KIND_CONST_VAL)
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(con->type!=exp->type)
				dump_error(ERROR_IDTYPE_NOT_MATCH);
			check_and_set_scalar(con);
			check_and_set_scalar(exp);
		}
	}
| func_invo
	{
		invo_val *p=(invo_val*)$1;
		symbol_list* sym=find_symbol(p->name,1);

		const_val *q=NEW_VAL(const_val);
		q->kind=KIND_RVAL;
		q->type=TYPE_INT;
		q->value = (void*)p;


		if(sym!=NULL)
		{
			id_val *sym_id=(id_val*)sym->val;

			if(sym_id->kind!=KIND_FUNCTION)
				dump_error(ERROR_ID_KIND);
			else
			{
				if(!check_parameter(sym,p))
					dump_error(ERROR_FUNC_ARGU_NOT_MATCH);
			}
			const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;
		}
	}
;

jump_stat
: RETURN ';'
	{
		if(func_type != TYPE_VOID)
			dump_error(ERROR_RETURN_VOID_ERROR);

		$$ = RETURN_YES;
	}
| RETURN expr ';'
	{
		const_val *exp=(const_val*)$2;
		if(exp->kind==KIND_RVAL)
		{
			invo_val* exp_invo=(invo_val*)exp->value;
			if(exp_invo->listc!=0)
				dump_error(ERROR_ARR_STEP);
			check_and_set_scalar(exp);
		}

		if(func_type==TYPE_VOID)
			dump_error(ERROR_RETURN_IN_VOID);
		else if(!check_func_change(func_type,exp->type))
			dump_error(ERROR_RETURN_TYPE);

		$$ = RETURN_YES;

	}
| BREAK ';'
	{
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		$$ = RETURN_NO;
	}
| CONTINUE ';'
	{
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		$$ = RETURN_NO;
	}
;



%%

int check_parameter(symbol_list* list, invo_val* invo)
{
	id_val *id=(id_val*)list->val;
	func_val *func=(func_val*)id->list;

	if(func->argc != invo->listc)
		return 0;
	else
	{
		for(int t=0;t<func->argc;t++) //check para
		{

			argu_val *argu = ((argu_val*)func->argv)+t;
			const_val *constp = ((const_val*)invo->listv)+t;
			id_val *id_d = (id_val*)argu->val;

			if(!check_func_change(id_d->type,constp->type))
				return 0;

			if( (constp->kind!=KIND_CONST_VAL))
			{
				invo_val *source=(invo_val*)constp->value;

				arr_val *arr_source = count_arr_ref(source->name);
				arr_val *arr_func = ((arr_val*)((id_val*)argu->val)->list);
				
				if(arr_func->stepc == source->listc)
				{

					for(int i1=0,i2=arr_source->stepc-source->listc;i1<arr_func->stepc;i1++,i2++)
					{
						if( arr_func->stepv[i1] != *(((int*)arr_source->stepv)+i2) )
							
							return 0;
					}

				}
				else return 0;
			}
			else
			{
				arr_val *arr_func = ((arr_val*)((id_val*)argu->val)->list);

				if(arr_func->stepc!=0)
					return 0;
			}

		}
		return 1;
	}
}

arr_val* count_arr_ref(char* name)
{
	arr_val* ans=NEW_VAL(arr_val);
	ans->stepc=-1;
	symbol_table *p =cur_table;
	while(p!=NULL)
	{
		symbol_list *list=p->s_list;
		while(list!=NULL)
		{
			if(strcmp(list->name,name)==0)
			{
				id_val* pr=(id_val*)list->val;
				if(pr->kind==KIND_CONSTANT)
				{
					ans->stepc=0;
					return ans;
				}
				if(pr->kind==KIND_PARAMETER || pr->kind==KIND_VARIABLE)
				{
					ans= (arr_val*)pr->list;
					return ans;
				}

			}
			list=list->next;
		}
		p=p->next;
	}
	return ans;
}

int def_build(char* name, void* my_val)
{

	symbol_list* list=find_symbol(name,0);
	if(list!=NULL)
	{
		id_val* id=(id_val*)list->val;
		id_val* id2=(id_val*)my_val;
		if(id->kind!=KIND_FUNCTION)
		{
			dump_error(ERROR_ID_REDCLARED);
			return 0;
		}
		else
		{
			func_val *func_ori=(func_val*)id->list;
			func_val *func=(func_val*)id2->list;
			if(func_ori->type==FUNC_DEF)
			{
				dump_error(ERROR_FUNC_REDEF);
				return 0;
			}
			if(id->type != id2->type)
			{
				dump_error(ERROR_FUNC_DEF_NOT_MATCH);
				return 0;
			}
			if(func->argc != func_ori->argc)
			{
				dump_error(ERROR_FUNC_DEF_NOT_MATCH);
				return 0;
			}
			else
			{
				for(int t=0;t<func->argc;t++)
				{
					argu_val *argu1 = ((argu_val*)func->argv)+t;
					argu_val *argu2 = ((argu_val*)func_ori->argv)+t;
					id_val *id1 = (id_val*)argu1->val;
					id_val *id2 = (id_val*)argu2->val;
					if(id1->type != id2->type)
					{
						dump_error(ERROR_FUNC_DEF_NOT_MATCH);
						return 0;
					}
					else
					{
						arr_val *arr1=(arr_val*)id1->list;
						arr_val *arr2=(arr_val*)id2->list;
						if(arr1->stepc != arr2->stepc)
						{
							dump_error(ERROR_FUNC_DEF_NOT_MATCH);
							return 0;
						}
						else
						{
							for(int t1=0;t1<arr1->stepc;t1++)
							{	
								if( arr1->stepv[t1] != arr2->stepv[t1] )
								{
									dump_error(ERROR_FUNC_DEF_NOT_MATCH);
									return 0;
								}
							}
						}
					}
				}
			}
		}

		//
		decl_check *parser=decl_stack;
		while(parser!=0)
		{
			if(strcmp(parser->name,name)==0)
			{
				parser->isUsed=1;
				break;
			}
			parser=parser->next;
		}
		//
		return 0;
	}
	else
	{
		return 1;
	}

}

int decl_build(char* name, void* my_val)
{
	symbol_list* list=find_symbol(name,0);
	if(list!=NULL)
	{
		dump_error(ERROR_ID_REDCLARED);
		return 0;
	}
	else
	{
		
		decl_check *node =NEW_VAL(decl_check);
		node->isUsed=0;
		node->name=strdup(name);
		node->line=linenum;
		node->next=decl_stack;
		decl_stack=node;

		return 1;
	}
}

symbol_list* find_symbol(char* name,int dump)
{
	symbol_table *table= cur_table;
	while(table!=NULL)
	{
		symbol_list *list=table->s_list;
		while(list!=NULL)
		{
			if(strcmp(list->name,name)==0)
				return list;
			list=list->next;
		}
		table=table->next;
	}
	if(dump)
		dump_error(ERROR_ID_NO_FOUND);
	return NULL;
}

int find_redclair(char* name)
{
	symbol_table *p =cur_table;

	symbol_list* list=p->s_list;
	while(list!=NULL)
	{
		if(strcmp(list->name,name)==0)
			return ERROR_ID_REDCLARED;
		list=list->next;
	}
	return NO_ERROR;

}


const_val *geneOneVal(const_val *a, int m_type)
{
	const_val *output = NEW_VAL(const_val);

	if(a->type==m_type)
	{
		output->type=m_type;
		output->kind=a->kind;
		output->value=a->value;
	}
	else
	{
		output->type=m_type;
		output->kind=KIND_CONST_VAL;
		output->value=a->value;
	}
	return output;
}

const_val *geneValConstOne(const_val *a, const_val *b, int m_type)
{
	const_val *output = NEW_VAL(const_val);

	int ch;
	if(a->type==m_type)
		ch+=1;
	if(b->type==m_type)
		ch+=2;

	output->type=m_type;
	if(a->kind==KIND_RVAL && ch&1)
	{
		output->kind=KIND_RVAL;
		output->value = a->value;
	}
	else if(b->kind==KIND_RVAL && ch==2)
	{
		output->kind=KIND_RVAL;
		output->value=b->value;
	}
	else
	{
		//combine a b
		output->kind=KIND_CONST_VAL;
		output->value=a->value;
	}
	return output;

}

const_val *geneValConst(const_val *a, const_val *b)
{
	const_val *output =NEW_VAL(const_val);

	int type=TYPE_DOUBLE+1;
	int ch=0;
	if(a->type<=TYPE_DOUBLE && (a->type > type || type> TYPE_DOUBLE) )
		type=a->type , ch+=1;
	if(b->type<=TYPE_DOUBLE && (b->type > type||type > TYPE_DOUBLE) )
		type=b->type , ch+=2;

	output->type=type;
	if(a->kind==KIND_RVAL && ch&1)
	{
		output->kind=KIND_RVAL;
		output->value = a->value;
	}
	else if(b->kind==KIND_RVAL && ch==2)
	{
		output->kind=KIND_RVAL;
		output->value = b->value;
	}
	else
	{
		//combine(a,b);
		output->kind=KIND_CONST_VAL;
		output->value = a->value;
	}
	return output;
}


int check_and_set_scalar(const_val *a)
{
	if(a->kind==KIND_CONST_VAL)
		return 1;
	else
	{
		symbol_list *list=find_symbol( ((invo_val*)a->value)->name,0);
		if(list!=NULL)
		{
			id_val *id=(id_val*)list->val;
			if(id->kind==KIND_FUNCTION) return 1;
			else
			{
				if( ((invo_val*)a->value)->listc==0 ) return 1;
			}
			((invo_val*)a->value)->listc=0;
			dump_error(ERROR_ARR_STEP);
		}
		return 0;
	}
	
	return  0;
}

int check_type_three(const_val *a,const_val *b)
{
	if(a->type==TYPE_BOOL || a->type==TYPE_STRING || a->type==TYPE_VOID)
		return 0;
	if(b->type==TYPE_BOOL || b->type==TYPE_STRING || b->type==TYPE_VOID)
		return 0;

	return 1;
}

int check_func_change(int assign, int from)
{
	if(assign == TYPE_VOID || from==TYPE_VOID)
		return 0;
	if(assign != from)
	{
		if(assign==TYPE_INT || assign==TYPE_FLOAT || assign==TYPE_DOUBLE)
		{
			if(from==TYPE_INT ||from==TYPE_FLOAT || from==TYPE_DOUBLE)
			{
				if(assign > from)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 1;
}

int check_type_one(const_val *a, const_val *b,int m_type)
{
	if(a->type!=m_type || b->type!=m_type) return 0;
	return 1;
}

int check_step(symbol_list *list,invo_val *invo)
{
	id_val *id=(id_val*)list->val;
	arr_val *arr = (arr_val*)id->list;

	if(invo->listc > arr->stepc)
		return 0;
	else
		invo->listc = arr->stepc - invo->listc;
	return 1;
}


int is_const_var(char* name)
{
	symbol_table* table= cur_table;
	while(table!=NULL)
	{
		symbol_list *list=table->s_list;
		while(list!=NULL)
		{
			if(strcmp(name,list->name)==0)
			{
				if( ((id_val*)list->val)->kind==KIND_CONSTANT )
				{
					return 1;
				}
				return 0;

			}

			list=list->next;
		}
		table=table->next;
	}
	return 0;
}

char* mergestring(char* a, char* b)
{
	a=(char*)realloc(a,sizeof(char)*(strlen(a)+strlen(b)+1));
	
	strcat(a,b);
	return a;
}

void dump_cur_table()
{
	char level_string[MAX_LENGTH];
 	sprintf(level_string,"%d",cur_table->level);
 	if(cur_table->level==0)
 		strcat(level_string,"(global)");
 	else
 		strcat(level_string,"(local)");
 	symbol_list* list=cur_table->s_list;
 		printf("=======================================================================================\n");
			
		printf("Name                             Kind       Level       Type               Attribute   \n");
		printf("---------------------------------------------------------------------------------------\n");
 	while(list!=NULL)
 	{
 		printf("%-33s",list->name);

 		id_val *pr = (id_val*)list->val;

 		switch(pr->kind)
 		{
 			case KIND_VARIABLE:
 				printf("%-11s","variable");
 				break;
 			case KIND_FUNCTION:
 				printf("%-11s","function");
 				break;
 			case KIND_CONSTANT:
 				printf("%-11s","constant");
 				break;
 			case KIND_PARAMETER:
 				printf("%-11s","parameter");
 				break;
 		}

 		printf("%-12s",level_string);
 		char *output=NEW_VAL(char);
 		switch(pr->type)
 		{
 			case TYPE_BOOL:
 				output=strdup("bool");
 				break;
 			case TYPE_STRING:
 				output=strdup("string");
 				break;
 			case TYPE_DOUBLE:
 				output=strdup("double");
 				break;
 			case TYPE_INT:
 				output=strdup("int");
 				break;
 			case TYPE_VOID:
 				output=strdup("void");
 				break;
 			case TYPE_FLOAT:
 				output=strdup("float");
 				break;
 		}

 		arr_val *arrp=(arr_val*)pr->list;


 		if(pr->kind==KIND_VARIABLE || pr->kind==KIND_PARAMETER)
 		{
	 		for(int t=0;t<arrp->stepc;t++)
	 		{
	 			
	 			int digi=0;
	 			int s=arrp->stepv[t];
	 			do
	 			{
	 				digi++;
	 				s/=10;
	 			}while(s);
	 			char *num=(char*)malloc(sizeof(char)*(digi+1));
	 			sprintf(num,"%d",arrp->stepv[t]);
	 			output=mergestring(output,"[");
	 			output=mergestring(output,num);
	 			output=mergestring(output,"]");

	 			free(num);
	 		}
 		}

 		printf("%-19s",output);
 		free(output);

 		if(pr->kind==KIND_CONSTANT)
 		{
 			switch(pr->type)
 			{
 				case TYPE_FLOAT:
 					printf("%-24f",*(float*)pr->list);
 					break;
 				case TYPE_INT:
 					printf("%-24d",*(int*)pr->list);
 					break;
 				case TYPE_DOUBLE:
 					printf("%-24f",*(double*)pr->list);
 					break;
 				case TYPE_BOOL:
 					printf("%-24s",(char*)pr->list);
 					break;
 				case TYPE_STRING:
 					printf("%-24s",(char*)pr->list);
 					break;
 			}
 		}

 		if(pr->kind==KIND_FUNCTION)
 		{
 			char *att_output=NULL;
 			func_val *p=(func_val*)pr->list;
 			for(int t=0;t<p->argc;t++)
 			{
 				argu_val *ar=(argu_val*)(p->argv+t);
				id_val *id_argu=(id_val*)ar->val;
				arr_val *arr_argu=(arr_val*)id_argu->list;

				if(t==0)
				{
					switch(id_argu->type)
					{
						case TYPE_BOOL:
			 				att_output=strdup("bool");
			 				break;
			 			case TYPE_STRING:
			 				att_output=strdup("string");
			 				break;
			 			case TYPE_DOUBLE:
			 				att_output=strdup("double");
			 				break;
			 			case TYPE_INT:
			 				att_output=strdup("int");
			 				break;	
			 			case TYPE_FLOAT:
			 				att_output=strdup("float");
			 				break;
			 		}
				}
				else
				{
					att_output=mergestring(att_output,",");
					switch(id_argu->type)
					{
						case TYPE_BOOL:
							att_output=mergestring(att_output,"bool");
			 				break;
			 			case TYPE_STRING:
			 				att_output=mergestring(att_output,"string");
			 				break;
			 			case TYPE_DOUBLE:
			 				att_output=mergestring(att_output,"double");
			 				break;
			 			case TYPE_INT:
			 				att_output=mergestring(att_output,"int");
			 				break;
			 			case TYPE_FLOAT:
			 				att_output=mergestring(att_output,"float");
			 				break;
			 		}
				}

				for(int t1=0;t1< arr_argu->stepc;t1++)
				{
					int digi=0;
		 			int s=arr_argu->stepv[t1];
		 			do
		 			{
		 				digi++;
		 				s/=10;
		 			}while(s);
		 			char *num=(char*)malloc(sizeof(char)*(digi+t1));
		 			sprintf(num,"%d",arr_argu->stepv[t1]);
		 			att_output=mergestring(att_output,"[");
		 			att_output=mergestring(att_output,num);
		 			att_output=mergestring(att_output,"]");

		 			free(num);
				}
 			}
 			printf("%-24s",att_output==NULL?"":att_output);
 		}


		
		printf("\n");
		//printf("%-33s%-11s%-12s%-19s%-24s\n",list->name,list->kind,level_string,list->type,list->attr==NULL?"":list->attr);

		
 		list=list->next;
 	}
 		printf("=======================================================================================\n");

 	cur_table=cur_table->next;
 	cur_level--;
}

void pop_cur_table()
{
	cur_table=cur_table->next;
	cur_level--;
}

void add_newtable()
{
	cur_level++;
	symbol_table* new_table=(symbol_table*)calloc(1,sizeof(symbol_table));

	new_table->level=cur_level;
	new_table->next=cur_table;

	cur_table=new_table;

	symbol_table* pre_table=cur_table->next;

}

void add_newtable_with_argu(char* name)
{
	add_newtable();
	symbol_list *p= cur_table->next->s_list;

	symbol_list *f;
	
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			f = p;
		}
		p=p->next;
	}

	func_val *f_list = (func_val*)f->val->list;

	symbol_list *argu_head=NULL;
	symbol_list *argu_index=NULL;

	for(int t=0;t<f_list->argc;t++)
	{
		symbol_list *new_node=NEW_VAL(symbol_list);

		argu_val *argu_p=(f_list->argv)+t;

		new_node->name = strdup(argu_p->name);
		new_node->val=NEW_VAL(id_val);
		memcpy(new_node->val,argu_p->val,sizeof(id_val));
		new_node->next=NULL;

		if(argu_head==NULL)
		{
			argu_head=new_node;
			argu_index=new_node;
		}
		else
		{
			argu_index->next=new_node;
			argu_index=argu_index->next;
		}
	}

	cur_table->s_list=argu_head;
	cur_table->s_index=argu_index;

	
}

void add_id(char* name, void* my_val)
{
	//check func def decl
	id_val *id_in=(id_val*)my_val;
	if(id_in->kind==KIND_FUNCTION)
	{
		symbol_list* p=cur_table->s_list;
		while(p!=NULL)
		{
			if(strcmp(p->name,name)==0)
			{
				return;
			}
			p=p->next;

		}
	}

	if(cur_table->s_index==NULL)
	{
		symbol_list* new_identify= NEW_VAL(symbol_list);
		new_identify->next=NULL;
		cur_table->s_list=new_identify;
		cur_table->s_index=cur_table->s_list;
	}
	else
	{
		symbol_list* new_identify= NEW_VAL(symbol_list);
		new_identify->next=NULL;
		cur_table->s_index->next=new_identify;
		cur_table->s_index=new_identify;
	}

	cur_table->s_index->name=strdup(name);

	cur_table->s_index->val=id_in;
}

void dump_error(int error)
{

	char* mess;

	isanyerr=1;

	switch(error)
	{
		case ERROR_NON_CHECK:
			mess=strdup("unknown error");
			break;
		case ERROR_ID_NO_FOUND:
			mess=strdup("identfier not define");
			break;
		case ERROR_IDTYPE_NOT_MATCH:
			mess=strdup("value can't be assigned by Coercion");
			break;
		case ERROR_TYPE_ERROR:
			mess=strdup("value can't be Coercion");
			break;
		case ERROR_ID_KIND:
			mess=strdup("identifier is not defined in such kind");
			break;
		case ERROR_FUNC_ARGU_NOT_MATCH:
			mess=strdup("function argument not match");
			break;
		case ERROR_ARR_STEP:
			mess=strdup("array's dimention wrong");
			break;
		case ERROR_ID_REDCLARED:
			mess=strdup("identifier is redeclared");
			break;
		case ERROR_JUMP_STATMENT:
			mess=strdup("jump statement need in loop structure");
			break;
		case ERROR_ASSIGN_CONST:
			mess=strdup("can't assigned value to const");
			break;
		case ERROR_NO_BOOL:
			mess=strdup("expression must be bool type");
			break;
		case ERROR_FUNC_DEF_NOT_MATCH:
			mess=strdup("function define and declare not match");
			break;
		case ERROR_FUNC_REDEF:
			mess=strdup("function is redefined");
			break;
		case ERROR_ARR_NO_INT:
			mess=strdup("array dimention argument need to be integer");
			break;
		case ERROR_DEF_DECL_NOT_PAIR:
			mess=strdup("no definition of this function declare");
			break;
		case ERROR_ARR_INITIAL:
			mess=strdup("array initial error");
			break;
		case ERROR_RETURN_VOID_ERROR:
			mess=strdup("need to return a value");
			break;
		case ERROR_RETURN_IN_VOID:
			mess=strdup("can't return value in a void function");
			break;
		case ERROR_RETURN_TYPE:
			mess=strdup("return type not match");
			break;
		case ERROR_NO_RETURN:
			mess=strdup("this function might have a route without return");
	}




	printf("##########Error at Line #%d: %s.##########\n",linenum,mess);

}


int yyerror( char *msg )
{
  fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
  fprintf(   stderr, "|--------------------------------------------------------------------------\n" );
  exit(-1);
}

int main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;

	symbol_table* new_table=(symbol_table*)calloc(1,sizeof(symbol_table));
	
	cur_table=new_table;
	
	yyparse();

	if(Opt_symbol)
		dump_cur_table();
	else pop_cur_table();


	decl_check *parser=decl_stack;
	while(parser!=NULL)
	{
		if(!parser->isUsed)
		{
			isanyerr=1;
			printf("##########Error at Line #%d: %s.##########\n",parser->line,"no definition of this function declare");
		}
		parser=parser->next;
	}

	if(!isanyerr)
	{
		fprintf( stdout, "\n" );
		fprintf( stdout, "|-------------------------------------------|\n" );
		fprintf( stdout, "| There is no syntactic and semantic error! |\n" );
		fprintf( stdout, "|-------------------------------------------|\n" );
	}



	if(Opt_Statistic)
	{
		printf("frequencies of identifiers:\n");
	 	id *offset = id_head;
	 	id *tobefree = id_head;
	   	while(offset){
			printf("%s\t%d\n",offset->id_name, offset->freq);
			offset = offset->next;
	   	}
	 	while(tobefree){
	 		offset = tobefree;
	 		tobefree = tobefree->next;
	 		free(offset);
	 	}
	 	printf("--------------------------\n");
	 }

	 

	exit(0);
}
