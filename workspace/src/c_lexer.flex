%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

#include "c_parser.tab.hpp"
#include "c_lexer_helper.hpp"

extern FILE* yyin;

// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}
		
IDENTIFIER  			[_a-zA-Z][0-9_a-zA-Z]*

INTEGER_SUFFIX          ([uU][lL]?) | ([lL][uU]?)

DECIMAL_CONSTANT        [1-9][0-9]*[integer_suffix]?

OCTAL_CONSTANT		    [0][0-7]*[integer_suffix]?

HEXAD_CONSTANT    		(0x|0X)[0-9a-fA-F]+[integer_suffix]?

CHAR_CONSTANT     		L?['][.]+[']

FLOAT_CONSTANT			([0-9]+|[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?)

INCLUDE					#[.^\n]

COMMENT					"/*"[^"*/"]*"*/"

WHITESPACE				[ \n\t\v\f\r]

STRINGLITERAL           L?\"(\\.|[^\\"])*\"

OTHER					.




%%

"auto"				{ fprintf(stderr, "AUTO\n"); 		return T_AUTO;}
"double"			{ fprintf(stderr, "DOUBLE\n"); 		return T_DOUBLE;}
"int"				{ fprintf(stderr, "INT\n"); 		return T_INT;}
"struct"			{ fprintf(stderr, "STRUCT\n");		return T_STRUCT;}
"break"				{ fprintf(stderr, "BREAK\n");		return T_BREAK;}
"else"				{ fprintf(stderr, "ELSE\n");		return T_ELSE;}
"long"				{ fprintf(stderr, "LONG\n");		return T_LONG;}
"switch"			{ fprintf(stderr, "SWITCH\n");		return T_SWITCH;}
"case"				{ fprintf(stderr, "CASE\n");		return T_CASE;}
"enum"				{ fprintf(stderr, "ENUM\n");		return T_ENUM;}
"..." 				{ fprintf(stderr, "ELIPSIS\n");		return T_ELIPSIS;}
"register"			{ fprintf(stderr, "REGISTER\n");	return T_REGISTER;}
"typedef"			{ fprintf(stderr, "TYPEDEF\n");		return T_TYPEDEF;}
"char"				{ fprintf(stderr, "CHAR\n");		return T_CHAR;}
"extern"			{ fprintf(stderr, "EXTERN\n");		return T_EXTERN;}
"return"			{ fprintf(stderr, "RETURN\n");		return T_RETURN;}
"union"				{ fprintf(stderr, "UNION\n");		return T_UNION;}
"const"				{ fprintf(stderr, "CONST\n");		return T_CONST;}
"float"				{ fprintf(stderr, "FLOAT\n");		return T_FLOAT;}
"short"				{ fprintf(stderr, "SHORT\n");		return T_SHORT;}
"unsigned"			{ fprintf(stderr, "UNSIGNED\n");	return T_UNSIGNED;}
"continue"			{ fprintf(stderr, "CONTINUE\n");	return T_CONTINUE;}
"for"				{ fprintf(stderr, "FOR\n");			return T_FOR;}
"signed"			{ fprintf(stderr, "SIGNED\n");		return T_SIGNED;}
"void"				{ fprintf(stderr, "VOID\n");		eturn T_VOID;}
"default"			{ fprintf(stderr, "DEFAULT\n");		return T_DEFAULT;}
"goto"				{ fprintf(stderr, "GOTO\n");		eturn T_GOTO;}
"sizeof"			{ fprintf(stderr, "SIZEOF\n");		return T_SIZEOF;}
"volatile"			{ fprintf(stderr, "VOLATILE\n");	return T_VOLATILE;}
"do"				{ fprintf(stderr, "DO\n");			return T_DO;}
"if"				{ fprintf(stderr, "IF\n");			return T_IF;}
"static"			{ fprintf(stderr, "STATIC\n");		return T_STATIC;}
"while"				{ fprintf(stderr, "WHILE\n");		return T_WHILE;}


{IDENTIFIER}		{ 	/* 标识符 */
						fprintf(stderr, "Identifier : %s\n", yytext);
						set_string_by_yytext();
						return T_IDENTIFIER; 
					}

{DECIMAL_CONSTANT}  { 	/* 整型常量*/
						fprintf(stderr, "Decimal : %s\n", yytext);
						if(isL() and isU())		{ set_int_value_by_yytext(10); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(10); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(10); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(10); return T_INT_CONSTANT;}
					}

{OCTAL_CONSTANT}  	{ 	/*八进制常量*/
						fprintf(stderr, "Octal : %s\n", yytext);
						if(isL() and isU())		{ set_int_value_by_yytext(8); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(8); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(8); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(8); return T_INT_CONSTANT;}
					}
					
{HEXAD_CONSTANT}  	{ 	/*十六进制*/
						fprintf(stderr, "Hexadecimal : %s\n", yytext);
						if(isL() and isU())		{ set_int_value_by_yytext(16); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(16); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(16); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(16); return T_INT_CONSTANT;}
					}

{FLOAT_CONSTANT}	{ 	/*浮点常量*/
						fprintf(stderr, "Float constant : %s\n", yytext);
						set_float_value_by_yytext();
						return T_FLOAT_CONSTANT;
					}

{CHAR_CONSTANT}		{ 	/*字符常量*/
						fprintf(stderr, "Character : %s\n", yytext);
						yylval.characterValue = yytext[0];
						return T_CHARACTER_CONSTANT; 
					}

{STRINGLITERAL}		{ 	/*字符串常量*/
						fprintf(stderr, "String : %s\n", yytext);
						set_string_by_yytext();
						return T_STRING_LITERAL;
					}


"{"					{ fprintf(stderr, "L_BRACE\n");return T_L_BRACE; }
"}"					{ fprintf(stderr, "R_BRACE\n");return T_R_BRACE; }
"("					{ fprintf(stderr, "L_BRACKET\n");return T_L_BRACKET; }
")"					{ fprintf(stderr, "R_BRACKET\n");return T_R_BRACKET; }
"["					{ fprintf(stderr, "L_SQUARE\n");return T_L_SQUARE; }
"]"					{ fprintf(stderr, "R_SQUARE\n");return T_R_SQUARE; }

"+"					{ fprintf(stderr, "OP_PLUS\n");return T_OP_PLUS; }
"-"					{ fprintf(stderr, "OP_MINUS\n");return T_OP_MINUS; }
"*"					{ fprintf(stderr, "OP_MUL\n");return T_OP_MUL; }
"/"					{ fprintf(stderr, "OP_DIV\n");return T_OP_DIV; }
"%"					{ fprintf(stderr, "OP_MOD\n");return T_OP_MOD; }

"++" 				{ fprintf(stderr, "OP_INC\n");return T_OP_INC; }
"--" 				{ fprintf(stderr, "OP_DEC\n");return T_OP_DEC; }
"<=" 				{ fprintf(stderr, "OP_LE\n");return T_OP_LE; }
">=" 				{ fprintf(stderr, "OP_GE\n");return T_OP_GE; }
"==" 				{ fprintf(stderr, "OP_EQ\n");return T_OP_EQ; }
"!="				{ fprintf(stderr, "OP_NE\n");return T_OP_NE; }
"<"					{ fprintf(stderr, "OP_L\n");return T_OP_LT; }
">"					{ fprintf(stderr, "OP_G\n");return T_OP_GT; }

"&&" 				{ fprintf(stderr, "OP_LAND\n");return T_OP_LAND; }
"||" 				{ fprintf(stderr, "OP_LOR\n");return T_OP_LOR; }
"!"					{ fprintf(stderr, "OP_LNOT\n");return T_OP_LNOT; }
"&"					{ fprintf(stderr, "OP_BAND\n");return T_OP_BAND; }
"|"					{ fprintf(stderr, "OP_BOR\n");return T_OP_BOR; }
"^"					{ fprintf(stderr, "OP_BXOR\n");return T_OP_BXOR; }
"~"					{ fprintf(stderr, "OP_B_ONESC\n");return T_OP_B_ONESC; }
">>"				{ fprintf(stderr, "OP_BRIGHT\n");return T_OP_BRIGHT; }
"<<" 				{ fprintf(stderr, "OP_BLEFT\n");return T_OP_BLEFT; }

"->" 				{ fprintf(stderr, "OP_PTR\n");return T_OP_PTR; }

"="					{ fprintf(stderr, "ASSIGN\n");return T_ASSIGN; }
">>=" 				{ fprintf(stderr, "RIGHT_ASSIGN\n");return T_RIGHT_ASSIGN; }
"<<="				{ fprintf(stderr, "LEFT_ASSIGN\n");return T_LEFT_ASSIGN; }
"+="				{ fprintf(stderr, "ADD_ASSIGN\n");return T_ADD_ASSIGN; }
"-="				{ fprintf(stderr, "SUB_ASSIGN\n");return T_SUB_ASSIGN; }
"*="				{ fprintf(stderr, "MUL_ASSIGN\n");return T_MUL_ASSIGN; }
"/="				{ fprintf(stderr, "DIV_ASSIGN\n");return T_DIV_ASSIGN; }
"%="				{ fprintf(stderr, "MOD_ASSIGN\n");return T_MOD_ASSIGN; }
"&="				{ fprintf(stderr, "AND_ASSIGN\n");return T_AND_ASSIGN; }
"|="				{ fprintf(stderr, "OR_ASSIGN\n");return T_OR_ASSIGN; }
"^="				{ fprintf(stderr, "XOR_ASSIGN\n");return T_XOR_ASSIGN; }

"?"					{ fprintf(stderr, "?\n");return '?'; }
":"					{ fprintf(stderr, ":\n");return ':'; }
";"					{ fprintf(stderr, ";\n");return ';'; }
","					{ fprintf(stderr, ",\n");return ','; }
"."					{ fprintf(stderr, ".\n");return '.'; }


{INCLUDE}			{ fprintf(stderr, "#include\n"); }
{COMMENT}			{ fprintf(stderr, "comment\n"); }
{WHITESPACE}    	{ fprintf(stderr, "Newline, tab or space\n");  }
{OTHER}				{ yyerror(yytext); }

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
	std::string tmp(yytext);//转成string 好处理
	//取最后一个字符
	char c = tmp(tmp.size()-1);
	if(c=='l' or c=='L')
		return true;
	else
		return false;
}
//是不是U后缀的整型常量
bool isU()
{
	std::string tmp(yytext);//转成string 好处理
	//取最后一个字符
	char c = tmp(tmp.size()-1);
	if(c=='u' or c=='U')
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
