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
	KIND_RVAL
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
int find_id_in_table(char* in,int *re_type);
int find_func_in_table(invo_val *in,int *re_type);
int find_arr_in_table(invo_val *in, int *re_type);
arr_val* count_arr_ref(char* name);

int is_const_var(char* name);


int yyerror( char *msg );
int main( int argc, char **argv );
int yylex();


#line 217 "parser.tab.c" /* yacc.c:339  */

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
#line 152 "parser.y" /* yacc.c:355  */

	char* str;
	void* v;
	int c_type;

#line 292 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   676

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
       0,   203,   203,   204,   205,   206,   210,   211,   212,   213,
     214,   215,   219,   220,   221,   222,   226,   231,   254,   230,
     262,   286,   261,   294,   311,   293,   319,   342,   318,   350,
     374,   349,   382,   399,   381,   410,   409,   421,   420,   431,
     432,   436,   437,   438,   439,   445,   444,   471,   470,   496,
     495,   515,   514,   540,   539,   566,   565,   587,   599,   615,
     631,   648,   659,   671,   689,   698,   707,   717,   726,   736,
     745,   758,   764,   770,   776,   785,   797,   809,   820,   834,
     852,   871,   888,   905,   952,   967,  1010,  1028,  1046,  1067,
    1085,  1102,  1119,  1136,  1178,  1192,  1234,  1248,  1264,  1284,
    1295,  1308,  1323,  1335,  1345,  1361,  1376,  1424,  1472,  1520,
    1568,  1614,  1648,  1682,  1717,  1751,  1785,  1819,  1823,  1850,
    1896,  1941,  1964,  1969,  1992,  2009,  2034,  2045,  2051,  2061,
    2077,  2088,  2099,  2112,  2127,  2128,  2129,  2130,  2131,  2132,
    2133,  2139,  2163,  2176,  2189,  2212,  2238,  2239,  2243,  2247,
    2247,  2248,  2248,  2248,  2252,  2252,  2253,  2253,  2257,  2258,
    2259,  2260,  2261,  2265,  2266,  2267,  2268,  2274,  2275,  2276,
    2280,  2281,  2284,  2294,  2299
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
      76,  -231,  -231,     1,    21,    76,    76,  -231,    24,    34,
    -231,    45,  -231,    76,  -231,  -231,    76,  -231,  -231,  -231,
     149,    50,    40,    13,    86,    76,  -231,  -231,  -231,     3,
    -231,  -231,    96,   284,   165,   195,     4,   153,    51,    85,
       1,    -6,   127,    91,   -12,  -231,  -231,  -231,  -231,   284,
     284,   284,  -231,  -231,  -231,  -231,  -231,   318,  -231,  -231,
    -231,  -231,   132,   110,  -231,  -231,   284,   231,   112,     1,
      52,   107,    79,  -231,  -231,  -231,  -231,   153,   120,   115,
      57,   125,  -231,   108,  -231,   100,   284,   122,  -231,   600,
     642,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,  -231,  -231,   145,   225,   103,   339,
    -231,  -231,   110,   154,   157,    89,   164,  -231,  -231,  -231,
    -231,   155,  -231,  -231,   182,  -231,   200,   201,   197,   202,
    -231,   360,   284,   273,   284,  -231,   630,   642,    54,    54,
      54,    54,    54,    54,   233,   233,  -231,  -231,  -231,  -231,
    -231,   284,   381,  -231,  -231,  -231,  -231,   170,  -231,  -231,
     206,   215,   218,  -231,  -231,   209,   217,   220,  -231,  -231,
     219,   257,  -231,  -231,   402,  -231,   302,   423,  -231,  -231,
    -231,  -231,   209,   230,   236,  -231,  -231,   -16,   280,   284,
     242,  -231,   250,   251,   260,   268,   284,   270,  -231,  -231,
     271,   209,   306,  -231,   500,   269,  -231,  -231,   274,  -231,
    -231,  -231,  -231,  -231,  -231,   209,  -231,   276,  -231,  -231,
    -231,  -231,  -231,   275,  -231,  -231,   209,   279,  -231,   272,
     520,   284,   299,   284,   312,  -231,  -231,   540,   209,   283,
    -231,  -231,  -231,   240,  -231,   284,   209,   314,  -231,  -231,
     209,   315,  -231,  -231,   617,   301,  -231,   319,   -12,   316,
     311,   326,   312,  -231,   163,  -231,   560,   335,  -231,   336,
    -231,   299,   361,  -231,  -231,   284,   243,   337,   333,  -231,
    -231,  -231,  -231,   374,   359,   299,   444,   280,   580,  -231,
     284,   299,   284,  -231,  -231,   352,   362,   280,   280,   458,
    -231,   363,   284,  -231,   354,   371,  -231,   376,   472,   299,
     284,  -231,  -231,  -231,  -231,   486,   299,   412,  -231
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
    -231,  -231,   405,  -231,  -191,   117,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -188,  -231,
    -231,  -134,   181,   124,  -231,  -231,  -231,  -231,  -231,  -231,
     385,   -13,  -231,     9,  -231,   364,  -231,   -35,   -34,   -31,
     -26,  -231,  -231,   141,   394,   325,  -231,   -33,  -111,  -231,
    -230,  -231,  -182,  -231,  -187,  -231,  -220,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,   140,  -231,  -231
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
      85,    12,     8,    70,    85,     8,    86,    80,  -144,    20,
      86,    81,   277,   109,     8,    82,   117,   118,    42,    22,
      39,    68,    73,    74,   256,    42,    75,   260,   223,    42,
      23,    76,   131,   133,   205,    35,   115,    37,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   205,   301,   241,   152,   278,    36,   228,    42,     1,
       2,   247,   242,   283,    99,   100,   101,   102,   103,   116,
     205,    38,   251,    82,   124,    77,     3,   293,   125,   174,
     295,   176,    43,   300,   205,    44,    45,    46,    47,    48,
     304,   295,   267,    45,    46,   205,   269,     6,   177,   119,
     120,   314,    13,   228,     7,   -49,   160,   205,   318,    14,
     125,    49,    83,    26,    84,   205,    50,   130,   106,   205,
      27,    10,    26,   153,   154,    51,    15,    19,   107,    27,
     128,   228,   -55,   205,    19,   123,   230,    28,   122,    45,
      46,    47,    48,   237,   134,   -47,    28,     2,   187,    45,
      46,    47,    48,   188,   189,   190,   228,   191,   192,   193,
     194,   195,   196,     3,    71,    29,   228,   228,   149,    30,
      31,    32,   158,    33,    49,   163,   164,   159,   254,    50,
     254,   197,   279,   170,   -53,    60,    61,    62,    51,    63,
     180,   181,   266,     2,   187,    45,    46,    47,    48,   188,
     189,   190,   -45,   191,   192,   193,   194,   195,   196,     3,
      44,    45,    46,    47,    48,    64,    65,    32,   168,    66,
      49,   169,   286,   288,   171,    50,   -51,   197,    44,    45,
      46,    47,    48,   185,    51,   213,    49,   299,   186,   254,
     214,    50,   216,   217,   150,   101,   102,   103,   224,   308,
      51,   110,   111,    62,    49,   112,   225,   315,   231,    50,
      30,    31,    32,   287,    33,   227,   233,   234,    51,    44,
      45,    46,    47,    48,    91,    92,    93,    94,    95,    96,
     235,    97,    98,    99,   100,   101,   102,   103,   236,   -37,
     240,   243,   252,  -145,   249,    49,   175,   258,   245,   248,
      50,    86,   265,    91,    92,    93,    94,    95,    96,    51,
      97,    98,    99,   100,   101,   102,   103,   197,   271,    91,
      92,    93,    94,    95,    96,   220,    97,    98,    99,   100,
     101,   102,   103,   268,   270,   275,   273,   274,   104,   105,
      91,    92,    93,    94,    95,    96,   276,    97,    98,    99,
     100,   101,   102,   103,   281,   282,   284,   290,   289,   155,
     156,    91,    92,    93,    94,    95,    96,   291,    97,    98,
      99,   100,   101,   102,   103,   292,   302,   172,   310,   303,
     307,   173,    91,    92,    93,    94,    95,    96,   311,    97,
      98,    99,   100,   101,   102,   103,   312,  -170,    25,   264,
     178,    69,   179,    91,    92,    93,    94,    95,    96,    67,
      97,    98,    99,   100,   101,   102,   103,   157,   305,   218,
       0,   121,     0,   219,    91,    92,    93,    94,    95,    96,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     298,    91,    92,    93,    94,    95,    96,     0,    97,    98,
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
      36,     0,    13,    36,    36,    16,    42,    40,    44,     5,
      42,    37,   262,    66,    25,    41,    71,    71,    29,     5,
      37,    37,    77,    77,   232,    36,    77,   234,   182,    40,
       5,    77,    85,    86,   165,     5,    69,    44,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   182,   292,   264,   107,   262,    36,   188,    69,     3,
       4,   215,   264,   271,    30,    31,    32,    33,    34,    37,
     201,     5,   226,    41,    37,    44,    20,   285,    41,   132,
     287,   134,     6,   291,   215,     5,     6,     7,     8,     9,
     297,   298,   246,     6,     7,   226,   250,     0,   151,    40,
      41,   309,     5,   234,     0,    40,    37,   238,   316,     5,
      41,    31,     5,    16,    43,   246,    36,    37,     6,   250,
      16,     0,    25,    40,    41,    45,     5,     6,    38,    25,
      42,   262,    40,   264,    13,    40,   189,    16,    38,     6,
       7,     8,     9,   196,    42,    40,    25,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   287,    14,    15,    16,
      17,    18,    19,    20,    31,    36,   297,   298,    43,    40,
      41,    42,    38,    44,    31,    40,    41,    40,   231,    36,
     233,    38,    39,     6,    40,    40,    41,    42,    45,    44,
      40,    41,   245,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    40,    14,    15,    16,    17,    18,    19,    20,
       5,     6,     7,     8,     9,    40,    41,    42,    38,    44,
      31,    40,   275,   276,    42,    36,    40,    38,     5,     6,
       7,     8,     9,    38,    45,    38,    31,   290,    40,   292,
      40,    36,    43,     6,    39,    32,    33,    34,    38,   302,
      45,    40,    41,    42,    31,    44,    40,   310,    36,    36,
      40,    41,    42,    40,    44,     5,    36,    36,    45,     5,
       6,     7,     8,     9,    21,    22,    23,    24,    25,    26,
      40,    28,    29,    30,    31,    32,    33,    34,    40,    39,
      39,     5,    40,    44,    39,    31,    43,     5,    44,    43,
      36,    42,    39,    21,    22,    23,    24,    25,    26,    45,
      28,    29,    30,    31,    32,    33,    34,    38,    37,    21,
      22,    23,    24,    25,    26,    43,    28,    29,    30,    31,
      32,    33,    34,    39,    39,    44,    37,    41,    40,    41,
      21,    22,    23,    24,    25,    26,    40,    28,    29,    30,
      31,    32,    33,    34,    39,    39,    15,    44,    41,    40,
      41,    21,    22,    23,    24,    25,    26,    13,    28,    29,
      30,    31,    32,    33,    34,    36,    44,    37,    44,    37,
      37,    41,    21,    22,    23,    24,    25,    26,    37,    28,
      29,    30,    31,    32,    33,    34,    40,     5,    13,   238,
      39,    36,    41,    21,    22,    23,    24,    25,    26,    35,
      28,    29,    30,    31,    32,    33,    34,   112,   298,    37,
      -1,    77,    -1,    41,    21,    22,    23,    24,    25,    26,
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
      40,    39,    39,    64,    15,   104,    93,    40,    93,    41,
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
#line 231 "parser.y" /* yacc.c:1661  */
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
#line 1707 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 254 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1715 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 258 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1723 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 262 "parser.y" /* yacc.c:1661  */
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
#line 1751 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 286 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1759 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 290 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1767 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 294 "parser.y" /* yacc.c:1661  */
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
#line 1788 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 311 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1796 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 315 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1804 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 319 "parser.y" /* yacc.c:1661  */
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
#line 1831 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 342 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-6].str));
	}
