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
	CAL_PLUS,
	CAL_MINUS,
	CAL_DIV,
	CAL_MULTI,
	CAL_MOD,
} enum_cal;

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
	CMP_EQ,
	CMP_NE,
	CMP_LE,
	CMP_LT,
	CMP_GE,
	CMP_GT,
	CMP_NOT
} emun_cmp;

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

typedef struct S_output_list
{
	char *content;
	struct S_output_list *next;
} output_list;



typedef struct S_const_val
{
	int kind;
	int type;
	void* value;
	int basic_val;
	int return_val;
	output_list* code_head;
	output_list* code_index;
} const_val;

typedef struct S_invo_val
{
	char *name;
	int listc;
	void *listv;
	const_val *func_code;
} invo_val;

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

typedef struct S_loop_stack
{
	int loop_val;
	struct S_loop_stack *next;
} loop_stack;

typedef struct symbol_lists{
	char *name;
	id_val *val;
	int cur_index;
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
void equal_type_check(const_val* con,const_val* exp);
void init_type_check(int type1,int type2);

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

FILE *fg = NULL;
output_list *output_head = NULL;
output_list *output_index = NULL;
output_list *output_func_head = NULL;
output_list *output_func_index = NULL;
output_list *output_main_head = NULL;
output_list *output_main_index = NULL;
output_list *output_cur_head = NULL;
output_list *output_cur_index = NULL;
loop_stack *l_stack = NULL;
int output_stack = 0;
int output_oper = 200;
int output_cur_position = 0;

int label = 0;
int loop_label = 0;

void gene_init_code();
void code_gvar(char* name, int type);
void code_final();
void code_cur_func_start(char* name, id_val* id);
void code_cur_func_end();
void code_calculate(const_val*output,const_val* v1, const_val *v2,int cal_type);
void code_go_minus(const_val* v1);
void code_load_val(const_val* v1);
void code_dump_expr(const_val* v1);
void code_change_type(const_val *v1, const_val *v2, int type);
void code_merge_expr(const_val *output, const_val *v1, const_val *v2);
void code_store_val(char* name,const_val*v1);
void code_single_change_type(const_val* v1, int type);
void code_find_max_type(const_val *v1,const_val *v2);
void code_cmp(const_val* output,const_val* v1,const_val* v2,int cmp);
void code_read(const_val* v1,int type);
void code_print(const_val* v1,int type);
void code_call_func(const_val* v1, symbol_list *list);
void code_dump_main();
void code_gvar_init(char *name,const_val *v1,int type);
void code_call_main(output_list** main_list);
void code_void_return(const_val** v1);
char *code_cmp_label(int cmp);
void f_output_cur_init();
void f_output_stack_add(int type);
char* f_get_type(int type);
char* f_get_s_type(int type);
char* f_read_type(int type);
char* f_print_type(int type);
int f_type_need(int type);
void f_push_loop_state();
void f_pop_loop_state();
char *f_argulist(symbol_list *type);
void f_assign_by_const_val(const_val*);


char *output_string = NULL;


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
%type <v> liter_const value_type 
%type <v> argu argu_list 
%type <v> expr expr_list func_invo var_ref simple_stat bool_expr
%type <v> basic void_reduce const_list gvar_list gconst_list

%type <v> var_list var_def compound_list init_expr init_expr_list incr_expr incr_expr_list
%type <v> for_stat while_stat jump_stat condition statement compound compound_in_argu_func

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
: prog_content gvar_def
| prog_content func_def
| prog_content func_decl
| gvar_def
| func_def
| func_decl
;

gvar_all_def 
: gvar_all_def gvar_def 
| gvar_all_def func_decl
| gvar_def
| func_decl
;

gvar_def
: basic gvar_list ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			add_id($3,(void*)p);
			code_gvar($3,((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);
	}
| basic gvar_list ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)$5)->type);
			code_single_change_type((const_val*)$5,p->type);
			add_id($3,(void*)p);
			code_gvar($3,((const_val*)$1)->basic_val);
			code_gvar_init($3,(const_val*)$5,((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);
	}
| basic ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			code_gvar($2,((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);
	}
| basic ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)$4)->type);
			code_single_change_type((const_val*)$4,p->type);
			add_id($2,(void*)p);
			code_gvar($2,((const_val*)$1)->basic_val);
			code_gvar_init($2,(const_val*)$4,((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);
	}

| CONST basic gconst_list ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$2)->basic_val;

		id_val *get_const=(id_val*)$6;
		

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($4);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($4,(void*)p);
			code_gvar($4,((const_val*)$2)->basic_val);
		}
		else
			dump_error(result);

	}
| CONST basic  ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$2)->basic_val;

		id_val *get_const=(id_val*)$5;
		

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}



		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($3,(void*)p);
			code_gvar($3,((const_val*)$2)->basic_val);
		}
		else
			dump_error(result);
	}
;

gvar_list
: gvar_list ID ','
	{
		$$ = $<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ((const_val*)$<v>0)->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			code_gvar($2,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
| gvar_list ID '=' expr ','
	{
		$$ = $<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$<v>0)->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)$4)->type);
			code_single_change_type((const_val*)$4,p->type);
			add_id($2,(void*)p);
			code_gvar($2,((const_val*)$<v>0)->basic_val);
			code_gvar_init($2,(const_val*)$4,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
| ID ','
	{
		$$ = $<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$<v>0)->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			add_id($1,(void*)p);
			code_gvar($1,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
| ID '=' expr ','
	{
		$$ = $<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=((const_val*)$<v>0)->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)$3)->type);
			code_single_change_type((const_val*)$3,p->type);
			add_id($1,(void*)p);
			code_gvar($1,((const_val*)$<v>0)->basic_val);
			code_gvar_init($1,(const_val*)$3,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
;

gconst_list
: gconst_list ID '=' liter_const ','
	{
		$$ = $<v>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$<v>0)->basic_val;

		id_val *get_const=(id_val*)$4;
		

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($2,(void*)p);
			code_gvar($2,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
| ID '=' liter_const ','
	{
		$$ = $<v>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$<v>0)->basic_val;

		id_val *get_const=(id_val*)$3;
		

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($1,(void*)p);
			code_gvar($1,((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);
	}
;

var_def
: basic var_list ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			add_id($3,(void*)p);
			f_output_stack_add(((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);



		$$ = $2;
	}
| basic var_list ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			add_id($3,(void*)p);
			f_output_stack_add(((const_val*)$1)->basic_val);

			const_val *exp = (const_val*)$5;
			init_type_check(p->type,exp->type);
		}
		else
			dump_error(result);


		const_val *con = (const_val*)$5;
		const_val *rev = (const_val*)$2;
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val($3,con);
		code_merge_expr(rev,rev,con);

		$$ = (void*)rev;
	}
| basic ID ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			f_output_stack_add(((const_val*)$1)->basic_val);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		$$ = (void*)con;
	}
| basic ID '=' expr ';'
	{
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$1)->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			f_output_stack_add(((const_val*)$1)->basic_val);

			const_val *exp = (const_val*)$4;
			init_type_check(p->type,exp->type);
		}
		else
			dump_error(result);

		const_val *con = (const_val*)$4;
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val($2,con);

		$$ = (void*)con;
	}

| CONST basic const_list ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$2)->basic_val;

		id_val *get_const=(id_val*)$6;
		

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];

			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($4);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($4,(void*)p);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		$$ = (void*)con;
	}
| CONST basic  ID '=' liter_const ';' 
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$2)->basic_val;

		id_val *get_const=(id_val*)$5;

		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($3);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($3,(void*)p);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		$$ = (void*)con;
	}
;

func_def
: basic ID '(' argu_list argu ')' 
	{
		

		func_type = ((const_val*)$1)->basic_val;
		argu_val *co=(argu_val*)$5;

		func_val *p_f = (func_val*)$4;
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func 
	{
		const_val *v1 = (const_val*)$10;
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	} 
	'}'
	{
		const_val* code= (const_val*)$10;
		code_dump_expr(code);
		code_cur_func_end();

		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| basic ID '(' argu ')'
	{
		func_type = ((const_val*)$1)->basic_val;
		argu_val *co=(argu_val*)$4;

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{' 
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func 
	{
		const_val *v1 = (const_val*)$9;
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
	'}'
	{
		const_val* code= (const_val*)$9;
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| basic ID '(' ')' 
	{
		func_type = ((const_val*)$1)->basic_val;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func
	{
		const_val *v1 = (const_val*)$8;
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
	'}'
	{
		const_val* code= (const_val*)$8;
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| void_reduce ID  '(' argu_list argu ')'
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func '}'
	{
		const_val* code= (const_val*)$10;
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func '}'
	{
		const_val* code= (const_val*)$9;
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
| void_reduce ID '(' ')'
	{
		func_type = TYPE_VOID;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		f_output_cur_init();
		code_cur_func_start($2,p);
	}
	'{'
	{
		add_newtable_with_argu($2);
	}
	compound_in_argu_func '}'
	{
		const_val* code= (const_val*)$8;
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
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
		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_NO;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next=NULL;
		new_node->content = strdup("");
		v1->code_head=new_node;
		v1->code_index=new_node;
		$$ = (void*)v1;
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
		const_val *con = (const_val*)$1;
		con->return_val = RETURN_NO;
		$$ = (void*)con;
	}
| condition
	{
		$$ = $1;
	}
| while_stat
	{
		const_val *con = (const_val*)$1;
		con->return_val = RETURN_NO;
		$$ = (void*)con;
	}
| for_stat
	{
		const_val *con = (const_val*)$1;
		con->return_val = RETURN_NO;
		$$ = (void*)con;
	}
| jump_stat
	{
		$$ = $1;
	}
| expr ';'
	{
		const_val* con=(const_val*)$1;
		//code_dump_expr(con);
		check_and_set_scalar($1);
		con->return_val = RETURN_NO;
		$$ = (void*)con;
	}
;

compound_in_argu_func
: compound_list
	{
		$$ = $1;
	}
| %empty
	{
		const_val *con = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->return_val = RETURN_NO;
		con->code_head = new_node;
		con->code_index = new_node;

		$$ = (void*)con;
	}
;

compound_list
: compound_list var_def
	{
		const_val *v1 = (const_val*)$1;
		const_val *v2 = (const_val*)$2;
		code_merge_expr(v1,v1,v2);

		$$ = (void*)v1;
	}
| compound_list statement
	{
		const_val *v1 = (const_val*)$1;
		const_val *v2 = (const_val*)$2;
		code_merge_expr(v1,v1,v2);

		if(v1->return_val==RETURN_YES || v2->return_val==RETURN_YES)
			v1->return_val = RETURN_YES;
		else
			v1->return_val = RETURN_NO;

		$$ = (void*)v1;

	}
| statement
	{
		$$ = $1;
	}
| var_def
	{
		const_val *v1 = (const_val*)$1;
		v1->return_val = RETURN_NO;
		$$ = (const_val*)v1;
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
	} 
	';'
| basic ID '(' ')'
	{
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
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
		p->type = ((const_val*)$1)->basic_val;

		p->list = (void*)p_f;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
		
	}
	';'
| void_reduce ID '(' ')'
	{
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)$1)->basic_val;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build($2,(void*)p);
		if(result)
			add_id($2,(void*)p);

		output_stack = 0;
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
		p->val->type=((const_val*)$1)->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;

		p->val->list=(void*)t;

		$$ = (void*)p;

		f_output_stack_add(((const_val*)$1)->basic_val);
	}
;


basic
: BASIC_TYPE
	{
		const_val *re = NEW_VAL(const_val);


		if(!strcmp($1,"bool"))
			re->basic_val = TYPE_BOOL;
		else if(!strcmp($1,"int"))
			re->basic_val = TYPE_INT;
		else if(!strcmp($1,"float"))
			re->basic_val = TYPE_FLOAT;
		else if(!strcmp($1,"double"))
			re->basic_val = TYPE_DOUBLE;
		else if(!strcmp($1,"string"))
			re->basic_val = TYPE_STRING;
		else if(!strcmp($1,"boolean"))
			re->basic_val = TYPE_BOOL;

		$$ = (void*)re;
	}
;

void_reduce
: VOID
	{
		const_val *re = NEW_VAL(const_val);
		re->basic_val = TYPE_VOID;
		
		$$ = (void*)re;
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

		char *str = strdup("-");
		p->list=(void*)mergestring(str,(char*)in->value);
		
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
		char *ou = strdup($1);
		p->value = (void*) ou;
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
		//$$ = $<v>0;
		const_val *ori = (const_val*)$<v>0;
		const_val *v1 = (const_val*)$1;
		v1->basic_val = ori->basic_val;


		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ori->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			f_output_stack_add(((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);

		$$ = (void*)v1;
	}
| var_list ID '=' expr ','
	{
		const_val *ori = (const_val*)$<v>0;
		const_val *v1 = (const_val*)$1;
		v1->basic_val = ori->basic_val;

		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ori->basic_val;


		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			add_id($2,(void*)p);
			f_output_stack_add(((const_val*)$<v>0)->basic_val);

			const_val *exp = (const_val*)$4;
			init_type_check(p->type,exp->type);

			
		}
		else
			dump_error(result);

		const_val *con = (const_val*)$4;
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val($2,con);
		code_merge_expr(v1,v1,con);

		$$ = (void*)v1;
	}
| ID ','
	{
		// $$ = $<v>0;
		const_val *ori = (const_val*)$<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$<v>0)->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			add_id($1,(void*)p);
			f_output_stack_add(((const_val*)$<v>0)->basic_val);
		}
		else
			dump_error(result);

		const_val *v1 = NEW_VAL(const_val);
		v1->basic_val = ori->basic_val;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;
		$$ = (void*)v1;


	}
| ID '=' expr ','
	{
		//$$ = $<v>0;
		const_val *ori = (const_val*)$<v>0;
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)$<v>0)->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			add_id($1,(void*)p);
			f_output_stack_add(((const_val*)$<v>0)->basic_val);

			const_val *exp = (const_val*)$3;
			init_type_check(p->type,exp->type);


		}
		else
			dump_error(result);
		const_val *con = (const_val*)$3;
		code_single_change_type(con,p->type);
		code_dump_expr(con);
		code_store_val($1,con);
		con->basic_val = ori->basic_val;

		$$ = (void*)con;
	}
;

const_list
: const_list ID '=' liter_const ','
	{
		$$ = $<v>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$<v>0)->basic_val;

		id_val *get_const=(id_val*)$4;


		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}

		int result= find_redclair($2);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($2,(void*)p);
		}
		else
			dump_error(result);
	}
| ID '=' liter_const ','
	{
		$$ = $<v>0;

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)$<v>0)->basic_val;

		id_val *get_const=(id_val*)$3;
		
		if(p->type > TYPE_INT && p->type <=TYPE_DOUBLE && get_const->type == TYPE_INT)
		{
			char outstring[200];
			sprintf(outstring,"%d",*(int*)get_const->list);
			p->list = (void*)strdup(outstring);
		}
		else
		{
			p->list = get_const->list;
		}


		int result= find_redclair($1);

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id($1,(void*)p);
		}
		else
			dump_error(result);
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
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_MULTI);
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
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_DIV);
		$$=(void*)output;
	}
| expr '+' expr
	{
		const_val *v1=(const_val*)$1;
		const_val *v2=(const_val*)$3;
		const_val *output;
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_PLUS);
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
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_MINUS);
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
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_MOD);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_LT);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_LE);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_GT);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_GE);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_EQ);
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
		code_find_max_type(v1,v2);
		code_cmp(output,v1,v2,CMP_NE);
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
		code_go_minus(v1);
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

		code_merge_expr(output,v1,v2);

		output_list *new_node = NEW_VAL(output_list);
		new_node->content = strdup("iand\n");
		new_node->next = NULL;

		output->code_index->next = new_node;
		output->code_index = new_node;

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

		code_merge_expr(output,v1,v2);

		output_list *new_node = NEW_VAL(output_list);
		new_node->content = strdup("ior\n");
		new_node->next = NULL;

		output->code_index->next = new_node;
		output->code_index = new_node;

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

		output->code_head = v1->code_head;
		output->code_index = v1->code_index;

		output_list *new_node = NEW_VAL(output_list);
		new_node->content = strdup("ixor\n");
		new_node->next = NULL;

		output->code_index->next = new_node;
		output->code_index = new_node;

		$$=(void*)output;

	}
| value_type
	{
		code_load_val((const_val*)$1);
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

			code_load_val(q);
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

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		q->code_head = new_node;
		q->code_index = new_node;

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
			//const_val *q=NEW_VAL(const_val);
			q->kind=KIND_RVAL;
			q->type=sym_id->type;
			q->value = (void*)p;

			code_merge_expr(q,q,p->func_code);
			code_call_func(q,sym);
		}

		$$ = (void*)q;
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

		code_merge_expr(p->func_code,p->func_code,((const_val*)$4));

		$$ = (void*)p;

	}
| ID '(' expr ')'
	{
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)($3);

		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		code_merge_expr(code,code,((const_val*)$3));

		p->func_code = code;
		$$ = (void*)p;

	}
| ID '(' ')'
	{
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup($1);
		p->listc = 0;

		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		p->func_code = code;

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

		code_merge_expr(p->func_code,p->func_code,((const_val*)$2));

		$$ = (void*)p;
	}
| expr ','
	{
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)$1);

		p->listv=(void*)co;

	
		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		code_merge_expr(code,code,(const_val*)$1);

		p->func_code = code;

		$$ = (void*)p;
	}
;

simple_stat
: var_ref '=' expr ';'
	{
		const_val* con=(const_val*)$1;
		const_val* exp=(const_val*)$3;


		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		$$ = (void*)exp;

	}
| PRINT expr ';'
	{
		const_val* con=(const_val*)$2;
		check_and_set_scalar(con);

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("getstatic java/lang/System/out Ljava/io/PrintStream;\n");

		new_node->next = con->code_head;
		con->code_head = new_node;
		
		code_print(con,con->type);

		$$ = (void*)con;
		//code_dump_expr(con);
		
	}
