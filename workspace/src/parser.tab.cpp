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
#line 1 "src/parser.y" /* yacc.c:339  */

  #include <cassert>
  #include "ast.hpp"
  extern const Node *g_root; // A way of getting the AST out

   extern FILE* yyin;
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 79 "src/parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
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
    T_K_INT = 258,
    T_K_RETURN = 259,
    T_K_STRUCT = 260,
    T_K_FOR = 261,
    T_K_DOUBLE = 262,
    T_K_FLOAT = 263,
    T_K_IF = 264,
    T_K_ELSE = 265,
    T_K_SWITCH = 266,
    T_K_WHILE = 267,
    T_K_DEFAULT = 268,
    T_K_TYPEDEF = 269,
    T_K_SIZEOF = 270,
    T_K_STATIC = 271,
    T_K_EXTERN = 272,
    T_K_VOID = 273,
    T_K_CHAR = 274,
    T_K_SHORT = 275,
    T_K_LONG = 276,
    T_K_SIGNED = 277,
    T_K_UNSIGNED = 278,
    T_K_UNION = 279,
    T_K_ENUM = 280,
    T_K_CONST = 281,
    T_K_VOLATILE = 282,
    T_K_CASE = 283,
    T_K_DO = 284,
    T_K_GOTO = 285,
    T_K_CONTINUE = 286,
    T_K_BREAK = 287,
    T_ID = 288,
    T_JH = 289,
    T_AND = 290,
    T_OR = 291,
    T_XOR = 292,
    T_QF = 293,
    T_NOT = 294,
    T_LAND = 295,
    T_LOR = 296,
    T_SHIFT_LEFT = 297,
    T_SHIFT_RIGHT = 298,
    T_K_AUTO = 299,
    T_LDKH = 300,
    T_RDKH = 301,
    T_LXKH = 302,
    T_RXKH = 303,
    T_LZKH = 304,
    T_RZKH = 305,
    T_FH = 306,
    T_WH = 307,
    T_MH = 308,
    T_ARROW = 309,
    T_EQ = 310,
    T_NEQ = 311,
    T_RFKH = 312,
    T_LT = 313,
    T_GT = 314,
    T_ASSIGN = 315,
    T_ADD_ASSIGN = 316,
    T_SUB_ASSIGN = 317,
    T_MUL_ASSIGN = 318,
    T_DIV_ASSIGN = 319,
    T_OR_ASSIGN = 320,
    T_AND_ASSIGN = 321,
    T_XLH = 322,
    T_MINUS = 323,
    T_ADD = 324,
    T_MUL = 325,
    T_DH = 326,
    T_LE = 327,
    T_GE = 328,
    T_ADDADD = 329,
    T_SUBSUB = 330,
    T_DOT = 331,
    T_DIV = 332,
    T_MOD = 333,
    T_V_CHAR = 334,
    T_V_FLOAT = 335,
    T_V_INTEGER = 336,
    T_V_STRING = 337
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/parser.y" /* yacc.c:355  */

  const Node *node;
  double doubletype;
  int inttype;
  char chartype;
  std::string *str;