#line 1839 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 346 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1847 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 350 "parser.y" /* yacc.c:1661  */
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
#line 1875 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 374 "parser.y" /* yacc.c:1661  */
    {
		add_newtable_with_argu((yyvsp[-5].str));
	}
#line 1883 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 378 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1891 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 382 "parser.y" /* yacc.c:1661  */
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
#line 1912 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 399 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1920 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 403 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1928 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 410 "parser.y" /* yacc.c:1661  */
    { 
		add_newtable();
	}
#line 1936 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 414 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol)
		{
			dump_cur_table();
		}
	}
#line 1947 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 421 "parser.y" /* yacc.c:1661  */
    {
		add_newtable();
	}
#line 1955 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 425 "parser.y" /* yacc.c:1661  */
    {
		if(Opt_symbol) dump_cur_table();
	}
#line 1963 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 445 "parser.y" /* yacc.c:1661  */
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
#line 1992 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 471 "parser.y" /* yacc.c:1661  */
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
#line 2020 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 496 "parser.y" /* yacc.c:1661  */
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
#line 2042 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 515 "parser.y" /* yacc.c:1661  */
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
#line 2070 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 540 "parser.y" /* yacc.c:1661  */
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
#line 2099 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 566 "parser.y" /* yacc.c:1661  */
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
#line 2120 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 588 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = (func_val*)(yyvsp[-2].v);

		argu_val *co =(argu_val*)(yyvsp[-1].v);

		p->argc+=1;
		p->argv = (argu_val*)realloc((argu_val*)p->argv,sizeof(argu_val)*(p->argc));
		((argu_val*)p->argv)[p->argc-1] = *co;

		(yyval.v) = (void*)p;
	}
#line 2136 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 600 "parser.y" /* yacc.c:1661  */
    {
		func_val *p = NEW_VAL(func_val);

		argu_val *co = (argu_val*)(yyvsp[-1].v);

		p->argc = 1;
		p->argv =NEW_VAL(argu_val);

		p->argv[0] = *co;

		(yyval.v) = (void*)p;
	}
#line 2153 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 616 "parser.y" /* yacc.c:1661  */
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
#line 2173 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 632 "parser.y" /* yacc.c:1661  */
    {
		argu_val *p = NEW_VAL(argu_val);
		p->name=strdup((yyvsp[-1].str));

		p->val=NEW_VAL(id_val);
		p->val->kind=KIND_PARAMETER;
		p->val->type=(yyvsp[-2].c_type);

		p->val->list=(yyvsp[0].v);

		(yyval.v) = (void*)p;
	}
#line 2190 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 649 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv=(int*)realloc((int*)p->stepv,sizeof(int)*(p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2205 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 660 "parser.y" /* yacc.c:1661  */
    {
		arr_val* p =NEW_VAL(arr_val);
		p->stepc=1;
		p->stepv=NEW_VAL(int);
		p->stepv[0]= atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2218 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 672 "parser.y" /* yacc.c:1661  */
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
#line 2237 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 690 "parser.y" /* yacc.c:1661  */
    {
		(yyval.c_type) = TYPE_VOID;
	}
#line 2245 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 699 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val *p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2258 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 708 "parser.y" /* yacc.c:1661  */
    {
		const_val *in = (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(int*)p->list= -*((int*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2272 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 718 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2285 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 727 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		*(double*)p->list= -*((double*)p->list);
		(yyval.v) = (void*)p;
	}
#line 2299 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 737 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2312 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 746 "parser.y" /* yacc.c:1661  */
    {
		const_val *in= (const_val*)(yyvsp[0].v);
		id_val* p = NEW_VAL(id_val);
		p->kind=KIND_CONSTANT;
		p->type=in->type;
		p->list=in->value;
		(yyval.v) = (void*)p;
	}
#line 2325 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 759 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2335 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 765 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2345 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 771 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2355 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 777 "parser.y" /* yacc.c:1661  */
    {
		const_val* p = (const_val*)(yyvsp[0].v);
		p->kind=KIND_CONST_VAL;
		(yyval.v) = (void*)p;
	}
#line 2365 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 786 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		int *val = NEW_VAL(int);
		*val = atoi((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_INT;
		(yyval.v) = (void*)p;
	}
#line 2378 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 798 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		float *val = NEW_VAL(float);
		*val = (float)atof((yyvsp[0].str));
		p->value = (void*)val;
		p->type = TYPE_DOUBLE;
		(yyval.v) = (void*)p;
	}
#line 2391 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 810 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_BOOL;
		(yyval.v) = (void*)p;
	}
#line 2403 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 821 "parser.y" /* yacc.c:1661  */
    {
		const_val *p = NEW_VAL(const_val);
		char *ou=strdup((yyvsp[0].str));
		p->value = (void*) ou;
		p->type = TYPE_STRING;
		(yyval.v) = (void*)p;
	}
#line 2415 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 835 "parser.y" /* yacc.c:1661  */
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
#line 2437 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 853 "parser.y" /* yacc.c:1661  */
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
#line 2460 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 872 "parser.y" /* yacc.c:1661  */
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
#line 2481 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 889 "parser.y" /* yacc.c:1661  */
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
#line 2502 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 906 "parser.y" /* yacc.c:1661  */
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
#line 2553 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 953 "parser.y" /* yacc.c:1661  */
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
#line 2572 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 968 "parser.y" /* yacc.c:1661  */
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
#line 2619 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 1011 "parser.y" /* yacc.c:1661  */
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
#line 2638 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 1029 "parser.y" /* yacc.c:1661  */
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
#line 2660 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 1047 "parser.y" /* yacc.c:1661  */
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
#line 2682 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 1068 "parser.y" /* yacc.c:1661  */
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
#line 2704 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 1086 "parser.y" /* yacc.c:1661  */
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
#line 2725 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 1103 "parser.y" /* yacc.c:1661  */
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
#line 2746 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 1120 "parser.y" /* yacc.c:1661  */
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
#line 2767 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 1137 "parser.y" /* yacc.c:1661  */
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
#line 2813 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 1179 "parser.y" /* yacc.c:1661  */
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
#line 2831 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 1193 "parser.y" /* yacc.c:1661  */
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
#line 2877 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 1235 "parser.y" /* yacc.c:1661  */
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
#line 2895 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 1249 "parser.y" /* yacc.c:1661  */
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
#line 2915 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 1265 "parser.y" /* yacc.c:1661  */
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
#line 2936 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 1285 "parser.y" /* yacc.c:1661  */
    {
		arr_val *p = (arr_val*)(yyvsp[-3].v);

		p->stepc+=1;
		p->stepv = (int*)realloc((int*)p->stepv,sizeof(int) * (p->stepc));
		((int*)p->stepv)[p->stepc-1] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;

	}
#line 2951 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 1296 "parser.y" /* yacc.c:1661  */
    {

		arr_val *p = NEW_VAL(arr_val);
		p->stepc = 1;
		p->stepv = NEW_VAL(int);
		p->stepv[0] = atoi((yyvsp[-1].str));

		(yyval.v) = (void*)p;
	}
#line 2965 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 1309 "parser.y" /* yacc.c:1661  */
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
#line 2984 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 1324 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3000 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 1336 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc=0;

		(yyval.v) = (void*)p;
	}
#line 3011 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 1346 "parser.y" /* yacc.c:1661  */
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
#line 3031 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 1362 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=NEW_VAL(invo_val);
		const_val *co=(const_val*)(yyvsp[-1].v);
		p->listc=1;
		const_val *q=NEW_VAL(const_val);
		q[0]=*co;

		p->listv=(void*)q;

		(yyval.v) =(void*)p;
	}
#line 3047 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 1377 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = (v1->type>v2->type)?(v1->type):(v2->type);

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			p->type = TYPE_INT;
			dump_error(ERROR_TYPE_ERROR);
		}

		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}


		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;
	}
