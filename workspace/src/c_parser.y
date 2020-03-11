%{
  #include <cassert>
  
  #include "../include/ast.hpp"
  
  extern FILE* yyin;
  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
%}

// 被yylval所用 且与flex文件中返回的token type一致
// 非终结符
%union{
  const Node *node;//节点
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
       T_UNSIGNED T_VOLATILE T_INLINE  T_DEFINE  T_SOON 
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

%token T_V_FLOAT T_INTEGER T_UINT T_LONGINT T_ULONG T_CHARACTOR T_V_STRING T_ID 

      
%type <float_value>     T_V_FLOAT
%type <int_value>       T_INTEGER 
%type <u_int_value>     T_UINT
%type <long_int_value>  T_LONGINT
%type <u_long_value>    T_ULONG
%type <char_value>      T_CHARACTOR
%type <string_value>    T_ID T_V_STRING

//非终结符
%type <node>  PROGRAM EX_DECLARATION   FUNCTION_NODE
              EX_NON_FUNCTION_DECLARATION EX_FUNCTION_DECLARATION
              EX_VAR_DECLATATION  EX_VAR_DEFINITION
              ARG_LIST TYPE ID VALUE SPECIAL EXPR
        


%start ROOT


%%

ROOT : PROGRAM { g_root = $1; }

/* 程序 分为 外部声明 和 函数 */
PROGRAM : EX_DECLARATION FUNCTION_NODE {$$ = new Program($1,$2);}
        | EX_DECLARATION          {$$ = $1;}
        | FUNCTION_NODE                {$$ = $1;}

/* 外部声明 分为 非函数声明 函数声明 */
EX_DECLARATION : EX_NON_FUNCTION_DECLARATION EX_FUNCTION_DECLARATION {$$ = new Ex_declaration($1,$2);}
               | EX_NON_FUNCTION_DECLARATION                         {$$ = $1;}
               | EX_FUNCTION_DECLARATION                             {$$ = $1;}


/* 非函数声明 可以分为 变量的声明 变量的定义 */
EX_NON_FUNCTION_DECLARATION : EX_VAR_DECLATATION  EX_VAR_DEFINITION   {$$ = new Ex_non_function_declaration($1,$2);}
                            | EX_VAR_DECLATATION                      {$$ = $1;}
                            | EX_VAR_DEFINITION                       {$$ = $1;}

/* 函数声明 = 返回值类型 函数名 ( 参数列表 ) ;*/
EX_FUNCTION_DECLARATION : TYPE ID T_LPARENTHESIS ARG_LIST T_RPARENTHESIS ';' {$$ = new Ex_function_declaration($1,$2,$4);}
                        | SPECIAL TYPE ID T_LPARENTHESIS ARG_LIST T_RPARENTHESIS {$$ = new Ex_function_declaration($1,$2,$3,$5);}
                        | TYPE ID T_LPARENTHESIS ARG_LIST T_RPARENTHESIS {$$ = new Ex_function_declaration($1,$2,$4);}

ARG_LIST : EX_VAR_DECLATATION               {$$=$1;}
         | ARG_LIST ',' EX_VAR_DECLATATION  {$$ = new Arg_list($1,$3);}

FUNCTION_NODE : EX_FUNCTION_DECLARATION  T_LBRACE   EXPR T_RBRACE  { $$ = new Funciton_node($1,$3);}
              | EX_FUNCTION_DECLARATION  T_LBRACE    T_RBRACE       {$$=$1;}
              ;

EXPR : ID T_EQ VALUE {$$ = new Expression($1,"==",$3);}
     ;

/* 变量的声明 = 类型 + 变量名 */
EX_VAR_DECLATATION : TYPE ID {$$ = new Ex_var_declaration($1,$2);}

/* 变量的定义 = 类型 + 变量名 + = 值*/ 
EX_VAR_DEFINITION : TYPE ID T_EQ VALUE {$$ = new Ex_var_definition($1,$2,$4);}



VALUE : T_INTEGER {$$ = new Integer($1);}
      | T_V_FLOAT {$$ = new Float($1);}
      | T_V_STRING {$$ = new Mystring(*$1);}


/* 类型  */
TYPE : SPECIAL TYPE   {$$ = new Type($1,$2);}
     | T_INT          {$$ = new Type(new std::string("int"));}
     | T_FLOAT        {$$ = new Type(new std::string("float"));}
     | T_DOUBLE       {$$ = new Type(new std::string("double"));}
     | T_UNSIGNED     {$$ = new Type(new std::string("unsigned"));}

SPECIAL : T_CONST     {$$ = new Special(new std::string("const"));}
        | T_STATIC    {$$ = new Special(new std::string("static"));}
        | T_VOLATILE  {$$ = new Special(new std::string("volatile"));}

ID : T_ID {$$ = new Identify($1);}


               

%%

const Node *g_root; 

const Node *parseAST(char* filename)
{
  g_root=0;
  yyin = fopen(filename, "r");//从文件中读取
  if(yyin)
  {
    yyparse();//会自动调用yylex()
  }
  
  return g_root;
}



