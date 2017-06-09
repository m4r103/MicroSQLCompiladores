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
#line 1 "sql.y" /* yacc.c:339  */

#include <stdio.h>
#include "sql.h"
int follow(int, int, int);

#line 72 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NAME = 258,
    STRING = 259,
    INTNUM = 260,
    BOOL = 261,
    APPROXNUM = 262,
    AUTO_INCREMENT = 263,
    CREATE = 264,
    DATABASE = 265,
    INDEX = 266,
    INSERT = 267,
    INTO = 268,
    VALUES = 269,
    PRIMARY = 270,
    KEY = 271,
    NULLX = 272,
    SCHEMA = 273,
    TABLE = 274,
    VARCHAR = 275,
    INTEGER = 276,
    INDEF = 277,
    ASC = 278,
    ORDER = 279,
    BY = 280,
    DESC = 281,
    SELECT = 282,
    FROM = 283,
    WHERE = 284,
    DELETE = 285,
    UPDATE = 286,
    SET = 287,
    OR = 288,
    ANDOP = 289,
    USERVAR = 290,
    NOT = 291,
    GT = 292,
    GE = 293,
    LT = 294,
    LE = 295,
    NE = 296,
    MOD = 297,
    nonassoc = 298,
    UMINUS = 299
  };
#endif
/* Tokens.  */
#define NAME 258
#define STRING 259
#define INTNUM 260
#define BOOL 261
#define APPROXNUM 262
#define AUTO_INCREMENT 263
#define CREATE 264
#define DATABASE 265
#define INDEX 266
#define INSERT 267
#define INTO 268
#define VALUES 269
#define PRIMARY 270
#define KEY 271
#define NULLX 272
#define SCHEMA 273
#define TABLE 274
#define VARCHAR 275
#define INTEGER 276
#define INDEF 277
#define ASC 278
#define ORDER 279
#define BY 280
#define DESC 281
#define SELECT 282
#define FROM 283
#define WHERE 284
#define DELETE 285
#define UPDATE 286
#define SET 287
#define OR 288
#define ANDOP 289
#define USERVAR 290
#define NOT 291
#define GT 292
#define GE 293
#define LT 294
#define LE 295
#define NE 296
#define MOD 297
#define nonassoc 298
#define UMINUS 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "sql.y" /* yacc.c:355  */

    int intval;
    double floatval;
    char *strval;
    int subtok;
    Symbol *sym;
    Inst *inst;
    Datum *const_val;
    Column *columnlist;
    Columnval *columnval;

