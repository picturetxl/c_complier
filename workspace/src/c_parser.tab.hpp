/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
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
    T_INT = 258,
    T_IF = 259,
    T_ELSE = 260,
    T_WHILE = 261,
    T_VOID = 262,
    T_FLOAT = 263,
    T_DOUBLE = 264,
    T_AUTO = 265,
    T_BREAK = 266,
    T_CASE = 267,
    T_CHAR = 268,
    T_CONST = 269,
    T_CONTINUE = 270,
    T_DEFUALT = 271,
    T_DO = 272,
    T_ENUM = 273,
    T_EXTERN = 274,
    T_FOR = 275,
    T_GOTO = 276,
    T_LONG = 277,
    T_REGISTER = 278,
    T_SHORT = 279,
    T_SIGNED = 280,
    T_SIZEOF = 281,
    T_STATIC = 282,
    T_STRUCT = 283,
    T_SWITCH = 284,
    T_TYPEDEF = 285,
    T_UNION = 286,
    T_UNSIGNED = 287,
    T_VOLATILE = 288,
    T_INLINE = 289,
    T_DEFINE = 290,
    T_SOON = 291,
    T_ADD = 292,
    T_SUB = 293,
    T_MUL = 294,
    T_DIV = 295,
    T_MOD = 296,
    T_INC = 297,
    T_DEC = 298,
    T_EQ = 299,
    T_GE = 300,
    T_LE = 301,
    T_GR = 302,
    T_LS = 303,
    T_ADD_ASSIGN = 304,
    T_SUB_ASSIGN = 305,
    T_MUL_ASSIGN = 306,
    T_DIV_ASSIGN = 307,
    T_LPARENTHESIS = 308,
    T_RPARENTHESIS = 309,
    T_LBRACE = 310,
    T_RBRACE = 311,
    T_LSQUARE = 312,
    T_RSQUARE = 313,
    T_BOR = 314,
    T_BAND = 315,
    T_BXOR = 316,
    T_NOT = 317,
    T_LSHIFT = 318,
    T_RSHIFT = 319,
    T_POINTER = 320,
    T_QUESTION = 321,
    T_SEMICOLON = 322,
    T_SPOT = 323,
    T_COMMA = 324,
    T_COLON = 325,
    T_V_FLOAT = 326,
    T_INTEGER = 327,
    T_UINT = 328,
    T_LONGINT = 329,
    T_ULONG = 330,
    T_CHARACTOR = 331,
    T_V_STRING = 332,
    T_ID = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/c_parser.y" /* yacc.c:1909  */

  const Node *node;//节点
  double float_value;//浮点数
  int int_value;//整数
  //处理后缀情况
  unsigned int u_int_value;//u
  long int long_int_value;//l
  unsigned long u_long_value;//ul
  char char_value;//字符
  std::string *string_value;//标识符或者字面量字符串


#line 146 "src/c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */
