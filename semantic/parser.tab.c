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

int cur_level=0;

symbol_table* cur_table=NULL;
symbol_list* argu_table=NULL;
symbol_list* argu_table_index=NULL;
symbol_list* cur_argu_ptr=NULL;

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
symbol_list* find_symbol(char* name);
const_val *geneOneVal(const_val *a,int m_type);
const_val *geneValConstOne(const_val *a, const_val *b, int m_type);
const_val *geneValConst(const_val *a, const_val *b);
int check_and_set_scalar(const_val *a);
int check_type_three(const_val *a,const_val *b);
int check_type_one(const_val *a, const_val *b,int m_type);
int is_const_var(char* name);


int yyerror( char *msg );
int main( int argc, char **argv );
int yylex();


#line 224 "parser.tab.c" /* yacc.c:339  */

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
#line 159 "parser.y" /* yacc.c:355  */

	char* str;
	void* v;
	int c_type;

#line 299 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 316 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   656

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

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
       0,   210,   210,   211,   212,   213,   217,   218,   219,   220,
     221,   222,   226,   227,   228,   229,   233,   238,   261,   237,
     269,   293,   268,   301,   318,   300,   326,   349,   325,   357,
     381,   356,   389,   406,   388,   417,   416,   428,   427,   438,
     439,   443,   444,   445,   446,   452,   451,   478,   477,   503,
     502,   522,   521,   547,   546,   573,   572,   594,   606,   622,
     638,   655,   666,   678,   696,   705,   714,   724,   733,   743,
     752,   765,   771,   777,   783,   792,   804,   816,   827,   841,
     859,   878,   895,   912,   959,   974,  1017,  1035,  1053,  1074,
    1092,  1109,  1126,  1143,  1185,  1199,  1241,  1255,  1271,  1291,
    1302,  1315,  1330,  1342,  1352,  1368,  1383,  1397,  1411,  1425,
    1439,  1453,  1467,  1481,  1495,  1509,  1524,  1539,  1545,  1558,
    1572,  1586,  1599,  1603,  1638,  1669,  1698,  1708,  1714,  1724,
    1740,  1751,  1762,  1775,  1790,  1791,  1792,  1793,  1794,  1795,
    1796,  1806,  1821,  1827,  1835,  1871,  1900,  1901,  1905,  1918,
    1918,  1919,  1919,  1919,  1923,  1923,  1924,  1924,  1928,  1943,
    1971,  1999,  2014,  2018,  2033,  2061,  2089,  2109,  2124,  2139,
    2143,  2158,  2175,  2185,  2190
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

#define YYPACT_NINF -231

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define YYTABLE_NINF -171

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,  -231,  -231,     1,    23,    76,    76,  -231,    25,    34,
    -231,    45,  -231,    76,  -231,  -231,    76,  -231,  -231,  -231,
     149,    50,    40,    47,    90,    76,  -231,  -231,  -231,     3,
    -231,  -231,    96,   284,   165,   195,     4,   153,    81,    92,
       1,    -6,   129,    95,   -16,  -231,  -231,  -231,  -231,   284,
     284,   284,  -231,  -231,  -231,  -231,  -231,   318,  -231,  -231,
    -231,  -231,   142,   112,  -231,  -231,   284,   231,   115,     1,
      52,   107,    79,  -231,  -231,  -231,  -231,   153,   114,   118,
      57,   125,  -231,   122,  -231,   100,   284,   146,  -231,   580,
     622,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,  -231,  -231,   154,   225,   103,   339,
    -231,  -231,   112,   166,   152,    89,   182,  -231,  -231,  -231,
    -231,   155,  -231,  -231,   198,  -231,   203,   204,   197,   211,
    -231,   360,   284,   273,   284,  -231,   610,   622,    54,    54,
      54,    54,    54,    54,   233,   233,  -231,  -231,  -231,  -231,
    -231,   284,   381,  -231,  -231,  -231,  -231,   170,  -231,  -231,
     206,   217,   218,  -231,  -231,   209,   222,   223,  -231,  -231,
     219,   262,  -231,  -231,   402,  -231,   302,   423,  -231,  -231,
    -231,  -231,   209,   238,   245,  -231,  -231,   -15,   281,   284,
     242,  -231,   251,   264,   268,   269,   284,   271,  -231,  -231,
     272,   209,   307,  -231,   500,   270,  -231,  -231,   274,  -231,
    -231,  -231,  -231,  -231,  -231,   209,  -231,   276,  -231,  -231,
    -231,  -231,  -231,   278,  -231,  -231,   209,   279,  -231,   282,
     520,   284,   275,   284,   332,  -231,  -231,   540,   209,   299,
    -231,  -231,  -231,   240,  -231,   284,   209,   314,  -231,  -231,
     209,   315,  -231,  -231,   597,   319,  -231,   320,   -16,   325,
     311,   334,   332,  -231,   163,  -231,   560,   336,  -231,   337,
    -231,   275,   362,  -231,  -231,   284,   243,   346,   351,  -231,
    -231,  -231,  -231,   365,   363,   275,   444,   281,   356,  -231,
     284,   275,   284,  -231,  -231,   354,   371,   281,   281,   458,
    -231,   379,   284,  -231,   373,   382,  -231,   378,   472,   275,
     284,  -231,  -231,  -231,  -231,   486,   275,   395,  -231
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
       0,     0,     0,     0,   162,   174,   173,     0,     0,     0,
      25,    41,    42,     0,   140,     0,    40,     0,    61,    34,
      40,     0,   143,   142,   148,     0,   152,     0,   144,   160,
       0,     0,     0,   172,     0,    38,     0,     0,    22,     0,
      31,     0,     0,   149,   165,     0,     0,   159,     0,    36,
     141,    19,    28,   146,     0,     0,   161,   169,     0,   164,
       0,     0,     0,   150,   166,     0,     0,     0,   169,   158,
     147,     0,     0,   156,     0,     0,   163,     0,   168,     0,
       0,   154,   153,   171,   157,     0,     0,   167,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,   408,  -231,  -191,   117,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -188,  -231,
    -231,  -134,   191,   124,  -231,  -231,  -231,  -231,  -231,  -231,
     401,   -12,  -231,     9,  -231,   361,  -231,   -35,   -34,   -31,
     -26,  -231,  -231,   141,   405,   329,  -231,   -33,  -111,  -231,
    -230,  -231,  -182,  -231,  -187,  -231,  -220,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,   144,  -231,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    16,     5,   198,    17,   166,   246,   126,   215,
      78,   165,   183,   250,   161,   226,   113,   182,   199,   238,
     239,   200,   201,    18,   167,   127,    79,   184,   162,   114,
      40,    41,   129,   202,     9,    72,    52,    53,    54,    55,
      56,    21,    24,   203,    34,   108,   151,   204,    58,    87,
      59,   132,   206,   207,   208,   209,   255,   210,   285,   232,
     272,   211,   316,   309,   261,   262,   296,   297,   212
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   229,    73,    74,   259,     2,    75,     2,     2,     8,
     241,    76,    11,   257,     8,     8,    88,    89,    90,   242,
      85,    85,     8,    12,    70,     8,    86,    86,    80,  -144,
      20,    81,   277,   109,     8,    82,   117,   118,    42,    22,
      39,    68,    73,    74,   256,    42,    75,   260,   223,    42,
      23,    76,   131,   133,   205,    35,   288,   115,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   205,   301,   241,   152,   278,    36,   228,    42,     1,
       2,   247,   242,   283,    99,   100,   101,   102,   103,   116,
     205,    37,   251,    82,   124,    38,     3,   293,   125,   174,
     295,   176,    43,   300,   205,    44,    45,    46,    47,    48,
     304,   295,   267,    45,    46,   205,   269,     6,   177,   119,
     120,   314,    13,   228,     7,    77,   160,   205,   318,    14,
     125,    49,   -49,    26,    83,   205,    50,   130,    84,   205,
      27,    10,    26,   153,   154,    51,    15,    19,   106,    27,
     107,   228,   122,   205,    19,   -55,   230,    28,   123,    45,
      46,    47,    48,   237,   128,   -47,    28,     2,   187,    45,
      46,    47,    48,   188,   189,   190,   228,   191,   192,   193,
     194,   195,   196,     3,    71,    29,   228,   228,   134,    30,
      31,    32,   159,    33,    49,   163,   164,   149,   254,    50,
     254,   197,   279,   170,   158,    60,    61,    62,    51,    63,
     180,   181,   266,     2,   187,    45,    46,    47,    48,   188,
     189,   190,   -53,   191,   192,   193,   194,   195,   196,     3,
      44,    45,    46,    47,    48,    64,    65,    32,   -45,    66,
      49,   168,   286,   254,   169,    50,   -51,   197,    44,    45,
      46,    47,    48,   171,    51,   185,    49,   299,   186,   254,
     213,    50,   216,   214,   150,   101,   102,   103,   217,   308,
      51,   110,   111,    62,    49,   112,   224,   315,   231,    50,
      30,    31,    32,   287,    33,   225,   227,   233,    51,    44,
      45,    46,    47,    48,    91,    92,    93,    94,    95,    96,
     234,    97,    98,    99,   100,   101,   102,   103,   235,   236,
     -37,   240,   243,   197,  -145,    49,   175,   249,   245,   248,
      50,    86,   252,    91,    92,    93,    94,    95,    96,    51,
      97,    98,    99,   100,   101,   102,   103,   258,   265,    91,
      92,    93,    94,    95,    96,   220,    97,    98,    99,   100,
     101,   102,   103,   268,   270,   275,   271,   273,   104,   105,
      91,    92,    93,    94,    95,    96,   274,    97,    98,    99,
     100,   101,   102,   103,   276,   281,   282,   284,   291,   155,
     156,    91,    92,    93,    94,    95,    96,   289,    97,    98,
      99,   100,   101,   102,   103,   290,   298,   172,   302,   292,
    -170,   173,    91,    92,    93,    94,    95,    96,   303,    97,
      98,    99,   100,   101,   102,   103,   307,   310,   312,   311,
     178,    25,   179,    91,    92,    93,    94,    95,    96,   264,
      97,    98,    99,   100,   101,   102,   103,    69,   121,   218,
      67,   157,   305,   219,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   221,     0,   222,    91,    92,    93,    94,    95,
      96,     0,    97,    98,    99,   100,   101,   102,   103,    91,
      92,    93,    94,    95,    96,   294,    97,    98,    99,   100,
     101,   102,   103,    91,    92,    93,    94,    95,    96,   306,
      97,    98,    99,   100,   101,   102,   103,    91,    92,    93,
      94,    95,    96,   313,    97,    98,    99,   100,   101,   102,
     103,    91,    92,    93,    94,    95,    96,   317,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     244,    91,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     253,    91,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     263,    91,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     280,    91,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   135,    91,    92,
      93,    94,    95,    96,     0,    97,    98,    99,   100,   101,
     102,   103,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,   102,   103,    93,    94,    95,    96,     0,
      97,    98,    99,   100,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      33,   188,    37,    37,   234,     4,    37,     4,     4,     0,
     201,    37,     3,   233,     5,     6,    49,    50,    51,   201,
      36,    36,    13,     0,    36,    16,    42,    42,    40,    44,
       5,    37,   262,    66,    25,    41,    71,    71,    29,     5,
      37,    37,    77,    77,   232,    36,    77,   234,   182,    40,
       5,    77,    85,    86,   165,     5,   276,    69,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   182,   292,   264,   107,   262,    36,   188,    69,     3,
       4,   215,   264,   271,    30,    31,    32,    33,    34,    37,
     201,    44,   226,    41,    37,     5,    20,   285,    41,   132,
     287,   134,     6,   291,   215,     5,     6,     7,     8,     9,
     297,   298,   246,     6,     7,   226,   250,     0,   151,    40,
      41,   309,     5,   234,     0,    44,    37,   238,   316,     5,
      41,    31,    40,    16,     5,   246,    36,    37,    43,   250,
      16,     0,    25,    40,    41,    45,     5,     6,     6,    25,
      38,   262,    38,   264,    13,    40,   189,    16,    40,     6,
       7,     8,     9,   196,    42,    40,    25,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   287,    14,    15,    16,
      17,    18,    19,    20,    31,    36,   297,   298,    42,    40,
      41,    42,    40,    44,    31,    40,    41,    43,   231,    36,
     233,    38,    39,     6,    38,    40,    41,    42,    45,    44,
      40,    41,   245,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    40,    14,    15,    16,    17,    18,    19,    20,
       5,     6,     7,     8,     9,    40,    41,    42,    40,    44,
      31,    38,   275,   276,    40,    36,    40,    38,     5,     6,
       7,     8,     9,    42,    45,    38,    31,   290,    40,   292,
      38,    36,    43,    40,    39,    32,    33,    34,     6,   302,
      45,    40,    41,    42,    31,    44,    38,   310,    36,    36,
      40,    41,    42,    40,    44,    40,     5,    36,    45,     5,
       6,     7,     8,     9,    21,    22,    23,    24,    25,    26,
      36,    28,    29,    30,    31,    32,    33,    34,    40,    40,
      39,    39,     5,    38,    44,    31,    43,    39,    44,    43,
      36,    42,    40,    21,    22,    23,    24,    25,    26,    45,
      28,    29,    30,    31,    32,    33,    34,     5,    39,    21,
      22,    23,    24,    25,    26,    43,    28,    29,    30,    31,
      32,    33,    34,    39,    39,    44,    37,    37,    40,    41,
      21,    22,    23,    24,    25,    26,    41,    28,    29,    30,
      31,    32,    33,    34,    40,    39,    39,    15,    13,    40,
      41,    21,    22,    23,    24,    25,    26,    41,    28,    29,
      30,    31,    32,    33,    34,    44,    40,    37,    44,    36,
       5,    41,    21,    22,    23,    24,    25,    26,    37,    28,
      29,    30,    31,    32,    33,    34,    37,    44,    40,    37,
      39,    13,    41,    21,    22,    23,    24,    25,    26,   238,
      28,    29,    30,    31,    32,    33,    34,    36,    77,    37,
      35,   112,   298,    41,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    -1,    41,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    21,
      22,    23,    24,    25,    26,    41,    28,    29,    30,    31,
      32,    33,    34,    21,    22,    23,    24,    25,    26,    41,
      28,    29,    30,    31,    32,    33,    34,    21,    22,    23,
      24,    25,    26,    41,    28,    29,    30,    31,    32,    33,
      34,    21,    22,    23,    24,    25,    26,    41,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    37,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34
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
      93,    36,   105,    36,    36,    40,    40,    93,    65,    66,
      39,    50,    98,     5,    40,    44,    53,    67,    43,    39,
      59,    67,    40,    40,    93,   102,    64,   102,     5,    96,
     100,   110,   111,    40,    68,    39,    93,    67,    39,    67,
      39,    37,   106,    37,    41,    44,    40,    96,   100,    39,
      40,    39,    39,    64,    15,   104,    93,    40,   102,    41,
      44,    13,    36,    64,    41,   100,   112,   113,    40,    93,
      64,   102,    44,    37,   100,   112,    41,    37,    93,   109,
      44,    37,    40,    41,    64,    93,   108,    41,    64
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
     113,   113,   114,   114,   114
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
       1,     3,     0,     5,     3,     2,     4,     5,     3,     0,
       5,     4,     3,     2,     2
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
#line 238 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 1710 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 261 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1718 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 265 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1726 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 269 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 1754 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 293 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1762 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 297 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1770 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 301 "parser.y" /* yacc.c:1661  */
    {
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);
		func_val *t =NEW_VAL(func_val);
		t->argc=0;
		p->list =(void*)t;

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 1791 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 318 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1799 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 322 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1807 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 326 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);
	}