#line 3099 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 1425 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = (v1->type>v2->type)?(v1->type):(v2->type);

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			p->type = TYPE_INT;
			dump_error(ERROR_TYPE_ERROR);
		}

		
		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;
	}
#line 3151 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 1473 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = (v1->type>v2->type)?(v1->type):(v2->type);

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			p->type = TYPE_INT;
			dump_error(ERROR_TYPE_ERROR);
		}


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;
	}
#line 3203 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 1521 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = (v1->type>v2->type)?(v1->type):(v2->type);

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			p->type = TYPE_INT;
			dump_error(ERROR_TYPE_ERROR);
		}


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;
	}
#line 3255 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 1569 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		if(v1->type!=TYPE_INT || v2->type!=TYPE_INT)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		const_val *p=NEW_VAL(const_val);
		p->type=TYPE_INT;


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;

	}
#line 3305 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 1615 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			dump_error(ERROR_TYPE_ERROR);
		}


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3343 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 1649 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		
		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3381 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 1683 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		
		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3420 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 1718 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			dump_error(ERROR_TYPE_ERROR);
		}


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3458 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 1752 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			if(v1->type!=TYPE_BOOL || v2->type!=TYPE_BOOL);
				dump_error(ERROR_TYPE_ERROR);
		}

		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3496 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 1786 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = TYPE_BOOL;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID ||
			v2->type==TYPE_BOOL || v2->type==TYPE_STRING || v2->type==TYPE_VOID)
		{
			if(v1->type!=TYPE_BOOL || v2->type!=TYPE_BOOL);
				dump_error(ERROR_TYPE_ERROR);
		}

		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=KIND_CONST_VAL;
		p->value=(void*)strdup("true");

		(yyval.v) = (void*)p;
	}
