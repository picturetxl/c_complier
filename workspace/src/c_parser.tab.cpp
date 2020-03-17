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

#line 67 "src/c_parser.tab.cpp" /* yacc.c:339  */

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
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 5 "src/c_parser.y" /* yacc.c:355  */

  #include "../include/ast.hpp"

  #include <cassert>

  extern FILE* yyin;
  extern const Node *g_root; 


  int yylex(void);
  void yyerror(const char *);

#line 110 "src/c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AUTO = 258,
    T_DOUBLE = 259,
    T_INT = 260,
    T_STRUCT = 261,
    T_BREAK = 262,
    T_ELSE = 263,
    T_LONG = 264,
    T_SWITCH = 265,
    T_CASE = 266,
    T_ENUM = 267,
    T_ELIPSIS = 268,
    T_REGISTER = 269,
    T_TYPEDEF = 270,
    T_CHAR = 271,
    T_EXTERN = 272,
    T_RETURN = 273,
    T_UNION = 274,
    T_CONST = 275,
    T_FLOAT = 276,
    T_SHORT = 277,
    T_UNSIGNED = 278,
    T_CONTINUE = 279,
    T_FOR = 280,
    T_SIGNED = 281,
    T_VOID = 282,
    T_DEFAULT = 283,
    T_GOTO = 284,
    T_SIZEOF = 285,
    T_VOLATILE = 286,
    T_DO = 287,
    T_IF = 288,
    T_STATIC = 289,
    T_WHILE = 290,
    T_IDENTIFIER = 291,
    T_STRING_LITERAL = 292,
    T_UNSIGNED_LONG_CONSTANT = 293,
    T_LONG_CONSTANT = 294,
    T_UNSIGNED_CONSTANT = 295,
    T_INT_CONSTANT = 296,
    T_FLOAT_CONSTANT = 297,
    T_CHARACTER_CONSTANT = 298,
    T_L_BRACE = 299,
    T_R_BRACE = 300,
    T_L_BRACKET = 301,
    T_R_BRACKET = 302,
    T_L_SQUARE = 303,
    T_R_SQUARE = 304,
    T_OP_PLUS = 305,
    T_OP_MINUS = 306,
    T_OP_MUL = 307,
    T_OP_DIV = 308,
    T_OP_MOD = 309,
    T_OP_INC = 310,
    T_OP_DEC = 311,
    T_OP_LE = 312,
    T_OP_GE = 313,
    T_OP_EQ = 314,
    T_OP_NE = 315,
    T_OP_LT = 316,
    T_OP_GT = 317,
    T_OP_LAND = 318,
    T_OP_LOR = 319,
    T_OP_LNOT = 320,
    T_OP_BAND = 321,
    T_OP_BOR = 322,
    T_OP_BXOR = 323,
    T_OP_B_ONESC = 324,
    T_OP_BRIGHT = 325,
    T_OP_BLEFT = 326,
    T_OP_PTR = 327,
    T_ASSIGN = 328,
    T_RIGHT_ASSIGN = 329,
    T_LEFT_ASSIGN = 330,
    T_ADD_ASSIGN = 331,
    T_SUB_ASSIGN = 332,
    T_MUL_ASSIGN = 333,
    T_DIV_ASSIGN = 334,
    T_MOD_ASSIGN = 335,
    T_AND_ASSIGN = 336,
    T_OR_ASSIGN = 337,
    T_XOR_ASSIGN = 338,
    T_ENDLESS_LOOP = 339
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/c_parser.y" /* yacc.c:355  */

  const Node* node;
  std::string* string;
  int intValue;
  unsigned int uintValue;
  long int longintValue;
  unsigned long longuintValue;
  char characterValue;
  double floatValue;

#line 218 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  92
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1014

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

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
       2,     2,     2,     2,    86,     2,    89,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    85,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    92,    93,    97,    98,   101,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   130,   133,   134,   135,
     136,   141,   144,   147,   148,   149,   152,   156,   157,   158,
     159,   160,   162,   166,   169,   170,   173,   178,   181,   185,
     189,   190,   194,   197,   198,   201,   202,   203,   204,   205,
     209,   210,   213,   216,   220,   221,   222,   223,   224,   225,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   243,   244,   245,   246,   247,   248,   249,
     250,   254,   259,   260,   261,   263,   264,   266,   268,   270,
     273,   276,   277,   278,   279,   280,   281,   284,   285,   288,
     289,   294,   295,   296,   297,   301,   302,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AUTO", "T_DOUBLE", "T_INT",
  "T_STRUCT", "T_BREAK", "T_ELSE", "T_LONG", "T_SWITCH", "T_CASE",
  "T_ENUM", "T_ELIPSIS", "T_REGISTER", "T_TYPEDEF", "T_CHAR", "T_EXTERN",
  "T_RETURN", "T_UNION", "T_CONST", "T_FLOAT", "T_SHORT", "T_UNSIGNED",
  "T_CONTINUE", "T_FOR", "T_SIGNED", "T_VOID", "T_DEFAULT", "T_GOTO",
  "T_SIZEOF", "T_VOLATILE", "T_DO", "T_IF", "T_STATIC", "T_WHILE",
  "T_IDENTIFIER", "T_STRING_LITERAL", "T_UNSIGNED_LONG_CONSTANT",
  "T_LONG_CONSTANT", "T_UNSIGNED_CONSTANT", "T_INT_CONSTANT",
  "T_FLOAT_CONSTANT", "T_CHARACTER_CONSTANT", "T_L_BRACE", "T_R_BRACE",
  "T_L_BRACKET", "T_R_BRACKET", "T_L_SQUARE", "T_R_SQUARE", "T_OP_PLUS",
  "T_OP_MINUS", "T_OP_MUL", "T_OP_DIV", "T_OP_MOD", "T_OP_INC", "T_OP_DEC",
  "T_OP_LE", "T_OP_GE", "T_OP_EQ", "T_OP_NE", "T_OP_LT", "T_OP_GT",
  "T_OP_LAND", "T_OP_LOR", "T_OP_LNOT", "T_OP_BAND", "T_OP_BOR",
  "T_OP_BXOR", "T_OP_B_ONESC", "T_OP_BRIGHT", "T_OP_BLEFT", "T_OP_PTR",
  "T_ASSIGN", "T_RIGHT_ASSIGN", "T_LEFT_ASSIGN", "T_ADD_ASSIGN",
  "T_SUB_ASSIGN", "T_MUL_ASSIGN", "T_DIV_ASSIGN", "T_MOD_ASSIGN",
  "T_AND_ASSIGN", "T_OR_ASSIGN", "T_XOR_ASSIGN", "T_ENDLESS_LOOP", "';'",
  "','", "':'", "\";\"", "'.'", "$accept", "ROOT", "PROGRAM",
  "EXTERNAL_OBJECT", "FUNCTION", "STATEMENT", "RETURN_STATEMENT",
  "DECLARATION_STATEMENT", "ARRAY_DECLARATION", "FUNCTION_DECLARATION",
  "REGULAR_DECLARATION", "STRUCT_DECLARATION", "ASSIGNMENT_STATEMENT",
  "ASSIGNMENT_DEFINITION", "COMPARE_STATEMENT", "IF_ELSE_STATEMENT",
  "WHILE_STATEMENT", "FOR_STATEMENT", "ENUM_STATEMENT", "SWITCH_STATEMENT",
  "CASE_STATEMENT", "BREAK_STATEMENT", "TYPEDEF_STATEMENT",
  "TWO_OP_STATEMENT", "INCREASE_STATEMENT", "STRUCT_STATEMENT",
  "SIZEOF_STATEMENT", "EXPR", "OP_EXPR", "SINGLE_EXPR", "LOGIC_EXPR",
  "NUMBER", "CHARACTOR", "INTEGER", "FLOAT", "DOT", "FUNCTION_CALL",
  "TYPE", "POINTER", "LIST", "ARG_LIST", "FOR_LIST", YY_NULLPTR
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
     335,   336,   337,   338,   339,    59,    44,    58,   340,    46
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     321,   -97,   -97,   132,   -71,   -28,   930,   -14,    -2,   930,
     -97,   -23,   -20,   -19,    -8,   -32,   -97,   -97,   -97,   -97,
     321,   930,   -18,   -97,   321,   321,   930,   930,    32,   321,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    -2,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   556,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,     5,   948,   -33,    -6,   948,   -97,
     930,   -32,   587,     8,   -97,    -2,   -10,   618,   264,   930,
     930,   930,   264,   930,     3,     5,   388,   -97,   -97,   -97,
     897,   897,   -97,   -97,   -97,    13,   930,   930,   930,   930,
     930,   930,   930,   930,   930,   930,   930,   930,   930,   930,
     930,   930,   930,   930,   -97,   930,    18,   -38,   -97,   897,
     321,   930,   930,   930,   930,   649,   412,   378,   321,   -97,
      65,   -97,   -97,   -97,   -97,   556,    11,   321,   321,   436,
     460,   484,    21,   508,   -97,   -13,   -97,     1,   897,   897,
     897,   897,   897,   897,   680,   897,   897,   897,   897,   897,
     711,   742,   773,   804,   835,   866,   897,   930,   930,   -97,
     -97,   321,   -97,    20,   -12,   897,   897,   -97,    27,   321,
     -97,    31,   -97,    35,   -97,   556,   -97,    -1,    33,    41,
     -97,   -97,   -97,   -97,    91,   -97,   -97,   -97,   -97,   -97,
     532,   897,    42,     7,    77,    44,     9,   321,   -97,   321,
     321,    10,   -97,   -97,    45,   -97,   -97,    46,    51,    52,
     -97,   -97,   -97,    90,   -97,    55,   321,    57,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,   101,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,    86,    96,    97,    98,    95,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     2,
       3,     6,     5,     9,    10,    27,    28,    29,    30,    11,
      41,    13,    14,    15,    12,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    66,    64,    65,    83,    89,
      92,    94,    90,    84,     0,     0,    86,     0,     0,    52,
       0,    86,     0,     0,   104,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     8,     8,
      68,    68,     1,     4,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,    35,     0,   107,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     105,   107,    26,   117,     8,    68,     0,   109,   110,     0,
       0,     0,     0,     0,    16,     0,    67,     0,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      39,     0,     0,     0,     0,     0,    68,     0,     0,    33,
      34,     0,    32,     0,    92,    68,    68,    36,     0,     0,
       8,     0,    54,     0,     8,    68,     8,     0,     0,     0,
     100,    85,    43,    37,    38,    55,    58,    57,    59,    56,
       0,    42,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     7,    62,     0,    16,    48,     0,     0,     0,
      31,    49,    47,    45,    46,     0,     0,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,    78,   -97,   -15,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,    67,   -97,   -97,   -97,   -97,   -97,   -97,
     -96,   -97,   -97,   -97,   -97,   -97,   -97,   136,   -97,   -97,
     -97,   -97,   -97,   -21,   -97,   -97,   -57,     4,     0,    28,
     -97,   -97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    85,    68,   136,
     137,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    87,     1,     2,    64,    84,   171,   117,    76,    88,
      89,   120,    75,    82,    82,    83,    83,    69,    70,    10,
      65,    78,    73,    17,    65,    65,    79,    80,   145,    65,
      71,    16,    92,    64,    74,    17,    18,    19,    81,    76,
      21,   116,   131,    95,    96,   121,   122,   172,   144,   147,
      23,    99,   128,   100,   101,   123,   183,   103,   104,    26,
     124,   106,   107,   134,    82,   203,   167,   134,   190,     1,
       2,   204,   172,   -93,   168,   130,   206,   209,    65,   129,
     114,   207,    65,   115,   208,   210,    10,   212,     6,   215,
     221,   168,   213,   222,   216,   220,   223,   224,   225,   226,
     174,    74,   228,   169,   170,   173,    94,    93,   214,     0,
     142,     0,   180,   181,     0,     0,     0,   118,     0,     0,
      65,     0,   184,   186,     0,     0,     0,    65,    65,     0,
      76,     0,     0,     0,   182,     0,     0,    65,    65,    67,
       0,   -69,    72,     0,     0,    77,     0,     0,   -69,     0,
     -69,   -69,   -69,     0,   -69,   -69,   202,    86,   -69,   -69,
       0,     0,    90,    91,   205,     0,     0,     0,    66,    16,
       0,    65,     0,    17,    18,    19,   -69,   -69,    21,    65,
     -69,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,   217,     0,   218,   219,     0,    26,    27,     0,
       0,   119,     0,   125,   119,     0,   126,    65,     0,    65,
      65,   227,     0,     0,   135,   139,   140,   141,   135,   143,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   166,     0,     0,     0,     0,     0,   149,   150,   175,
     176,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     0,   185,     5,     6,     7,     0,     0,     8,
       0,     0,     9,     0,     0,    10,     0,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,    13,     0,    14,
      15,    16,     0,   200,   201,    17,    18,    19,    20,     0,
      21,     0,     0,     0,     0,    22,    23,     0,     0,    24,
      25,     0,     0,     0,     0,     1,     2,     3,     4,    26,
      27,     5,     6,     7,     0,     0,     8,     0,     0,     9,
       0,     0,    10,     0,     0,     0,    11,     0,   133,     0,
       0,    12,     0,     0,    13,     0,    14,    15,    16,     0,
       0,     0,    17,    18,    19,    20,     0,    21,     0,     0,
       0,     0,    22,    23,     0,     0,    24,    25,     0,     0,
       0,     0,     1,     2,     3,     4,    26,    27,     5,     6,
       7,     0,     0,     8,     0,     0,     9,     0,     0,    10,
       0,     0,     0,    11,     0,     0,     0,     0,    12,     0,
       0,    13,     0,    14,    15,    16,     0,     0,     0,    17,
      18,    19,   179,     0,    21,     0,     0,     0,     0,    22,
      23,     0,     0,    24,    25,   146,     0,     0,    96,    97,
      98,     0,     0,    26,    27,    99,     0,   100,   101,   123,
       0,   103,   104,     0,   105,   106,   107,     0,     0,   178,
       0,     0,    96,    97,    98,     0,     0,     0,     0,    99,
       0,   100,   101,   123,   114,   103,   104,   115,   105,   106,
     107,     0,     0,   187,     0,     0,    96,    97,    98,     0,
       0,     0,     0,    99,     0,   100,   101,   123,   114,   103,
     104,   115,   105,   106,   107,     0,     0,   188,     0,     0,
      96,    97,    98,     0,     0,     0,     0,    99,     0,   100,
     101,   123,   114,   103,   104,   115,   105,   106,   107,     0,
       0,   189,     0,     0,    96,    97,    98,     0,     0,     0,
       0,    99,     0,   100,   101,   123,   114,   103,   104,   115,
     105,   106,   107,     0,     0,     0,     0,   191,    96,    97,
      98,     0,     0,     0,     0,    99,     0,   100,   101,   123,
     114,   103,   104,   115,   105,   106,   107,     0,     0,     0,
       0,   211,    96,    97,    98,     0,     0,     0,     0,    99,
       0,   100,   101,   123,   114,   103,   104,   115,   105,   106,
     107,     0,     0,     0,     0,     0,    96,    97,    98,     0,
       0,     0,     0,    99,     0,   100,   101,   102,   114,   103,
     104,   115,   105,   106,   107,     0,     0,     0,     0,   108,
       0,     0,   109,   110,   111,   112,   113,    96,    97,    98,
       0,     0,   114,     0,    99,   115,   100,   101,   123,     0,
     103,   104,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,     0,   114,   127,    99,   115,   100,   101,   123,
       0,   103,   104,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   132,   114,     0,    99,   115,   100,   101,
     123,     0,   103,   104,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   177,   114,     0,    99,   115,   100,
     101,   123,     0,   103,   104,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   192,   114,     0,    99,   115,
     100,   101,   123,     0,   103,   104,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   193,   194,     0,    99,
     115,   100,   101,   123,     0,   103,   104,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   195,   114,     0,
      99,   115,   100,   101,   123,     0,   103,   104,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   196,   114,
       0,    99,   115,   100,   101,   123,     0,   103,   104,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   197,
     114,     0,    99,   115,   100,   101,   123,     0,   103,   104,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     198,   114,     0,    99,   115,   100,   101,   123,     0,   103,
     104,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   199,   114,     0,    99,   115,   100,   101,   123,     0,
     103,   104,     0,   105,   106,   107,    71,    16,     0,     0,
       0,    17,    18,    19,     0,     0,    21,     0,     0,     0,
       0,    22,    23,   114,    71,    16,   115,     0,     0,    17,
      18,    19,     0,     0,    21,    26,    27,     0,     0,    22,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27
};