| READ var_ref ';'
	{
		const_val* con=(const_val*)$2;
		check_and_set_scalar(con);

		const_val* v1= NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		code_read(v1,con->type);
		code_store_val( ((invo_val*)con->value)->name,v1 );

		$$ = (void*)v1;
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
;


condition
: IF '(' bool_expr ')' compound
	{
		char outstring[2000];
		const_val *exp = (const_val*)$3;

		
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifne TRUE_%d\ngoto END_%d\nTRUE_%d:\n",label,label,label);
		new_node->content = mergestring(new_node->content,outstring);
		
		exp->code_index->next = new_node;
		exp->code_index = new_node;

		const_val *v1 = (const_val*)$5;
		code_merge_expr(v1,exp,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"END_%d:\n",label);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_index->next = new_node;
		v1->code_index = new_node;

		label++;



		$$ = (void*)v1;
	}
| IF '(' bool_expr ')' compound ELSE compound
	{
		char outstring[2000];
		const_val *v1 = (const_val*)$5;
		const_val *v2=(const_val*)$7;
		if(v1->return_val==RETURN_YES && v2->return_val==RETURN_YES)
			v1->return_val = RETURN_YES;
		else
			v1->return_val = RETURN_NO;

		const_val *exp = (const_val*)$3;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifne TRUE_%d\ngoto FALSE_%d\nTRUE_%d:\n",label,label,label);
		new_node->content = mergestring(new_node->content,outstring);

		exp->code_index->next = new_node;
		exp->code_index = new_node;

		code_merge_expr(v1,exp,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"goto END_%d\nFALSE_%d:\n",label,label);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_index->next = new_node;
		v1->code_index = new_node;
		code_merge_expr(v1,v1,v2);
		
		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"END_%d:\n",label);
		new_node->content = mergestring(new_node->content,outstring);
		v1->code_index->next = new_node;
		v1->code_index = new_node;

		label++;
		$$ = (void*)v1;
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
		$$ = (void*)$1;
	}
;

while_stat
: WHILE '(' bool_expr ')'
	{
		f_push_loop_state();
		isInLoop+=1;
	}
	compound 
	{
		char outstring[2000];

		int loop_label = l_stack->loop_val;

		const_val *v1 = (const_val*)$6;
		const_val *exp = (const_val*)$3;

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"LOOP_START_%d:\n",loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		new_node->next = exp->code_head;
		exp->code_head = new_node;

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifeq LOOP_END_%d\n",loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		exp->code_index->next = new_node;
		exp->code_index = new_node;

		code_merge_expr(v1,exp,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"NEXT_%d:\ngoto LOOP_START_%d\nLOOP_END_%d:\n",loop_label,loop_label,loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_index->next = new_node;
		v1->code_index = new_node;

		f_pop_loop_state();
		isInLoop-=1;
		$$ = (void*)v1;
	}
| DO 
	{
		f_push_loop_state();
		isInLoop+=1;
	}
	compound WHILE '(' bool_expr ')' ';'
	{
		char outstring[2000];

		int loop_label = l_stack->loop_val;

		const_val *v1 = (const_val*)$3;
		const_val *exp = (const_val*)$6;

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"LOOP_START_%d:\n",loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		new_node->next = exp->code_head;
		exp->code_head = new_node;

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifeq LOOP_END_%d\n",loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		exp->code_index->next = new_node;
		exp->code_index = new_node;


		code_merge_expr(exp,v1,exp);
		code_merge_expr(v1,exp,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"NEXT_%d:\ngoto LOOP_START_%d\nLOOP_END_%d:\n",loop_label,loop_label,loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_index->next = new_node;
		v1->code_index = new_node;

		f_pop_loop_state();
		isInLoop-=1;
		$$ = (void*)v1;
	}
;

for_stat
: FOR '(' init_expr ';' bool_expr ';' incr_expr ')'
	{
		f_push_loop_state();
		isInLoop+=1;
	} 
	compound 
	{
		char outstring[2000];
		
		int loop_label=l_stack->loop_val;

		const_val *v1 = (const_val*)$10;
		const_val *init = (const_val*)$3;
		const_val *cond = (const_val*)$5;
		const_val *incr = (const_val*)$7;

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"LOOP_START_%d:\n",loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);

		init->code_index->next = new_node;
		init->code_index = new_node;

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifeq LOOP_END_%d\n",loop_label);
		new_node->content = mergestring(new_node->content,outstring);

		cond->code_index->next = new_node;
		cond->code_index = new_node;

		code_merge_expr(v1,cond,v1);
		code_merge_expr(v1,init,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"NEXT_%d:\n",loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);
		v1->code_index->next = new_node;
		v1->code_index = new_node;

		code_merge_expr(v1,v1,incr);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"goto LOOP_START_%d\nLOOP_END_%d:\n",loop_label,loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);
		v1->code_index->next = new_node;
		v1->code_index = new_node;

		f_pop_loop_state();
		isInLoop-=1;
		$$ = (void*)v1;
	}
| FOR '(' init_expr ';' ';' incr_expr ')'
	{
		f_push_loop_state();
		isInLoop+=1;
	} compound
	{

		char outstring[2000];
		
		int loop_label=l_stack->loop_val;

		const_val *v1 = (const_val*)$9;
		const_val *init = (const_val*)$3;
		const_val *incr = (const_val*)$6;

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"LOOP_START_%d:\n",loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);

		init->code_index->next = new_node;
		init->code_index = new_node;

		code_merge_expr(v1,init,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"NEXT_%d:\n",loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);
		v1->code_index->next = new_node;
		v1->code_index = new_node;

		code_merge_expr(v1,v1,incr);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		sprintf(outstring,"goto LOOP_START_%d\nLOOP_END_%d:\n",loop_label,loop_label);
		new_node->content = strdup("");
		new_node->content = mergestring(new_node->content,outstring);
		v1->code_index->next = new_node;
		v1->code_index = new_node;

		f_pop_loop_state();
		isInLoop-=1;
		$$ = (void*)v1;
	}
;

init_expr 
: init_expr_list var_ref '=' expr 
	{
		const_val *v1 = (const_val*)$1;
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name,exp );

		code_merge_expr(v1,v1,exp);

		$$ = (void*)con;
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

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		$$ = (void*)exp;
	}
| %empty
	{
		const_val *v1 = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node -> next =NULL;
		new_node->content =strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		$$ = (void*)v1;
	}
;

init_expr_list 
: init_expr_list var_ref '=' expr ','
	{
		const_val* v1 = (const_val*)$1;
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);
		code_merge_expr(v1,v1,exp);

		$$ = (void*)v1;
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

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name,exp );

		$$ = (void*)exp;
	}
;



incr_expr
: incr_expr_list var_ref '=' expr ','
	{
		const_val* v1= (const_val*)$1;
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		code_merge_expr(v1,v1,exp);

		$$ = (void*)v1;
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

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		$$ = (void*)exp;

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
	{
		const_val *v1 = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node -> next =NULL;
		new_node->content =strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		$$ = (void*)v1;
	}
;

incr_expr_list
: incr_expr_list var_ref '=' expr ','
	{
		const_val * v1 =(const_val*)$1;
		const_val* con=(const_val*)$2;
		const_val* exp=(const_val*)$4;

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		code_merge_expr(v1,v1,exp);
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

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		$$ = (void*)exp;
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

		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_YES;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("return\n");
		v1->code_head = new_node;
		v1->code_index = new_node;

		$$ = (void*)v1;
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

		//code_dump_expr(exp);

		code_single_change_type(exp,func_type);

		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_YES;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = f_get_s_type(func_type);
		new_node->content = mergestring(new_node->content,"return\n");
		v1->code_head = new_node;
		v1->code_index = new_node;

		code_merge_expr(v1,exp,v1);

		$$ = (void*)v1;

	}
| BREAK ';'
	{
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_NO;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		

		char outstring[2000];
		sprintf(outstring,"goto LOOP_END_%d\n",l_stack!=NULL?l_stack->loop_val:0);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_head = new_node;
		v1->code_index = new_node;

		$$ = (void*)v1;
	}
| CONTINUE ';'
	{
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_NO;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");


		char outstring[2000];
		sprintf(outstring,"goto LOOP_END_%d\n",l_stack!=NULL?l_stack->loop_val:0);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_head = new_node;
		v1->code_index = new_node;

		$$ = (void*)v1;
	}
;



%%

void init_type_check(int type1,int type2)
{

	if(type1!=type2)
	{
		if(type1==TYPE_INT || type1==TYPE_DOUBLE || type1==TYPE_FLOAT)
		{
			if(type2==TYPE_INT || type2==TYPE_DOUBLE || type2==TYPE_FLOAT)
			{
				if(type1<type2)
					dump_error(ERROR_IDTYPE_NOT_MATCH);
			}
			else
				dump_error(ERROR_IDTYPE_NOT_MATCH);
		}
		else
			dump_error(ERROR_IDTYPE_NOT_MATCH);
		
	}
	
}

void equal_type_check(const_val* con,const_val *exp)
{
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
 					printf("%-24s",(char*)pr->list);
 					break;
 				case TYPE_INT:
 					printf("%-24d",*(int*)pr->list);
 					break;
 				case TYPE_DOUBLE:
 					printf("%-24s",(char*)pr->list);
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
 		printf("  p:%d ",list->cur_index);

		
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

	symbol_list *f = NULL;

	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			if(p->val->kind==KIND_FUNCTION)
				f = p;
		}
		p=p->next;
	}

	func_val *f_list = f==NULL?(NULL):((func_val*)f->val->list);

	symbol_list *argu_head=NULL;
	symbol_list *argu_index=NULL;

	output_cur_position = 0;

	for(int t=0; f_list!=NULL && t<f_list->argc;t++)
	{
		symbol_list *new_node=NEW_VAL(symbol_list);

		argu_val *argu_p=(f_list->argv)+t;

		new_node->name = strdup(argu_p->name);
		new_node->val=NEW_VAL(id_val);
		new_node->cur_index = output_cur_position;
		output_cur_position += f_type_need(argu_p->val->type);
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

	if(cur_table->level != 0)
	{
		cur_table->s_index->cur_index = output_cur_position;
		output_cur_position += f_type_need(id_in->type);
	}
	else
		cur_table->s_index->cur_index = -1;
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

void gene_init_code()
{
	output_string = strdup("output");

	output_list *new_node = NEW_VAL(output_list);
	//new_node->content = strdup(".class public demo\n");
	new_node->content = strdup(".class public ");
	new_node->content = mergestring(new_node->content,output_string);
	new_node->content = mergestring(new_node->content,"\n");
	new_node->next = NULL;

	output_head = new_node;
	output_index = new_node;

	new_node = NEW_VAL(output_list);
	new_node->content = strdup(".super java/lang/Object\n");
	new_node->next = NULL;

	output_index->next = new_node;
	output_index = new_node;

	new_node = NEW_VAL(output_list);
	new_node->content = strdup(".field public static _sc Ljava/util/Scanner;\n");
	new_node->next = NULL;

	output_index->next = new_node;
	output_index = new_node;

	//

	new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

	output_func_head = new_node;
	output_func_index = new_node;

	//

	new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

	output_main_head = new_node;
	output_main_index = new_node;

	
	



}

void code_gvar(char* name, int type)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup(".field public static ");
	new_node->content = mergestring(new_node->content,name);
	switch(type)
	{
		case TYPE_INT:
			new_node->content = mergestring(new_node->content," I\n");
			break;
		case TYPE_FLOAT:
			new_node->content = mergestring(new_node->content," F\n");
			break;
		case TYPE_DOUBLE:
			new_node->content = mergestring(new_node->content," D\n");
			break;
		case TYPE_BOOL:
			new_node->content = mergestring(new_node->content," Z\n");
			break;
	}

	output_index->next = new_node;
	output_index = new_node;
}

void code_cur_func_start(char *name, id_val *id)
{



	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;

	new_node->content = strdup(".method public static _");
	new_node->content = mergestring(new_node->content,name);
	new_node->content = mergestring(new_node->content,"(");
	
	func_val *f = (func_val*)id->list;

	int t;
	for(t=0;t<f->argc;t++)
	{
		argu_val* argu = &f->argv[t];
		new_node->content = mergestring(new_node->content,f_get_type(argu->val->type));
	}

	new_node->content = mergestring(new_node->content,")");
	new_node->content = mergestring(new_node->content,f_get_type(id->type));
	new_node->content = mergestring(new_node->content,"\n");

	output_func_index->next = new_node;
	output_func_index = new_node;

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("");
	output_cur_head = new_node;
	output_cur_index = new_node;

}

