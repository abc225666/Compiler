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


#line 256 "parser.tab.c" /* yacc.c:339  */

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
#line 191 "parser.y" /* yacc.c:355  */

	char* str;
	void* v;
	int c_type;

#line 331 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 348 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  323

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
       2,     2,     2,    45,     2,     2,     2,    34,     2,     2,
      36,    37,    32,    30,    41,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      28,    44,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
       0,   242,   242,   243,   244,   245,   249,   250,   251,   252,
     253,   254,   258,   259,   260,   261,   265,   270,   292,   269,
     300,   323,   299,   331,   347,   330,   355,   377,   354,   385,
     408,   384,   416,   432,   415,   443,   442,   454,   453,   464,
     465,   469,   470,   471,   472,   478,   477,   500,   499,   523,
     522,   540,   539,   563,   562,   587,   586,   606,   618,   634,
     650,   667,   678,   690,   708,   717,   726,   736,   745,   755,
     764,   777,   783,   789,   795,   804,   816,   828,   839,   853,
     871,   890,   907,   924,   971,   986,  1029,  1047,  1065,  1086,
    1104,  1121,  1138,  1155,  1197,  1211,  1253,  1267,  1283,  1303,
    1314,  1327,  1342,  1354,  1364,  1380,  1395,  1409,  1423,  1437,
    1451,  1465,  1479,  1493,  1507,  1521,  1536,  1551,  1557,  1570,
    1584,  1598,  1611,  1615,  1650,  1681,  1710,  1720,  1731,  1745,
    1761,  1772,  1783,  1796,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1827,  1856,  1862,  1870,  1907,  1936,  1937,  1941,  1954,
    1954,  1955,  1955,  1955,  1959,  1959,  1960,  1960,  1964,  1979,
    2007,  2035,  2050,  2054,  2069,  2097,  2125,  2145,  2160,  2188,
    2203,  2231,  2235,  2250,  2278,  2293,  2324,  2329,  2346,  2351
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
  "'*'", "'/'", "'%'", "UMINUS", "'('", "')'", "'{'", "'}'", "';'", "','",
  "'['", "']'", "'='", "'!'", "$accept", "program", "prog_content",
  "gvar_all_def", "var_all_def", "func_def", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "compound",
  "$@13", "$@14", "compound_in_argu_func", "compound_list", "func_decl",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "argu_list", "argu",
  "array_argu_step", "basic", "void_reduce", "liter_const", "value_type",
  "int_value", "float_value", "bool_value", "string_value", "var_list",
  "const_list", "var_def", "arr_step", "arr_init", "arr_argu_list", "expr",
  "arr_ref", "arr_ref_step", "func_invo", "expr_list", "statement",
  "simple_stat", "var_ref", "condition", "bool_expr", "while_stat", "$@21",
  "$@22", "$@23", "for_stat", "$@24", "$@25", "init_expr",
  "init_expr_list", "incr_expr", "incr_expr_list", "jump_stat", YY_NULLPTR
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
      43,    45,    42,    47,    37,   283,    40,    41,   123,   125,
      59,    44,    91,    93,    61,    33
};
# endif

#define YYPACT_NINF -207

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define YYTABLE_NINF -176

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,  -207,  -207,    -2,     4,    10,    10,  -207,    19,    21,
    -207,    24,  -207,    10,  -207,  -207,    10,  -207,  -207,  -207,
      67,    31,    40,    41,    83,    10,  -207,  -207,  -207,    -3,
    -207,  -207,    92,   277,   251,   257,    36,   220,    58,    66,
      -2,   -16,   108,    76,    13,  -207,  -207,  -207,  -207,   277,
     277,   277,  -207,  -207,  -207,  -207,  -207,   327,  -207,  -207,
    -207,  -207,   116,    97,  -207,  -207,   277,   265,   113,    -2,
      46,    32,    84,  -207,  -207,  -207,  -207,   220,   119,   125,
      54,   128,  -207,   117,  -207,   124,   277,   120,  -207,   589,
     631,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,  -207,  -207,   133,   136,    98,   348,
    -207,  -207,    97,   148,   140,    59,   162,  -207,  -207,  -207,
    -207,   130,  -207,  -207,   163,  -207,   194,   193,   195,   192,
    -207,   369,   277,   295,   277,  -207,   619,   631,   161,   161,
     161,   161,   161,   161,   151,   151,  -207,  -207,  -207,  -207,
    -207,   277,   390,  -207,  -207,  -207,  -207,   156,  -207,  -207,
     197,   202,   201,  -207,  -207,   258,   204,   208,  -207,  -207,
     206,   244,  -207,  -207,   411,  -207,   311,   432,  -207,  -207,
    -207,  -207,   258,   215,   214,  -207,  -207,   122,   252,   277,
     223,  -207,   243,   254,   240,   247,   142,   249,  -207,  -207,
     261,   258,   297,  -207,   509,   260,  -207,  -207,   271,  -207,
    -207,  -207,  -207,  -207,  -207,   258,  -207,   287,  -207,  -207,
    -207,  -207,  -207,   292,  -207,  -207,   258,   304,  -207,   307,
     529,   277,   324,   277,   358,  -207,  -207,  -207,   549,   258,
     325,  -207,  -207,  -207,   270,  -207,   277,   258,   326,  -207,
    -207,   258,   336,  -207,  -207,   606,   329,  -207,   346,    13,
     343,   341,   347,   358,  -207,   200,  -207,   569,   357,  -207,
     365,  -207,   324,   371,  -207,  -207,   277,   216,   364,   363,
    -207,  -207,  -207,  -207,   395,   373,   324,   453,   358,   377,
    -207,   277,   324,   277,  -207,  -207,   420,   382,   391,   358,
     358,   467,  -207,   393,   277,  -207,   386,   394,   409,  -207,
     407,   481,   324,  -207,   277,  -207,  -207,  -207,  -207,   495,
     324,   444,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    63,     0,     0,     0,     5,    15,     0,     0,
      14,     0,     1,     3,    13,    12,     4,    10,    11,     9,
       0,     0,     0,     0,     0,     2,     7,     8,     6,     0,
      91,    81,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,   123,    75,    76,    77,    78,     0,
       0,     0,   122,    71,    72,    73,    74,     0,   125,   124,
      96,    86,     0,     0,    89,    79,     0,     0,    32,     0,
       0,     0,     0,    65,    67,    69,    70,     0,     0,     0,
       0,    20,    58,    59,   100,     0,     0,   126,   118,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    82,     0,     0,     0,     0,
      94,    84,     0,     0,     0,     0,    29,    66,    68,    98,
      88,     0,    24,    50,    17,    57,     0,     0,     0,    60,
     131,     0,     0,     0,     0,   117,   120,   119,   112,   115,
     114,   116,   111,   113,   108,   109,   106,   107,   110,    99,
     103,     0,     0,    95,    85,    90,    80,     0,    33,    56,
      26,     0,     0,    97,    87,    40,     0,     0,    21,    48,
       0,     0,   130,   133,     0,   128,     0,     0,   102,   105,
      93,    83,    40,     0,     0,    30,    54,   123,     0,     0,
       0,   151,     0,     0,     0,     0,     0,    35,    44,   134,
       0,    39,     0,    16,     0,   125,    43,   135,     0,   136,
     137,   138,   139,    18,    46,    40,    62,     0,   129,   132,
     127,   101,   104,     0,    27,    52,    40,   144,   145,     0,
       0,     0,     0,     0,   162,   179,   178,   176,     0,     0,
       0,    25,    41,    42,     0,   140,     0,    40,     0,    61,
      34,    40,     0,   143,   142,   148,     0,   152,     0,   144,
     160,     0,     0,     0,   177,     0,    38,     0,     0,    22,
       0,    31,     0,     0,   149,   165,     0,     0,   159,     0,
      36,   141,    19,    28,   146,     0,     0,   161,   171,     0,
     164,     0,     0,     0,   150,   166,   170,     0,     0,     0,
     171,   158,   147,     0,     0,   156,   168,     0,     0,   163,
       0,   169,     0,   173,     0,   154,   153,   174,   157,     0,
       0,   167,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,   437,  -207,  -186,   174,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -200,  -207,
    -207,  -137,   212,   230,  -207,  -207,  -207,  -207,  -207,  -207,
     423,   -13,  -207,     6,  -207,   392,  -207,   -30,   -27,   -34,
     -29,  -207,  -207,   121,   433,   355,  -207,   -33,  -111,  -207,
    -206,  -207,  -181,  -207,  -183,  -207,  -196,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,   170,  -207,  -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    16,     5,   198,    17,   166,   247,   126,   215,
      78,   165,   183,   251,   161,   226,   113,   182,   199,   239,
     240,   200,   201,    18,   167,   127,    79,   184,   162,   114,
      40,    41,   129,   202,     9,    72,    52,    53,    54,    55,
      56,    21,    24,   203,    34,   108,   151,   204,    58,    87,
      59,   132,   206,   207,   208,   209,   256,   210,   286,   232,
     273,   211,   320,   312,   262,   263,   298,   299,   212
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,     2,     2,    75,    12,   229,     8,    73,    76,    11,
      74,     8,     8,     1,     2,   242,    88,    89,    90,     8,
     243,    81,     8,    70,    20,    82,    22,    80,   260,    23,
       3,     8,   257,   109,    39,    42,    35,   258,    45,    46,
       2,   117,    42,    75,   118,   223,    42,    73,    76,    85,
      74,   261,   131,   133,   205,    86,   115,   278,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   205,   284,    68,   152,    42,    36,   228,   248,   242,
     279,   289,   296,   116,   243,    37,   294,    82,    38,   252,
     205,   124,   302,   306,   296,   125,   160,   303,    43,   174,
     125,   176,    77,    29,   205,   297,   -49,    30,    31,    32,
     268,    33,   318,    83,   270,   205,   307,   297,   177,    84,
     322,    10,   106,   228,   119,   120,    15,    19,   205,    44,
      45,    46,    47,    48,    19,   107,   205,    28,   153,   154,
     205,    44,    45,    46,    47,    48,    28,    44,    45,    46,
      47,    48,   228,   -55,   205,    49,   230,   122,    85,   128,
      50,   130,   134,   238,    86,   123,  -144,    49,   -47,    51,
     163,   164,    50,    49,     6,   150,   149,   228,    50,    13,
     159,    51,   237,   101,   102,   103,   158,    51,   228,   228,
      26,    99,   100,   101,   102,   103,   180,   181,   255,    26,
     255,   170,   -53,   -45,     2,   187,    45,    46,    47,    48,
     188,   189,   190,   267,   191,   192,   193,   194,   195,   196,
       3,    44,    45,    46,    47,    48,    45,    46,    47,    48,
       7,    49,   168,   169,   171,    14,    50,   -51,   197,   280,
     185,   186,   213,   287,   255,    51,    27,    49,   214,   216,
     217,    71,    50,   224,   225,    27,   288,   227,   301,   231,
     255,    51,     2,   187,    45,    46,    47,    48,   188,   189,
     190,   311,   191,   192,   193,   194,   195,   196,     3,   233,
     235,   319,    44,    45,    46,    47,    48,   236,   -37,    49,
     234,    60,    61,    62,    50,    63,   197,    64,    65,    32,
     241,    66,   244,    51,  -145,   110,   111,    62,    49,   112,
      30,    31,    32,    50,    33,   246,    91,    92,    93,    94,
      95,    96,    51,    97,    98,    99,   100,   101,   102,   103,
     249,   250,    91,    92,    93,    94,    95,    96,   175,    97,
      98,    99,   100,   101,   102,   103,    86,   253,    91,    92,
      93,    94,    95,    96,   220,    97,    98,    99,   100,   101,
     102,   103,   197,   259,   266,   269,   272,   104,   105,    91,
      92,    93,    94,    95,    96,   271,    97,    98,    99,   100,
     101,   102,   103,   274,   275,   276,   285,   277,   155,   156,
      91,    92,    93,    94,    95,    96,   282,    97,    98,    99,
     100,   101,   102,   103,   283,   290,   172,   291,   292,   293,
     173,    91,    92,    93,    94,    95,    96,   300,    97,    98,
      99,   100,   101,   102,   103,  -175,   304,   313,   305,   178,
     310,   179,    91,    92,    93,    94,    95,    96,   314,    97,
      98,    99,   100,   101,   102,   103,   315,   316,   218,  -172,
      25,   265,   219,    91,    92,    93,    94,    95,    96,    69,
      97,    98,    99,   100,   101,   102,   103,   157,    67,   121,
     308,   221,     0,   222,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    99,   100,   101,   102,   103,    91,    92,
      93,    94,    95,    96,   295,    97,    98,    99,   100,   101,
     102,   103,    91,    92,    93,    94,    95,    96,   309,    97,
      98,    99,   100,   101,   102,   103,    91,    92,    93,    94,
      95,    96,   317,    97,    98,    99,   100,   101,   102,   103,
      91,    92,    93,    94,    95,    96,   321,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,   245,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,   254,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,   264,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,   281,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,   135,    91,    92,    93,
      94,    95,    96,     0,    97,    98,    99,   100,   101,   102,
     103,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,    93,    94,    95,    96,     0,    97,
      98,    99,   100,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      33,     4,     4,    37,     0,   188,     0,    37,    37,     3,
      37,     5,     6,     3,     4,   201,    49,    50,    51,    13,
     201,    37,    16,    36,     5,    41,     5,    40,   234,     5,
      20,    25,   232,    66,    37,    29,     5,   233,     6,     7,
       4,    71,    36,    77,    71,   182,    40,    77,    77,    36,
      77,   234,    85,    86,   165,    42,    69,   263,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   182,   272,    37,   107,    69,    36,   188,   215,   265,
     263,   277,   288,    37,   265,    44,   286,    41,     5,   226,
     201,    37,   292,   299,   300,    41,    37,   293,     6,   132,
      41,   134,    44,    36,   215,   288,    40,    40,    41,    42,
     247,    44,   312,     5,   251,   226,   299,   300,   151,    43,
     320,     0,     6,   234,    40,    41,     5,     6,   239,     5,
       6,     7,     8,     9,    13,    38,   247,    16,    40,    41,
     251,     5,     6,     7,     8,     9,    25,     5,     6,     7,
       8,     9,   263,    40,   265,    31,   189,    38,    36,    42,
      36,    37,    42,   196,    42,    40,    44,    31,    40,    45,
      40,    41,    36,    31,     0,    39,    43,   288,    36,     5,
      40,    45,    40,    32,    33,    34,    38,    45,   299,   300,
      16,    30,    31,    32,    33,    34,    40,    41,   231,    25,
     233,     6,    40,    40,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   246,    14,    15,    16,    17,    18,    19,
      20,     5,     6,     7,     8,     9,     6,     7,     8,     9,
       0,    31,    38,    40,    42,     5,    36,    40,    38,    39,
      38,    40,    38,   276,   277,    45,    16,    31,    40,    43,
       6,    31,    36,    38,    40,    25,    40,     5,   291,    36,
     293,    45,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   304,    14,    15,    16,    17,    18,    19,    20,    36,
      40,   314,     5,     6,     7,     8,     9,    40,    39,    31,
      36,    40,    41,    42,    36,    44,    38,    40,    41,    42,
      39,    44,     5,    45,    44,    40,    41,    42,    31,    44,
      40,    41,    42,    36,    44,    44,    21,    22,    23,    24,
      25,    26,    45,    28,    29,    30,    31,    32,    33,    34,
      43,    39,    21,    22,    23,    24,    25,    26,    43,    28,
      29,    30,    31,    32,    33,    34,    42,    40,    21,    22,
      23,    24,    25,    26,    43,    28,    29,    30,    31,    32,
      33,    34,    38,     5,    39,    39,    37,    40,    41,    21,
      22,    23,    24,    25,    26,    39,    28,    29,    30,    31,
      32,    33,    34,    37,    41,    44,    15,    40,    40,    41,
      21,    22,    23,    24,    25,    26,    39,    28,    29,    30,
      31,    32,    33,    34,    39,    41,    37,    44,    13,    36,
      41,    21,    22,    23,    24,    25,    26,    40,    28,    29,
      30,    31,    32,    33,    34,     5,    44,    41,    37,    39,
      37,    41,    21,    22,    23,    24,    25,    26,    44,    28,
      29,    30,    31,    32,    33,    34,    37,    40,    37,     5,
      13,   239,    41,    21,    22,    23,    24,    25,    26,    36,
      28,    29,    30,    31,    32,    33,    34,   112,    35,    77,
     300,    39,    -1,    41,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    21,    22,
      23,    24,    25,    26,    41,    28,    29,    30,    31,    32,
      33,    34,    21,    22,    23,    24,    25,    26,    41,    28,
      29,    30,    31,    32,    33,    34,    21,    22,    23,    24,
      25,    26,    41,    28,    29,    30,    31,    32,    33,    34,
      21,    22,    23,    24,    25,    26,    41,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    20,    47,    49,    51,    69,    79,    80,
      89,    79,     0,    51,    69,    89,    48,    51,    69,    89,
       5,    87,     5,     5,    88,    48,    51,    69,    89,    36,
      40,    41,    42,    44,    90,     5,    36,    44,     5,    37,
      76,    77,    79,     6,     5,     6,     7,     8,     9,    31,
      36,    45,    82,    83,    84,    85,    86,    93,    94,    96,
      40,    41,    42,    44,    40,    41,    44,    90,    37,    76,
      77,    31,    81,    83,    84,    85,    86,    44,    56,    72,
      77,    37,    41,     5,    43,    36,    42,    95,    93,    93,
      93,    21,    22,    23,    24,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    40,    41,     6,    38,    91,    93,
      40,    41,    44,    62,    75,    77,    37,    83,    84,    40,
      41,    81,    38,    40,    37,    41,    54,    71,    42,    78,
      37,    93,    97,    93,    42,    37,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    43,
      39,    92,    93,    40,    41,    40,    41,    91,    38,    40,
      37,    60,    74,    40,    41,    57,    52,    70,    38,    40,
       6,    42,    37,    41,    93,    43,    93,    93,    39,    41,
      40,    41,    63,    58,    73,    38,    40,     5,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    38,    50,    64,
      67,    68,    79,    89,    93,    94,    98,    99,   100,   101,
     103,   107,   114,    38,    40,    55,    43,     6,    37,    41,
      43,    39,    41,    67,    38,    40,    61,     5,    94,   100,
      93,    36,   105,    36,    36,    40,    40,    40,    93,    65,
      66,    39,    50,    98,     5,    40,    44,    53,    67,    43,
      39,    59,    67,    40,    40,    93,   102,    64,   102,     5,
      96,   100,   110,   111,    40,    68,    39,    93,    67,    39,
      67,    39,    37,   106,    37,    41,    44,    40,    96,   100,
      39,    40,    39,    39,    64,    15,   104,    93,    40,   102,
      41,    44,    13,    36,    64,    41,    96,   100,   112,   113,
      40,    93,    64,   102,    44,    37,    96,   100,   112,    41,
      37,    93,   109,    41,    44,    37,    40,    41,    64,    93,
     108,    41,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    50,    52,    53,    51,
      54,    55,    51,    56,    57,    51,    58,    59,    51,    60,
      61,    51,    62,    63,    51,    65,    64,    66,    64,    67,
      67,    68,    68,    68,    68,    70,    69,    71,    69,    72,
      69,    73,    69,    74,    69,    75,    69,    76,    76,    77,
      77,    78,    78,    79,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    83,    84,    85,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    95,    95,    96,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101,   102,   104,
     103,   105,   106,   103,   108,   107,   109,   107,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   114,   114,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     1,     0,     0,    11,
       0,     0,    10,     0,     0,     9,     0,     0,    11,     0,
       0,    10,     0,     0,     9,     0,     4,     0,     3,     1,
       0,     2,     2,     1,     1,     0,     8,     0,     7,     0,
       6,     0,     8,     0,     7,     0,     6,     3,     2,     2,
       3,     4,     3,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     2,     4,     6,     4,     5,     3,     5,     4,     4,
       6,     3,     5,     7,     5,     6,     4,     7,     6,     4,
       3,     4,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     2,     4,     3,     5,
       4,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     3,     1,     1,     5,     7,     1,     0,
       6,     0,     0,     9,     0,    10,     0,     9,     4,     2,
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
        case 17:
#line 270 "parser.y" /* yacc.c:1661  */
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
	}
#line 1746 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 292 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1754 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 296 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1762 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 300 "parser.y" /* yacc.c:1661  */
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
	}
#line 1789 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 323 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1797 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 327 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1805 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 331 "parser.y" /* yacc.c:1661  */
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
	}
#line 1825 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 347 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1833 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 351 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1841 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 355 "parser.y" /* yacc.c:1661  */
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
	}
#line 1867 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 377 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1875 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 381 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1883 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 385 "parser.y" /* yacc.c:1661  */
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
	}
#line 1910 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 408 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1918 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 412 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1926 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 416 "parser.y" /* yacc.c:1661  */
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
	}
#line 1946 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 432 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1954 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 436 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1962 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 443 "parser.y" /* yacc.c:1661  */
    { 
		add_newtable();
	}
#line 1970 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 447 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol)
		{
			dump_cur_table();
		}
	}
#line 1981 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 454 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1989 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 458 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1997 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 478 "parser.y" /* yacc.c:1661  */
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
	}
#line 2022 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 500 "parser.y" /* yacc.c:1661  */
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
	}
#line 2048 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 523 "parser.y" /* yacc.c:1661  */
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
	}
#line 2068 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 540 "parser.y" /* yacc.c:1661  */
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

	}
#line 2094 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 563 "parser.y" /* yacc.c:1661  */
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
		
	}
#line 2121 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 587 "parser.y" /* yacc.c:1661  */
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
	}
#line 2140 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 607 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = (func_val*)(yyvsp[-2].v);

		argu_val *co =(argu_val*)(yyvsp[-1].v);

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		(yyval.v) = (void*)p;
	}
#line 2156 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 619 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)(yyvsp[-1].v);

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		(yyval.v) = (void*)p;
	}
#line 2173 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 635 "parser.y" /* yacc.c:1661  */
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
	}
#line 2193 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 651 "parser.y" /* yacc.c:1661  */
    {
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup((yyvsp[-1].str));

		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=(yyvsp[-2].c_type);

		p->val->list=(yyvsp[0].v);

		(yyval.v) = (void*)p;
	}
#line 2210 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 668 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv=(int*)realloc((int*)p->stepv,sizeof(int)*(p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2225 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 679 "parser.y" /* yacc.c:1661  */
    {
		arr_val* p =NEW_VAL(arr_val);
		p->stepc=1;
		p->stepv=NEW_VAL(int);
		p->stepv[0]= atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2238 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 691 "parser.y" /* yacc.c:1661  */
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
#line 2257 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 709 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = TYPE_VOID;
	}
