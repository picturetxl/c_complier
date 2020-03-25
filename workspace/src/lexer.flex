%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "ast.hpp"
//包含parser生成的头文件
#include "parser.tab.hpp"
#include <iostream>
#include <string>
using namespace std;
void yyerror (char const *s);

%}

ID          [_a-zA-Z][_a-zA-Z0-9]*
INTEGER     [1-9][0-9]*
FLOAT        ([0-9]+|[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?)
WHITESPACE  [ \n\t\v\f\r]
CHARACTOR   L?['][.]+[']
STRING      L?\"(\\.|[^\\"])*\"


%%

int        {return T_K_INT;}
return     return T_K_RETURN;
struct     return T_K_STRUCT;
for        return T_K_FOR;
double     return T_K_DOUBLE;
float      return T_K_FLOAT;
if         return T_K_IF;
else       return T_K_ELSE;
switch     return T_K_SWITCH;
while      return T_K_WHILE;
default    return T_K_DEFAULT;
typedef    return T_K_TYPEDEF;
sizeof     return T_K_SIZEOF;
static     return T_K_STATIC;
extern     return T_K_EXTERN;
void       {return T_K_VOID;}
char       return T_K_CHAR;
short      return T_K_SHORT;
long       return T_K_LONG;
signed     return T_K_SIGNED;
unsigned   return T_K_UNSIGNED;
union      return T_K_UNION;
enum       return T_K_ENUM;
const      return T_K_CONST;
volatile   return T_K_VOLATILE;
case       return T_K_CASE; 
do         return T_K_DO;
goto       return T_K_GOTO;
continue   return T_K_CONTINUE;
break      return T_K_BREAK;
auto       return T_K_AUTO;
"..."      return T_XLH;

{ID}        {yylval.str = new string(yytext);return T_ID;}
{INTEGER}   {yylval.inttype=stoi(string(yytext));return T_V_INTEGER; }
{FLOAT}     {yylval.doubletype = stod(string(yytext));return T_V_FLOAT;}

{CHARACTOR} {yylval.chartype = yytext[0];return T_V_CHAR;}

{STRING}    {yylval.str = new string(yytext);return T_V_STRING;}



[<]        return T_LT;
[>]        return T_GT;
[/]   	   return T_DIV;
[%]        return T_MOD;
[#]        return T_JH;
[-]        return T_MINUS;

[&]        return T_AND;
[|]        return T_OR;
[~]        return T_QF;
[!]        return T_NOT;
[{]		     {return T_LDKH;}
[}]		     {return T_RDKH;}
[(]		     return T_LXKH;
[)]		     return T_RXKH;
[;]		     return T_FH;
[]]	       return T_RZKH;
[[]	       return T_LZKH;
[=]        {return T_ASSIGN;}
[,]         return T_DH;
[:]         return T_MH;

\?         return T_WH;
\^         return T_XOR;
\*         return T_MUL;
\.         return T_DOT;
\+         return T_ADD;

"+="       return T_ADD_ASSIGN; 
"-="       return T_SUB_ASSIGN;
"*="       return T_MUL_ASSIGN;
"/="       return T_DIV_ASSIGN;
"|="       return T_OR_ASSIGN;
"&="       return T_AND_ASSIGN;
"&&"       return T_LAND;
"||"       return T_LOR;
"<<"       return T_SHIFT_LEFT;
">>"       return T_SHIFT_RIGHT;
"<="       return T_LE;
">="       return T_GE;
"++"       return T_ADDADD;
"--"       return T_SUBSUB;
"->"       return T_ARROW;
"=="       return T_EQ;
"!="       return T_NEQ;


{WHITESPACE}    ;

.           {yyerror(yytext);}


%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