void code_read(const_val *v1,int type)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	//new_node->content = strdup("getstatic demo/_sc Ljava/util/Scanner;\n");
	new_node->content = strdup("getstatic ");
	new_node->content = mergestring(new_node->content,output_string);
	new_node->content = mergestring(new_node->content,"/_sc Ljava/util/Scanner;\n");
	new_node->content = mergestring(new_node->content,"invokevirtual java/util/Scanner/next");
	new_node->content = mergestring(new_node->content,f_read_type(type));
	new_node->content = mergestring(new_node->content,"()");
	new_node->content = mergestring(new_node->content,f_get_type(type));
	new_node->content = mergestring(new_node->content,"\n");

	v1->code_index->next = new_node;
	v1->code_index = new_node;
}

void code_print(const_val *v1, int type)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("invokevirtual java/io/PrintStream/print(");
	new_node->content = mergestring(new_node->content,f_print_type(type));
	new_node->content = mergestring(new_node->content,")V\n");

	v1->code_index->next = new_node;
	v1->code_index = new_node;
}

void code_cur_func_end()
{
	char* num = (char*)malloc(sizeof(char)*200);
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;

	new_node->content = strdup(".limit stack ");
	sprintf(num,"%d",300);
	new_node->content = mergestring(new_node->content,num);
	new_node->content = mergestring(new_node->content,"\n");

	output_func_index->next = new_node;
	output_func_index = new_node;

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;

	new_node->content = strdup(".limit locals ");
	sprintf(num,"%d",output_stack+5);
	new_node->content = mergestring(new_node->content,num);
	new_node->content = mergestring(new_node->content,"\n");

	output_func_index->next = new_node;
	output_func_index = new_node;

	//.....
	output_list *parser= output_cur_head;
	while(parser!=NULL)
	{
		output_func_index->next = parser;
		output_func_index = output_func_index->next;
		parser = parser->next;
	}
	//

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup(".end method\n");

	output_func_index->next = new_node;
	output_func_index = new_node;
}

void code_void_return(const_val **v1)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("return\n");

	(*v1)->code_index->next = new_node;
	(*v1)->code_index = new_node;
}

void code_calculate(const_val *output,const_val *v1, const_val *v2, int cal_type)
{	
	code_merge_expr(output,v1,v2);
	char *oper = strdup("");
	switch(output->type)
	{
		case TYPE_INT:
			oper = strdup("i");
			break;
		case TYPE_FLOAT:
			oper = strdup("f");
			break;
		case TYPE_DOUBLE:
			oper = strdup("d");
			break;
	}
	switch(cal_type)
	{
		case CAL_MULTI:
			oper = mergestring(oper,"mul\n");
			break;
		case CAL_PLUS:
			oper = mergestring(oper,"add\n");
			break;
		case CAL_MINUS:
			oper = mergestring(oper,"sub\n");
			break;
		case CAL_DIV:
			oper = mergestring(oper,"div\n");
			break;
		case CAL_MOD:
			oper = mergestring(oper,"rem\n");
			break;
	}

	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = oper;

	output->code_index->next = new_node;
	output->code_index = new_node;
}

void code_cmp(const_val *output,const_val *v1,const_val *v2, int cmp)
{
	int cur_type = (v1->type>v2->type)?(v1->type):(v2->type);
	code_merge_expr(output,v1,v2);
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("");
	char c_out[1000];
	if( cur_type==TYPE_INT || cur_type == TYPE_BOOL)
	{
		sprintf(c_out,"if_icmp%s TRUE_%d\nbipush 0\ngoto END_%d\nTRUE_%d:\nbipush 1\nEND_%d:\n",code_cmp_label(cmp),label,label,label,label);
		new_node->content = mergestring(new_node->content,c_out);
	}
	else
	{
		sprintf(c_out,"%scmpg\nif%s TRUE_%d\nbipush 0\ngoto END_%d\nTRUE_%d:\nbipush 1\nEND_%d:\n",f_get_s_type(cur_type),code_cmp_label(cmp)
			,label,label,label,label);
		new_node->content = mergestring(new_node->content,c_out);
	}
	label++;

	output->code_index->next = new_node;
	output->code_index = new_node;
	
}

char *code_cmp_label(int cmp)
{
	char *ans;
	switch(cmp)
	{
		case CMP_EQ:
			ans = strdup("eq");
			break;
		case CMP_NE:
			ans = strdup("ne");
			break;
		case CMP_LT:
			ans = strdup("lt");
			break;
		case CMP_LE:
			ans = strdup("le");
			break;
		case CMP_GT:
			ans = strdup("gt");
			break;
		case CMP_GE:
			ans = strdup("ge");
			break;

	}
	return ans;
}


void code_merge_expr(const_val *output, const_val *v1, const_val *v2)
{
	output_list *ans;
	output_list *index;

	output_list *parser=v1->code_head;

	output_list *new_node = NEW_VAL(output_list);
	new_node->content = strdup(parser->content);
	new_node->next = NULL;


	ans= new_node;
	index = new_node;
	parser = parser->next;
	while(parser!=NULL)
	{
		new_node = NEW_VAL(output_list);
		new_node->content = strdup(parser->content);
		new_node->next = NULL;

		index->next = new_node;
		index = new_node;
		parser = parser->next;
	}

	parser = v2->code_head;
	while(parser!=NULL)
	{

		new_node = NEW_VAL(output_list);
		new_node->content = strdup(parser->content);
		new_node->next = NULL;

		index->next = new_node;
		index = new_node;
		parser = parser->next;
	}

	output->code_head = ans;
	output->code_index = index;
}

void code_dump_expr(const_val *v1)
{
	output_list *parser = v1->code_head;
	while(parser!=NULL)
	{
		output_cur_index->next = parser;
		output_cur_index = parser;
		parser = parser->next;
	}
}

void code_go_minus(const_val *v1)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	switch(v1->type)
	{
		case TYPE_INT:
			new_node->content =strdup("ineg\n");
			break;
		case TYPE_FLOAT:
			new_node->content = strdup("fneg\n");
			break;
		case TYPE_DOUBLE:
			new_node->content = strdup("dneg\n");
			break;
	}

	v1->code_index->next = new_node;
	v1->code_index = new_node;

}

	
void code_load_val(const_val *v1)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("");
	if( v1->kind == KIND_CONST_VAL )
	{
		new_node->content = strdup("ldc");
		char num[200];
		switch(v1->type)
		{
			case TYPE_INT:
				sprintf(num," %d",*(int*)v1->value);
				new_node->content = mergestring(new_node->content,num);
				break;
			case TYPE_FLOAT:
				new_node->content = mergestring(new_node->content," \"");
				new_node->content = mergestring(new_node->content,(char*)v1->value);
				new_node->content = mergestring(new_node->content,"\"");

				new_node->content = mergestring(new_node->content,"\ninvokestatic java/lang/Float/parseFloat(Ljava/lang/String;)F");
				break;
			case TYPE_DOUBLE:
				new_node->content = mergestring(new_node->content," \"");
				new_node->content = mergestring(new_node->content,(char*)v1->value);
				new_node->content = mergestring(new_node->content,"\"");

				new_node->content = mergestring(new_node->content,"\ninvokestatic java/lang/Double/parseDouble(Ljava/lang/String;)D");
				break;
			case TYPE_STRING:
				new_node->content = mergestring(new_node->content," \"");
				new_node->content = mergestring(new_node->content,(char*)v1->value);
				new_node->content = mergestring(new_node->content,"\"");
				break;
			case TYPE_BOOL:
				if(strcmp(v1->value,"true")==0)
					sprintf(num," %d",1);
				else
					sprintf(num," %d",0);
				new_node->content = mergestring(new_node->content,num);
				break;
		}
	}
	if( v1->kind == KIND_RVAL)
	{
		invo_val *id_info = (invo_val*)v1->value;
		symbol_list *f_id = find_symbol(id_info->name,0);

		if(f_id->cur_index==-1) //global
		{
			//new_node->content = strdup("getstatic demo/");
			new_node->content = strdup("getstatic ");
			new_node->content = mergestring(new_node->content,output_string);
			new_node->content = mergestring(new_node->content,"/");
			new_node->content = mergestring(new_node->content,id_info->name);
			new_node->content = mergestring(new_node->content," ");
			new_node->content = mergestring(new_node->content,f_get_type(v1->type));
		}
		else
		{
			new_node->content = f_get_s_type(v1->type);
			new_node->content = mergestring(new_node->content,"load ");
			char num[200];
			sprintf(num,"%d",f_id->cur_index);
			new_node->content = mergestring(new_node->content,num);
		}

	}
	new_node->content = mergestring(new_node->content,"\n");

	v1->code_head = new_node;
	v1->code_index = new_node;

}

void code_store_val(char* name,const_val *v1)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("");

	symbol_list *f_id = find_symbol(name, 0);
	
	if(f_id==NULL) return;

	id_val *id = (id_val*)f_id->val;
	if(f_id->cur_index == -1) //global
	{
		// new_node->content = strdup("putstatic demo/");
		new_node->content = strdup("putstatic ");
		new_node->content = mergestring(new_node->content,output_string);
		new_node->content = mergestring(new_node->content,"/");
		new_node->content = mergestring(new_node->content,name);
		new_node->content = mergestring(new_node->content," ");
		new_node->content = mergestring(new_node->content,f_get_type(id->type));
	}
	else
	{
		new_node->content = f_get_s_type(id->type);
		new_node->content = mergestring(new_node->content,"store ");
		char num[200];
		sprintf(num,"%d",f_id->cur_index);
		new_node->content = mergestring(new_node->content,num);
	}

	new_node->content = mergestring(new_node->content,"\n");
	

	v1->code_index->next = new_node;
	v1->code_index = new_node;
	//output_cur_index->next = new_node;
	//output_cur_index = new_node;
}

void code_single_change_type(const_val *v1,int type)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

	if(v1->type!=type)
	{
		if(v1->type == TYPE_INT)
			new_node->content = strdup("i2");
		if(v1->type == TYPE_FLOAT)
			new_node->content = strdup("f2");
		
		if(type == TYPE_DOUBLE)
			new_node->content = mergestring(new_node->content,"d\n");
		else if(type == TYPE_FLOAT)
			new_node->content = mergestring(new_node->content,"f\n");
		v1->code_index->next = new_node;
		v1->code_index = new_node;
	}

	new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

}

void code_call_func(const_val *v1, symbol_list *list)
{
	if( ((id_val*)list->val)->kind != KIND_FUNCTION) return;
	char outstring[2000];
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("");

	// sprintf(outstring,"invokestatic demo/_%s(%s)%s\n",list->name,f_argulist(list),f_get_type( ((id_val*)list->val)->type ));
	sprintf(outstring,"invokestatic %s/_%s(%s)%s\n",output_string,list->name,f_argulist(list),f_get_type( ((id_val*)list->val)->type ));
	new_node->content = mergestring(new_node->content,outstring);
	v1->code_index->next = new_node;
	v1->code_index = new_node;
}

void code_change_type(const_val* v1, const_val *v2, int type)
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

	if(v1->type!=type)
	{
		if(v1->type == TYPE_INT)
			new_node->content = strdup("i2");
		if(v1->type == TYPE_FLOAT)
			new_node->content = strdup("f2");
		
		if(type == TYPE_DOUBLE)
			new_node->content = mergestring(new_node->content,"d\n");
		else if(type == TYPE_FLOAT)
			new_node->content = mergestring(new_node->content,"f\n");
		v1->code_index->next = new_node;
		v1->code_index = new_node;
	}

	new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;

	if(v2->type!=type)
	{
		if(v2->type == TYPE_INT)
			new_node->content = strdup("i2");
		if(v2->type == TYPE_FLOAT)
			new_node->content = strdup("f2");

		if(type == TYPE_DOUBLE)
			new_node->content = mergestring(new_node->content,"d\n");
		else if(type == TYPE_FLOAT)
			new_node->content = mergestring(new_node->content,"f\n");
		v2->code_index->next = new_node;
		v2->code_index = new_node;
		
	}
}

void code_find_max_type(const_val* v1, const_val* v2)
{
	int cur_type;
	if(v1->type <= TYPE_DOUBLE && v2->type <= TYPE_DOUBLE)
	{
		cur_type = (v1->type>v2->type) ? (v1->type): (v2->type);
		code_change_type(v1,v2,cur_type);
	}
}


void code_final()
{
	fg = fopen("gene.j", "w");
	
	output_list *parser = output_head;
	while(parser!=NULL)
	{
		fprintf(fg,"%s",parser->content);
		parser = parser->next;
	}

	parser = output_func_head;
	while(parser!=NULL)
	{
		fprintf(fg,"%s",parser->content);
		parser = parser->next;
	}

	
	parser = output_main_head;
	while(parser!=NULL)
	{
		fprintf(fg,"%s",parser->content);
		parser = parser->next;
	}
	fclose(fg);
}

void code_dump_main()
{
	printf("START\n");
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup(".method public static main([Ljava/lang/String;)V\n");
	new_node->content = mergestring(new_node->content ,".limit stack 100\n");
	new_node->content = mergestring(new_node->content ,".limit locals 10\n");
	new_node->content = mergestring(new_node->content ,"new java/util/Scanner\ndup\n");
	new_node->content = mergestring(new_node->content ,"getstatic java/lang/System/in Ljava/io/InputStream;\n");
	new_node->content = mergestring(new_node->content ,"invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V\n");
	//new_node->content = mergestring(new_node->content ,"putstatic demo/_sc Ljava/util/Scanner;\n");
	new_node->content = mergestring(new_node->content ,"putstatic ");
	new_node->content = mergestring(new_node->content ,output_string);
	new_node->content = mergestring(new_node->content ,"/_sc Ljava/util/Scanner;\n");

	new_node->next = output_main_head;
	output_main_head = new_node;

	code_call_main(&output_main_index);

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup("return\n.end method\n");


	output_main_index->next = new_node;
	output_main_index = new_node;

}

void code_call_main(output_list **main_list)
{
	symbol_list *id = find_symbol("main",0);



	if(id!=NULL)
	{
		
		const_val *v1 = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		v1->code_head = new_node;
		v1->code_index = new_node;

		code_call_func(v1,id);

		output_list *parser = v1->code_head;
		
		while(parser!=NULL)
		{
			new_node = NEW_VAL(output_list);
			new_node->next = NULL;
			new_node->content = strdup(parser->content);
			(*main_list)->next = new_node;
			(*main_list) = new_node;
			parser= parser->next;
		}
	}

}

void code_gvar_init(char* name, const_val* v1,int type)
{
	output_list *parser = v1->code_head;
	output_list *new_node;
	while(parser!=NULL)
	{
		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup(parser->content);

		output_main_index->next = new_node;
		output_main_index = new_node;

		parser = parser->next;
	}
	new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	//new_node->content = strdup("putstatic demo/");
	new_node->content = strdup("putstatic ");
	new_node->content = mergestring(new_node->content,output_string);
	new_node->content = mergestring(new_node->content,"/");
	new_node->content = mergestring(new_node->content,name);
	new_node->content = mergestring(new_node->content," ");
	new_node->content = mergestring(new_node->content,f_get_type(type));
	new_node->content = mergestring(new_node->content,"\n");
	
	output_main_index->next = new_node;
	output_main_index = new_node;
}

char* f_argulist(symbol_list *list)
{
	id_val *pr =(id_val*)list->val;
	if( pr->kind != KIND_FUNCTION ) return strdup("");

	char *ans = strdup("");
	func_val *p=(func_val*)pr->list;
	for(int t=0;t<p->argc;t++)
	{
		argu_val *ar=(argu_val*)(p->argv+t);
		id_val *id_argu=(id_val*)ar->val;
		arr_val *arr_argu=(arr_val*)id_argu->list;

		ans = mergestring(ans,f_get_type(id_argu->type));
	}

	return ans;
}

void f_push_loop_state()
{
	loop_stack *new_node = NEW_VAL(loop_stack);
	new_node->loop_val = loop_label;
	new_node->next = l_stack;
	l_stack = new_node;

	loop_label++;
}

void f_pop_loop_state()
{
	loop_stack *f = l_stack;
	l_stack = l_stack->next;
	
	free(f);
}


char *f_print_type(int type)
{
	char *ans = strdup("");
	switch(type)
	{
		case TYPE_INT:
			ans = strdup("I");
			break;
		case TYPE_FLOAT:
			ans = strdup("F");
			break;
		case TYPE_DOUBLE:
			ans = strdup("D");
			break;
		case TYPE_BOOL:
			ans = strdup("Z");
			break;
		case TYPE_STRING:
			ans = strdup("Ljava/lang/String;");
			break;
	}

	return ans;
}

char *f_read_type(int type)
{
	char *ans=strdup("");
	switch(type)
	{
		case TYPE_INT:
			ans = strdup("Int");
			break;
		case TYPE_FLOAT:
			ans = strdup("Float");
			break;
		case TYPE_DOUBLE:
			ans = strdup("Double");
			break;
		case TYPE_BOOL:
			ans = strdup("Boolean");
			break;
	}
	return ans;
}

void f_output_cur_init()
{
	output_list *new_node = NEW_VAL(output_list);
	new_node->content = strdup("");
	new_node->next = NULL;
	output_cur_head = new_node;
	output_cur_index = new_node;
	//output_stack = 0;
	output_oper = 0;
}

void f_output_stack_add(int type)
{
	switch(type)
	{
		case TYPE_INT:
		case TYPE_BOOL:
		case TYPE_FLOAT:
			output_stack += 1;
			break;
		case TYPE_DOUBLE:
			output_stack += 2;
			break;
	}
}

int f_type_need(int type)
{
	switch(type)
	{
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_BOOL:
			return 1;
		case TYPE_DOUBLE:
			return 2;
	}
}

char* f_get_s_type(int type)
{
	char* ans = NULL;
	switch(type)
	{
		case TYPE_INT:
		case TYPE_BOOL:
			ans = strdup("i");
			break;
		case TYPE_DOUBLE:
			ans = strdup("d");
			break;
		case TYPE_FLOAT:
			ans = strdup("f");
	}
	return ans;
}

char* f_get_type(int type)
{
	char* ans=NULL;
	switch(type)
	{
		case TYPE_INT:
			ans = strdup("I");
			break;
		case TYPE_FLOAT:
			ans = strdup("F");
			break;
		case TYPE_DOUBLE:
			ans = strdup("D");
			break;
		case TYPE_BOOL:
			ans = strdup("Z");
			break;
		case TYPE_VOID:
			ans = strdup("V");
			break;
		default:
			ans = strdup("");
			break;
	}
	return ans;
}

int main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	gene_init_code();
	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;

	symbol_table* new_table=(symbol_table*)calloc(1,sizeof(symbol_table));
	
	cur_table=new_table;
	
	yyparse();


	code_dump_main();
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
		code_final();
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

	 
	 fclose(fp);
	exit(0);
}
