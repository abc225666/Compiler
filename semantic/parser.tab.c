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

typedef struct S_output_list
{
	char *content;
	struct S_output_list *next;
} output_list;

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

FILE *fg = NULL;
output_list *output_head = NULL;
output_list *output_index = NULL;
output_list *output_func_head = NULL;
output_list *output_func_index = NULL;
output_list *output_main_head = NULL;
output_list *output_main_index = NULL;
output_list *output_cur_head = NULL;
output_list *output_cur_index = NULL;
int output_stack = 0;
int output_oper = 0;

void gene_init_code();
void code_gvar(char* name, int type);
void code_final();
void code_cur_func_start(char* name, id_val* id);
void code_cur_func_end();
void f_output_cur_init();
void f_output_stack_add(int type);
char* f_get_type(int type);



int yyerror( char *msg );
int main( int argc, char **argv );
int yylex();


#line 291 "parser.tab.c" /* yacc.c:339  */

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
#line 226 "parser.y" /* yacc.c:355  */

	char* str;
	void* v;
	int c_type;
	int return_type;

#line 367 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 384 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   601

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

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
       0,   280,   280,   281,   282,   283,   287,   288,   289,   290,
     291,   292,   296,   297,   298,   299,   303,   307,   328,   348,
     368,   389,   408,   431,   452,   474,   494,   517,   538,   562,
     583,   603,   623,   644,   660,   681,   708,   712,   680,   725,
     751,   755,   724,   768,   787,   791,   767,   804,   829,   803,
     840,   866,   839,   876,   895,   875,   909,   908,   920,   919,
     932,   936,   940,   944,   948,   952,   956,   966,   970,   977,
     981,   988,   992,  1001,  1000,  1025,  1024,  1050,  1049,  1069,
    1068,  1093,  1092,  1119,  1118,  1140,  1152,  1168,  1190,  1208,
    1217,  1226,  1236,  1245,  1255,  1264,  1277,  1283,  1289,  1295,
    1304,  1316,  1328,  1339,  1353,  1374,  1396,  1416,  1439,  1457,
    1478,  1492,  1506,  1520,  1534,  1548,  1562,  1576,  1590,  1604,
    1619,  1634,  1640,  1653,  1667,  1681,  1694,  1698,  1733,  1767,
    1783,  1794,  1805,  1818,  1833,  1862,  1868,  1876,  1917,  1921,
    1931,  1944,  1944,  1949,  1949,  1949,  1956,  1956,  1961,  1961,
    1969,  1984,  2012,  2040,  2055,  2059,  2074,  2102,  2130,  2150,
    2165,  2193,  2208,  2236,  2240,  2255,  2283,  2298,  2329,  2336,
    2355,  2362
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
  "var_all_def", "gvar_def", "gvar_list", "gconst_list", "var_def",
  "func_def", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "compound",
  "$@16", "$@17", "statement", "compound_in_argu_func", "compound_list",
  "func_decl", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "argu_list",
  "argu", "basic", "void_reduce", "liter_const", "value_type", "int_value",
  "float_value", "bool_value", "string_value", "var_list", "const_list",
  "expr", "func_invo", "expr_list", "simple_stat", "var_ref", "condition",
  "bool_expr", "while_stat", "$@24", "$@25", "$@26", "for_stat", "$@27",
  "$@28", "init_expr", "init_expr_list", "incr_expr", "incr_expr_list",
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

#define YYTABLE_NINF -168

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,  -188,  -188,     7,    20,    65,  -188,    65,  -188,    27,
      55,    72,  -188,  -188,    65,  -188,    65,  -188,  -188,  -188,
     124,    73,    76,    61,   106,    65,  -188,  -188,  -188,  -188,
     147,  -188,    -2,    84,    17,    95,    87,    89,  -188,  -188,
    -188,  -188,   147,   147,   147,  -188,  -188,  -188,  -188,  -188,
     347,  -188,   102,     7,   -10,   128,  -188,   147,  -188,   114,
       7,    25,    10,    56,  -188,  -188,  -188,  -188,    95,    74,
    -188,   327,   567,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,  -188,  -188,   110,   122,
      57,  -188,   139,  -188,   365,   141,   145,    78,   149,  -188,
    -188,  -188,  -188,    93,  -188,   287,   147,  -188,   247,   567,
      -8,    -8,    -8,    -8,    -8,    -8,   133,   133,  -188,  -188,
    -188,  -188,  -188,  -188,   152,   150,   166,  -188,  -188,  -188,
    -188,   169,   165,   171,  -188,  -188,  -188,  -188,   307,   283,
     167,   173,  -188,  -188,   283,   174,   178,  -188,  -188,  -188,
    -188,    97,   199,   147,   182,  -188,   183,   184,   188,   189,
     101,     7,   185,  -188,  -188,  -188,  -188,  -188,   283,   221,
     491,  -188,   191,  -188,  -188,  -188,  -188,  -188,  -188,   283,
     192,  -188,  -188,   283,  -188,   193,   507,   147,   190,   147,
     225,  -188,  -188,  -188,   523,   230,   283,   197,   200,  -188,
    -188,   158,   236,  -188,   147,   283,  -188,  -188,   283,   201,
    -188,  -188,   555,   204,  -188,   205,    89,   208,   227,   229,
     225,  -188,   246,   261,   243,  -188,  -188,  -188,   147,  -188,
     163,   539,  -188,   254,   262,  -188,   190,   252,  -188,  -188,
     147,   140,   267,   269,    95,   270,  -188,   383,  -188,   147,
    -188,  -188,   281,  -188,  -188,   321,   303,   190,   419,   225,
     308,  -188,   147,   103,    95,  -188,  -188,   401,  -188,   190,
     147,  -188,  -188,   338,   309,   314,   225,   225,   437,  -188,
    -188,   134,  -188,  -188,  -188,   322,   147,  -188,   325,   328,
     324,  -188,  -188,  -188,   330,   455,   190,  -188,   147,  -188,
    -188,  -188,  -188,   473,   190,   369,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    89,    88,     0,     0,     0,    14,     5,    15,     0,
       0,     0,     1,    12,     3,    13,     4,     9,    10,    11,
       0,     0,     0,     0,     0,     2,     6,     7,     8,    19,
       0,    25,     0,     0,     0,     0,     0,   127,   100,   101,
     102,   103,     0,     0,     0,   126,    96,    97,    98,    99,
       0,   128,    43,     0,     0,     0,    17,     0,    23,    53,
       0,     0,     0,     0,    90,    92,    94,    95,     0,     0,
     122,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    26,     0,     0,
       0,    86,    39,    87,     0,     0,     0,     0,    50,    91,
      93,    22,    28,     0,   131,     0,     0,   121,   124,   123,
     116,   119,   118,   120,   115,   117,   112,   113,   110,   111,
     114,    44,    78,    85,    35,     0,     0,    18,    24,    54,
      84,    47,     0,     0,    21,    27,   133,   130,     0,    68,
       0,     0,    40,    76,    68,     0,     0,    51,    82,   132,
     129,   127,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,    56,    72,    16,    60,    71,    45,    67,     0,
       0,    61,     0,    62,    63,    64,    65,    36,    74,    68,
       0,    48,    80,    68,   137,     0,     0,     0,     0,     0,
     154,   171,   170,   168,     0,     0,     0,     0,     0,    69,
      70,     0,     0,    66,     0,    68,    41,    55,    68,     0,
     136,   135,   140,     0,   144,     0,   137,   152,     0,     0,
       0,   169,     0,     0,     0,    59,    46,    31,     0,   106,
       0,     0,    37,     0,     0,    52,     0,     0,   141,   157,
       0,     0,   151,     0,     0,     0,    57,     0,    29,     0,
     104,   134,     0,    42,    49,   138,     0,     0,   153,   163,
       0,   156,     0,     0,     0,    32,   107,     0,    38,     0,
       0,   142,   158,   162,     0,     0,     0,   163,   150,    34,
     109,     0,    30,   105,   139,     0,     0,   148,   160,     0,
       0,   155,    33,   108,     0,   161,     0,   165,     0,   146,
     145,   166,   149,     0,     0,   159,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,   368,  -188,  -163,   164,  -188,  -188,  -188,   168,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -169,  -188,  -188,  -153,  -109,
     196,   187,  -188,  -188,  -188,  -188,  -188,  -188,   350,   -24,
      59,  -188,   -67,  -188,   -31,   -28,   -27,   -26,  -188,  -188,
     -30,  -187,  -188,  -188,  -134,  -188,  -183,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   123,  -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    16,     5,   163,    17,    21,    24,   164,    18,
     140,   205,   252,   125,   179,   233,    88,   139,   198,   145,
     208,   132,   183,    95,   144,   165,   196,   197,   166,   167,
     168,    19,   141,   126,    89,   146,   133,    96,    53,    54,
     169,    10,    63,    45,    46,    47,    48,    49,   202,   223,
     170,    51,   106,   171,   172,   173,   213,   174,   257,   188,
     237,   175,   304,   296,   219,   220,   275,   276,   176
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   103,     2,   217,    64,   199,   215,    65,    66,    67,
      61,     2,    70,    71,    72,   200,    38,    39,   185,   214,
      12,     2,    81,    82,    83,    84,    85,    94,    91,    90,
      92,    99,    20,   242,   100,   180,    97,    64,    52,   105,
      65,    66,    67,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   218,    59,   260,     9,
      22,   199,    11,    91,     9,    98,     9,   255,     1,     2,
     206,   200,   273,     9,   209,     9,   138,    23,    33,    37,
      38,    39,    40,    41,     9,     3,   243,   285,   271,   288,
     273,    55,   101,    55,   102,   123,   232,   124,    35,   234,
     284,    38,    39,    40,    41,    42,    37,    38,    39,    40,
      41,    36,    55,    43,   104,    34,   123,    44,   131,    55,
      56,    57,    58,   186,    68,   274,    62,   302,    69,   134,
     194,   135,    42,    93,  -137,   306,    69,   193,   -77,   279,
      43,   280,   289,   274,    44,    37,    38,    39,    40,    41,
     -83,   121,    37,    38,    39,    40,    41,   212,   122,   212,
      29,    30,    31,    32,     6,    83,    84,    85,     7,    13,
     292,    42,   293,    14,   231,   -75,   259,   263,    42,    43,
      26,   130,   129,    44,    27,   -81,    43,     8,   -73,    26,
      44,   142,    15,    27,   227,   228,   229,   281,   247,   248,
     249,   250,   143,    28,   184,   -79,   147,   148,   177,   178,
     258,   212,    28,    64,   182,   181,    65,    66,    67,   267,
     195,   187,   189,   190,   191,   192,   201,   -58,   204,   210,
     216,   162,   278,    64,   207,   222,    65,    66,    67,   225,
     212,   230,   226,   235,   236,   238,   239,     2,   151,    38,
      39,    40,    41,   152,   153,   154,   295,   155,   156,   157,
     158,   159,   160,   161,   240,   241,   245,   256,   303,    74,
      75,    76,    77,    78,    42,    79,    80,    81,    82,    83,
      84,    85,    43,   244,   162,   246,    44,     2,   151,    38,
      39,    40,    41,   152,   153,   154,   253,   155,   156,   157,
     158,   159,   160,   161,   254,   261,   262,   264,    73,    74,
      75,    76,    77,    78,    42,    79,    80,    81,    82,    83,
      84,    85,    43,   268,   162,   136,    44,   137,    73,    74,
      75,    76,    77,    78,   269,    79,    80,    81,    82,    83,
      84,    85,   270,  -167,   277,   149,   286,   150,    73,    74,
      75,    76,    77,    78,   287,    79,    80,    81,    82,    83,
      84,    85,   294,   297,   299,   298,   300,   107,    73,    74,
      75,    76,    77,    78,  -164,    79,    80,    81,    82,    83,
      84,    85,    25,    86,    60,    87,    73,    74,    75,    76,
      77,    78,   224,    79,    80,    81,    82,    83,    84,    85,
     290,   127,     0,   128,    73,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,   265,
       0,   266,    73,    74,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,   282,     0,   283,
      73,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,   272,    73,    74,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,   291,    73,    74,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,    84,    85,
       0,     0,     0,   301,    73,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,   305,    73,    74,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,   203,    73,    74,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
      84,    85,     0,   211,    73,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,   221,
      73,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,     0,   251,    73,    74,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,    84,    85,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
      84,    85
};