#line 210 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   337

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    74,    75,    76,    77,    78,    79,    82,
      83,    84,    85,    86,    87,    88,    89,    91,    92,    94,
      95,    96,    97,    98,    99,   101,   102,   103,   104,   105,
     106,   108,   109,   111,   112,   113,   114,   116,   117,   118,
     120,   121,   122,   124,   125,   126,   127,   128,   130,   131,
     132,   134,   135,   137,   138,   140,   141,   143,   144,   146,
     147,   149,   150,   152,   153,   155,   156,   157,   158,   159,
     160,   161,   163,   164,   166,   171,   172,   174,   175,   176,
     177,   178,   179,   181,   182,   184,   185,   187,   188,   189,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   203,   204,   205,   207,   208,   210,   211,   213,   217,
     218,   219,   220,   222,   223,   225,   226,   227,   229,   230,
     231,   233,   234,   236,   237,   239,   240,   242,   243,   245,
     246,   247,   248,   249,   250,   251,   253,   254,   255,   256,
     258,   259,   261,   262,   264,   265,   267,   268,   269,   271,
     272,   274,   275,   277,   278,   279,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   291,   292,   293,   295,   296,
     300,   301,   302,   303,   304,   305,   306,   308,   309,   310,
     312,   313,   315,   316,   318,   319,   321,   322,   324,   325,
     326,   328,   329,   330,   331,   333,   334,   335,   336,   337,
     339,   340,   342,   343,   345,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_K_INT", "T_K_RETURN", "T_K_STRUCT",
  "T_K_FOR", "T_K_DOUBLE", "T_K_FLOAT", "T_K_IF", "T_K_ELSE", "T_K_SWITCH",
  "T_K_WHILE", "T_K_DEFAULT", "T_K_TYPEDEF", "T_K_SIZEOF", "T_K_STATIC",
  "T_K_EXTERN", "T_K_VOID", "T_K_CHAR", "T_K_SHORT", "T_K_LONG",
  "T_K_SIGNED", "T_K_UNSIGNED", "T_K_UNION", "T_K_ENUM", "T_K_CONST",
  "T_K_VOLATILE", "T_K_CASE", "T_K_DO", "T_K_GOTO", "T_K_CONTINUE",
  "T_K_BREAK", "T_ID", "T_JH", "T_AND", "T_OR", "T_XOR", "T_QF", "T_NOT",
  "T_LAND", "T_LOR", "T_SHIFT_LEFT", "T_SHIFT_RIGHT", "T_K_AUTO", "T_LDKH",
  "T_RDKH", "T_LXKH", "T_RXKH", "T_LZKH", "T_RZKH", "T_FH", "T_WH", "T_MH",
  "T_ARROW", "T_EQ", "T_NEQ", "T_RFKH", "T_LT", "T_GT", "T_ASSIGN",
  "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN", "T_DIV_ASSIGN",
  "T_OR_ASSIGN", "T_AND_ASSIGN", "T_XLH", "T_MINUS", "T_ADD", "T_MUL",
  "T_DH", "T_LE", "T_GE", "T_ADDADD", "T_SUBSUB", "T_DOT", "T_DIV",
  "T_MOD", "T_V_CHAR", "T_V_FLOAT", "T_V_INTEGER", "T_V_STRING", "$accept",
  "ROOT", "BASIC_EXPR", "POSTFIX_EXPR", "AGR_LIST", "UNARY_EXPR",
  "OPR_UNARY", "CAST_EXPR", "MUL_EXPR", "ADD_EXPR", "SHIFT_EXPR",
  "RELATION_EXPR", "EQ_EXPR", "AND_EXPR", "XOR_EXPR", "OR_EXPR",
  "LOGIC_AND_EXPR", "LOGIC_OR_EXPR", "CONDITION_EXPR", "ASSIGN_EXPR",
  "ASSIGN", "EXPR", "REGULAR_EXPR", "DECLARATION", "TYPE_PART",
  "TERMS_LIST", "TERM", "STORE_CLASS", "REGULAR_TYPE", "STRUCT_UNION_TYPE",
  "STRUCT_UNION", "STRUCT_UNION_LIST", "STRUCT_UNION_DECLARATION",
  "LIST_SPEC_QUAL", "LIST_STRUCT_DECLARATOR", "STRUCT_DECLARATOR",
  "SPECIFIER_ENUM", "LIST_ENUMERATOR", "ENUMERATOR", "QUALIFIER_TYPE",
  "DECLARATOR", "DECLARATOR_DIRECT", "POINTER", "LIST_QUALIFIER_TYPE",
  "LIST_PARAM_TYPE", "LIST_PARAMETER", "DECLARATION_PARAMETER",
  "LIST_IDENTIFIER", "TYPE", "DECLARATOR_ABSTRACT",
  "DECLARATOR_DIRECT_ABSTRACT", "INITIALIZER", "LIST_INITIALIZER",
  "STATEMENT", "CASE_STATEMENT", "STATEMENTS", "LIST_DECLARATION",
  "STATEMENT_SEQUENCE", "EXPR_STATEMENT", "SELECTION_STATEMENT",
  "ITERATION_STATEMENT", "JUMP_STATEMENT", "PROGRAM", "EXTERNAL_OBJECT",
  "FUNCTION", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1224,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,   136,  -196,  -196,    33,  -196,
     -13,  1224,  1224,  -196,   140,  -196,  1224,  1224,  -196,  -196,
      -8,    41,  -196,  -196,   -15,  -196,   -14,     1,  -196,   150,
     144,    89,  -196,  -196,    74,  1249,  -196,  -196,    41,    65,
      -7,  -196,   123,  -196,  -196,   -14,  -196,   -15,   307,  -196,
     920,  -196,  1100,   718,   144,  1249,  1249,  1164,  -196,     7,
    1249,    -5,   945,  -196,    41,  -196,  -196,  -196,  -196,   118,
     743,   141,   159,   179,   183,   180,   970,   945,   467,   205,
     190,   193,   192,  -196,  -196,  -196,  -196,   547,  -196,  -196,
    -196,  -196,   995,   995,  -196,  -196,  -196,  -196,  -196,    21,
     197,   945,  -196,   137,    60,    47,   117,   157,   215,   216,
     228,   225,    80,  -196,  -196,    64,  -196,   -13,  -196,  -196,
    -196,  1224,   387,  -196,  -196,  -196,  -196,  -196,   585,  -196,
    -196,  -196,  -196,    18,   220,   198,  -196,    10,  -196,  -196,
    -196,   221,  1193,  -196,  -196,  -196,   945,    67,  -196,   219,
    -196,  -196,  -196,  -196,  -196,    69,   768,   945,   945,   945,
     467,   547,  -196,   222,   261,   223,  -196,  -196,   467,    28,
      24,   229,   945,  -196,  -196,   793,   945,   245,  -196,  -196,
     246,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   945,  -196,
     945,   945,   945,   945,   945,   945,   945,   945,   945,   945,
     945,   945,   945,   945,   945,   945,   945,   945,   945,  -196,
     945,  -196,  -196,  -196,  -196,  -196,    30,   665,   819,  -196,
     133,  -196,   147,  -196,  1075,  -196,   247,  -196,  -196,  -196,
    -196,     7,   945,  -196,   768,    32,    37,    38,  -196,   233,
     467,   235,  -196,  -196,  -196,   701,   162,  -196,   945,  -196,
      39,  -196,    -2,  -196,  -196,  -196,  -196,  -196,  -196,   137,
     137,    60,    60,    47,    47,    47,    47,   117,   117,   157,
     215,   216,   228,   225,    70,  -196,  -196,   844,  -196,   237,
     238,  -196,   239,   147,  1133,   870,  -196,  -196,  -196,  -196,
    -196,   895,   467,   467,   467,  -196,  -196,   945,  -196,  -196,
     945,  -196,   945,  -196,  -196,  -196,  -196,  -196,  -196,   240,
    -196,   241,   467,    59,   273,  -196,  -196,    63,  -196,  -196,
    -196,  -196,  -196,   467,   467,   236,  -196,  -196,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    93,   104,    96,    95,    87,    89,    88,    90,    91,
      92,    94,    97,    98,   105,     0,   125,   126,     0,   202,
       0,    77,    79,    99,     0,   100,    81,     2,   200,   203,
     120,     0,     1,   129,     0,    75,   136,     0,    83,    85,
     128,     0,    78,    80,   103,     0,    82,   201,     0,   123,
       0,   121,     0,   140,   138,   137,    76,     0,     0,   204,
       0,   205,     0,     0,   127,     0,   110,     0,   106,     0,
     112,     0,     0,   118,     0,   130,   141,   139,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,    25,    26,    27,   180,     0,   186,    30,
      29,    28,     0,     0,     6,     5,     4,     7,     9,    19,
      31,     0,    33,    37,    40,    43,    48,    51,    53,    55,
      57,    59,    61,    63,    72,     0,   182,     0,   184,   170,
     171,   176,     0,   172,   173,   174,   175,     3,     0,   165,
      86,   149,   135,   148,     0,   142,   144,     0,   132,    31,
      74,     0,     0,   109,   102,   107,     0,     0,   113,   115,
     111,   119,   124,   122,   198,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,   196,   197,     0,     0,
     151,     0,     0,    20,    21,     0,     0,     0,    15,    16,
       0,    65,    66,    67,    68,    69,    71,    70,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   183,   181,   185,    72,   168,     0,     0,     0,   146,
     153,   147,   154,   133,     0,   134,     0,   131,   101,   116,
     108,     0,     0,   199,     0,     0,     0,     0,   179,     0,
       0,     0,   195,   177,     8,     0,   153,   152,     0,    11,
       0,    17,     0,    14,    13,    64,    34,    35,    36,    39,
      38,    41,    42,    44,    45,    46,    47,    49,    50,    52,
      54,    56,    58,    60,     0,    73,   166,     0,   162,     0,
       0,   161,     0,   155,     0,     0,   143,   145,   150,   114,
     117,     0,     0,     0,     0,    24,   178,     0,    32,    12,
       0,    10,     0,   167,   169,   160,   156,   157,   159,     0,
     158,     0,     0,     0,   188,   190,   191,     0,    18,    62,
     164,   163,   193,     0,     0,     0,   194,   189,   192
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,  -196,   -58,  -196,   -96,    16,    61,
      15,    31,    79,    81,    78,    82,    83,  -196,   -56,   -59,
    -196,   -55,   -63,    36,     0,  -196,   242,  -196,   138,  -196,
    -196,   231,   -50,   -47,  -196,    56,  -196,   253,   230,   132,
     -10,   -38,    -6,  -196,   -54,  -196,    68,  -196,   134,  -137,
    -195,  -127,  -196,   -86,  -196,   267,  -196,  -196,  -162,  -196,
    -196,  -196,  -196,   280,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,   108,   109,   260,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     198,   125,   151,   126,   127,    37,    38,    21,    22,    23,
      24,    67,    68,    69,   157,   158,    25,    50,    51,    26,
      52,    40,    41,    55,   289,   145,   146,   147,   181,   290,
     232,   140,   226,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      20,   139,   174,    64,   244,   149,   231,   150,   144,   162,
      39,   225,    16,    17,   149,   199,   150,   155,    33,   153,
      33,    42,    43,   160,   173,   165,    46,    20,   172,   149,
      54,   150,    34,    32,    34,   293,    19,    48,    35,    73,
      33,   161,   179,   257,   183,   184,   223,    79,   311,    77,
     180,    33,    56,   149,    34,    36,    36,    36,   235,   159,
     156,   293,   143,    19,    74,   227,    74,   228,   185,   220,
     186,   255,    57,   228,    49,   187,   254,    36,   286,   224,
     302,   236,   301,   179,   248,   303,   304,   309,    36,   205,
     206,   180,   253,   239,    36,   188,   189,   190,   149,   220,
     150,   287,   155,   220,   266,   267,   268,   333,   220,   220,
     310,   335,   245,   246,   247,   219,   179,    79,   240,    65,
     243,   217,    33,   312,   180,    72,   261,   179,   203,   204,
     220,   262,   218,   229,   220,   220,    34,   230,   241,   265,
     220,   220,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     314,   285,   308,   284,   306,   292,    33,   221,    53,    30,
     149,    75,   150,    44,   256,   207,   208,    70,    60,   300,
     227,    31,   228,    66,   149,    45,   150,    76,   166,   209,
     210,    62,    64,    63,   294,    58,   295,    70,    70,    70,
     149,    59,    70,    66,    66,    66,   167,   200,    66,   255,
      60,   228,   211,   212,   201,   202,   324,   325,   326,   269,
     270,   230,   273,   274,   275,   276,   168,   143,   139,    70,
     169,   159,   321,   170,   143,    66,   332,   149,   175,   150,
     319,   176,   277,   278,   177,   178,   323,   336,   337,   256,
     213,   328,   327,   214,   149,   143,   329,   191,   192,   193,
     194,   195,   196,   197,   215,   216,   271,   272,   233,   234,
      70,   237,   242,   251,   252,   250,    66,   258,   263,   264,
     298,   305,   307,   334,    70,   315,   316,   338,   330,   317,
      66,   331,   279,   281,   143,   280,   152,   299,   282,    78,
     283,    71,   297,    70,   163,   249,    61,    47,     0,    66,
       1,    80,     2,    81,     3,     4,    82,     0,    83,    84,
      85,     5,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    87,    88,    89,    90,    91,
      92,     0,    93,     0,     0,    94,    95,     0,     0,     0,
       0,     0,    58,    96,    97,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   102,   103,     0,     0,     0,   104,   105,   106,   107,
       1,    80,     2,    81,     3,     4,    82,     0,    83,    84,
      85,     5,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    87,    88,    89,    90,    91,
      92,     0,    93,     0,     0,    94,    95,     0,     0,     0,
       0,     0,    58,   222,    97,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   102,   103,     0,     0,     0,   104,   105,   106,   107,
       1,    80,     2,    81,     3,     4,    82,     0,    83,    84,
      85,     5,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    87,    88,    89,    90,    91,
      92,     0,    93,     0,     0,    94,    95,     0,     0,     0,
       0,     0,    58,     0,    97,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   102,   103,     0,     0,     0,   104,   105,   106,   107,
       1,     0,     2,     0,     3,     4,     0,     0,     0,     0,
       0,     0,    86,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,     0,
     137,     0,    93,     0,     0,    94,    95,     0,     1,     0,
       2,     0,     3,     4,    97,     0,     0,     0,     0,     0,
      86,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,    99,   100,   101,   137,     0,
      93,   102,   103,    94,    95,     0,   104,   105,   106,   107,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,   102,
     103,     0,     0,     0,   104,   105,   106,   107,     1,     0,
       2,     0,     3,     4,     0,     0,     0,     0,     0,     5,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     1,     0,     2,     0,     3,     4,
       0,     0,   227,   288,   228,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,    86,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   288,
     228,   137,     0,    93,     0,     0,    94,    95,    86,     0,
       0,     0,     0,     0,     0,    97,     0,     0,   148,     0,
       0,    36,     0,     0,     0,     0,   137,     0,    93,     0,
       0,    94,    95,    86,     0,     0,    99,   100,   101,     0,
      97,     0,   102,   103,   164,     0,     0,   104,   105,   106,
     107,   137,     0,    93,     0,     0,    94,    95,    86,     0,
       0,    99,   100,   101,     0,    97,     0,   102,   103,    98,
       0,     0,   104,   105,   106,   107,   137,     0,    93,     0,
       0,    94,    95,     0,    86,     0,    99,   100,   101,     0,
      97,   259,   102,   103,     0,     0,     0,   104,   105,   106,
     107,     0,   137,     0,    93,     0,     0,    94,    95,    86,
       0,    99,   100,   101,     0,     0,    97,   102,   103,   291,
       0,     0,   104,   105,   106,   107,     0,   137,     0,    93,
       0,     0,    94,    95,     0,    86,     0,    99,   100,   101,
       0,   138,   313,   102,   103,     0,     0,     0,   104,   105,
     106,   107,     0,   137,     0,    93,     0,     0,    94,    95,
      86,     0,    99,   100,   101,     0,     0,    97,   102,   103,
     320,     0,     0,   104,   105,   106,   107,     0,   137,     0,
      93,     0,     0,    94,    95,    86,     0,     0,    99,   100,
     101,     0,    97,   322,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   137,     0,    93,     0,     0,    94,    95,
      86,     0,     0,    99,   100,   101,     0,   138,     0,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   137,     0,
      93,     0,     0,    94,    95,    86,     0,     0,    99,   100,
     101,     0,    97,     0,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   137,     0,    93,     0,     0,    94,    95,
      86,     0,     0,    99,   100,   101,     0,   171,     0,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   137,     0,
      93,     0,     0,    94,    95,     0,     0,     0,    99,   100,
     101,     0,   182,     0,   102,   103,     0,     0,     0,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,   102,
     103,     0,     0,     0,   104,   105,   106,   107,     1,     0,
       2,     0,     3,     4,     0,     0,     0,     0,     0,     5,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     1,     0,     2,     0,     3,     4,     0,
       0,     0,     0,     0,     5,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   141,     0,     0,     1,     0,     2,     0,
       3,     4,   296,     0,     0,     0,     0,     5,   142,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,   318,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     1,     0,     2,     0,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     3,     4,     0,     0,     0,     0,     0,     5,   238,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     1,     0,     2,     0,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17
};

static const yytype_int16 yycheck[] =
{
       0,    60,    88,    41,   166,    63,   143,    63,    62,    72,
      20,   138,    26,    27,    72,   111,    72,    67,    33,    66,
      33,    21,    22,    70,    87,    80,    26,    27,    86,    87,
      36,    87,    47,     0,    47,   230,     0,    45,    51,    46,
      33,    46,    97,   180,   102,   103,   132,    57,    50,    55,
      97,    33,    51,   111,    47,    70,    70,    70,    48,    69,
      53,   256,    62,    27,    71,    47,    71,    49,    47,    71,
      49,    47,    71,    49,    33,    54,    48,    70,    48,   138,
      48,    71,   244,   138,   170,    48,    48,    48,    70,    42,
      43,   138,   178,   156,    70,    74,    75,    76,   156,    71,
     156,    71,   152,    71,   200,   201,   202,    48,    71,    71,
      71,    48,   167,   168,   169,    51,   171,   127,    51,    45,
      51,    41,    33,    53,   171,    60,   185,   182,    68,    69,
      71,   186,    52,   143,    71,    71,    47,   143,    71,   198,
      71,    71,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     287,   220,   258,   218,   250,   228,    33,   131,    36,    33,
     228,    48,   228,    33,   180,    58,    59,    45,    60,   242,
      47,    45,    49,    45,   242,    45,   242,    55,    47,    72,
      73,    47,   230,    49,    47,    45,    49,    65,    66,    67,
     258,    51,    70,    65,    66,    67,    47,    70,    70,    47,
      60,    49,    55,    56,    77,    78,   302,   303,   304,   203,
     204,   227,   207,   208,   209,   210,    47,   227,   287,    97,
      47,   241,   295,    53,   234,    97,   322,   295,    33,   295,
     294,    51,   211,   212,    51,    53,   301,   333,   334,   255,
      35,   310,   307,    37,   312,   255,   312,    60,    61,    62,
      63,    64,    65,    66,    36,    40,   205,   206,    48,    71,
     138,    50,    53,    12,    51,    53,   138,    48,    33,    33,
      33,    48,    47,    10,   152,    48,    48,    51,    48,    50,
     152,    50,   213,   215,   294,   214,    65,   241,   216,    57,
     217,    48,   234,   171,    74,   171,    39,    27,    -1,   171,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,    82,
       3,    -1,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    38,    39,    -1,     3,    -1,
       5,    -1,     7,     8,    47,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    68,    69,    70,    33,    -1,
      35,    74,    75,    38,    39,    -1,    79,    80,    81,    82,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    82,     3,    -1,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,    -1,     7,     8,
      -1,    -1,    47,    48,    49,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    15,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    33,    -1,    35,    -1,    -1,    38,    39,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    38,    39,    15,    -1,    -1,    68,    69,    70,    -1,
      47,    -1,    74,    75,    51,    -1,    -1,    79,    80,    81,
      82,    33,    -1,    35,    -1,    -1,    38,    39,    15,    -1,
      -1,    68,    69,    70,    -1,    47,    -1,    74,    75,    51,
      -1,    -1,    79,    80,    81,    82,    33,    -1,    35,    -1,
      -1,    38,    39,    -1,    15,    -1,    68,    69,    70,    -1,
      47,    48,    74,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    33,    -1,    35,    -1,    -1,    38,    39,    15,
      -1,    68,    69,    70,    -1,    -1,    47,    74,    75,    50,
      -1,    -1,    79,    80,    81,    82,    -1,    33,    -1,    35,
      -1,    -1,    38,    39,    -1,    15,    -1,    68,    69,    70,
      -1,    47,    48,    74,    75,    -1,    -1,    -1,    79,    80,
      81,    82,    -1,    33,    -1,    35,    -1,    -1,    38,    39,
      15,    -1,    68,    69,    70,    -1,    -1,    47,    74,    75,
      50,    -1,    -1,    79,    80,    81,    82,    -1,    33,    -1,
      35,    -1,    -1,    38,    39,    15,    -1,    -1,    68,    69,
      70,    -1,    47,    48,    74,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    33,    -1,    35,    -1,    -1,    38,    39,
      15,    -1,    -1,    68,    69,    70,    -1,    47,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    82,    33,    -1,
      35,    -1,    -1,    38,    39,    15,    -1,    -1,    68,    69,
      70,    -1,    47,    -1,    74,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    33,    -1,    35,    -1,    -1,    38,    39,
      15,    -1,    -1,    68,    69,    70,    -1,    47,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    82,    33,    -1,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    68,    69,
      70,    -1,    47,    -1,    74,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    82,     3,    -1,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     3,    -1,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,     3,    -1,     5,    -1,
       7,     8,    67,    -1,    -1,    -1,    -1,    14,    48,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,    46,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     3,    -1,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,     8,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    84,   106,
     107,   110,   111,   112,   113,   119,   122,   145,   146,   147,
      33,    45,     0,    33,    47,    51,    70,   108,   109,   123,
     124,   125,   107,   107,    33,    45,   107,   146,    45,    33,
     120,   121,   123,   122,   125,   126,    51,    71,    45,    51,
      60,   138,    47,    49,   124,    45,   111,   114,   115,   116,
     122,   120,    60,    46,    71,    48,   122,   125,   109,   123,
       4,     6,     9,    11,    12,    13,    15,    28,    29,    30,
      31,    32,    33,    35,    38,    39,    46,    47,    51,    68,
      69,    70,    74,    75,    79,    80,    81,    82,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   106,   107,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    33,    47,   102,
     134,    33,    48,   107,   127,   128,   129,   130,    50,    88,
     101,   105,   114,   116,    46,   115,    53,   117,   118,   123,
     116,    46,   105,   121,    51,   104,    47,    47,    47,    47,
      53,    47,    88,   105,   136,    33,    51,    51,    53,   104,
     116,   131,    47,    88,    88,    47,    49,    54,    74,    75,
      76,    60,    61,    62,    63,    64,    65,    66,   103,    90,
      70,    77,    78,    68,    69,    42,    43,    58,    59,    72,
      73,    55,    56,    35,    37,    36,    40,    41,    52,    51,
      71,   106,    46,   136,   102,   134,   135,    47,    49,   123,
     125,   132,   133,    48,    71,    48,    71,    50,    46,   105,
      51,    71,    53,    51,   141,   104,   104,   104,   136,   131,
      53,    12,    51,   136,    48,    47,   125,   132,    48,    48,
      87,   102,   104,    33,    33,   102,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      96,    97,    98,    99,   104,   102,    48,    71,    48,   127,
     132,    50,   105,   133,    47,    49,    67,   129,    33,   118,
     105,   141,    48,    48,    48,    48,   136,    47,    90,    48,
      71,    50,    53,    48,   134,    48,    48,    50,    48,   127,
      50,   105,    48,   104,   136,   136,   136,   104,   102,   101,
      48,    50,   136,    48,    10,    48,   136,   136,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    94,    94,    94,    94,    94,    95,    95,
      95,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   112,   113,   113,   114,   114,   115,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   130,
     130,   131,   131,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   143,   143,   143,   143,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   147,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     1,     2,     3,     2,
       1,     2,     1,     1,     3,     1,     2,     3,     4,     5,
       2,     1,     3,     1,     3,     1,     1,     2,     1,     1,
       3,     4,     3,     4,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     2,     1,     1,
       3,     1,     2,     1,     1,     2,     3,     3,     3,     3,
       3,     2,     2,     4,     4,     1,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     2,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     3,     3
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
        case 2:
#line 69 "src/parser.y" /* yacc.c:1646  */
    {g_root = (yyvsp[0].node);}
#line 1762 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[0].str),2);}
#line 1768 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 75 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[0].inttype));}
#line 1774 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[0].doubletype));}
#line 1780 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[0].chartype));}
#line 1786 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[0].str),1);}
#line 1792 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BasicExpression((yyvsp[-1].node));}
#line 1798 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1804 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-3].node),(yyvsp[-1].node),"expr");}
#line 1810 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 84 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-2].node),"fc no args");}
#line 1816 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-3].node),(yyvsp[-1].node),"fc with args");}
#line 1822 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-2].node),(yyvsp[0].str),".");}
#line 1828 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-2].node),(yyvsp[0].str),"->");}
#line 1834 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-1].node),"++");}
#line 1840 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new PostfixExpression((yyvsp[-1].node),"--");}
#line 1846 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 91 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ArgList((yyvsp[0].node));}
#line 1852 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 92 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ArgList((yyvsp[-2].node),(yyvsp[0].node));}
#line 1858 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1864 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 95 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new UnaryExpression("++",(yyvsp[0].node));}
#line 1870 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 96 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new UnaryExpression("--",(yyvsp[0].node));}
#line 1876 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new UnaryExpression((yyvsp[-1].node),(yyvsp[0].node));}
#line 1882 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 98 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new UnaryExpression("sizeof",(yyvsp[0].node));}
#line 1888 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 99 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new UnaryExpression("sizeof",(yyvsp[-1].node));}
#line 1894 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("&"); }
#line 1900 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("~"); }
#line 1906 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("!"); }
#line 1912 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("*"); }
#line 1918 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("+"); }
#line 1924 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OprUnary("-"); }
#line 1930 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 108 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1936 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 109 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CastExpr((yyvsp[-2].node),(yyvsp[0].node));}
#line 1942 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 111 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1948 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 112 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"*");}
#line 1954 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"/");}
#line 1960 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"%");}
#line 1966 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1972 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"+");}
#line 1978 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 118 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"-");}
#line 1984 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1990 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 121 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"<<");}
#line 1996 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),">>");}
#line 2002 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 124 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2008 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 125 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"<");}
#line 2014 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 126 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),">");}
#line 2020 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 127 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"<=");}
#line 2026 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 128 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),">=");}
#line 2032 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2038 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 131 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"==");}
#line 2044 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 132 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"!=");}
#line 2050 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 134 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2056 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"&");}
#line 2062 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2068 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 138 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"^");}
#line 2074 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2080 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 141 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"|");}
#line 2086 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 143 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2092 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 144 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"&&");}
#line 2098 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 146 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2104 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 147 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new BinaryExpression((yyvsp[-2].node),(yyvsp[0].node),"||");}
#line 2110 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2116 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 150 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ConditionExpr((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2122 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2128 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 153 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignExpression((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 2134 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 155 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("=");}
#line 2140 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 156 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("+=");}
#line 2146 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 157 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("-=");}
#line 2152 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 158 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("*=");}
#line 2158 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 159 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("/=");}
#line 2164 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 160 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("&=");}
#line 2170 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 161 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Assign("|=");}
#line 2176 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 163 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2182 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 164 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Expr((yyvsp[-2].node),(yyvsp[0].node));}
#line 2188 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 166 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2194 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Declaration((yyvsp[-1].node));}
#line 2200 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 172 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Declaration((yyvsp[-2].node),(yyvsp[-1].node));}
#line 2206 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 174 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2212 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 175 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypePart((yyvsp[-1].node), (yyvsp[0].node));}
#line 2218 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 176 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2224 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypePart((yyvsp[-1].node), (yyvsp[0].node));}
#line 2230 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 178 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2236 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypePart((yyvsp[-1].node), (yyvsp[0].node));}
#line 2242 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 181 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2248 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 182 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TermList((yyvsp[-2].node), (yyvsp[0].node));}
#line 2254 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 184 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Term((yyvsp[0].node));}
#line 2260 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 185 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Term((yyvsp[-2].node),(yyvsp[0].node),"=");}
#line 2266 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 187 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StoreClass("typedef");}
#line 2272 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 188 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StoreClass("extern");}
#line 2278 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 189 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StoreClass("static");}
#line 2284 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 191 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("void");}
#line 2290 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 192 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("char");}
#line 2296 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 193 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("short");}
#line 2302 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 194 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("int");}
#line 2308 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 195 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("long");}
#line 2314 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 196 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("float");}
#line 2320 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 197 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("double");}
#line 2326 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 198 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("signed");}
#line 2332 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 199 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("unsigned");}
#line 2338 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2344 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 201 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2350 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 203 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructUnionType((yyvsp[-4].node),(yyvsp[-3].str),(yyvsp[-1].node));}
#line 2356 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructUnionType((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2362 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 205 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructUnionType((yyvsp[-1].node),(yyvsp[0].str));}
#line 2368 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("struct");}
#line 2374 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 208 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularType("union");}
#line 2380 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 210 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2386 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 211 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructUnionList((yyvsp[-1].node),(yyvsp[0].node));}
#line 2392 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 213 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructUnionDeclaration((yyvsp[-2].node),(yyvsp[-1].node));}
#line 2398 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 217 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListSpecQual((yyvsp[-1].node),(yyvsp[0].node));}
#line 2404 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 218 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2410 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 219 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListSpecQual((yyvsp[-1].node),(yyvsp[0].node));}
#line 2416 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 220 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2422 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 222 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2428 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 223 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListStructDeclaration((yyvsp[-2].node),(yyvsp[0].node));}
#line 2434 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2440 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 226 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructDeclaration((yyvsp[0].node));}
#line 2446 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 227 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructDeclaration((yyvsp[-2].node),(yyvsp[0].node));}
#line 2452 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SpecifierEnum((yyvsp[-1].node));}
#line 2458 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 230 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SpecifierEnum((yyvsp[-3].str),(yyvsp[-1].node));}
#line 2464 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SpecifierEnum((yyvsp[0].str));}
#line 2470 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 233 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2476 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 234 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListEnumerator((yyvsp[-2].node),(yyvsp[0].node));}
#line 2482 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 236 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Enumerator((yyvsp[0].str));}
#line 2488 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 237 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Enumerator((yyvsp[-2].str),(yyvsp[0].node));}
#line 2494 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 239 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new QualifierType("const");}
#line 2500 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 240 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new QualifierType("valatile");}
#line 2506 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 242 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Declarator((yyvsp[-1].node),(yyvsp[0].node));}
#line 2512 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 243 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2518 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 245 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[0].str));}
#line 2524 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 246 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-1].node),"(d)");}
#line 2530 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 247 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-3].node),(yyvsp[-1].node),"[]");}
#line 2536 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 248 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-2].node),"[]");}
#line 2542 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 249 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-3].node),(yyvsp[-1].node),"(p)");}
#line 2548 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 250 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-3].node),(yyvsp[-1].node),"(l)");}
#line 2554 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 251 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclaratorDirect((yyvsp[-2].node),"()");}
#line 2560 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 253 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Pointer();}
#line 2566 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 254 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Pointer((yyvsp[0].node));}
#line 2572 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 255 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Pointer((yyvsp[0].node));}
#line 2578 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 256 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Pointer((yyvsp[-1].node),(yyvsp[0].node));}
#line 2584 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 258 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2590 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 259 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListQualifierType((yyvsp[-1].node),(yyvsp[0].node));}
#line 2596 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 261 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2602 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 262 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListParamType((yyvsp[-2].node));}
#line 2608 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2614 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 265 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListParameter((yyvsp[-2].node),(yyvsp[0].node));}
#line 2620 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 267 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationParameter((yyvsp[-1].node),(yyvsp[0].node));}
#line 2626 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 268 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationParameter((yyvsp[-1].node),(yyvsp[0].node));}
#line 2632 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 269 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2638 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 271 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListIdentifier((yyvsp[0].str));}
#line 2644 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 272 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListIdentifier((yyvsp[-2].node),(yyvsp[0].str));}
#line 2650 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 274 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2656 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 275 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Type((yyvsp[-1].node),(yyvsp[0].node));}
#line 2662 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 277 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2668 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 278 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2674 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 279 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationAbstract((yyvsp[-1].node),(yyvsp[0].node));}
#line 2680 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 281 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-1].node),"(k)");}
#line 2686 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 282 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-1].node),"[r]");}
#line 2692 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 283 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-2].node),"[]");}
#line 2698 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 284 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-2].node),"()");}
#line 2704 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 285 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-1].node),"k()");}
#line 2710 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 286 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract("[]");}
#line 2716 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 287 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract("()");}
#line 2722 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 288 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-3].node),(yyvsp[-1].node),"[r]");}
#line 2728 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 289 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new DeclarationDirectAbstract((yyvsp[-3].node),(yyvsp[-1].node),"(r)");}
#line 2734 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 291 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2740 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 292 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Initializer((yyvsp[-1].node),"()");}
#line 2746 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 293 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Initializer((yyvsp[-2].node),"(,)");}
#line 2752 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 295 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2758 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 296 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListInitializer((yyvsp[-2].node),(yyvsp[0].node));}
#line 2764 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 300 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2770 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 301 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2776 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 302 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2782 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 303 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 305 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2806 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 308 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CaseStatement((yyvsp[-2].str),(yyvsp[0].node));}
#line 2812 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 309 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CaseStatement((yyvsp[-2].node),(yyvsp[0].node),"case");}
#line 2818 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 310 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CaseStatement((yyvsp[0].node),"default");}
#line 2824 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Statements();}
#line 2830 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 313 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Statements((yyvsp[-1].node));}
#line 2836 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 315 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2842 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 316 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ListDeclaration((yyvsp[-1].node),(yyvsp[0].node));}
#line 2848 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 318 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2854 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 319 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StatementSequence((yyvsp[-1].node),(yyvsp[0].node));}
#line 2860 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 321 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ExprStatement();}
#line 2866 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 322 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ExprStatement((yyvsp[-1].node));}
#line 2872 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 324 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SelectionStatement((yyvsp[-2].node),(yyvsp[0].node),"if");}
#line 2878 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 325 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SelectionStatement((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node),"ifelse");}
#line 2884 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 326 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SelectionStatement((yyvsp[-2].node),(yyvsp[0].node),"switch");}
#line 2890 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 328 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IterationStatement((yyvsp[-2].node),(yyvsp[0].node),"while");}
#line 2896 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 329 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IterationStatement((yyvsp[-5].node),(yyvsp[-2].node),"dowhile");}
#line 2902 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 330 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IterationStatement((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node),"for");}
#line 2908 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 331 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IterationStatement((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node),"for");}
#line 2914 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 333 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new JumpStatement((yyvsp[-1].str),"goto");}
#line 2920 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 334 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new JumpStatement("continue");}
#line 2926 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 335 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new JumpStatement("break");}
#line 2932 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new JumpStatement("return");}
#line 2938 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 337 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new JumpStatement((yyvsp[-1].node),"return");}
#line 2944 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 339 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2950 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 340 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Program((yyvsp[-1].node),(yyvsp[0].node));}
#line 2956 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 342 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2962 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 343 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2968 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 345 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Function((yyvsp[-2].node),(yyvsp[-1].node));}
#line 2974 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 346 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Function((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 2980 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2984 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 350 "src/parser.y" /* yacc.c:1906  */


const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(char *filename)
{
  if(!filename)
  {
    cerr<<"file name is null"<<endl;
    exit(-1);
  }
  yyin = fopen(filename,"r");
  if(!yyin)
  {
    cerr<<"file can not open"<<endl;
    exit(-2);
  }
  // cout<<"work on it"<<endl;
  g_root=0;
  yyparse();
  return g_root;
}