static const yytype_int16 yycheck[] =
{
       0,    22,     4,     5,     0,    20,    44,    64,     8,    24,
      25,    44,     8,    46,    46,    48,    48,    88,    46,    21,
      20,    44,    36,    41,    24,    25,    46,    46,    85,    29,
      36,    37,     0,    29,    36,    41,    42,    43,    46,    39,
      46,    36,    52,    39,    50,    51,    52,    85,    45,    36,
      52,    57,    44,    59,    60,    61,    45,    63,    64,    65,
      66,    67,    68,    78,    46,    45,    48,    82,    47,     4,
       5,    44,    85,    85,    73,    75,    45,    44,    78,    75,
      86,    46,    82,    89,    85,    44,    21,    45,    11,    45,
      45,    73,    85,    47,    85,    85,    45,    45,     8,    44,
     121,    36,    45,    85,    86,   120,    39,    29,   204,    -1,
      82,    -1,   127,   128,    -1,    -1,    -1,    52,    -1,    -1,
     120,    -1,   137,   138,    -1,    -1,    -1,   127,   128,    -1,
     130,    -1,    -1,    -1,   130,    -1,    -1,   137,   138,     3,
      -1,    50,     6,    -1,    -1,     9,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,    63,    64,   171,    21,    67,    68,
      -1,    -1,    26,    27,   179,    -1,    -1,    -1,    36,    37,
      -1,   171,    -1,    41,    42,    43,    85,    86,    46,   179,
      89,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,   209,   210,    -1,    65,    66,    -1,
      -1,    65,    -1,    67,    68,    -1,    70,   207,    -1,   209,
     210,   226,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,    -1,   137,    10,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    37,    -1,   167,   168,    41,    42,    43,    44,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      56,    -1,    -1,    -1,    -1,     4,     5,     6,     7,    65,
      66,    10,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    84,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,    65,    66,    10,    11,
      12,    -1,    -1,    15,    -1,    -1,    18,    -1,    -1,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    56,    47,    -1,    -1,    50,    51,
      52,    -1,    -1,    65,    66,    57,    -1,    59,    60,    61,
      -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,    47,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    86,    63,    64,    89,    66,    67,
      68,    -1,    -1,    47,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    86,    63,
      64,    89,    66,    67,    68,    -1,    -1,    47,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    86,    63,    64,    89,    66,    67,    68,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    86,    63,    64,    89,
      66,    67,    68,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      86,    63,    64,    89,    66,    67,    68,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    86,    63,    64,    89,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    86,    63,
      64,    89,    66,    67,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    77,    78,    79,    80,    50,    51,    52,
      -1,    -1,    86,    -1,    57,    89,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    86,    87,    57,    89,    59,    60,    61,
      -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    85,    86,    -1,    57,    89,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    85,    86,    -1,    57,    89,    59,
      60,    61,    -1,    63,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    85,    86,    -1,    57,    89,
      59,    60,    61,    -1,    63,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    85,    86,    -1,    57,
      89,    59,    60,    61,    -1,    63,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    85,    86,    -1,
      57,    89,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    85,    86,
      -1,    57,    89,    59,    60,    61,    -1,    63,    64,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    85,
      86,    -1,    57,    89,    59,    60,    61,    -1,    63,    64,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      85,    86,    -1,    57,    89,    59,    60,    61,    -1,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    85,    86,    -1,    57,    89,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    68,    36,    37,    -1,    -1,
      -1,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    86,    36,    37,    89,    -1,    -1,    41,
      42,    43,    -1,    -1,    46,    65,    66,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,    10,    11,    12,    15,    18,
      21,    25,    30,    33,    35,    36,    37,    41,    42,    43,
      44,    46,    51,    52,    55,    56,    65,    66,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    36,   117,   128,    88,
      46,    36,   117,    36,    36,   127,   128,   117,    44,    46,
      46,    46,    46,    48,    95,   127,   117,   123,    95,    95,
     117,   117,     0,    93,   103,   127,    50,    51,    52,    57,
      59,    60,    61,    63,    64,    66,    67,    68,    73,    76,
      77,    78,    79,    80,    86,    89,    36,   126,    52,   117,
      44,    51,    52,    61,    66,   117,   117,    87,    44,   127,
     128,    52,    85,    84,    95,   117,   129,   130,   131,   117,
     117,   117,   129,   117,    45,   126,    47,    36,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,    48,    73,    85,
      86,    44,    85,    95,   123,   117,   117,    85,    47,    44,
      95,    95,   127,    45,    95,   117,    95,    47,    47,    47,
      47,    49,    85,    85,    86,    85,    85,    85,    85,    85,
     117,   117,    95,    45,    44,    95,    45,    46,    85,    44,
      44,    49,    45,    85,   110,    45,    85,    95,    95,    95,
      85,    45,    47,    45,    45,     8,    44,    95,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    92,    93,    93,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    97,    97,    97,
      97,    98,    99,   100,   100,   100,   101,   102,   102,   102,
     102,   102,   103,   104,   105,   105,   106,   107,   108,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   115,   116,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   121,   121,   121,   122,   122,   123,   124,   125,
     126,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     6,     3,     3,     3,     2,     4,     4,     4,     3,
       2,     1,     4,     4,    11,     7,     7,     7,     6,     7,
       6,     4,     2,     3,     4,     4,     4,     4,     4,     4,
       2,     2,     6,     5,     1,     1,     1,     3,     1,     2,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     1,     2,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     1
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
#line 92 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1652 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Program((yyvsp[-1].node),(yyvsp[0].node));}
#line 1658 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1664 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1670 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new Function((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1676 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1682 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1688 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 111 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1694 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 112 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1700 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1706 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1712 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1718 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 116 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1724 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 117 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1730 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1736 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1742 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 120 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1748 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1754 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1760 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 123 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1766 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1772 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 125 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1778 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 126 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1784 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1790 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1796 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 134 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1802 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 135 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1808 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 136 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1814 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 141 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ArrayDeclaration((yyvsp[-5].node),(yyvsp[-2].node));}
#line 1820 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 144 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new FunctionDeclaration((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1826 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularDeclaration((yyvsp[-2].node));}
#line 1832 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularDeclaration((yyvsp[-2].node));}
#line 1838 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 149 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new RegularDeclaration((yyvsp[-1].node));}
#line 1844 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructDeclaration((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1850 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 156 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignmentStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1856 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 157 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignmentStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1862 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignmentStatement((yyvsp[-2].node),(yyvsp[0].node));}
#line 1868 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 159 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignmentStatement((yyvsp[-1].node),(yyvsp[0].node));}
#line 1874 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 160 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1880 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 162 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new AssignDefinition((yyvsp[-3].node),(yyvsp[0].node));}
#line 1886 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 166 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)= new CompareStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1892 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 169 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IfelseStatment((yyvsp[-8].node),(yyvsp[-5].node),(yyvsp[-1].node));}
#line 1898 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new IfelseStatment((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1904 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new WhileStatement((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1910 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 178 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ForStatement((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1916 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 181 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node);}
#line 1922 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 185 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SwitchStatement((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1928 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 189 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CaseStatement((yyvsp[-4].node),(yyvsp[-1].node));}
#line 1934 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 190 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new CaseStatement((yyvsp[-2].node),(yyvsp[0].node));}
#line 1940 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 194 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Break("break");}
#line 1946 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 197 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TypedefStatement((yyvsp[-1].node),(yyvsp[0].node));}
#line 1952 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 198 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TypedefStatement((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1958 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 201 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TwoOpStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1964 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 202 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TwoOpStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1970 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 203 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TwoOpStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1976 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 204 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TwoOpStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1982 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 205 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new TwoOpStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1988 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 209 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1994 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 210 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2000 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 213 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new StructStatement((yyvsp[-2].node));}
#line 2006 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 216 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SizeofStatement((yyvsp[-2].node));}
#line 2012 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 220 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2018 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 221 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2024 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 222 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2030 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 223 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2036 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 224 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2042 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 225 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2048 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 228 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2054 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 229 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2060 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 230 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2066 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 231 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2072 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 232 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2078 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 233 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2084 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 234 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2090 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 235 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2096 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 236 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2102 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 237 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2108 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2114 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2120 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new OpExpression((yyvsp[-2].node),(yyvsp[0].node));}
#line 2126 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 243 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node); }
#line 2132 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 244 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2138 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 245 "src/c_parser.y" /* yacc.c:1646  */
    {/*数组*/ (yyval.node)=(yyvsp[-1].node);}
#line 2144 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 246 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Identify((yyvsp[0].string));}
#line 2150 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 247 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new SingleExpression((yyvsp[-1].node),(yyvsp[0].node));}
#line 2156 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 248 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2162 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 249 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2168 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 250 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2174 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 254 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2180 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 259 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2186 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 260 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2192 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 261 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2198 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 263 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Charator((yyvsp[0].characterValue));}
#line 2204 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 264 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new String((yyvsp[0].string));}
#line 2210 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 266 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Integer((yyvsp[0].intValue));}
#line 2216 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 268 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Float((yyvsp[0].floatValue));}
#line 2222 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 270 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new Dot((yyvsp[-2].node),(yyvsp[0].node));}
#line 2228 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 273 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2234 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 276 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypeInt("int");}
#line 2240 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 277 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypeDouble("double");}
#line 2246 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 278 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypeFloat("float");}
#line 2252 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 279 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new Identify((yyvsp[0].string));}
#line 2258 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 280 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2264 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 281 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2270 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 284 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2276 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 285 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new TypeStar("*");}
#line 2282 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 288 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2288 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 289 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2294 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 294 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ArgList((yyvsp[-1].node),(yyvsp[0].node));}
#line 2300 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 295 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2306 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 296 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ArgList((yyvsp[-1].node),(yyvsp[0].node));}
#line 2312 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 297 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2318 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 301 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new ForList((yyvsp[-1].node),(yyvsp[0].node));}
#line 2324 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 302 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2330 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 303 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node)=new String((yyvsp[0].string));}
#line 2336 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2340 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 305 "src/c_parser.y" /* yacc.c:1906  */



const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(char* x)
{
  yyin = fopen(x, "r");
  g_root=0;
  if(yyin) yyparse();
  fclose(yyin);
  return g_root;
}