static const yytype_int16 yycheck[] =
{
      30,    68,     4,   190,    35,   168,   189,    35,    35,    35,
      34,     4,    42,    43,    44,   168,     6,     7,   152,   188,
       0,     4,    30,    31,    32,    33,    34,    57,    38,    53,
      40,    62,     5,   220,    62,   144,    60,    68,    40,    69,
      68,    68,    68,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   190,    40,   241,     0,
       5,   224,     3,    38,     5,    40,     7,   236,     3,     4,
     179,   224,   259,    14,   183,    16,   106,     5,     5,     5,
       6,     7,     8,     9,    25,    20,   220,   270,   257,   276,
     277,    32,    36,    34,    38,    38,   205,    40,    37,   208,
     269,     6,     7,     8,     9,    31,     5,     6,     7,     8,
       9,     5,    53,    39,    40,    39,    38,    43,    40,    60,
      36,    37,    38,   153,    37,   259,    31,   296,    39,    36,
     160,    38,    31,     5,    37,   304,    39,    36,    36,    36,
      39,    38,   276,   277,    43,     5,     6,     7,     8,     9,
      36,    41,     5,     6,     7,     8,     9,   187,    36,   189,
      36,    37,    38,    39,     0,    32,    33,    34,     0,     5,
      36,    31,    38,     5,   204,    36,    36,   244,    31,    39,
      16,    36,    41,    43,    16,    36,    39,     0,    36,    25,
      43,    41,     5,    25,    36,    37,    38,   264,   228,    36,
      37,    38,    36,    16,     5,    36,    41,    36,    41,    36,
     240,   241,    25,   244,    36,    41,   244,   244,   244,   249,
     161,    39,    39,    39,    36,    36,     5,    42,    37,    36,
       5,    41,   262,   264,    42,     5,   264,   264,   264,    42,
     270,     5,    42,    42,    40,    40,    38,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   286,    14,    15,    16,
      17,    18,    19,    20,    37,    36,     5,    15,   298,    22,
      23,    24,    25,    26,    31,    28,    29,    30,    31,    32,
      33,    34,    39,    37,    41,    42,    43,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    42,    14,    15,    16,
      17,    18,    19,    20,    42,    38,    37,    37,    21,    22,
      23,    24,    25,    26,    31,    28,    29,    30,    31,    32,
      33,    34,    39,    42,    41,    38,    43,    40,    21,    22,
      23,    24,    25,    26,    13,    28,    29,    30,    31,    32,
      33,    34,    39,     5,    36,    38,    37,    40,    21,    22,
      23,    24,    25,    26,    40,    28,    29,    30,    31,    32,
      33,    34,    40,    38,    40,    37,    36,    40,    21,    22,
      23,    24,    25,    26,     5,    28,    29,    30,    31,    32,
      33,    34,    14,    36,    34,    38,    21,    22,    23,    24,
      25,    26,   196,    28,    29,    30,    31,    32,    33,    34,
     277,    36,    -1,    38,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    38,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    38,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    20,    45,    47,    49,    53,    75,    84,
      85,    84,     0,    49,    53,    75,    46,    49,    53,    75,
       5,    50,     5,     5,    51,    46,    49,    53,    75,    36,
      37,    38,    39,     5,    39,    37,     5,     5,     6,     7,
       8,     9,    31,    39,    43,    87,    88,    89,    90,    91,
      94,    95,    40,    82,    83,    84,    36,    37,    38,    40,
      82,    83,    31,    86,    88,    89,    90,    91,    37,    39,
      94,    94,    94,    21,    22,    23,    24,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    36,    38,    60,    78,
      83,    38,    40,     5,    94,    67,    81,    83,    40,    88,
      89,    36,    38,    86,    40,    94,    96,    40,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    41,    36,    38,    40,    57,    77,    36,    38,    41,
      36,    40,    65,    80,    36,    38,    38,    40,    94,    61,
      54,    76,    41,    36,    68,    63,    79,    41,    36,    38,
      40,     5,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    41,    48,    52,    69,    72,    73,    74,    84,
      94,    97,    98,    99,   101,   105,   112,    41,    36,    58,
      73,    41,    36,    66,     5,    98,    94,    39,   103,    39,
      39,    36,    36,    36,    94,    84,    70,    71,    62,    48,
      72,     5,    92,    36,    37,    55,    73,    42,    64,    73,
      36,    36,    94,   100,    69,   100,     5,    95,    98,   108,
     109,    36,     5,    93,    74,    42,    42,    36,    37,    38,
       5,    94,    73,    59,    73,    42,    40,   104,    40,    38,
      37,    36,    95,    98,    37,     5,    42,    94,    36,    37,
      38,    36,    56,    42,    42,    69,    15,   102,    94,    36,
     100,    38,    37,    86,    37,    36,    38,    94,    42,    13,
      39,    69,    38,    95,    98,   110,   111,    36,    94,    36,
      38,    86,    36,    38,    69,   100,    37,    40,    95,    98,
     110,    38,    36,    38,    40,    94,   107,    38,    37,    40,
      36,    38,    69,    94,   106,    38,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    48,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    54,    55,    56,    53,    57,
      58,    59,    53,    60,    61,    62,    53,    63,    64,    53,
      65,    66,    53,    67,    68,    53,    70,    69,    71,    69,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    74,    74,    76,    75,    77,    75,    78,    75,    79,
      75,    80,    75,    81,    75,    82,    82,    83,    84,    85,
      86,    86,    86,    86,    86,    86,    87,    87,    87,    87,
      88,    89,    90,    91,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    97,    97,    97,    98,    99,    99,
     100,   102,   101,   103,   104,   101,   106,   105,   107,   105,
     108,   108,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     1,     4,     6,     3,
       5,     7,     6,     3,     5,     2,     4,     5,     4,     4,
       6,     3,     5,     7,     6,     0,     0,     0,    12,     0,
       0,     0,    11,     0,     0,     0,    10,     0,     0,    11,
       0,     0,    10,     0,     0,     9,     0,     4,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     2,
       2,     1,     1,     0,     8,     0,     7,     0,     6,     0,
       8,     0,     7,     0,     6,     3,     2,     2,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     2,     4,     5,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     5,
       4,     3,     3,     2,     4,     3,     3,     1,     5,     7,
       1,     0,     6,     0,     0,     9,     0,    10,     0,     9,
       4,     2,     1,     3,     0,     5,     3,     2,     4,     5,
       2,     3,     1,     0,     5,     3,     4,     1,     2,     3,
       2,     2
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
        case 17:
#line 308 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),(yyvsp[-3].c_type));
		}
		else
			dump_error(result);
	}
#line 1763 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 329 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 1787 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 349 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-2].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),(yyvsp[-2].c_type));
		}
		else
			dump_error(result);
	}
#line 1811 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 369 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-4].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 1835 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 390 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-5].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 1858 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 409 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-4].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 1882 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 432 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-3].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),(yyvsp[-3].c_type));
		}
		else
			dump_error(result);
	}
#line 1907 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 453 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-5].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 1933 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 475 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-2].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-2].c_type);
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			code_gvar((yyvsp[-1].str),(yyvsp[-2].c_type));
		}
		else
			dump_error(result);
	}
#line 1957 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 495 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-4].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-4].c_type);
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 1981 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 518 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-5].c_type);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-5].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 2006 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 539 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-4].c_type);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-4].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			code_gvar((yyvsp[-3].str),(yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 2031 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 563 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add((yyvsp[-3].c_type));
		}
		else
			dump_error(result);
	}
#line 2056 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 584 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add((yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 2080 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 604 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-2].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add((yyvsp[-2].c_type));
		}
		else
			dump_error(result);
	}
#line 2104 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 624 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-4].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add((yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 2128 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 645 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-5].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2148 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 661 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-4].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2169 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 681 "parser.y" /* yacc.c:1661  */
    {
		

		func_type = (yyvsp[-5].c_type);
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DEF;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-4].str),p);
	}
