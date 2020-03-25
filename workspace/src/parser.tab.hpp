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
#line 19 "src/parser.y" /* yacc.c:1909  */

  const Node *node;
  double doubletype;
  int inttype;
  char chartype;
  std::string *str;

#line 145 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