#line 1834 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 349 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1842 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 353 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1850 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 357 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 1878 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 381 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1886 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 385 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1894 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 389 "parser.y" /* yacc.c:1661  */
    {
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);
		func_val *t =NEW_VAL(func_val);
		t->argc=0;
		p->list =(void*)t;

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 1915 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 406 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1923 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 410 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1931 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 417 "parser.y" /* yacc.c:1661  */
    { 
		add_newtable();
	}
#line 1939 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 421 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol)
		{
			dump_cur_table();
		}
	}
#line 1950 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 428 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1958 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 432 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1966 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 452 "parser.y" /* yacc.c:1661  */
    {
		
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);

	}
#line 1995 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 478 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
	}
#line 2023 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 503 "parser.y" /* yacc.c:1661  */
    {
		id_val *p = NEW_VAL(id_val);

		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);

		func_val *t =NEW_VAL(func_val);
		t->argc=0;
		p->list =(void*)t;

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2045 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 522 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = (func_val*)(yyvsp[-2].v);

		p_f->argc+=1;
		p_f->argv=realloc((argu_val*)p_f->argv,sizeof(argu_val)*(p_f->argc));
		((argu_val*)p_f->argv)[p_f->argc-1] = *co;

		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-5].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-4].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-4].str),(void*)p);
		else
			dump_error(result);

	}
#line 2073 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 547 "parser.y" /* yacc.c:1661  */
    {
		argu_val *co=(argu_val*)(yyvsp[-1].v);

		func_val *p_f = NEW_VAL(func_val);
		p_f->argc=1;
		p_f->argv=NEW_VAL(argu_val);

		p_f->argv[0]= *co;


		id_val *p = NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-4].c_type);

		p->list = (void*)p_f;

		int result= find_redclair((yyvsp[-3].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-3].str),(void*)p);
		else
			dump_error(result);
		
	}
#line 2102 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 573 "parser.y" /* yacc.c:1661  */
    {
		id_val *p=NEW_VAL(id_val);
		p->kind = KIND_FUNCTION;
		p->type = (yyvsp[-3].c_type);

		func_val *t =NEW_VAL(func_val);
		t->argc=0;
		p->list =(void*)t;

		int result= find_redclair((yyvsp[-2].str));

		if(result==NO_ERROR)
			add_id((yyvsp[-2].str),(void*)p);
		else
			dump_error(result);
	}
#line 2123 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 595 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = (func_val*)(yyvsp[-2].v);

		argu_val *co =(argu_val*)(yyvsp[-1].v);

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		(yyval.v) = (void*)p;
	}
#line 2139 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 607 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)(yyvsp[-1].v);

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		(yyval.v) = (void*)p;
	}
#line 2156 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 623 "parser.y" /* yacc.c:1661  */
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
#line 2176 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 639 "parser.y" /* yacc.c:1661  */
    {
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup((yyvsp[-1].str));

		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=(yyvsp[-2].c_type);

		p->val->list=(yyvsp[0].v);

		(yyval.v) = (void*)p;
	}
#line 2193 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 656 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv=(int*)realloc((int*)p->stepv,sizeof(int)*(p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2208 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 667 "parser.y" /* yacc.c:1661  */
    {
		arr_val* p =NEW_VAL(arr_val);
		p->stepc=1;
		p->stepv=NEW_VAL(int);
		p->stepv[0]= atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2221 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 679 "parser.y" /* yacc.c:1661  */
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
#line 2240 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 697 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = TYPE_VOID;
	}
#line 2248 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 706 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2261 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 715 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2275 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 725 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2288 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 734 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(double*)p->list= -*((double*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2302 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 744 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2315 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 753 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2328 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 766 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2338 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 772 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2348 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 778 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2358 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 784 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2368 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 793 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_INT;
		(yyval.v) = (void*)p;
	}
#line 2381 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 805 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		float *val = NEW_VAL(float);
		*val = (float)atof((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_DOUBLE;
		(yyval.v) = (void*)p;
	}
#line 2394 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 817 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		(yyval.v) = (void*)p;
	}
#line 2406 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 828 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		(yyval.v) = (void*)p;
	}
#line 2418 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 842 "parser.y" /* yacc.c:1661  */
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
#line 2440 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 860 "parser.y" /* yacc.c:1661  */
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
#line 2463 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 879 "parser.y" /* yacc.c:1661  */
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
#line 2484 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 896 "parser.y" /* yacc.c:1661  */
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
#line 2505 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 913 "parser.y" /* yacc.c:1661  */
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
			dump_error(ERROR_ARR_STEP);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(constp->type != p->type)
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
#line 2556 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 960 "parser.y" /* yacc.c:1661  */
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
#line 2575 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 975 "parser.y" /* yacc.c:1661  */
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
			dump_error(ERROR_ARR_STEP);
		}

		int typeerr=0;
		for(int t=0;t<invo->listc;t++)
		{
			const_val *constp=((const_val*)invo->listv)+t;

			if(constp->type != p->type)
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
#line 2622 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 1018 "parser.y" /* yacc.c:1661  */
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
#line 2641 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 1036 "parser.y" /* yacc.c:1661  */
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
#line 2663 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 1054 "parser.y" /* yacc.c:1661  */
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
#line 2685 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 1075 "parser.y" /* yacc.c:1661  */
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
#line 2707 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 1093 "parser.y" /* yacc.c:1661  */
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
#line 2728 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 1110 "parser.y" /* yacc.c:1661  */
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
#line 2749 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 1127 "parser.y" /* yacc.c:1661  */
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
#line 2770 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 1144 "parser.y" /* yacc.c:1661  */
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

			if(constp->type != p->type)
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
#line 2816 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 1186 "parser.y" /* yacc.c:1661  */
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
#line 2834 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 1200 "parser.y" /* yacc.c:1661  */
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

			if(constp->type != p->type)
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
#line 2880 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 1242 "parser.y" /* yacc.c:1661  */
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
#line 2898 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 1256 "parser.y" /* yacc.c:1661  */
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
#line 2918 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 1272 "parser.y" /* yacc.c:1661  */
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
#line 2939 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 1292 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv = (int*)realloc((int*)p->stepv,sizeof(int) * (p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2954 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 1303 "parser.y" /* yacc.c:1661  */
    {

		arr_val *p = NEW_VAL(arr_val);
		p->stepc = 1;
		p->stepv = NEW_VAL(int);
		p->stepv[0] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2968 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 1316 "parser.y" /* yacc.c:1661  */
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
#line 2987 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 1331 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3003 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 1343 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc=0;

		(yyval.v) = (void*)p;
	}
#line 3014 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 1353 "parser.y" /* yacc.c:1661  */
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
#line 3034 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 1369 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3050 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 1384 "parser.y" /* yacc.c:1661  */
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
#line 3068 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 1398 "parser.y" /* yacc.c:1661  */
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
#line 3086 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 1412 "parser.y" /* yacc.c:1661  */
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
#line 3104 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 1426 "parser.y" /* yacc.c:1661  */
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
#line 3122 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 1440 "parser.y" /* yacc.c:1661  */
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
#line 3140 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 1454 "parser.y" /* yacc.c:1661  */
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
#line 3158 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 1468 "parser.y" /* yacc.c:1661  */
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
#line 3176 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 1482 "parser.y" /* yacc.c:1661  */
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
#line 3194 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 1496 "parser.y" /* yacc.c:1661  */
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
#line 3212 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 1510 "parser.y" /* yacc.c:1661  */
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
#line 3231 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 1525 "parser.y" /* yacc.c:1661  */
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
#line 3250 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 1540 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(v1);
		(yyval.v) = (yyvsp[-1].v);
	}
#line 3260 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 1546 "parser.y" /* yacc.c:1661  */
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
#line 3277 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 1559 "parser.y" /* yacc.c:1661  */
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
#line 3295 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 1573 "parser.y" /* yacc.c:1661  */
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
#line 3313 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 1587 "parser.y" /* yacc.c:1661  */
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
#line 3330 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 1600 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[0].v);
	}
#line 3338 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 1604 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0
		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
		p->listc = 0;

		symbol_list* sym=find_symbol(p->name);

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
				q->kind=KIND_RVAL;
				q->value= (void*)p;
			}
		}

		(yyval.v) = (void*)q;
	}
#line 3377 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 1639 "parser.y" /* yacc.c:1661  */
    {
		// check func id exist and argu form correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3412 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 1670 "parser.y" /* yacc.c:1661  */
    {
		// check arr id exist and dimention correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3442 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 1699 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[0].v);
		p->name = strdup((yyvsp[-1].str));
		
		(yyval.v) = (void*)p;
	}
#line 3453 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 1709 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-3].v);
		p->listc += 1;
		(yyval.v) =(void*)p;
	}
#line 3463 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 1715 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc = 1;

		(yyval.v) = (void*)p;
	}
#line 3474 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 1725 "parser.y" /* yacc.c:1661  */
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
#line 3494 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 1741 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-3].str));
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)((yyvsp[-1].v));

		(yyval.v) = (void*)p;

	}
#line 3509 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 1752 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-2].str));
		p->listc = 0;

		(yyval.v) = (void*)p;
	}
#line 3521 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 1763 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)(yyvsp[-1].v));
		p->listv = (void*)co;

		(yyval.v) = (void*)p;
	}
#line 3538 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 1776 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

		(yyval.v) = (void*)p;
	}
#line 3554 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 1797 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar((yyvsp[-1].v));
	}
#line 3563 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 1807 "parser.y" /* yacc.c:1661  */
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
#line 3582 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 1822 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
		
	}
#line 3592 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 1828 "parser.y" /* yacc.c:1661  */
    {
		const_val* con=(const_val*)(yyvsp[-1].v);
		check_and_set_scalar(con);
	}
#line 3601 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 1836 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0

		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
		p->listc = 0;

		symbol_list* sym=find_symbol(p->name);

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
				q->kind=KIND_LVAL;
				q->value= (void*)p;
			}
		}

		(yyval.v) = (void*)q;
	}
#line 3641 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 1872 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3670 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 1906 "parser.y" /* yacc.c:1661  */
    {
		const_val *con =(const_val*)(yyvsp[0].v);
		if(con->type!=TYPE_BOOL)
			dump_error(ERROR_NO_BOOL);
		else
		{
			check_and_set_scalar(con);
		}
	}
#line 3684 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 1918 "parser.y" /* yacc.c:1661  */
    { isInLoop+=1;}
#line 3690 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 1918 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3696 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 1919 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3702 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 1919 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3708 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 1923 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3714 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 1923 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3720 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 1924 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 3726 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 1924 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 3732 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 1929 "parser.y" /* yacc.c:1661  */
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
#line 3751 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 1944 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3783 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 1972 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[0].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3815 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 2000 "parser.y" /* yacc.c:1661  */
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
#line 3834 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 2019 "parser.y" /* yacc.c:1661  */
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
#line 3853 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 2034 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-1].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3885 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 2062 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-1].v);
		symbol_list* sym=find_symbol(p->name);

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
#line 3917 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 2090 "parser.y" /* yacc.c:1661  */
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
#line 3936 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 2110 "parser.y" /* yacc.c:1661  */
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
#line 3955 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 2125 "parser.y" /* yacc.c:1661  */
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
#line 3974 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 2144 "parser.y" /* yacc.c:1661  */
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
#line 3993 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 171:
#line 2159 "parser.y" /* yacc.c:1661  */
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
#line 4012 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 172:
#line 2176 "parser.y" /* yacc.c:1661  */
    {
		const_val *exp=(const_val*)(yyvsp[-1].v);
		if(exp->kind==KIND_RVAL)
		{
			invo_val* exp_invo=(invo_val*)exp->value;
			if(exp_invo->listc!=0)
				dump_error(ERROR_ARR_STEP);
		}
	}
#line 4026 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 173:
#line 2186 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4035 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 174:
#line 2191 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4044 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 4048 "parser.tab.c" /* yacc.c:1661  */
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
#line 2199 "parser.y" /* yacc.c:1906  */


symbol_list* find_symbol(char* name)
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
		output->kind=KIND_RVAL;
		output->value= a->value;
	}
	return output;

}

const_val *geneValConst(const_val *a, const_val *b)
{
	const_val *output =NEW_VAL(const_val);

	int type=TYPE_DOUBLE+1;
	int ch=0;
	if(a->type<=TYPE_DOUBLE && a->type > type)
		type=a->type , ch+=1;
	if(b->type<=TYPE_DOUBLE && b->type > type)
		type=a->type , ch+=2;

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
		symbol_list *list=find_symbol( ((invo_val*)a->value)->name );
		id_val *id=(id_val*)list->val;
		if(id->kind==KIND_FUNCTION) return 1;
		else
		{
			if( ((invo_val*)a->value)->listc==0 ) return 1;
		}
		((invo_val*)a->value)->listc=0;
		dump_error(ERROR_ARR_STEP);
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

int check_type_one(const_val *a, const_val *b,int m_type)
{
	if(a->type!=m_type || b->type!=m_type) return 0;
	return 1;
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
		return 1;
	}
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
	printf("///////////////////// error in line:%d ---> %d //////////////////\n",linenum,error);

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

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );



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