#line 2200 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 708 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 2208 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 712 "parser.y" /* yacc.c:1661  */
    {
		int hasreturn=(yyvsp[0].return_type);
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2218 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 718 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2229 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 725 "parser.y" /* yacc.c:1661  */
    {
		func_type = (yyvsp[-4].c_type);
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DEF;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-3].str),p);
	}
#line 2259 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 751 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 2267 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 755 "parser.y" /* yacc.c:1661  */
    {
		int hasreturn=(yyvsp[0].return_type);
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2277 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 761 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2288 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 768 "parser.y" /* yacc.c:1661  */
    {
		func_type = (yyvsp[-3].c_type);
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);
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
#line 2311 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 787 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 2319 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 791 "parser.y" /* yacc.c:1661  */
    {
		int hasreturn=(yyvsp[0].return_type);
		if(hasreturn==RETURN_NO)
			dump_error(ERROR_NO_RETURN);
	}
#line 2329 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 797 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2340 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 804 "parser.y" /* yacc.c:1661  */
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
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-4].str),p);
	}
#line 2369 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 829 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 2377 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 833 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2388 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 840 "parser.y" /* yacc.c:1661  */
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
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= def_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		f_output_cur_init();
		code_cur_func_start((yyvsp[-3].str),p);
	}
#line 2418 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 866 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 2426 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 870 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2436 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 876 "parser.y" /* yacc.c:1661  */
    {
		func_type = TYPE_VOID;
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);
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
#line 2459 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 895 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 2467 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 899 "parser.y" /* yacc.c:1661  */
    {
		code_cur_func_end();
		output_stack = 0;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2478 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 909 "parser.y" /* yacc.c:1661  */
    { 
		add_newtable();
	}
#line 2486 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 913 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();

		(yyval.return_type) = (yyvsp[-1].return_type);
	}
#line 2497 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 920 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 2505 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 924 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
		if(Opt_symbol) dump_cur_table();
		else pop_cur_table();
	}
#line 2515 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 933 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 2523 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 937 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
	}
#line 2531 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 941 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 2539 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 945 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
	}
#line 2547 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 949 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
	}
#line 2555 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 953 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 2563 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 957 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar((yyvsp[-1].v));

		(yyval.return_type) = RETURN_NO;
	}
#line 2574 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 967 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 2582 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 971 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
	}
#line 2590 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 978 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[-1].return_type);
	}
#line 2598 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 982 "parser.y" /* yacc.c:1661  */
    {
		if((yyvsp[-1].return_type)==RETURN_YES || (yyvsp[0].return_type)==RETURN_YES)
			(yyval.return_type) = RETURN_YES;
		else
			(yyval.return_type) = RETURN_NO;
	}
#line 2609 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 989 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 2617 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 993 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = RETURN_NO;
	}
#line 2625 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 1001 "parser.y" /* yacc.c:1661  */
    {
		
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DECL;
		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		output_stack = 0;
	}
#line 2652 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 1025 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		output_stack = 0;
	}
#line 2680 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 1050 "parser.y" /* yacc.c:1661  */
    {
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		output_stack = 0;
	}
#line 2702 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 1069 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);
		p_f->type=FUNC_DECL;

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-4].str),(void*)p);
		if(result)
			add_id((yyvsp[-4].str),(void*)p);

		output_stack = 0;
	}
#line 2729 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 1093 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->type=FUNC_DECL;
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= decl_build((yyvsp[-3].str),(void*)p);
		if(result)
			add_id((yyvsp[-3].str),(void*)p);

		output_stack = 0;
		
	}
#line 2758 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 1119 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);

		func_val *t =NEW_VAL(func_val);
		t->type=FUNC_DECL;
		t->argc=0;
		p->list =(void*)t;

		int result= decl_build((yyvsp[-2].str),(void*)p);
		if(result)
			add_id((yyvsp[-2].str),(void*)p);

		output_stack = 0;
	}
#line 2779 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 1141 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = (func_val*)(yyvsp[-2].v);

		argu_val *co =(argu_val*)(yyvsp[-1].v);

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		(yyval.v) = (void*)p;
	}
#line 2795 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 1153 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)(yyvsp[-1].v);

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		(yyval.v) = (void*)p;
	}
#line 2812 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 1169 "parser.y" /* yacc.c:1661  */
    {
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup((yyvsp[0].str));
		
		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=(yyvsp[-1].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;

		p->val->list=(void*)t;

		(yyval.v) = (void*)p;

		f_output_stack_add((yyvsp[-1].c_type));
	}
#line 2834 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 1191 "parser.y" /* yacc.c:1661  */
    {
		if(!strcmp((yyvsp[0].str),"bool"))
			(yyval.c_type) = TYPE_BOOL;
		else if(!strcmp((yyvsp[0].str),"int"))
			(yyval.c_type) = TYPE_INT;
		else if(!strcmp((yyvsp[0].str),"float"))
			(yyval.c_type) = TYPE_FLOAT;
		else if(!strcmp((yyvsp[0].str),"double"))
			(yyval.c_type) = TYPE_DOUBLE;
		else if(!strcmp((yyvsp[0].str),"string"))
			(yyval.c_type) = TYPE_STRING;
		else if(!strcmp((yyvsp[0].str),"boolean"))
			(yyval.c_type) = TYPE_BOOL;
	}
#line 2853 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 1209 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = TYPE_VOID;
	}