#line 212 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    49,    39,     2,
      56,    57,    47,    45,    58,    46,    55,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    37,    40,    41,    42,    43,    44,    50,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    54,    55,    58,    59,    60,    61,    62,
      63,    64,    67,    68,    69,    70,    71,    72,    73,    74,
      77,    80,    81,    85,    88,    91,    94,    95,    98,    99,
     100,   103,   104,   107,   109,   110,   111,   112,   113,   115,
     116,   119,   122,   125,   126,   128,   129,   131,   132,   136,
     139,   143,   144,   146,   147,   149,   150,   152,   153,   154,
     156,   157,   158,   160,   162,   163,   167,   169,   173,   175,
     177,   178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "AUTO_INCREMENT", "CREATE", "DATABASE", "INDEX", "INSERT",
  "INTO", "VALUES", "PRIMARY", "KEY", "NULLX", "SCHEMA", "TABLE",
  "VARCHAR", "INTEGER", "INDEF", "ASC", "ORDER", "BY", "DESC", "SELECT",
  "FROM", "WHERE", "DELETE", "UPDATE", "SET", "OR", "ANDOP", "USERVAR",
  "'='", "NOT", "'|'", "'&'", "GT", "GE", "LT", "LE", "NE", "'+'", "'-'",
  "'*'", "'/'", "'%'", "MOD", "'^'", "nonassoc", "UMINUS", "';'", "'.'",
  "'('", "')'", "','", "$accept", "stmt_list", "expr", "stmt",
  "create_database_stmt", "create_table_stmt", "create_col_list",
  "create_definition", "column_list", "column_atts", "data_type",
  "insert_stmt", "opt_col_names", "insert_vals_list", "insert_vals",
  "select_stmt", "opt_where", "opt_orderby", "groupby_list",
  "opt_asc_desc", "select_expr_list", "select_expr", "table_references",
  "delete_stmt", "update_stmt", "update_asgn_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    61,   291,   124,    38,
     292,   293,   294,   295,   296,    43,    45,    42,    47,    37,
     297,    94,   298,   299,    59,    46,    40,    41,    44
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    50,     9,     5,    -2,    32,    19,   -10,   -58,   -58,
     -58,   -58,   -58,   -58,    56,    58,    73,    75,    26,   -58,
     -58,   -58,   -58,   -58,   -58,    63,    -7,   -58,    32,    40,
      70,   -58,    66,   -58,   -58,   -58,     2,    71,   118,    10,
      10,    10,    10,    10,    10,    10,    10,    32,    10,    97,
     125,   126,   -58,   127,    64,   128,   119,   -58,    43,    48,
      63,   -58,   -58,   -58,   -58,   -58,    97,   -58,    10,   108,
     -58,    98,   -11,    79,    80,    81,   120,    82,    51,   -58,
     -58,    53,    83,   108,    63,   115,   -58,    10,   138,   108,
      64,    86,   -58,   -58,   128,    87,   128,   -58,    64,   -58,
     141,    10,    88,   -58,    10,    63,   109,   -58,    55,   142,
      17,    57,   128,    59,   -58,   -58,    63,    61,    92,    30,
      91,    10,   -58,    93,   -58,   135,   -58,   136,   -58,    65,
     -58,   -58,    10,    10,   -58,   -58,   -58,    10,    63,   -58,
     -58,   -58,   -58,    63,    67,    30,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,    20,    23,
      41,    49,    66,    68,     0,     0,     0,     0,     5,     8,
       9,    11,    10,     7,    62,    63,     0,    60,     0,    64,
       0,     1,     0,     3,    21,    22,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     4,     0,     0,     0,     0,     6,    18,    19,
      12,    13,    14,    15,    16,    17,    51,    61,     0,    53,
      65,     0,    51,     0,     0,     0,     0,     0,     0,    26,
      31,     0,     0,    53,    52,     0,    67,     0,     0,    53,
       0,     0,    40,    34,     0,     0,     0,    24,     0,    44,
       0,     0,    42,    50,     0,    70,     0,    69,     0,     0,
      33,     0,     0,     0,    27,    32,    47,     0,     0,    57,
      54,     0,    25,     0,    37,     0,    36,     0,    30,     0,
      29,    45,     0,     0,    58,    59,    55,     0,    71,    39,
      38,    35,    28,    48,     0,    57,    46,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -39,   146,   -58,   -58,    68,    62,   -57,   -58,
     -58,   -58,   -58,   -58,    21,   -58,   -36,   -56,   -58,    12,
     -58,   107,    -4,   -58,   -58,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    25,     7,     8,     9,    78,    79,    81,   110,
      93,    10,    56,   102,   117,    11,    69,    86,   120,   136,
      26,    27,    30,    12,    13,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    59,    60,    61,    62,    63,    64,    65,    18,    19,
      20,    21,    22,    18,    19,    20,    21,    22,    68,    31,
       1,    47,    17,     2,    49,   124,    28,   103,     1,    84,
      83,     2,   125,   107,   126,    29,    89,   111,     3,   113,
      23,     4,     5,    66,    33,    23,     3,    88,   105,     4,
       5,    48,    24,   134,   127,   129,   135,    53,    54,    34,
      14,    35,   116,    39,    40,   119,    41,    74,    15,    16,
      42,    43,    44,    45,    46,    75,    36,    40,    37,    76,
      77,    38,   138,    42,    43,    44,    45,    46,    42,    43,
      44,    45,    46,   143,   116,    50,    39,    40,   145,    41,
      91,    92,    51,    42,    43,    44,    45,    46,    97,    98,
      99,   100,   122,    98,   128,   100,   130,   100,   131,   132,
      52,    57,   142,   100,   146,   132,    68,    55,    70,    71,
      73,    80,    85,    82,    87,    90,    95,    94,    96,   101,
     104,   106,   109,   112,   115,   121,   118,   123,   133,   137,
     139,   140,    32,   141,   144,    67,     0,   147,   108,     0,
     114
};

