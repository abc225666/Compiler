/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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



int yyerror( char *msg );
int main( int argc, char **argv );
int yylex();


#line 359 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    BASIC_TYPE = 259,
    ID = 260,
    INT_CONST = 261,
    FLOAT_CONST = 262,
    BOOL_CONST = 263,
    STRING_CONST = 264,
    READ = 265,
    PRINT = 266,
    IF = 267,
    ELSE = 268,
    DO = 269,
    WHILE = 270,
    FOR = 271,
    CONTINUE = 272,
    BREAK = 273,
    RETURN = 274,
    CONST = 275,
    OR = 276,
    AND = 277,
    LE = 278,
    EQ = 279,
    GE = 280,
    NE = 281,
    UNOT = 282,
    UMINUS = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 294 "parser.y" /* yacc.c:355  */

	char* str;
	void* v;
	int c_type;
	int return_type;

#line 435 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 452 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    34,     2,     2,
      39,    40,    32,    30,    38,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      28,    37,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   349,   349,   350,   351,   352,   356,   357,   358,   359,
     360,   361,   365,   366,   367,   368,   372,   393,   416,   436,
     460,   481,   505,   526,   551,   571,   597,   619,   644,   669,
     702,   731,   762,   790,   823,   850,   854,   822,   871,   897,
     901,   870,   917,   936,   940,   916,   956,   981,   955,   995,
    1021,   994,  1034,  1053,  1033,  1070,  1069,  1081,  1080,  1100,
    1104,  1110,  1114,  1120,  1126,  1130,  1141,  1145,  1160,  1168,
    1182,  1186,  1197,  1196,  1221,  1220,  1246,  1245,  1265,  1264,
    1289,  1288,  1315,  1314,  1336,  1348,  1364,  1386,  1409,  1421,
    1430,  1440,  1449,  1461,  1470,  1483,  1489,  1495,  1501,  1510,
    1522,  1533,  1544,  1558,  1586,  1625,  1657,  1693,  1714,  1738,
    1754,  1770,  1784,  1800,  1816,  1832,  1848,  1864,  1880,  1897,
    1914,  1920,  1934,  1958,  1982,  2006,  2011,  2050,  2093,  2110,
    2132,  2153,  2168,  2196,  2211,  2229,  2249,  2290,  2323,  2369,
    2384,  2383,  2431,  2430,  2483,  2482,  2542,  2541,  2592,  2608,
    2636,  2664,  2677,  2691,  2706,  2734,  2762,  2780,  2796,  2824,
    2838,  2866,  2880,  2894,  2922,  2935,  2966,  2981,  3015,  3036
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "BASIC_TYPE", "ID", "INT_CONST",
  "FLOAT_CONST", "BOOL_CONST", "STRING_CONST", "READ", "PRINT", "IF",
  "ELSE", "DO", "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "CONST",
  "OR", "AND", "LE", "EQ", "GE", "NE", "UNOT", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UMINUS", "';'", "'='", "','", "'('", "')'", "'{'",
  "'}'", "'!'", "$accept", "program", "prog_content", "gvar_all_def",
  "gvar_def", "gvar_list", "gconst_list", "var_def", "func_def", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "compound", "$@16", "$@17", "statement",
  "compound_in_argu_func", "compound_list", "func_decl", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "argu_list", "argu", "basic",
  "void_reduce", "liter_const", "value_type", "int_value", "float_value",
  "bool_value", "string_value", "var_list", "const_list", "expr",
  "func_invo", "expr_list", "simple_stat", "var_ref", "condition",
  "bool_expr", "while_stat", "$@24", "$@25", "for_stat", "$@26", "$@27",
  "init_expr", "init_expr_list", "incr_expr", "incr_expr_list",
  "jump_stat", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      43,    45,    42,    47,    37,   283,    59,    61,    44,    40,
      41,   123,   125,    33
};
# endif

#define YYPACT_NINF -188

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-188)))