#line 2861 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 1218 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2874 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 1227 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2888 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 1237 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2901 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 1246 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(double*)p->list= -*((double*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2915 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 1256 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2928 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 1265 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2941 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 1278 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2951 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 1284 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2961 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 1290 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2971 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 1296 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2981 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 1305 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_INT;
		(yyval.v) = (void*)p;
	}
#line 2994 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 1317 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		float *val = NEW_VAL(float);
		*val = (float)atof((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_FLOAT;
		(yyval.v) = (void*)p;
	}
#line 3007 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 1329 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		(yyval.v) = (void*)p;
	}
#line 3019 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 1340 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		(yyval.v) = (void*)p;
	}
#line 3031 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 1354 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-3].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add((yyvsp[-3].c_type));
		}
		else
			dump_error(result);
	}
#line 3056 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 1375 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-5].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;


		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add((yyvsp[-5].c_type));
		}
		else
			dump_error(result);
	}
#line 3082 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 1397 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-2].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-2].c_type);
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-1].str),(void*)p);
			f_output_stack_add((yyvsp[-2].c_type));
		}
		else
			dump_error(result);
	}
#line 3106 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 1417 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-4].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-4].c_type);
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
		{
			add_id((yyvsp[-3].str),(void*)p);
			f_output_stack_add((yyvsp[-4].c_type));
		}
		else
			dump_error(result);
	}
#line 3130 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 1440 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-5].c_type);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-5].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 3152 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 1458 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-4].c_type);

		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_CONSTANT;
		p->type = (yyvsp[-4].c_type);

		id_val *get_const=(id_val*)(yyvsp[-1].v);
		p->list = get_const->list;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 3174 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 1479 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3192 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 1493 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3210 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 1507 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3228 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 1521 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3246 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 1535 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);
		const_val *output;
		check_and_set_scalar(v1);
		check_and_set_scalar(v2);
		if(!check_type_one(v1,v2,TYPE_INT))
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneValConstOne(v1,v2,TYPE_INT);
		(yyval.v)=(void*)output;
	}
#line 3264 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 1549 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3282 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 1563 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3300 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 1577 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3318 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 1591 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3336 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 1605 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3355 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 1620 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3374 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 1635 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(v1);
		(yyval.v) = (yyvsp[-1].v);
	}
#line 3384 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 1641 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);
		const_val *output;
		check_and_set_scalar(v1);
		if(v1->type!=TYPE_INT && v1->type!=TYPE_DOUBLE && v1->type!=TYPE_FLOAT)
		{	
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneOneVal(v1,v1->type);
		(yyval.v)=(void*)v1;

	}
#line 3401 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 1654 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3419 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 1668 "parser.y" /* yacc.c:1661  */
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
		(yyval.v)=(void*)output;
	}
#line 3437 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 1682 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);
		const_val *output;
		check_and_set_scalar(v1);
		if(v1->type!=TYPE_BOOL)
		{	
			dump_error(ERROR_TYPE_ERROR);
		}
		output=geneOneVal(v1,TYPE_BOOL);
		(yyval.v)=(void*)v1;

	}
#line 3454 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 1695 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 3462 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 1699 "parser.y" /* yacc.c:1661  */
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
		}

		(yyval.v) = (void*)q;
	}
#line 3501 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 1734 "parser.y" /* yacc.c:1661  */
    {
		// check func id exist and argu form correct;
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

		(yyval.v) = (void*)q;
	}
#line 3536 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 1768 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->name=strdup((yyvsp[-4].str));
		p->listc+=1;

		const_val *co=(const_val*)p->listv;
		co=(const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]= *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;
		

		(yyval.v) = (void*)p;

	}
#line 3556 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 1784 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-3].str));
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)((yyvsp[-1].v));

		(yyval.v) = (void*)p;

	}
#line 3571 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 1795 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-2].str));
		p->listc = 0;

		(yyval.v) = (void*)p;
	}
#line 3583 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 1806 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)(yyvsp[-1].v));
		p->listv = (void*)co;

		(yyval.v) = (void*)p;
	}
#line 3600 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 1819 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

		(yyval.v) = (void*)p;
	}
#line 3616 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 1834 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 3649 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 1863 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
		
	}
