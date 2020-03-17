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
/* "%code requires" blocks.  */
#line 5 "src/c_parser.y" /* yacc.c:1909  */

  #include "../include/ast.hpp"

  #include <cassert>

  extern FILE* yyin;
  extern const Node *g_root; 


  int yylex(void);
  void yyerror(const char *);

#line 57 "src/c_parser.tab.hpp" /* yacc.c:1909  */

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
#line 19 "src/c_parser.y" /* yacc.c:1909  */

  const Node* node;
  std::string* string;
  int intValue;
  unsigned int uintValue;
  long int longintValue;
  unsigned long longuintValue;
  char characterValue;
  double floatValue;

#line 165 "src/c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */
