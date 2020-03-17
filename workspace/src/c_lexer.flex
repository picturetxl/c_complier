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

INCLUDE					#[.^\n]

COMMENT					"/*"[^"*/"]*"*/"

WHITESPACE				[ \n\t\v\f\r]

STRINGLITERAL           L?\"(\\.|[^\\"])*\"

OTHER					.




%%

"auto"				{ fprintf(stderr, "auto"); 		return T_AUTO;}
"double"			{ fprintf(stderr, "double"); 		return T_DOUBLE;}
"int"				{ fprintf(stderr, "int"); 		return T_INT;}
"struct"			{ fprintf(stderr, "struct\n");		return T_STRUCT;}
"break"				{ fprintf(stderr, "break\n");		return T_BREAK;}
"else"				{ fprintf(stderr, "else\n");		return T_ELSE;}
"long"				{ fprintf(stderr, "long\n");		return T_LONG;}
"switch"			{ fprintf(stderr, "switch\n");		return T_SWITCH;}
"case"				{ fprintf(stderr, "case\n");		return T_CASE;}
"enum"				{ fprintf(stderr, "enum\n");		return T_ENUM;}
"..." 				{ fprintf(stderr, "...\n");		return T_ELIPSIS;}
"register"			{ fprintf(stderr, "register\n");	return T_REGISTER;}
"typedef"			{ fprintf(stderr, "typdef\n");		return T_TYPEDEF;}
"char"				{ fprintf(stderr, "char\n");		return T_CHAR;}
"extern"			{ fprintf(stderr, "extern\n");		return T_EXTERN;}
"return"			{ fprintf(stderr, "return\n");		return T_RETURN;}
"union"				{ fprintf(stderr, "union\n");		return T_UNION;}
"const"				{ fprintf(stderr, "const\n");		return T_CONST;}
"float"				{ fprintf(stderr, "float\n");		return T_FLOAT;}
"short"				{ fprintf(stderr, "short\n");		return T_SHORT;}
"unsigned"			{ fprintf(stderr, "unsigned\n");	return T_UNSIGNED;}
"continue"			{ fprintf(stderr, "continue\n");	return T_CONTINUE;}
"for"				{ fprintf(stderr, "for\n");			return T_FOR;}
"signed"			{ fprintf(stderr, "signed\n");		return T_SIGNED;}
"void"				{ fprintf(stderr, "void\n");		return T_VOID;}
"default"			{ fprintf(stderr, "default\n");		return T_DEFAULT;}
"goto"				{ fprintf(stderr, "goto\n");		return T_GOTO;}
"sizeof"			{ fprintf(stderr, "sizeof\n");		return T_SIZEOF;}
"volatile"			{ fprintf(stderr, "volatile\n");	return T_VOLATILE;}
"do"				{ fprintf(stderr, "do\n");			return T_DO;}
"if"				{ fprintf(stderr, "if\n");			return T_IF;}
"static"			{ fprintf(stderr, "static\n");		return T_STATIC;}
"while"				{ fprintf(stderr, "while\n");		return T_WHILE;}



"{"					{ fprintf(stderr, "{");return T_L_BRACE; }
"}"					{ fprintf(stderr, "}");return T_R_BRACE; }
"("					{ fprintf(stderr, "(");return T_L_BRACKET; }
")"					{ fprintf(stderr, ")");return T_R_BRACKET; }
"["					{ fprintf(stderr, "[");return T_L_SQUARE; }
"]"					{ fprintf(stderr, "]");return T_R_SQUARE; }

"+"					{ fprintf(stderr, "+");return T_OP_PLUS; }
"-"					{ fprintf(stderr, "-");return T_OP_MINUS; }
"*"					{ fprintf(stderr, "*");return T_OP_MUL; }
"/"					{ fprintf(stderr, "/");return T_OP_DIV; }
"%"					{ fprintf(stderr, "%%");return T_OP_MOD; }

"++" 				{ fprintf(stderr, "++");return T_OP_INC; }
"--" 				{ fprintf(stderr, "--");return T_OP_DEC; }
"<=" 				{ fprintf(stderr, "<=");return T_OP_LE; }
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
";;"				{ fprintf(stderr, ";;\n");return T_ENDLESS_LOOP; }

{IDENTIFIER}		{ 	/* 标识符 */
						fprintf(stderr, "%s", yytext);
						set_string_by_yytext();
						return T_IDENTIFIER; 
					}

{DECIMAL_CONSTANT}  { 	/* 整型常量*/
						fprintf(stderr, "%s", yytext);
						if(isL() and isU())		{ set_int_value_by_yytext(10); return T_UNSIGNED_LONG_CONSTANT; }
						if(isL() and !isU())	{ set_int_value_by_yytext(10); return T_LONG_CONSTANT;}
						if(!isL() and isU())	{ set_int_value_by_yytext(10); return T_UNSIGNED_CONSTANT;}
						if(!isL() and !isU())	{ set_int_value_by_yytext(10); return T_INT_CONSTANT;}
					}

{OCTAL_CONSTANT}  	{ 	/*八进制常量*/
						fprintf(stderr, "%s", yytext);
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



{INCLUDE}			{ fprintf(stderr, "#include\n"); }
{COMMENT}			{ fprintf(stderr, "comment\n"); }
{WHITESPACE}    	{ fprintf(stderr, "	");  }
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