#line 3659 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 1869 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
	}
#line 3668 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 1877 "parser.y" /* yacc.c:1661  */
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
#line 3709 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 1918 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 3717 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 1922 "parser.y" /* yacc.c:1661  */
    {
		if((yyvsp[-2].return_type)==RETURN_YES && (yyvsp[0].return_type)==RETURN_YES)
			(yyval.return_type) = RETURN_YES;
		else
			(yyval.return_type) = RETURN_NO;
	}
#line 3728 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 1932 "parser.y" /* yacc.c:1661  */
    {
		const_val *con =(const_val*)(yyvsp[0].v);
		if(con->type!=TYPE_BOOL)
			dump_error(ERROR_NO_BOOL);
		else
		{
			check_and_set_scalar(con);
		}
	}
#line 3742 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 1944 "parser.y" /* yacc.c:1661  */
    { isInLoop+=1;}
#line 3748 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 1945 "parser.y" /* yacc.c:1661  */
    {
		isInLoop-=1;
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 3757 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 1949 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3763 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 1949 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3769 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 1950 "parser.y" /* yacc.c:1661  */
    {
		(yyval.return_type) = (yyvsp[-6].return_type);
	}
#line 3777 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 1956 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3783 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 1957 "parser.y" /* yacc.c:1661  */
    {
		isInLoop-=1;
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 3792 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 1961 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3798 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 1962 "parser.y" /* yacc.c:1661  */
    {
		isInLoop-=1;
		(yyval.return_type) = (yyvsp[0].return_type);
	}
#line 3807 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 1970 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

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
#line 3826 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 1985 "parser.y" /* yacc.c:1661  */
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
#line 3858 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 2013 "parser.y" /* yacc.c:1661  */
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
#line 3890 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 2041 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

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
#line 3909 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 2060 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 3928 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 2075 "parser.y" /* yacc.c:1661  */
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
#line 3960 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 2103 "parser.y" /* yacc.c:1661  */
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
#line 3992 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 2131 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 4011 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 2151 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 4030 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 2166 "parser.y" /* yacc.c:1661  */
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
#line 4062 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 2194 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-2].v);
		const_val* exp=(const_val*)(yyvsp[0].v);

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
#line 4081 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 2209 "parser.y" /* yacc.c:1661  */
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
#line 4113 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 2241 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 4132 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 2256 "parser.y" /* yacc.c:1661  */
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
#line 4164 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 2284 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-3].v);
		const_val* exp=(const_val*)(yyvsp[-1].v);

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
#line 4183 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 2299 "parser.y" /* yacc.c:1661  */
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
#line 4215 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 2330 "parser.y" /* yacc.c:1661  */
    {
		if(func_type != TYPE_VOID)
			dump_error(ERROR_RETURN_VOID_ERROR);

		(yyval.return_type) = RETURN_YES;
	}
#line 4226 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 2337 "parser.y" /* yacc.c:1661  */
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

		(yyval.return_type) = RETURN_YES;

	}
#line 4249 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 2356 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		(yyval.return_type) = RETURN_NO;
	}
#line 4260 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 171:
#line 2363 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);

		(yyval.return_type) = RETURN_NO;
	}
#line 4271 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 4275 "parser.tab.c" /* yacc.c:1661  */
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
#line 2373 "parser.y" /* yacc.c:1906  */


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

}

void code_cur_func_end()
{
	char* num = (char*)malloc(sizeof(char)*200);
	output_list *new_node = NEW_VAL(output_list);
	new_node->next = NULL;

	new_node->content = strdup(".limit stack ");
	sprintf(num,"%d",output_oper);
	new_node->content = mergestring(new_node->content,num);
	new_node->content = mergestring(new_node->content,"\n");

	output_func_index->next = new_node;
	output_func_index = new_node;

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;

	new_node->content = strdup(".limit locals ");
	sprintf(num,"%d",output_stack);
	new_node->content = mergestring(new_node->content,num);
	new_node->content = mergestring(new_node->content,"\n");

	output_func_index->next = new_node;
	output_func_index = new_node;

	//.....

	new_node = NEW_VAL(output_list);
	new_node->next = NULL;
	new_node->content = strdup(".end method\n");

	output_func_index->next = new_node;
	output_func_index = new_node;
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
	fclose(fg);
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
	 fclose(fg);
	exit(0);
}