#define YYTABLE_NINF -166

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,  -188,  -188,    22,    33,     2,  -188,     2,  -188,    61,
      65,    70,  -188,  -188,     2,  -188,     2,  -188,  -188,  -188,
      83,    91,    45,    68,   109,     2,  -188,  -188,  -188,  -188,
     155,  -188,    17,    -8,    20,   120,    96,    99,  -188,  -188,
    -188,  -188,   155,   155,   155,  -188,  -188,  -188,  -188,  -188,
     338,  -188,   121,    22,   -23,   140,  -188,   155,  -188,   129,
      22,   -20,   168,   -13,  -188,  -188,  -188,  -188,   120,    73,
    -188,   318,   571,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,  -188,  -188,   111,   142,
      -2,  -188,   145,  -188,   356,   148,   156,    53,   157,  -188,
    -188,  -188,  -188,    79,  -188,   278,   155,  -188,   559,   571,
      69,    69,    69,    69,    69,    69,   102,   102,  -188,  -188,
    -188,  -188,  -188,  -188,   159,   162,   169,  -188,  -188,  -188,
    -188,   170,   163,   171,  -188,  -188,  -188,  -188,   298,   274,
     172,   175,  -188,  -188,   274,   173,   184,  -188,  -188,  -188,
    -188,   116,   185,   155,   182,  -188,   187,   188,   186,   192,
     101,    22,   181,  -188,  -188,  -188,  -188,   274,   219,   482,
    -188,   193,  -188,  -188,  -188,  -188,  -188,  -188,   274,   191,
    -188,  -188,   274,  -188,   198,   498,   155,   206,   155,   224,
    -188,  -188,  -188,   514,   251,   274,   215,   216,  -188,  -188,
     131,   254,  -188,   155,   274,  -188,  -188,   274,   218,  -188,
    -188,   546,   221,   247,   223,    99,   226,   229,   232,   224,
    -188,   233,   264,   234,  -188,  -188,  -188,   155,  -188,   164,
     530,  -188,   230,   245,  -188,   206,   235,  -188,  -188,   155,
     141,   257,   259,   120,   260,  -188,   374,  -188,   155,  -188,
    -188,   256,  -188,  -188,   258,   155,   206,   410,   224,   289,
    -188,   155,   103,   120,  -188,  -188,   392,  -188,   206,   293,
    -188,  -188,   309,   297,   295,   224,   224,   428,  -188,  -188,
     149,  -188,  -188,  -188,   301,   155,  -188,   307,   316,   314,
    -188,  -188,  -188,  -188,   446,   206,  -188,   155,  -188,  -188,
    -188,   464,   206,   350,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    88,    87,     0,     0,     0,    14,     5,    15,     0,
       0,     0,     1,    12,     3,    13,     4,     9,    10,    11,
       0,     0,     0,     0,     0,     2,     6,     7,     8,    18,
       0,    24,     0,     0,     0,     0,     0,   126,    99,   100,
     101,   102,     0,     0,     0,   125,    95,    96,    97,    98,
       0,   127,    42,     0,     0,     0,    16,     0,    22,    52,
       0,     0,     0,     0,    89,    91,    93,    94,     0,     0,
     121,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    25,     0,     0,
       0,    85,    38,    86,     0,     0,     0,     0,    49,    90,
      92,    21,    27,     0,   130,     0,     0,   120,   123,   122,
     115,   118,   117,   119,   114,   116,   111,   112,   109,   110,
     113,    43,    77,    84,    34,     0,     0,    17,    23,    53,
      83,    46,     0,     0,    20,    26,   132,   129,     0,    67,
       0,     0,    39,    75,    67,     0,     0,    50,    81,   131,
     128,   126,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,    55,    71,    59,    70,    44,    66,     0,     0,
      60,     0,    61,    62,    63,    64,    35,    73,    67,     0,
      47,    79,    67,   136,     0,     0,     0,     0,     0,   152,
     169,   168,   166,     0,     0,     0,     0,     0,    68,    69,
       0,     0,    65,     0,    67,    40,    54,    67,     0,   135,
     134,   139,     0,     0,     0,   136,   150,     0,     0,     0,
     167,     0,     0,     0,    58,    45,    30,     0,   105,     0,
       0,    36,     0,     0,    51,     0,     0,   140,   155,     0,
       0,   149,     0,     0,     0,    56,     0,    28,     0,   103,
     133,     0,    41,    48,   137,     0,     0,   151,   161,     0,
     154,     0,     0,     0,    31,   106,     0,    37,     0,     0,
     141,   156,   160,     0,     0,     0,   161,   148,    33,   108,
       0,    29,   104,   138,     0,     0,   146,   158,     0,     0,
     153,    32,   107,   143,   159,     0,   163,     0,   144,   164,
     147,     0,     0,   157,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,   342,  -188,   154,  -188,  -188,  -164,   166,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -171,  -188,  -188,  -156,  -109,   178,
     183,  -188,  -188,  -188,  -188,  -188,  -188,   323,    34,    58,
    -188,   -67,  -188,   -31,   -28,   -27,   -26,  -188,  -188,   -30,
    -187,  -188,  -188,  -133,  -188,  -178,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,    89,  -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    16,     5,    17,    21,    24,   163,    18,   140,
     204,   251,   125,   178,   232,    88,   139,   197,   145,   207,
     132,   182,    95,   144,   164,   195,   196,   165,   166,   167,
      19,   141,   126,    89,   146,   133,    96,    53,    54,   168,
      10,    63,    45,    46,    47,    48,    49,   201,   222,   169,
      51,   106,   170,   171,   172,   212,   173,   256,   187,   174,
     302,   295,   218,   219,   274,   275,   175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   103,   216,   198,    64,     1,     2,    65,    66,    67,
     214,   199,    70,    71,    72,    91,   213,    92,    91,   184,
      98,     2,     3,   101,     2,   102,     2,    94,    56,    57,
      58,    99,   241,    12,   100,   179,   123,    64,   124,   105,
      65,    66,    67,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   217,    52,     9,   198,
      59,    11,   259,     9,   254,     9,    20,   199,    61,   205,
      22,   272,     9,   208,     9,    23,   138,   269,    37,    38,
      39,    40,    41,     9,    34,   270,   242,    90,   287,   272,
      55,   123,    55,   131,    97,   231,    33,   283,   233,    81,
      82,    83,    84,    85,    42,    35,    37,    38,    39,    40,
      41,    55,    43,   104,    36,   134,    44,   135,    55,    29,
      30,    31,    32,   185,   300,   273,    38,    39,    40,    41,
     193,   304,    42,    68,    83,    84,    85,   192,    69,   278,
      43,   279,   288,   273,    44,    93,    37,    38,    39,    40,
      41,    62,   121,  -136,     6,    69,   211,   -76,   211,    13,
      37,    38,    39,    40,    41,   -82,     7,   226,   227,   228,
      26,    14,    42,   230,    38,    39,   262,   258,   122,    26,
      43,   -74,    27,     8,    44,   291,    42,   292,    15,   129,
     183,    27,   130,   -80,    43,   -72,   280,   246,    44,    28,
     247,   248,   249,   142,   147,   143,   -78,   148,    28,   257,
     211,   177,    64,   176,   180,    65,    66,    67,   266,   194,
     181,   186,   190,   -57,   200,   211,   188,   189,   191,   215,
     203,   277,    64,   206,   209,    65,    66,    67,     2,   151,
      38,    39,    40,    41,   152,   153,   154,   162,   155,   156,
     157,   158,   159,   160,   161,   294,   221,   224,   225,   229,
     234,   235,   236,   237,   238,    42,   239,   301,   240,   244,
     243,   268,   252,    43,   255,   162,   245,    44,     2,   151,
      38,    39,    40,    41,   152,   153,   154,   253,   155,   156,
     157,   158,   159,   160,   161,   260,   261,   263,   267,    73,
      74,    75,    76,    77,    78,    42,    79,    80,    81,    82,
      83,    84,    85,    43,  -165,   162,   136,    44,   137,    73,
      74,    75,    76,    77,    78,   276,    79,    80,    81,    82,
      83,    84,    85,   284,   285,   286,   149,   293,   150,    73,
      74,    75,    76,    77,    78,   296,    79,    80,    81,    82,
      83,    84,    85,   297,   298,  -162,    25,    60,   107,    73,
      74,    75,    76,    77,    78,   289,    79,    80,    81,    82,
      83,    84,    85,   223,    86,     0,    87,    73,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,    84,
      85,     0,   127,     0,   128,    73,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
     264,     0,   265,    73,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,     0,   281,     0,
     282,    73,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,   271,    73,
      74,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,   290,    73,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,   299,    73,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,   303,    73,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,     0,   202,    73,
      74,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,    84,    85,     0,   210,    73,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
     220,    73,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,     0,   250,    73,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,    84,
      85,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      30,    68,   189,   167,    35,     3,     4,    35,    35,    35,
     188,   167,    42,    43,    44,    38,   187,    40,    38,   152,
      40,     4,    20,    36,     4,    38,     4,    57,    36,    37,
      38,    62,   219,     0,    62,   144,    38,    68,    40,    69,
      68,    68,    68,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   189,    40,     0,   223,
      40,     3,   240,     5,   235,     7,     5,   223,    34,   178,
       5,   258,    14,   182,    16,     5,   106,   255,     5,     6,
       7,     8,     9,    25,    39,   256,   219,    53,   275,   276,
      32,    38,    34,    40,    60,   204,     5,   268,   207,    30,
      31,    32,    33,    34,    31,    37,     5,     6,     7,     8,
       9,    53,    39,    40,     5,    36,    43,    38,    60,    36,
      37,    38,    39,   153,   295,   258,     6,     7,     8,     9,
     160,   302,    31,    37,    32,    33,    34,    36,    39,    36,
      39,    38,   275,   276,    43,     5,     5,     6,     7,     8,
       9,    31,    41,    37,     0,    39,   186,    36,   188,     5,
       5,     6,     7,     8,     9,    36,     0,    36,    37,    38,
      16,     5,    31,   203,     6,     7,   243,    36,    36,    25,
      39,    36,    16,     0,    43,    36,    31,    38,     5,    41,
       5,    25,    36,    36,    39,    36,   263,   227,    43,    16,
      36,    37,    38,    41,    41,    36,    36,    36,    25,   239,
     240,    36,   243,    41,    41,   243,   243,   243,   248,   161,
      36,    39,    36,    42,     5,   255,    39,    39,    36,     5,
      37,   261,   263,    42,    36,   263,   263,   263,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    41,    14,    15,
      16,    17,    18,    19,    20,   285,     5,    42,    42,     5,
      42,    40,    15,    40,    38,    31,    37,   297,    36,     5,
      37,    13,    42,    39,    39,    41,    42,    43,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    42,    14,    15,
      16,    17,    18,    19,    20,    38,    37,    37,    42,    21,
      22,    23,    24,    25,    26,    31,    28,    29,    30,    31,
      32,    33,    34,    39,     5,    41,    38,    43,    40,    21,
      22,    23,    24,    25,    26,    36,    28,    29,    30,    31,
      32,    33,    34,    40,    37,    40,    38,    36,    40,    21,
      22,    23,    24,    25,    26,    38,    28,    29,    30,    31,
      32,    33,    34,    37,    40,     5,    14,    34,    40,    21,
      22,    23,    24,    25,    26,   276,    28,    29,    30,    31,
      32,    33,    34,   195,    36,    -1,    38,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    38,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      38,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    20,    45,    47,    48,    52,    74,    83,
      84,    83,     0,    48,    52,    74,    46,    48,    52,    74,
       5,    49,     5,     5,    50,    46,    48,    52,    74,    36,
      37,    38,    39,     5,    39,    37,     5,     5,     6,     7,
       8,     9,    31,    39,    43,    86,    87,    88,    89,    90,
      93,    94,    40,    81,    82,    83,    36,    37,    38,    40,
      81,    82,    31,    85,    87,    88,    89,    90,    37,    39,
      93,    93,    93,    21,    22,    23,    24,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    36,    38,    59,    77,
      82,    38,    40,     5,    93,    66,    80,    82,    40,    87,
      88,    36,    38,    85,    40,    93,    95,    40,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    41,    36,    38,    40,    56,    76,    36,    38,    41,
      36,    40,    64,    79,    36,    38,    38,    40,    93,    60,
      53,    75,    41,    36,    67,    62,    78,    41,    36,    38,
      40,     5,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    41,    51,    68,    71,    72,    73,    83,    93,
      96,    97,    98,   100,   103,   110,    41,    36,    57,    72,
      41,    36,    65,     5,    97,    93,    39,   102,    39,    39,
      36,    36,    36,    93,    83,    69,    70,    61,    51,    71,
       5,    91,    36,    37,    54,    72,    42,    63,    72,    36,
      36,    93,    99,    68,    99,     5,    94,    97,   106,   107,
      36,     5,    92,    73,    42,    42,    36,    37,    38,     5,
      93,    72,    58,    72,    42,    40,    15,    40,    38,    37,
      36,    94,    97,    37,     5,    42,    93,    36,    37,    38,
      36,    55,    42,    42,    68,    39,   101,    93,    36,    99,
      38,    37,    85,    37,    36,    38,    93,    42,    13,    99,
      68,    38,    94,    97,   108,   109,    36,    93,    36,    38,
      85,    36,    38,    68,    40,    37,    40,    94,    97,   108,
      38,    36,    38,    36,    93,   105,    38,    37,    40,    38,
      68,    93,   104,    38,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    53,    54,    55,    52,    56,    57,
      58,    52,    59,    60,    61,    52,    62,    63,    52,    64,
      65,    52,    66,    67,    52,    69,    68,    70,    68,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    75,    74,    76,    74,    77,    74,    78,    74,
      79,    74,    80,    74,    81,    81,    82,    83,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    86,    86,    87,
      88,    89,    90,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    96,    96,    96,    97,    98,    98,    99,
     101,   100,   102,   100,   104,   103,   105,   103,   106,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     4,     6,     3,     5,
       7,     6,     3,     5,     2,     4,     5,     4,     4,     6,
       3,     5,     7,     6,     0,     0,     0,    12,     0,     0,
       0,    11,     0,     0,     0,    10,     0,     0,    11,     0,
       0,    10,     0,     0,     9,     0,     4,     0,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     2,     2,
       1,     1,     0,     8,     0,     7,     0,     6,     0,     8,
       0,     7,     0,     6,     3,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     2,     4,     5,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     1,     1,     1,     5,     4,
       3,     3,     2,     4,     3,     3,     1,     5,     7,     1,
       0,     6,     0,     8,     0,    10,     0,     9,     4,     2,
       1,     3,     0,     5,     3,     2,     4,     5,     2,     3,
       1,     0,     5,     3,     4,     1,     2,     3,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 16:
#line 373 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),((const_val*)(yyvsp[-3].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1828 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 394 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)(yyvsp[-1].v))->type);
			code_single_change_type((const_val*)(yyvsp[-1].v),p->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-5].v))->basic_val);
			code_gvar_init((yyvsp[-3].str),(const_val*)(yyvsp[-1].v),((const_val*)(yyvsp[-5].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1855 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 417 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-2].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),((const_val*)(yyvsp[-2].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1879 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 437 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)(yyvsp[-1].v))->type);
			code_single_change_type((const_val*)(yyvsp[-1].v),p->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-4].v))->basic_val);
			code_gvar_init((yyvsp[-3].str),(const_val*)(yyvsp[-1].v),((const_val*)(yyvsp[-4].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1906 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 461 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-5].v))->basic_val);
		}
		else
			dump_error(result);

	}
#line 1931 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 482 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-4].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1956 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 506 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-3].v);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),((const_val*)(yyvsp[-3].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 1981 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 527 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-5].v);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)(yyvsp[-1].v))->type);
			code_single_change_type((const_val*)(yyvsp[-1].v),p->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-5].v))->basic_val);
			code_gvar_init((yyvsp[-3].str),(const_val*)(yyvsp[-1].v),((const_val*)(yyvsp[-5].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 2010 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 552 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-2].v);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-2].v))->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),((const_val*)(yyvsp[-2].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 2034 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 572 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-4].v);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=((const_val*)(yyvsp[-4].v))->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,((const_val*)(yyvsp[-1].v))->type);
			code_single_change_type((const_val*)(yyvsp[-1].v),p->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-4].v))->basic_val);
			code_gvar_init((yyvsp[-3].str),(const_val*)(yyvsp[-1].v),((const_val*)(yyvsp[-4].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 2061 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 598 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-5].v);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-5].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 2087 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 620 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-4].v);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),((const_val*)(yyvsp[-4].v))->basic_val);
		}
		else
			dump_error(result);
	}
#line 2113 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 645 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-3].v))->basic_val);
		}
		else
			dump_error(result);



		(yyval.v) = (yyvsp[-2].v);
	}
#line 2142 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 670 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-5].v))->basic_val);

			const_val *exp = (const_val*)(yyvsp[-1].v);
			init_type_check(p->type,exp->type);
		}
		else
			dump_error(result);


		const_val *con = (const_val*)(yyvsp[-1].v);
		const_val *rev = (const_val*)(yyvsp[-4].v);
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val((yyvsp[-3].str),con);
		code_merge_expr(rev,rev,con);

		(yyval.v) = (void*)rev;
	}
#line 2179 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 703 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-2].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-2].v))->basic_val);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		(yyval.v) = (void*)con;
	}
#line 2212 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 732 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-4].v))->basic_val);

			const_val *exp = (const_val*)(yyvsp[-1].v);
			init_type_check(p->type,exp->type);
		}
		else
			dump_error(result);

		const_val *con = (const_val*)(yyvsp[-1].v);
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val((yyvsp[-3].str),con);

		(yyval.v) = (void*)con;
	}
#line 2246 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 763 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		(yyval.v) = (void*)con;
	}
#line 2278 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 791 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);

		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
		}
		else
			dump_error(result);

		const_val *con  = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->code_head = new_node;
		con->code_index = new_node;

		(yyval.v) = (void*)con;
	}
#line 2311 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 823 "parser.y" /* yacc.c:1661  */
    {
		

		func_type = ((const_val*)(yyvsp[-5].v))->basic_val;
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-4].str),p);
	}
#line 2342 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 850 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 2350 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 854 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[0].v);
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2361 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 861 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-2].v);
		code_dump_expr(code);
		code_cur_func_end();

		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2375 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 871 "parser.y" /* yacc.c:1661  */
    {
		func_type = ((const_val*)(yyvsp[-4].v))->basic_val;
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-3].str),p);
	}
#line 2405 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 897 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 2413 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 901 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[0].v);
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2424 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 908 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-2].v);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2437 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 917 "parser.y" /* yacc.c:1661  */
    {
		func_type = ((const_val*)(yyvsp[-3].v))->basic_val;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-2].str),p);
	}
#line 2460 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 936 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-4].str));
	}
#line 2468 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 940 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[0].v);
		int hasreturn=v1->return_val;
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2479 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 947 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-2].v);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2492 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 956 "parser.y" /* yacc.c:1661  */
    {
		func_type = TYPE_VOID;
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-4].str),p);
	}
#line 2521 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 981 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 2529 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 985 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-1].v);
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2543 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 995 "parser.y" /* yacc.c:1661  */
    {
		func_type = TYPE_VOID;
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-3].str),p);
	}
#line 2573 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 1021 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 2581 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 1025 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-1].v);
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2594 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 1034 "parser.y" /* yacc.c:1661  */
    {
		func_type = TYPE_VOID;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;
		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DEF;
		t->argc=0;
		p->list =(void*)t;

		int result= def_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-2].str),p);
	}
#line 2617 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 1053 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-4].str));
	}
#line 2625 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 1057 "parser.y" /* yacc.c:1661  */
    {
		const_val* code= (const_val*)(yyvsp[-1].v);
		code_void_return(&code);
		code_dump_expr(code);
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2639 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 1070 "parser.y" /* yacc.c:1661  */
    { 
		add_newtable();
	}
#line 2647 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 1074 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();

		(yyval.v) = (yyvsp[-1].v);
	}
#line 2658 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 1081 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 2666 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 1085 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_NO;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next=NULL;
		new_node->content = strdup("");
		v1->code_head=new_node;
		v1->code_index=new_node;
		(yyval.v) = (void*)v1;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2683 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 1101 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 2691 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 1105 "parser.y" /* yacc.c:1661  */
    {
		const_val *con = (const_val*)(yyvsp[0].v);
		con->return_val = RETURN_NO;
		(yyval.v) = (void*)con;
	}
#line 2701 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 1111 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 2709 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 1115 "parser.y" /* yacc.c:1661  */
    {
		const_val *con = (const_val*)(yyvsp[0].v);
		con->return_val = RETURN_NO;
		(yyval.v) = (void*)con;
	}
#line 2719 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 1121 "parser.y" /* yacc.c:1661  */
    {
		const_val *con = (const_val*)(yyvsp[0].v);
		con->return_val = RETURN_NO;
		(yyval.v) = (void*)con;
	}
#line 2729 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 1127 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 2737 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 1131 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		//code_dump_expr(con);
		check_and_set_scalar((yyvsp[-1].v));
		con->return_val = RETURN_NO;
		(yyval.v) = (void*)con;
	}
#line 2749 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 1142 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 2757 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 1146 "parser.y" /* yacc.c:1661  */
    {
		const_val *con = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		con->return_val = RETURN_NO;
		con->code_head = new_node;
		con->code_index = new_node;

		(yyval.v) = (void*)con;
	}
#line 2773 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 1161 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[-1].v);
		const_val *v2 = (const_val*)(yyvsp[0].v);
		code_merge_expr(v1,v1,v2);

		(yyval.v) = (void*)v1;
	}
#line 2785 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 1169 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[-1].v);
		const_val *v2 = (const_val*)(yyvsp[0].v);
		code_merge_expr(v1,v1,v2);

		if(v1->return_val==RETURN_YES || v2->return_val==RETURN_YES)
			v1->return_val = RETURN_YES;
		else
			v1->return_val = RETURN_NO;

		(yyval.v) = (void*)v1;

	}
#line 2803 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 1183 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 2811 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 1187 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[0].v);
		v1->return_val = RETURN_NO;
		(yyval.v) = (const_val*)v1;
	}
#line 2821 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 1197 "parser.y" /* yacc.c:1661  */
    {
		
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DECL;
		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		output_stack = 0;
	}
#line 2848 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 1221 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		output_stack = 0;
	}
#line 2876 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 1246 "parser.y" /* yacc.c:1661  */
    {
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		output_stack = 0;
	}
#line 2898 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 1265 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DECL;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		output_stack = 0;
	}
#line 2925 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 1289 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		output_stack = 0;
		
	}
#line 2954 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 1315 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = ((const_val*)(yyvsp[-3].v))->basic_val;

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		output_stack = 0;
	}
#line 2975 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 1337 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = (func_val*)(yyvsp[-2].v);

		argu_val *co =(argu_val*)(yyvsp[-1].v);

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		(yyval.v) = (void*)p;
	}
#line 2991 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 1349 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)(yyvsp[-1].v);

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		(yyval.v) = (void*)p;
	}
#line 3008 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 1365 "parser.y" /* yacc.c:1661  */
    {
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup((yyvsp[0].str));
		
		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=((const_val*)(yyvsp[-1].v))->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;

		p->val->list=(void*)t;

		(yyval.v) = (void*)p;

		f_output_stack_add(((const_val*)(yyvsp[-1].v))->basic_val);
	}
#line 3030 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 1387 "parser.y" /* yacc.c:1661  */
    {
		const_val *re = NEW_VAL(const_val);


		if(!strcmp((yyvsp[0].str),"bool"))
			re->basic_val = TYPE_BOOL;
		else if(!strcmp((yyvsp[0].str),"int"))
			re->basic_val = TYPE_INT;
		else if(!strcmp((yyvsp[0].str),"float"))
			re->basic_val = TYPE_FLOAT;
		else if(!strcmp((yyvsp[0].str),"double"))
			re->basic_val = TYPE_DOUBLE;
		else if(!strcmp((yyvsp[0].str),"string"))
			re->basic_val = TYPE_STRING;
		else if(!strcmp((yyvsp[0].str),"boolean"))
			re->basic_val = TYPE_BOOL;

		(yyval.v) = (void*)re;
	}
#line 3054 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 1410 "parser.y" /* yacc.c:1661  */
    {
		const_val *re = NEW_VAL(const_val);
		re->basic_val = TYPE_VOID;
		
		(yyval.v) = (void*)re;
	}
#line 3065 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 1422 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 3078 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 1431 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		(yyval.v) = (void*)p;
	}
#line 3092 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 1441 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 3105 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 1450 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;

		char *str = strdup("-");
		p->list=(void*)mergestring(str,(char*)in->value);
		
		(yyval.v) = (void*)p;
	}
#line 3121 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 1462 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 3134 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 1471 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 3147 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 1484 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 3157 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 1490 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 3167 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 1496 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 3177 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 1502 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 3187 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 1511 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_INT;
		(yyval.v) = (void*)p;
	}
#line 3200 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 1523 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou = strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_FLOAT;
		(yyval.v) = (void*)p;
	}
#line 3212 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 1534 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		(yyval.v) = (void*)p;
	}
#line 3224 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 1545 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		(yyval.v) = (void*)p;
	}
#line 3236 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 1559 "parser.y" /* yacc.c:1661  */
    {
		//$$ = $<v>0;
		const_val *ori = (const_val*)(yyvsp[-3].v);
		const_val *v1 = (const_val*)(yyvsp[-2].v);
		v1->basic_val = ori->basic_val;


		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ori->basic_val;

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-3].v))->basic_val);
		}
		else
			dump_error(result);

		(yyval.v) = (void*)v1;
	}
#line 3268 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 1587 "parser.y" /* yacc.c:1661  */
    {
		const_val *ori = (const_val*)(yyvsp[-5].v);
		const_val *v1 = (const_val*)(yyvsp[-4].v);
		v1->basic_val = ori->basic_val;

		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = ori->basic_val;


		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-5].v))->basic_val);

			const_val *exp = (const_val*)(yyvsp[-1].v);
			init_type_check(p->type,exp->type);

			
		}
		else
			dump_error(result);

		const_val *con = (const_val*)(yyvsp[-1].v);
		code_single_change_type(con,p->type);
		//code_dump_expr(con);
		code_store_val((yyvsp[-3].str),con);
		code_merge_expr(v1,v1,con);

		(yyval.v) = (void*)v1;
	}
#line 3311 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 1626 "parser.y" /* yacc.c:1661  */
    {
		// $$ = $<v>0;
		const_val *ori = (const_val*)(yyvsp[-2].v);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-2].v))->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-2].v))->basic_val);
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
		(yyval.v) = (void*)v1;


	}
#line 3347 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 1658 "parser.y" /* yacc.c:1661  */
    {
		//$$ = $<v>0;
		const_val *ori = (const_val*)(yyvsp[-4].v);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add(((const_val*)(yyvsp[-4].v))->basic_val);

			const_val *exp = (const_val*)(yyvsp[-1].v);
			init_type_check(p->type,exp->type);


		}
		else
			dump_error(result);
		const_val *con = (const_val*)(yyvsp[-1].v);
		code_single_change_type(con,p->type);
		code_dump_expr(con);
		code_store_val((yyvsp[-3].str),con);
		con->basic_val = ori->basic_val;

		(yyval.v) = (void*)con;
	}
#line 3384 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 1694 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-5].v);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-5].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
		}
		else
			dump_error(result);
	}
#line 3409 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 1715 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-4].v);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = ((const_val*)(yyvsp[-4].v))->basic_val;

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			init_type_check(p->type,get_const->type);
			add_id((yyvsp[-3].str),(void*)p);
		}
		else
			dump_error(result);
	}
#line 3434 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 1739 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3454 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 1755 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3474 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 1771 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
		const_val *output;
		if(!check_type_three(v1,v2))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConst(v1,v2);
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_PLUS);
		(yyval.v)=(void*)output;
	}
#line 3492 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 1785 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3512 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 1801 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!(v1,v2,TYPE_INT))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_INT);
		code_change_type(v1,v2,output->type);
		code_calculate(output,v1,v2,CAL_MOD);
		(yyval.v)=(void*)output;
	}
#line 3532 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 1817 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3552 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 1833 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3572 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 1849 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3592 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 1865 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3612 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 1881 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3633 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 1898 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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
		(yyval.v)=(void*)output;
	}
#line 3654 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 1915 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(v1);
		(yyval.v) = (yyvsp[-1].v);
	}
#line 3664 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 1921 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);
		const_val *output;
		check_and_set_scalar(v1);
		if(v1->type!=TYPE_INT && v1->type!=TYPE_DOUBLE && v1->type!=TYPE_FLOAT)
		{	
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneOneVal(v1,v1->type);
		code_go_minus(v1);
		(yyval.v)=(void*)v1;

	}
#line 3682 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 1935 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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

		(yyval.v)=(void*)output;
	}
#line 3710 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 1959 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
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

		(yyval.v)=(void*)output;
	}
#line 3738 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 1983 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);
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

		(yyval.v)=(void*)output;

	}
#line 3766 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 2007 "parser.y" /* yacc.c:1661  */
    {
		code_load_val((const_val*)(yyvsp[0].v));
		(yyval.v) = (yyvsp[0].v);
	}
#line 3775 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 2012 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0
		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
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

		
		(yyval.v) = (void*)q;
	}
#line 3818 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 2051 "parser.y" /* yacc.c:1661  */
    {
		// check func id exist and argu form correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);
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

		(yyval.v) = (void*)q;
	}
#line 3862 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 2094 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->name=strdup((yyvsp[-4].str));
		p->listc+=1;

		const_val *co=(const_val*)p->listv;
		co=(const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]= *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

		code_merge_expr(p->func_code,p->func_code,((const_val*)(yyvsp[-1].v)));

		(yyval.v) = (void*)p;

	}
#line 3883 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 2111 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-3].str));
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)((yyvsp[-1].v));

		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		code_merge_expr(code,code,((const_val*)(yyvsp[-1].v)));

		p->func_code = code;
		(yyval.v) = (void*)p;

	}
#line 3909 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 2133 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-2].str));
		p->listc = 0;

		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		p->func_code = code;

		(yyval.v) = (void*)p;
	}
#line 3931 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 2154 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)(yyvsp[-1].v));
		p->listv = (void*)co;

		code_merge_expr(p->func_code,p->func_code,((const_val*)(yyvsp[-1].v)));

		(yyval.v) = (void*)p;
	}
#line 3950 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 2169 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

	
		const_val *code = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");

		code->code_head = new_node;
		code->code_index = new_node;

		code_merge_expr(code,code,(const_val*)(yyvsp[-1].v));

		p->func_code = code;

		(yyval.v) = (void*)p;
	}
#line 3979 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 2197 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);


		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		(yyval.v) = (void*)exp;

	}
#line 3998 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 2212 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);

		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("getstatic java/lang/System/out Ljava/io/PrintStream;\n");

		new_node->next = con->code_head;
		con->code_head = new_node;
		
		code_print(con,con->type);

		(yyval.v) = (void*)con;
		//code_dump_expr(con);
		
	}
#line 4020 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 2230 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);

		const_val* v1= NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		code_read(v1,con->type);
		code_store_val( ((invo_val*)con->value)->name,v1 );

		(yyval.v) = (void*)v1;
	}
#line 4041 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 2250 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0

		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
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

		(yyval.v) = (void*)q;
	}
#line 4082 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 2291 "parser.y" /* yacc.c:1661  */
    {
		char outstring[2000];
		const_val *exp = (const_val*)(yyvsp[-2].v);

		
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"ifne TRUE_%d\ngoto END_%d\nTRUE_%d:\n",label,label,label);
		new_node->content = mergestring(new_node->content,outstring);
		
		exp->code_index->next = new_node;
		exp->code_index = new_node;

		const_val *v1 = (const_val*)(yyvsp[0].v);
		code_merge_expr(v1,exp,v1);

		new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = strdup("");
		sprintf(outstring,"END_%d:\n",label);
		new_node->content = mergestring(new_node->content,outstring);

		v1->code_index->next = new_node;
		v1->code_index = new_node;

		label++;



		(yyval.v) = (void*)v1;
	}
#line 4119 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 2324 "parser.y" /* yacc.c:1661  */
    {
		char outstring[2000];
		const_val *v1 = (const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
		if(v1->return_val==RETURN_YES && v2->return_val==RETURN_YES)
			v1->return_val = RETURN_YES;
		else
			v1->return_val = RETURN_NO;

		const_val *exp = (const_val*)(yyvsp[-4].v);
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
		(yyval.v) = (void*)v1;
	}
#line 4166 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 2370 "parser.y" /* yacc.c:1661  */
    {
		const_val *con =(const_val*)(yyvsp[0].v);
		if(con->type!=TYPE_BOOL)
			dump_error(ERROR_NO_BOOL);
		else
		{
			check_and_set_scalar(con);
		}
		(yyval.v) = (void*)(yyvsp[0].v);
	}
#line 4181 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 2384 "parser.y" /* yacc.c:1661  */
    {
		f_push_loop_state();
		isInLoop+=1;
	}
#line 4190 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 2389 "parser.y" /* yacc.c:1661  */
    {
		char outstring[2000];

		int loop_label = l_stack->loop_val;

		const_val *v1 = (const_val*)(yyvsp[0].v);
		const_val *exp = (const_val*)(yyvsp[-3].v);

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
		(yyval.v) = (void*)v1;
	}
#line 4236 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 2431 "parser.y" /* yacc.c:1661  */
    {
		f_push_loop_state();
		isInLoop+=1;
	}
#line 4245 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 2436 "parser.y" /* yacc.c:1661  */
    {
		char outstring[2000];

		int loop_label = l_stack->loop_val;

		const_val *v1 = (const_val*)(yyvsp[-5].v);
		const_val *exp = (const_val*)(yyvsp[-2].v);

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
		(yyval.v) = (void*)v1;
	}
#line 4293 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 2483 "parser.y" /* yacc.c:1661  */
    {
		f_push_loop_state();
		isInLoop+=1;
	}
#line 4302 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 2488 "parser.y" /* yacc.c:1661  */
    {
		char outstring[2000];
		
		int loop_label=l_stack->loop_val;

		const_val *v1 = (const_val*)(yyvsp[0].v);
		const_val *init = (const_val*)(yyvsp[-7].v);
		const_val *cond = (const_val*)(yyvsp[-5].v);
		const_val *incr = (const_val*)(yyvsp[-3].v);

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
		(yyval.v) = (void*)v1;
	}
#line 4360 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 2542 "parser.y" /* yacc.c:1661  */
    {
		f_push_loop_state();
		isInLoop+=1;
	}
#line 4369 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 2546 "parser.y" /* yacc.c:1661  */
    {

		char outstring[2000];
		
		int loop_label=l_stack->loop_val;

		const_val *v1 = (const_val*)(yyvsp[0].v);
		const_val *init = (const_val*)(yyvsp[-6].v);
		const_val *incr = (const_val*)(yyvsp[-3].v);

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
		(yyval.v) = (void*)v1;
	}
#line 4417 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 2593 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = (const_val*)(yyvsp[-3].v);
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name,exp );

		code_merge_expr(v1,v1,exp);

		(yyval.v) = (void*)con;
	}
#line 4437 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 2609 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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
#line 4469 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 2637 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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
#line 4501 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 2665 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		(yyval.v) = (void*)exp;
	}
#line 4518 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 2678 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node -> next =NULL;
		new_node->content =strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		(yyval.v) = (void*)v1;
	}
#line 4533 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 2692 "parser.y" /* yacc.c:1661  */
    {
		const_val* v1 = (const_val*)(yyvsp[-4].v);
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);
		code_merge_expr(v1,v1,exp);

		(yyval.v) = (void*)v1;
	}
#line 4552 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 2707 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-1].v);
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
#line 4584 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 2735 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-1].v);
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
#line 4616 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 2763 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name,exp );

		(yyval.v) = (void*)exp;
	}
#line 4633 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 2781 "parser.y" /* yacc.c:1661  */
    {
		const_val* v1= (const_val*)(yyvsp[-4].v);
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		code_merge_expr(v1,v1,exp);

		(yyval.v) = (void*)v1;
	}
#line 4653 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 2797 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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
#line 4685 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 2825 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		(yyval.v) = (void*)exp;

	}
#line 4703 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 2839 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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
#line 4735 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 2867 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1 = NEW_VAL(const_val);
		output_list *new_node = NEW_VAL(output_list);
		new_node -> next =NULL;
		new_node->content =strdup("");
		v1->code_head = new_node;
		v1->code_index = new_node;

		(yyval.v) = (void*)v1;
	}
#line 4750 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 2881 "parser.y" /* yacc.c:1661  */
    {
		const_val * v1 =(const_val*)(yyvsp[-4].v);
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		//code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		code_merge_expr(v1,v1,exp);
	}
#line 4768 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 2895 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-1].v);
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
#line 4800 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 2923 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

		equal_type_check(con,exp);

		code_single_change_type(exp,con->type);
		code_dump_expr(exp);
		code_store_val( ((invo_val*)con->value)->name ,exp);

		(yyval.v) = (void*)exp;
	}
#line 4817 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 2936 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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
#line 4849 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 2967 "parser.y" /* yacc.c:1661  */
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

		(yyval.v) = (void*)v1;
	}
#line 4868 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 2982 "parser.y" /* yacc.c:1661  */
    {
		const_val *exp=(const_val*)(yyvsp[-1].v);
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



		const_val *v1 = NEW_VAL(const_val);
		v1->return_val = RETURN_YES;
		output_list *new_node = NEW_VAL(output_list);
		new_node->next = NULL;
		new_node->content = f_get_s_type(exp->type);
		new_node->content = mergestring(new_node->content,"return\n");
		v1->code_head = new_node;
		v1->code_index = new_node;

		code_merge_expr(v1,exp,v1);

		(yyval.v) = (void*)v1;

	}
#line 4906 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 3016 "parser.y" /* yacc.c:1661  */
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

		(yyval.v) = (void*)v1;
	}
#line 4931 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 3037 "parser.y" /* yacc.c:1661  */
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

		(yyval.v) = (void*)v1;
	}
#line 4956 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 4960 "parser.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3061 "parser.y" /* yacc.c:1906  */


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
	output_list *new_node = NEW_VAL(output_list);
	new_node->content = strdup(".class public demo\n");
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
	new_node->content = strdup("getstatic demo/_sc Ljava/util/Scanner;\n");
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
			new_node->content = strdup("getstatic demo/");
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
		new_node->content = strdup("putstatic demo/");
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

	sprintf(outstring,"invokestatic demo/_%s(%s)%s\n",list->name,f_argulist(list),f_get_type( ((id_val*)list->val)->type ));
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

	code_dump_main();
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
	new_node->content = mergestring(new_node->content ,"putstatic demo/_sc Ljava/util/Scanner;\n");

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
	new_node->content = strdup("putstatic demo/");
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

	code_final();
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

	 
	 fclose(fp);
	 fclose(fg);
	exit(0);
}
