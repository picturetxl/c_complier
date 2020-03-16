
// Grammar developed with the guide of the draft C89 spec
// X3J11 Technical Committee on the C Programming Language. The C89 Draft. Available from: https://port70.net/~nsz/c/c89/c89-draft.html [Accessed 2nd February 2018].

%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern FILE* yyin;
  extern const Node *g_root; 


  int yylex(void);
  void yyerror(const char *);
}

// AST node.
%union{
  const Node* node;
  std::string* string;
  int intValue;
  unsigned int uintValue;
  long int longintValue;
  unsigned long longuintValue;
  char characterValue;
  double floatValue;
}

// keywords
%token T_AUTO T_DOUBLE T_INT T_STRUCT T_BREAK T_ELSE T_LONG T_SWITCH T_CASE T_ENUM T_ELIPSIS
%token T_REGISTER T_TYPEDEF T_CHAR T_EXTERN T_RETURN T_UNION T_CONST T_FLOAT T_SHORT T_UNSIGNED
%token T_CONTINUE T_FOR T_SIGNED T_VOID T_DEFAULT T_GOTO T_SIZEOF T_VOLATILE T_DO T_IF T_STATIC T_WHILE
      
// constants
%token T_IDENTIFIER  T_STRING_LITERAL
%token T_UNSIGNED_LONG_CONSTANT T_LONG_CONSTANT T_UNSIGNED_CONSTANT T_INT_CONSTANT
%token T_FLOAT_CONSTANT  T_CHARACTER_CONSTANT

// brakets
%token T_L_BRACE T_R_BRACE T_L_BRACKET T_R_BRACKET T_L_SQUARE T_R_SQUARE


// operators
%token T_OP_PLUS T_OP_MINUS T_OP_MUL T_OP_DIV T_OP_MOD
%token T_OP_INC T_OP_DEC T_OP_LE T_OP_GE T_OP_EQ T_OP_NE T_OP_LT T_OP_GT

//logical // bits
%token  T_OP_LAND T_OP_LOR T_OP_LNOT T_OP_BAND T_OP_BOR T_OP_BXOR T_OP_B_ONESC T_OP_BRIGHT T_OP_BLEFT

//pointer
%token  T_OP_PTR

// assignments
%token  T_ASSIGN T_RIGHT_ASSIGN T_LEFT_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN
%token  T_DIV_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN



%type <node> 


// type
%type <string> T_IDENTIFIER T_STRING_LITERAL
%type <intValue>  T_INT_CONSTANT
%type <uintValue> T_UNSIGNED_CONSTANT
%type <longintValue> T_LONG_CONSTANT
%type <longuintValue> T_UNSIGNED_LONG_CONSTANT
%type <characterValue> T_CHARACTER_CONSTANT
%type <floatValue> T_FLOAT_CONSTANT


%start ROOT

%%

ROOT : PROGRAM

//思路:1.什么可以看成一个大的东东
//    2.一个东东可以分成那几个部分

// 程序可以有多个外部对象组成
PROGRAM : EXTERNAL_OBJECT
        | PROGRAM EXTERNAL_OBJECT

//外部对象由声明和函数组成
EXTERNAL_OBJECT : DECLARATION
                | FUNCTION

//函数由声明和定义两种形式
//函数声明: const/extern/static/type  id ;
//函数定义: const/extern/static/type  id {  }
FUNCTION : SPECIFIER_DESCRIBE DECLARATION
         | SPECIFIER_DESCRIBE DECLARATION FUNCTION_BODY

//声明部分
DECLARATION : T_IDENTIFIER ';'
            | T_IDENTIFIER
            | SPECIFIER_DESCRIBE DECLARATION

//特定描述符:存储类 类型
SPECIFIER_DESCRIBE : STORE_CLASS 
                   | TYPE
                   | STORE_CLASS SPECIFIER_DESCRIBE
                   | TYPE SPECIFIER_DESCRIBE

// 存储类:typedef extern static auto register
STORE_CLASS : T_TYPEDEF
            | T_STATIC
            | T_EXTERN
            | T_AUTO
            | T_REGISTER

// 类型
TYPE : T_VOID 
     | T_INT 
     | T_SHORT
     | T_FLOAT
     | T_DOUBLE
     | T_LONG
     | T_SIGNED
     | T_UNSIGNED
     | T_CHAR
     | UNION
     | STRUCT 

//结构体类型和定义
STRUCT : T_STRUCT T_IDENTIFIER
       | T_STRUCT T_IDENTIFIER T_L_BRACE STRUCT_STATMENT T_R_BRACE ';'




STRUCT_STATMENT : STATMENT
                | STRUCT_STATMENT STATMENT




%%


const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(char* x)
{
  yyin = fopen(x, "r");
  g_root=0;
  if(yyin) yyparse();
  fclose(yyin);
  return g_root;
}