#line 3534 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 1820 "parser.y" /* yacc.c:1661  */
    {
		(yyval.v) = (yyvsp[-1].v);
	}
#line 3542 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 1824 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);

		const_val *p=NEW_VAL(const_val);

		p->type = v1->type;

		if(v1->type==TYPE_BOOL || v1->type==TYPE_STRING || v1->type==TYPE_VOID)
		{
			p->type = TYPE_INT;
			dump_error(ERROR_TYPE_ERROR);
		}


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		p->kind=v1->kind;
		p->value=v1->value;

		(yyval.v) = (void*)p;
	}
#line 3573 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 1851 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		if(v1->type!=TYPE_BOOL || v2->type!=TYPE_BOOL)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		const_val *p=NEW_VAL(const_val);
		p->type=TYPE_BOOL;

		
		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;

	}
#line 3623 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 1897 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[-2].v);
		const_val *v2=(const_val*)(yyvsp[0].v);

		if(v1->type!=TYPE_BOOL || v2->type!=TYPE_BOOL)
		{
			dump_error(ERROR_TYPE_ERROR);
		}

		const_val *p=NEW_VAL(const_val);
		p->type=TYPE_BOOL;


		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}
		if( v2->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v2->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		if(v1->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v1->value;
		}
		else if(v2->kind==KIND_RVAL)
		{
			p->kind=KIND_RVAL;
			p->value=v2->value;
		}
		else
		{
			p->kind=KIND_CONST_VAL;
			p->value=v1->value;
		}

		(yyval.v) = (void*)p;
	}
#line 3672 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 1942 "parser.y" /* yacc.c:1661  */
    {
		const_val *v1=(const_val*)(yyvsp[0].v);

		if(v1->type!=TYPE_BOOL)
		{
			dump_error(ERROR_TYPE_ERROR);
		}
		
		if( v1->kind==KIND_RVAL )
		{
			invo_val *invo = (invo_val*)v1->value;
			if(invo->listc !=0) dump_error(ERROR_ARR_STEP);
			invo->listc=0;
		}

		const_val *p=NEW_VAL(const_val);
		p->type=TYPE_BOOL;
		p->kind=v1->kind;
		p->value=v1->value;

		(yyval.v) =(void*)p;
	}
#line 3699 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 1965 "parser.y" /* yacc.c:1661  */
    {
		// const_val
		(yyval.v) = (yyvsp[0].v);
	}
#line 3708 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 1970 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0
		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
		p->listc = 0;

		int *re_type=NEW_VAL(int);
		*re_type=0;

		arr_val* orig_arr = count_arr_ref(p->name);
		
		int result = find_arr_in_table(p,re_type);

		if(result!=NO_ERROR) dump_error(result);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_RVAL;
		q->type= *re_type;
		q->value = (void*)p;

		(yyval.v) = (void*)q;
	}
#line 3735 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 1993 "parser.y" /* yacc.c:1661  */
    {
		// check func id exist and argu form correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);

		int *re_type=NEW_VAL(int);
		*re_type=0;
		int result= find_func_in_table(p,re_type);
		if(result!=NO_ERROR) dump_error(result);

		const_val *q = NEW_VAL(const_val);
		q->kind = KIND_RVAL;
		q->type = *re_type;
		q->value = (void*)p;

		(yyval.v) = (void*)q;
	}
#line 3756 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 2010 "parser.y" /* yacc.c:1661  */
    {
		// check arr id exist and dimention correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);

		int *re_type=NEW_VAL(int);
		*re_type=0;

		arr_val* orig_arr = count_arr_ref(p->name);

		int result = find_arr_in_table(p,re_type);


		if(result!=NO_ERROR) dump_error(result);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_RVAL;
		q->type= *re_type;
		q->value = (void*)p;

		(yyval.v) = (void*)q;
	}
#line 3782 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 2035 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[0].v);
		p->name = strdup((yyvsp[-1].str));
		

		(yyval.v) = (void*)p;
	}
#line 3794 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 2046 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p=(invo_val*)(yyvsp[-3].v);
		p->listc += 1;
		(yyval.v) =(void*)p;
	}
#line 3804 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 2052 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p =NEW_VAL(invo_val);
		p->listc = 1;

		(yyval.v) = (void*)p;
	}
#line 3815 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 2062 "parser.y" /* yacc.c:1661  */
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
#line 3835 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 2078 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-3].str));
		p->listc = 1;
		p->listv = malloc(sizeof(const_val));
		((const_val*)p->listv)[0] = *(const_val*)((yyvsp[-1].v));

		(yyval.v) = (void*)p;

	}
#line 3850 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 2089 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->name = strdup((yyvsp[-2].str));
		p->listc = 0;

		(yyval.v) = (void*)p;
	}
#line 3862 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 2100 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = (invo_val*)(yyvsp[-2].v);
		p->listc+=1;

		const_val *co = (const_val*)p->listv;

		co = (const_val*)realloc(co,sizeof(const_val)*(p->listc));
		co[p->listc-1]=*((const_val*)(yyvsp[-1].v));
		p->listv = (void*)co;

		(yyval.v) = (void*)p;
	}
#line 3879 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 2113 "parser.y" /* yacc.c:1661  */
    {
		invo_val *p = NEW_VAL(invo_val);
		p->listc = 1;

		const_val *co =NEW_VAL(const_val);
		co[0] = *((const_val*)(yyvsp[-1].v));

		p->listv=(void*)co;

		(yyval.v) = (void*)p;
	}
#line 3895 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 2140 "parser.y" /* yacc.c:1661  */
    {
		const_val *exp = (const_val*)(yyvsp[-1].v);
		const_val *ref = (const_val*)(yyvsp[-3].v);

		invo_val *ref_invo = (invo_val*)ref->value;
		if(is_const_var(ref_invo->name))
			dump_error(ERROR_ASSIGN_CONST);
		else
		{
			if(ref_invo -> listc !=0)
				dump_error(ERROR_ARR_STEP);
		}

		if(exp->kind==KIND_RVAL)
		{
			invo_val* exp_invo = (invo_val*)exp->value;
			if(exp_invo->listc!=0)
				dump_error(ERROR_ARR_STEP);
		}

		if(exp->type != ref->type)
			dump_error(ERROR_TYPE_ERROR);
	}
#line 3923 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 2164 "parser.y" /* yacc.c:1661  */
    {
		const_val *exp = (const_val*)(yyvsp[-1].v);
		if(exp->kind==KIND_RVAL)
		{
			invo_val *exp_invo = (invo_val*)exp->value;
			if(!is_const_var(exp_invo->name))
			{
				if(exp_invo->listc!=0)
					dump_error(ERROR_ARR_STEP);
			}
		}
	}
#line 3940 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 2177 "parser.y" /* yacc.c:1661  */
    {
		const_val *ref =(const_val*)(yyvsp[-1].v);
		invo_val *ref_invo = (invo_val*)ref->value;
		if(!is_const_var(ref_invo->name))
		{
			if(ref_invo->listc!=0)
				dump_error(ERROR_ARR_STEP);
		}
	}
#line 3954 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 2190 "parser.y" /* yacc.c:1661  */
    {
		// same with array but step is 0
		invo_val *p=NEW_VAL(invo_val);
		p->name = strdup((yyvsp[0].str));
		p->listc = 0;

		int *re_type=NEW_VAL(int);
		*re_type=0;

		arr_val* orig_arr = count_arr_ref(p->name);
		
		int result = find_arr_in_table(p,re_type);

		if(result!=NO_ERROR) dump_error(result);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_RVAL;
		q->type= *re_type;
		q->value = (void*)p;

		(yyval.v) = (void*)q;
	}
#line 3981 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 2213 "parser.y" /* yacc.c:1661  */
    {
		// check arr id exist and dimention correct;
		invo_val *p=(invo_val*)(yyvsp[0].v);

		int *re_type=NEW_VAL(int);
		*re_type=0;

		arr_val* orig_arr = count_arr_ref(p->name);

		int result = find_arr_in_table(p,re_type);


		if(result!=NO_ERROR) dump_error(result);

		const_val *q= NEW_VAL(const_val);
		q->kind= KIND_RVAL;
		q->type= *re_type;
		q->value = (void*)p;

		(yyval.v) = (void*)q;
	}
#line 4007 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 2247 "parser.y" /* yacc.c:1661  */
    { isInLoop+=1;}
#line 4013 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 2247 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 4019 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 2248 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 4025 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 2248 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 4031 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 2252 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 4037 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 2252 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 4043 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 2253 "parser.y" /* yacc.c:1661  */
    {isInLoop+=1;}
#line 4049 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 2253 "parser.y" /* yacc.c:1661  */
    {isInLoop-=1;}
#line 4055 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 172:
#line 2285 "parser.y" /* yacc.c:1661  */
    {
		const_val *exp=(const_val*)(yyvsp[-1].v);
		if(exp->kind==KIND_RVAL)
		{
			invo_val* exp_invo=(invo_val*)exp->value;
			if(exp_invo->listc!=0)
				dump_error(ERROR_ARR_STEP);
		}
	}
#line 4069 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 173:
#line 2295 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4078 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 174:
#line 2300 "parser.y" /* yacc.c:1661  */
    {
		if(isInLoop<=0)
			dump_error(ERROR_JUMP_STATMENT);
	}
#line 4087 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 4091 "parser.tab.c" /* yacc.c:1661  */
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
#line 2308 "parser.y" /* yacc.c:1906  */



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

int find_id_in_table(char* in,int *re_type)
{
	symbol_table *p = cur_table;

	while(p!=NULL)
	{
		symbol_list* list = p->s_list;
		while(list!=NULL)
		{
			if(strcmp(list->name,in)==0)
			{
				id_val* pr = (id_val*)list->val;
				*re_type = pr->type;
				if(pr->kind!=KIND_VARIABLE && pr->kind!=KIND_PARAMETER )
				{
					return ERROR_ID_KIND;
				}
				else
				{
					return NO_ERROR;
				}
			}
			list=list->next;
		}
		p=p->next;
	}
	*re_type = TYPE_INT;
	return ERROR_ID_NO_FOUND;
}
int find_func_in_table(invo_val *in,int *re_type)
{
	symbol_table *p =cur_table;

	while(p!=NULL)
	{
		symbol_list* list = p->s_list;
		while(list!=NULL)
		{
			if(strcmp(list->name,in->name)==0)
			{
				id_val* pr = (id_val*)list->val;
				*re_type = pr->type;
				if(pr->kind!=KIND_FUNCTION)
					return ERROR_ID_KIND;
				else
				{
					// check argu;
					func_val* funcp= (func_val*)pr->list;

					if(funcp->argc != in->listc )
						return ERROR_FUNC_ARGU_NOT_MATCH;
					else
					{
						for(int t=0;t<funcp->argc;t++)
						{
							const_val *constp = ((const_val*)in->listv)+t;
							argu_val *argup = ((argu_val*)funcp->argv)+t;

							invo_val* source=(invo_val*)constp->value;
							arr_val* arr_source= count_arr_ref(source->name);
							arr_val* arr_func =  ((arr_val*)((id_val*)argup->val)->list);
							
							if(arr_func->stepc == source->listc)
							{
								for(int i1=0,i2=arr_source->stepc-source->listc;i1<arr_func->stepc;i1++,i2++)
								{
									if( arr_func->stepv[i1] != *(((int*)arr_source->stepv)+i2) )
										return ERROR_FUNC_ARGU_NOT_MATCH;
								}
							}
							else
								return ERROR_FUNC_ARGU_NOT_MATCH;
						}
						return NO_ERROR;
					}
				}
			}
			list=list->next;
		}
		p=p->next;
	}
	*re_type=TYPE_INT;
	return ERROR_ID_NO_FOUND;
}

int find_arr_in_table(invo_val *in, int *re_type)
{
	symbol_table *table = cur_table;
	while(table!=NULL)
	{
		symbol_list *list= table->s_list;
		while(list!=NULL)
		{
			if(strcmp(in->name,list->name)==0)
			{
				id_val *pr=(id_val*)list->val;
				*re_type = pr->type;


				if(pr->kind != KIND_VARIABLE && pr->kind != KIND_PARAMETER && pr->kind!=KIND_CONSTANT)
					return ERROR_ID_KIND;
				else
				{
					arr_val* arr_step=(arr_val*)pr->list;
					if(in->listc > arr_step->stepc)
						return ERROR_ARR_STEP;
					else
						in->listc = arr_step->stepc - in->listc;
				}
				return NO_ERROR;
			}
			list= list->next;
		}
		table=table->next;
	}
	*re_type=TYPE_INT;
	return ERROR_ID_NO_FOUND;
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
				if(pr->kind==KIND_PARAMETER || pr->kind==KIND_VARIABLE || pr->kind==KIND_CONSTANT)
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
