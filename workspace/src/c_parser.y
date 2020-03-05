%{
  #include <cassert>
  
  #include "../include/ast.hpp"
  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
%}

// 被yylval所用 且与flex文件中返回的token type一致
// 非终结符
%union{
  const Expression *expr;//节点
  double float_value;//浮点数
  int int_value;//整数
  //处理后缀情况
  unsigned int u_int_value;//u
  long int long_int_value;//l
  unsigned long u_long_value;//ul
  char char_value;//字符
  std::string *string_value;//标识符或者字面量字符串

}

//终结符

//关键字
%token T_INT T_IF T_ELSE T_WHILE T_VOID 
       T_FLOAT T_DOUBLE T_AUTO T_BREAK
       T_CASE T_CHAR  T_CONST T_CONTINUE  T_DEFUALT
       T_DO T_ENUM T_EXTERN T_FOR  T_GOTO
       T_LONG T_REGISTER T_SHORT T_SIGNED T_SIZEOF
       T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION
       T_UNSIGNED T_VOLATILE T_INLINE
//算术运算
%token T_ADD T_SUB T_MUL T_DIV T_MOD T_INC T_DEC
//比较
%token T_EQ  T_GE T_LE T_GR T_LS
//加等
%token T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN
//括号
%token T_LPARENTHESIS T_RPARENTHESIS T_LBRACE T_RBRACE T_LSQUARE T_RSQUARE
//按位操作
%token T_BOR T_BAND T_BXOR T_NOT T_LSHIFT T_RSHIFT
//特殊字符:指针 三目操作符 分隔符
%token T_POINTER T_QUESTION T_SEMICOLON T_SPOT T_COMMA T_COLON




//非终结符
%type <expr>  

%type <float_value>     T_FLOAT
%type <int_value>       T_INTEGER 
%type <u_int_value>     T_UINT
%type <long_int_value>  T_LONGINT
%type <u_long_value>    T_ULONG
%type <char_value>      T_CHARACTOR
%type <string_value>    T_ID T_STRING_L



%start ROOT


%%
ROOT : PROGRAM { g_root = $1; }

PROGRAM : 


%%
const Expression *g_root; 

const Expression *parseAST(char* filename)
{
  g_root=0;
  yyin = fopen(filename, "r");//从文件中读取
  if(yyin)
  {
    yyparse();//会自动调用yylex()
  }
  
  return g_root;
}