#line 2265 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 718 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2278 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 727 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2292 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 737 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2305 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 746 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(double*)p->list= -*((double*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2319 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 756 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2332 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 765 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2345 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 778 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2355 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 784 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2365 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 790 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2375 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 796 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2385 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 805 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_INT;
		(yyval.v) = (void*)p;
	}
#line 2398 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 817 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		float *val = NEW_VAL(float);
		*val = (float)atof((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_FLOAT;
		(yyval.v) = (void*)p;
	}
#line 2411 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 829 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		(yyval.v) = (void*)p;
	}
#line 2423 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 840 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		(yyval.v) = (void*)p;
	}
#line 2435 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 854 "parser.y" /* yacc.c:1661  */
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
			add_id((yyvsp[-1].str),(void*)p);
		else
			dump_error(result);
	}
#line 2457 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 872 "parser.y" /* yacc.c:1661  */
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
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2480 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 891 "parser.y" /* yacc.c:1661  */
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
			add_id((yyvsp[-1].str),(void*)p);
		else
			dump_error(result);
	}
#line 2501 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 908 "parser.y" /* yacc.c:1661  */
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
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2522 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 925 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-6].c_type);

		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-6].c_type);

		p->list=(yyvsp[-3].v);


		arr_val *arrs=(arr_val*)(yyvsp[-3].v);
		invo_val *invo=(invo_val*)(yyvsp[-1].v);

		long long int allstep=1;
		for(int t=0;t<arrs->stepc;t++)
		{
			allstep *= arrs->stepv[t];
		}

		if(invo->listc > allstep)
		{
			dump_error(ERROR_ARR_INITIAL);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(!(check_func_change(p->type,constp->type)))
				typeerr=1;
		}

		if(typeerr)
		{
			dump_error(ERROR_TYPE_ERROR);
		}


		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 2573 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 972 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-4].c_type);
		id_val *p= NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-4].c_type);
		p->list=(yyvsp[-1].v);

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2592 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 987 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-5].c_type);
		id_val *p= NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-5].c_type);
		p->list=(yyvsp[-3].v);

		arr_val *arrs=(arr_val*)(yyvsp[-3].v);
		invo_val *invo=(invo_val*)(yyvsp[-1].v);

		long long int allstep=1;
		for(int t=0;t<arrs->stepc;t++)
		{
			allstep *= arrs->stepv[t];
		}

		if(invo->listc > allstep)
		{
			dump_error(ERROR_ARR_INITIAL);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(!(check_func_change(p->type,constp->type)))
				typeerr=1;
		}

		if(typeerr)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 2639 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 1030 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = (yyvsp[-3].c_type);
		id_val *p=NEW_VAL(id_val);
		p->kind=KIND_VARIABLE;
		p->type=(yyvsp[-3].c_type);
		p->list=(yyvsp[-1].v);

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2658 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 1048 "parser.y" /* yacc.c:1661  */
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
#line 2680 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 1066 "parser.y" /* yacc.c:1661  */
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
#line 2702 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 1087 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);

		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;
		

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-1].str),(void*)p);
		else
			dump_error(result);
	}
#line 2724 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 1105 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2745 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 1122 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-2].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-1].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-1].str),(void*)p);
		else
			dump_error(result);
	}
#line 2766 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 1139 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-4].c_type);
		
		arr_val *t = NEW_VAL(arr_val);
		t->stepc=0;
		p->list=(void*)t;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2787 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 1156 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-6].c_type);
		p->list = (yyvsp[-3].v);

		arr_val *arrs=(arr_val*)(yyvsp[-3].v);
		invo_val *invo=(invo_val*)(yyvsp[-1].v);

		long long int allstep=1;
		for(int t=0;t<arrs->stepc;t++)
		{
			allstep *= arrs->stepv[t];
		}

		if(invo->listc > allstep)
		{
			dump_error(ERROR_ARR_STEP);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(!(check_func_change(p->type,constp->type)))
				typeerr=1;
		}

		if(typeerr)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 2833 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 1198 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-4].c_type);
		p->list = (yyvsp[-1].v);

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2851 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 1212 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-5].c_type);
		p->list = (yyvsp[-3].v);

		arr_val *arrs=(arr_val*)(yyvsp[-3].v);
		invo_val *invo=(invo_val*)(yyvsp[-1].v);

		long long int allstep=1;
		for(int t=0;t<arrs->stepc;t++)
		{
			allstep *= arrs->stepv[t];
		}

		if(invo->listc > allstep)
		{
			dump_error(ERROR_ARR_STEP);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(!(check_func_change(p->type,constp->type)))
				typeerr=1;
		}

		if(typeerr)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 2897 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 1254 "parser.y" /* yacc.c:1661  */
    {
		id_val* p=NEW_VAL(id_val);
		p->kind = KIND_VARIABLE;
		p->type = (yyvsp[-3].c_type);
		p->list = (yyvsp[-1].v);

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2915 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 1268 "parser.y" /* yacc.c:1661  */
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
#line 2935 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 1284 "parser.y" /* yacc.c:1661  */
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
#line 2956 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 1304 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv = (int*)realloc((int*)p->stepv,sizeof(int) * (p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2971 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 1315 "parser.y" /* yacc.c:1661  */
    {

		arr_val *p = NEW_VAL(arr_val);
		p->stepc = 1;
		p->stepv = NEW_VAL(int);
		p->stepv[0] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2985 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 1328 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-2].v);
		const_val *co=(const_val*)(yyvsp[-1].v);

		p->listc+=1;
		const_val *q=(const_val*)p->listv;

		q=(const_val*)realloc(q,sizeof(const_val)*(p->listc));
		q[p->listc-1]=*co;

		p->listv=(void*)q;

		(yyval.v) = (void*)p;
	}
#line 3004 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 1343 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3020 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 1355 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc=0;

		(yyval.v) = (void*)p;
	}
#line 3031 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 1365 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-2].v);
		const_val *co=(const_val*)(yyvsp[-1].v);

		p->listc+=1;
		const_val *q=(const_val*)p->listv;

		q=(const_val*)realloc(q,sizeof(const_val)*(p->listc));
		q[p->listc-1]=*co;

		p->listv=(void*)q;

		(yyval.v) = (void*)p;

	}
#line 3051 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 1381 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3067 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 1396 "parser.y" /* yacc.c:1661  */
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
#line 3085 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 1410 "parser.y" /* yacc.c:1661  */
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
#line 3103 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 1424 "parser.y" /* yacc.c:1661  */
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
#line 3121 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 1438 "parser.y" /* yacc.c:1661  */
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
#line 3139 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 1452 "parser.y" /* yacc.c:1661  */
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
#line 3157 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 1466 "parser.y" /* yacc.c:1661  */
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
#line 3175 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 1480 "parser.y" /* yacc.c:1661  */
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
#line 3193 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 1494 "parser.y" /* yacc.c:1661  */
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
#line 3211 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 1508 "parser.y" /* yacc.c:1661  */
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
#line 3229 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 1522 "parser.y" /* yacc.c:1661  */
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
#line 3248 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 1537 "parser.y" /* yacc.c:1661  */
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
#line 3267 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 1552 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(v1);
		(yyval.v) = (yyvsp[-1].v);
	}
#line 3277 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 1558 "parser.y" /* yacc.c:1661  */
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
#line 3294 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 1571 "parser.y" /* yacc.c:1661  */
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
#line 3312 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 1585 "parser.y" /* yacc.c:1661  */
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
#line 3330 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 1599 "parser.y" /* yacc.c:1661  */
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
#line 3347 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 1612 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 3355 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 1616 "parser.y" /* yacc.c:1661  */
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
#line 3394 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 1651 "parser.y" /* yacc.c:1661  */
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
#line 3429 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 1682 "parser.y" /* yacc.c:1661  */
    {
		// check arr id exist and dimention correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);
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

		(yyval.v) = (void*)q;
	}
#line 3459 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 1711 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[0].v);
		p->name = strdup((yyvsp[-1].str));
		
		(yyval.v) = (void*)p;
	}
#line 3470 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 1721 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-3].v);
		p->listc += 1;

		const_val *exp=(yyvsp[-1].v);
		if(exp->type!=TYPE_INT)
			dump_error(ERROR_ARR_NO_INT);

		(yyval.v) =(void*)p;
	}
#line 3485 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 1732 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc = 1;

		const_val *exp=(yyvsp[-1].v);
		if(exp->type!=TYPE_INT)
			dump_error(ERROR_ARR_NO_INT);

		(yyval.v) = (void*)p;
	}
#line 3500 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 1746 "parser.y" /* yacc.c:1661  */
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
#line 3520 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 1762 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-3].str));
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)((yyvsp[-1].v));

		(yyval.v) = (void*)p;

	}
#line 3535 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 1773 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-2].str));
		p->listc = 0;

		(yyval.v) = (void*)p;
	}
#line 3547 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 1784 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)(yyvsp[-1].v));
		p->listv = (void*)co;

		(yyval.v) = (void*)p;
	}
#line 3564 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 1797 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

		(yyval.v) = (void*)p;
	}
#line 3580 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 1818 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar((yyvsp[-1].v));
	}
#line 3589 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 1828 "parser.y" /* yacc.c:1661  */
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
#line 3622 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 1857 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
		
	}
#line 3632 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 1863 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
	}
#line 3641 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 1871 "parser.y" /* yacc.c:1661  */
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
#line 3682 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 1908 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
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

		(yyval.v) = (void*)q;
	}
#line 3711 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 1942 "parser.y" /* yacc.c:1661  */
    {
		const_val *con =(const_val*)(yyvsp[0].v);
		if(con->type!=TYPE_BOOL)
			dump_error(ERROR_NO_BOOL);
		else
		{
			check_and_set_scalar(con);
		}
	}
#line 3725 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 1954 "parser.y" /* yacc.c:1661  */
    { isInLoop+=1;}
#line 3731 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 1954 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3737 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 1955 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3743 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 1955 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3749 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 1959 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3755 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 1959 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3761 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 1960 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3767 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 1960 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3773 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 1965 "parser.y" /* yacc.c:1661  */
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
#line 3792 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 1980 "parser.y" /* yacc.c:1661  */
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
#line 3824 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 2008 "parser.y" /* yacc.c:1661  */
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
#line 3856 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 2036 "parser.y" /* yacc.c:1661  */
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
#line 3875 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 2055 "parser.y" /* yacc.c:1661  */
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
#line 3894 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 2070 "parser.y" /* yacc.c:1661  */
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
#line 3926 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 2098 "parser.y" /* yacc.c:1661  */
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
#line 3958 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 2126 "parser.y" /* yacc.c:1661  */
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
#line 3977 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 2146 "parser.y" /* yacc.c:1661  */
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
#line 3996 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 2161 "parser.y" /* yacc.c:1661  */
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
#line 4028 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 2189 "parser.y" /* yacc.c:1661  */
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
#line 4047 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 2204 "parser.y" /* yacc.c:1661  */
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
#line 4079 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 172:
#line 2236 "parser.y" /* yacc.c:1661  */
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
#line 4098 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 173:
#line 2251 "parser.y" /* yacc.c:1661  */
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
#line 4130 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 174:
#line 2279 "parser.y" /* yacc.c:1661  */
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
#line 4149 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 175:
#line 2294 "parser.y" /* yacc.c:1661  */
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
#line 4181 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 176:
#line 2325 "parser.y" /* yacc.c:1661  */
    {
		if(func_type != TYPE_VOID)
			dump_error(ERROR_RETURN_VOID_ERROR);
	}
#line 4190 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 177:
#line 2330 "parser.y" /* yacc.c:1661  */
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

	}
#line 4211 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 178:
#line 2347 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4220 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 179:
#line 2352 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4229 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 4233 "parser.tab.c" /* yacc.c:1661  */
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
#line 2360 "parser.y" /* yacc.c:1906  */


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


	decl_check *parser=decl_stack;
	while(parser!=NULL)
	{
		if(!parser->isUsed)
			printf("##########Error at Line #%d: %s.##########\n",parser->line,"no definition of this function declare");
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