static const yytype_int16 yycheck[] =
{
      39,    40,    41,    42,    43,    44,    45,    46,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    29,     0,
       9,    28,    13,    12,    28,     8,    28,    83,     9,    68,
      66,    12,    15,    89,    17,     3,    72,    94,    27,    96,
      35,    30,    31,    47,    54,    35,    27,    58,    87,    30,
      31,    58,    47,    23,    37,   112,    26,    55,    56,     3,
      10,     3,   101,    33,    34,   104,    36,     3,    18,    19,
      40,    41,    42,    43,    44,    11,     3,    34,     3,    15,
      16,    55,   121,    40,    41,    42,    43,    44,    40,    41,
      42,    43,    44,   132,   133,    55,    33,    34,   137,    36,
      20,    21,    32,    40,    41,    42,    43,    44,    57,    58,
      57,    58,    57,    58,    57,    58,    57,    58,    57,    58,
      54,     3,    57,    58,    57,    58,    29,    56,     3,     3,
       3,     3,    24,    14,    36,    56,    16,    56,    56,    56,
      25,     3,    56,    56,     3,    36,    58,     5,    56,    58,
      57,    16,     6,    17,   133,    48,    -1,   145,    90,    -1,
      98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    12,    27,    30,    31,    60,    62,    63,    64,
      70,    74,    82,    83,    10,    18,    19,    13,     3,     4,
       5,     6,     7,    35,    47,    61,    79,    80,    28,     3,
      81,     0,    62,    54,     3,     3,     3,     3,    55,    33,
      34,    36,    40,    41,    42,    43,    44,    28,    58,    81,
      55,    32,    54,    55,    56,    56,    71,     3,    61,    61,
      61,    61,    61,    61,    61,    61,    81,    80,    29,    75,
       3,     3,    84,     3,     3,    11,    15,    16,    65,    66,
       3,    67,    14,    75,    61,    24,    76,    36,    58,    75,
      56,    20,    21,    69,    56,    16,    56,    57,    58,    57,
      58,    56,    72,    76,    25,    61,     3,    76,    65,    56,
      68,    67,    56,    67,    66,     3,    61,    73,    58,    61,
      77,    36,    57,     5,     8,    15,    17,    37,    57,    67,
      57,    57,    58,    56,    23,    26,    78,    58,    61,    57,
      16,    17,    57,    61,    73,    61,    57,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    62,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    66,    68,    68,    68,    68,    68,    69,
      69,    62,    70,    71,    71,    72,    72,    73,    73,    62,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      79,    79,    79,    80,    81,    81,    62,    82,    62,    83,
      84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     6,     8,     1,     3,     5,     4,
       4,     1,     3,     3,     0,     3,     2,     2,     3,     4,
       1,     1,     6,     0,     3,     3,     5,     1,     3,     1,
       6,     0,     2,     0,     3,     2,     4,     0,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     5,     1,     6,
       3,     5
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
        case 3:
#line 54 "sql.y" /* yacc.c:1646  */
    {code(STOP); return 1;}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "sql.y" /* yacc.c:1646  */
    {code(STOP); return 1;}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = createColumn((yyvsp[0].const_val)->str, 0, 0, (yyvsp[0].const_val));}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "sql.y" /* yacc.c:1646  */
    {;}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "sql.y" /* yacc.c:1646  */
    {;}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = createColumn(0, STRING, 0, (yyvsp[0].const_val));}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = createColumn(0, INTNUM, 0, (yyvsp[0].const_val));}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "sql.y" /* yacc.c:1646  */
    {;}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 64 "sql.y" /* yacc.c:1646  */
    {;}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(eq);}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(gt);}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(ge);}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(lt);}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(le);}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "sql.y" /* yacc.c:1646  */
    {code2(colpush, (yyvsp[-2].columnval)->type == 0 ? (Inst)(yyvsp[0].columnval) : (Inst)(yyvsp[-2].columnval)); code2(colpush, (yyvsp[-2].columnval)->type == 0 ?(Inst)(yyvsp[-2].columnval):(Inst)(yyvsp[0].columnval)); code(ne);}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "sql.y" /* yacc.c:1646  */
    {code(or);}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "sql.y" /* yacc.c:1646  */
    {code(and);}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "sql.y" /* yacc.c:1646  */
    {;}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "sql.y" /* yacc.c:1646  */
    {code3(constpush, (Inst)(yyvsp[0].const_val), createDatabase);}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "sql.y" /* yacc.c:1646  */
    {code3(constpush, (Inst)(yyvsp[0].const_val), createDatabase);}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "sql.y" /* yacc.c:1646  */
    {;}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 88 "sql.y" /* yacc.c:1646  */
    {code3(constpush, (Inst)(yyvsp[-3].const_val), createTable); code((Inst)(yyvsp[-1].columnlist));}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 91 "sql.y" /* yacc.c:1646  */
    {;}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), 0);}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), (yyvsp[-2].columnlist));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 98 "sql.y" /* yacc.c:1646  */
    {;}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 99 "sql.y" /* yacc.c:1646  */
    {;}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "sql.y" /* yacc.c:1646  */
    {;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 103 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist(createColumn((yyvsp[0].const_val)->str, 0, 0, (yyvsp[0].const_val)), 0);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 104 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist(createColumn((yyvsp[0].const_val)->str, 0, 0, (yyvsp[0].const_val)), (yyvsp[-2].columnlist));}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "sql.y" /* yacc.c:1646  */
    {(yyvsp[-1].columnval)->nombre = (yyvsp[-2].const_val)->str; (yyval.columnval) = (yyvsp[-1].columnval);}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 109 "sql.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 110 "sql.y" /* yacc.c:1646  */
    {;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 111 "sql.y" /* yacc.c:1646  */
    {;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 112 "sql.y" /* yacc.c:1646  */
    {;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 115 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = createColumn(0, VARCHAR, (yyvsp[-1].const_val)->intval, 0);}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = createColumn(0, INTNUM, 0, 0);}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "sql.y" /* yacc.c:1646  */
    {;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "sql.y" /* yacc.c:1646  */
    {code3(constpush, (Inst)(yyvsp[-3].const_val), insert); code2((Inst)(yyvsp[-2].columnlist), (Inst)(yyvsp[0].columnlist));}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "sql.y" /* yacc.c:1646  */
    {;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = (yyvsp[-1].columnlist);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = (yyvsp[-1].columnlist);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 129 "sql.y" /* yacc.c:1646  */
    {;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), 0);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), (yyvsp[-2].columnlist));}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "sql.y" /* yacc.c:1646  */
    {;}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 139 "sql.y" /* yacc.c:1646  */
    {code3(selectsql, (Inst)(yyvsp[-4].columnlist), (Inst)(yyvsp[-1].const_val));}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 143 "sql.y" /* yacc.c:1646  */
    {(yyval.const_val) = (Datum *)0;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 144 "sql.y" /* yacc.c:1646  */
    {(yyval.const_val) = (Datum *)1;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 147 "sql.y" /* yacc.c:1646  */
    {;}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "sql.y" /* yacc.c:1646  */
    {;}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 153 "sql.y" /* yacc.c:1646  */
    {;}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 154 "sql.y" /* yacc.c:1646  */
    {;}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 156 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), 0);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 157 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = columnlist((yyvsp[0].columnval), (yyvsp[-2].columnlist));}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 158 "sql.y" /* yacc.c:1646  */
    {(yyval.columnlist) = 0;}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 160 "sql.y" /* yacc.c:1646  */
    {(yyval.columnval) = (yyvsp[0].columnval);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 162 "sql.y" /* yacc.c:1646  */
    {code2(constpush, (Inst)(yyvsp[0].const_val));}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 163 "sql.y" /* yacc.c:1646  */
    {;}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 167 "sql.y" /* yacc.c:1646  */
    {;}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 169 "sql.y" /* yacc.c:1646  */
    {code(deletesql);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 173 "sql.y" /* yacc.c:1646  */
    {;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 175 "sql.y" /* yacc.c:1646  */
    {code2(updatesql, (Inst)(yyvsp[-2].columnlist));}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 177 "sql.y" /* yacc.c:1646  */
    {(yyvsp[0].columnval)->nombre = (yyvsp[-2].const_val)->str; (yyval.columnlist) = columnlist((yyvsp[0].columnval), 0);}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 178 "sql.y" /* yacc.c:1646  */
    {(yyvsp[0].columnval)->nombre = (yyvsp[-2].const_val)->str; (yyval.columnlist) = columnlist((yyvsp[0].columnval), (yyvsp[-4].columnlist));}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1802 "y.tab.c" /* yacc.c:1646  */
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
#line 180 "sql.y" /* yacc.c:1906  */


#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include<setjmp.h>

char *progname;
int lineno = 1;
jmp_buf begin;
int indef;

void main (int argc, char *argv[]){
	progname=argv[0];
    init();
    setjmp(begin);
    signal(SIGFPE, fpecatch);
    //initcode();
    //yyparse();
  	for(initcode(); yyparse (); initcode())
        execute(progbase);
}

void execerror(char *s, char *t){
    warning(s, t);
    longjmp(begin, 0);
}

void fpecatch(){
    execerror("Excepcion de punto flotante", (char *)0);
}

int yylex (){
  	int c;

  	while ((c = getchar ()) == ' ' || c == '\t' || c == '\n'){
        lineno = c == '\n' ? lineno + 1 : lineno;
    }
 	if (c == EOF)                            
    		return 0;
  	if (isdigit (c)) {
        ungetc (c, stdin);
        yylval.const_val = (Datum *)malloc(sizeof(Datum)); 
        scanf ("%d", &(yylval.const_val->intval));
	    return INTNUM;
    }
    if(c == '\"'){
		char sbuf[200], *p=sbuf;
		while ((c=getchar())!=EOF && c != '\"'){
			*p++=c;
        }
        if(c == EOF) return 0;
        *p = 0;
        yylval.const_val = (Datum *)malloc(sizeof(Datum));
        char *temp = (char *)malloc(strlen(sbuf));
        memcpy(temp, sbuf, strlen(sbuf));
        yylval.const_val->str = temp; 
        return STRING;
    }
	if(isalpha(c)){
		Symbol *s;
		char sbuf[200], *p=sbuf;
		do {
			*p++=c;
		} while ((c=getchar())!=EOF && isalnum(c));
		ungetc(c, stdin);
		*p='\0';
		if((s=lookup(sbuf))==(Symbol *)NULL){
            yylval.const_val = (Datum *)malloc(sizeof(Datum));
            char *temp = (char *)malloc(strlen(sbuf));
            memcpy(temp, sbuf, strlen(sbuf));
		    yylval.const_val->str = temp; 
			return NAME;
        }
		yylval.sym=s;   
 		//printf("func=(%s) tipo=(%d) \n", s->name, s->type);
        return s->type;
	}
    switch(c) {
        case '>' :   return follow('=', GE, GT);
        case '<' :   return follow('=', LE, LT);
        case '!' :   return follow('=', NE, NOT);
        default  :   return c;
    }
}
void yyerror (char *s) {
	warning(s, (char *) 0);
}
void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, " cerca de la linea %d\n", lineno);
}
int follow(int expect, int ifyes, int ifno){
    int c = getchar();
    if(c == expect) return ifyes;
    ungetc(c, stdin);
    return ifno;
}
