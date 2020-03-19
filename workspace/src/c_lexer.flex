%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

#include "c_parser.tab.hpp"
extern FILE* yyin;

// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);


void set_string_by_yytext();
bool isL();
bool isU();
void set_int_value_by_yytext(int format);
void set_float_value_by_yytext();


/* End the embedded code section. */
%}

IDENTIFIER  			[_a-zA-Z][0-9_a-zA-Z]*

INTEGER_SUFFIX          ([uU][lL]?) | ([lL][uU]?)

DECIMAL_CONSTANT        [1-9][0-9]*[integer_suffix]?

OCTAL_CONSTANT		    [0][0-7]*[integer_suffix]?

HEXAD_CONSTANT    		(0x|0X)[0-9a-fA-F]+[integer_suffix]?

CHAR_CONSTANT     		L?['][.]+[']

FLOAT_CONSTANT			([0-9]+|[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?)

WHITESPACE				[ \n\t\v\f\r]

STRINGLITERAL           L?\"(\\.|[^\\"])*\"


%%

auto					{ return T_AUTO;}
double					{ return T_DOUBLE;}
int						{ return T_INT;}
struct					{ return T_STRUCT;}
break					{ return T_BREAK;}
else					{ return T_ELSE;}
long					{ return T_LONG;}
switch					{ return T_SWITCH;}
case					{ return T_CASE;}
enum					{ return T_ENUM;}
register				{ return T_REGISTER;}
typedef					{ return T_TYPEDEF;}
char					{ return T_CHAR;}
extern					{ return T_EXTERN;}
return					{ return T_RETURN;}
union					{ return T_UNION;}
const					{ return T_CONST;}
float					{ return T_FLOAT;}
short					{ return T_SHORT;}
unsigned				{ return T_UNSIGNED;}
continue				{ return T_CONTINUE;}
for						{ return T_FOR;}
signed					{ return T_SIGNED;}
void					{ return T_VOID;}
default					{ return T_DEFAULT;}
goto					{ return T_GOTO;}
sizeof					{ return T_SIZEOF;}
volatile				{ return T_VOLATILE;}
do						{ return T_DO;}
if						{ return T_IF;}
static					{ return T_STATIC;}
while					{ return T_WHILE;}


[{]						{ return T_L_BRACE;}
[}]						{ return T_R_BRACE;}
[(]						{ return T_L_BRACKET;}
[)]						{ return T_R_BRACKET;}
[\[]					{ return T_L_SQUARE;}
[\]]					{ return T_R_SQUARE;}
	
[+]						{ return T_OP_PLUS;}
[\-]					{ return T_OP_MINUS;}
[*]						{ return T_OP_MUL; }
[/]						{ return T_OP_DIV; }
[%]						{ return T_OP_MOD; }
	
(\+\+) 					{ return T_OP_INC; }
	
[<]						{ return T_OP_LT; }
[>]						{ return T_OP_GT; }
	
[!]						{ return T_OP_LNOT; }
[&]						{ return T_OP_BAND; }
[|]						{ return T_OP_BOR; }
[\^]					{ return T_OP_BXOR; }
[~]						{ return T_OP_B_ONESC; }
[=]						{ return T_ASSIGN; }
(\+=)					{ return T_ADD_ASSIGN; }
(\*=)					{ return T_MUL_ASSIGN; }
[\?]					{ return T_QUESTION; }
[;]						{ return T_SEMICOLON; }
[,]						{ return T_COMMA; }
[\.]					{ return T_DOT; }

(;;)					{ return T_ENDLESS_LOOP; }


(\-=)					{ return T_SUB_ASSIGN; }
(>>=) 					{ return T_RIGHT_ASSIGN; }
(<<=)					{ return T_LEFT_ASSIGN; }
(>>)					{ return T_OP_BRIGHT; }
(<<)					{ return T_OP_BLEFT; }
(\->) 					{ return T_OP_PTR; }
(\/=)					{ return T_DIV_ASSIGN; }
(\^=)					{ return T_XOR_ASSIGN; }
(%=)					{ return T_MOD_ASSIGN; }
(&=)					{ return T_AND_ASSIGN; }
(\|=)					{ return T_OR_ASSIGN; }
(&&) 					{ return T_OP_LAND; }
(\|\|) 					{ return T_OP_LOR; }
(\-\-) 					{ return T_OP_DEC; }
(<=) 					{ return T_OP_LE; }
(>=) 					{ return T_OP_GE; }
(==) 					{ return T_OP_EQ; }
(!=)					{ return T_OP_NE; }

{IDENTIFIER}		{ 	/* 标识符 */
						set_string_by_yytext();
						return T_IDENTIFIER; 
					}
{DECIMAL_CONSTANT}  { 	/* 整型常量*/
						if(isL() and isU())		{ set_int_value_by_yytext(10); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(10); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(10); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(10); return T_INT_CONSTANT;}
					}
{OCTAL_CONSTANT}  	{ 	/*八进制常量*/
						if(isL() and isU())		{ set_int_value_by_yytext(8); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(8); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(8); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(8); return T_INT_CONSTANT;}
					}
					
{HEXAD_CONSTANT}  	{ 	/*十六进制*/
						if(isL() and isU())		{ set_int_value_by_yytext(16); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(16); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(16); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(16); return T_INT_CONSTANT;}
					}
{FLOAT_CONSTANT}	{ 	/*浮点常量*/
						set_float_value_by_yytext();
						return T_FLOAT_CONSTANT;
					}
{CHAR_CONSTANT}		{ 	/*字符常量*/
						yylval.characterValue = yytext[0];
						return T_CHARACTER_CONSTANT; 
					}
{STRINGLITERAL}		{ 	/*字符串常量*/
						set_string_by_yytext();
						return T_STRING_LITERAL;
					}

{WHITESPACE}    	{}

.					{ yyerror(yytext); exit(1);}


%%



/*-----------------------.
| function definition.  |
`-----------------------*/
//将yytest 给到
void set_string_by_yytext()
{
 	std::string *word = new std::string(yytext);
	yylval.string = word;
}
//是不是L后缀的整型常量
bool isL()
{
	int size = strlen(yytext);
	if(size < 2){
		return false;
	}
	if(yytext[size-1]=='l' || yytext[size-1]=='L')
		return true;
	else
		return false;
}
//是不是U后缀的整型常量
bool isU()
{
	int size = strlen(yytext);
	if(size < 2){
		return false;
	}
	
	if(yytext[size-1]=='u'|| yytext[size-1]=='U')
		return true;
	else
		return false;
}
void set_int_value_by_yytext(int format)
{
	char* end;
	yylval.intValue = std::strtol(yytext, &end, format);
}
void set_float_value_by_yytext()
{
	char* end;
	yylval.floatValue = strtof(yytext, &end);
}
/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}