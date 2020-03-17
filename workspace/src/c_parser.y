
// Grammar developed with the guide of the draft C89 spec
// X3J11 Technical Committee on the C Programming Language. The C89 Draft. Available from: https://port70.net/~nsz/c/c89/c89-draft.html [Accessed 2nd February 2018].

%code requires{
  #include "../include/ast.hpp"

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
%token  T_DIV_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN T_ENDLESS_LOOP



%type <node> ROOT PROGRAM EXTERNAL_OBJECT STATEMENT FUNCTION
             TYPE FUNCTION_CALL 
             RETURN_STATEMENT DECLARATION_STATEMENT ASSIGNMENT_STATEMENT FOR_STATEMENT COMPARE_STATEMENT
             IF_ELSE_STATEMENT  WHILE_STATEMENT ENUM_STATEMENT SWITCH_STATEMENT  CASE_STATEMENT BREAK_STATEMENT
             TYPEDEF_STATEMENT  TWO_OP_STATEMENT INCREASE_STATEMENT STRUCT_STATEMENT SIZEOF_STATEMENT
             ARRAY_DECLARATION  FUNCTION_DECLARATION REGULAR_DECLARATION STRUCT_DECLARATION
             SINGLE_EXPR  LOGIC_EXPR  OP_EXPR  EXPR
             NUMBER CHARACTOR  INTEGER  FLOAT DOT POINTER LIST ARG_LIST FOR_LIST  ASSIGNMENT_DEFINITION



// type   
%type <string> T_IDENTIFIER T_STRING_LITERAL  T_ENDLESS_LOOP
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
//    3.自顶向下

// 程序可以有多个外部对象组成
PROGRAM : EXTERNAL_OBJECT { $$ = $1;}
        | PROGRAM EXTERNAL_OBJECT { $$ = new Program($1,$2);}
        ;

//外部对象由语句和函数组成
EXTERNAL_OBJECT : STATEMENT { $$ = $1;}
                | FUNCTION { $$ = $1;}

//函数: 返回类型 函数调用 函数体-可以看成是多个语句
FUNCTION : TYPE FUNCTION_CALL T_L_BRACE STATEMENT T_R_BRACE {$$ = new Function($1,$2,$4);}


//----------------------------------------------
// 语句:多个语句
// 语句: return 语句
//     | 函数语句
//     | 声明语句 DS
STATEMENT : STATEMENT {$$=$1;}
          | RETURN_STATEMENT {$$=$1;}
          | DECLARATION_STATEMENT {$$=$1;}
          | ASSIGNMENT_STATEMENT {$$=$1;}
          | FOR_STATEMENT {$$=$1;}
          | COMPARE_STATEMENT {$$=$1;}
          | IF_ELSE_STATEMENT {$$=$1;}
          | WHILE_STATEMENT {$$=$1;}
          | T_L_BRACE STATEMENT T_R_BRACE {$$=$2;}
          | ENUM_STATEMENT {$$=$1;}
          | SWITCH_STATEMENT {$$=$1;}
          | CASE_STATEMENT {$$=$1;}
          | BREAK_STATEMENT {$$=$1;}
          | TYPEDEF_STATEMENT {$$=$1;}
          | TWO_OP_STATEMENT {$$=$1;}
          | INCREASE_STATEMENT {$$=$1;}
          | STRUCT_STATEMENT {$$=$1;}
          | SIZEOF_STATEMENT {$$=$1;}
          ;

//return 语句
RETURN_STATEMENT : T_RETURN EXPR ';' {$$=$2;}

//声明语句
DECLARATION_STATEMENT : ARRAY_DECLARATION   {$$=$1;}
                      | FUNCTION_DECLARATION  {$$=$1;}
                      | REGULAR_DECLARATION   {$$=$1;}
                      | STRUCT_DECLARATION  {$$=$1;}



//数组声明
ARRAY_DECLARATION : TYPE T_IDENTIFIER T_L_SQUARE EXPR T_R_SQUARE ';'  {$$=new ArrayDeclaration($1,$4);}

//函数声明
FUNCTION_DECLARATION : TYPE FUNCTION_CALL  ';' {$$=new FunctionDeclaration($1,$2);} 

//常规的类型声明
REGULAR_DECLARATION : TYPE T_IDENTIFIER ';' {$$=new RegularDeclaration($1);}
                    | TYPE T_IDENTIFIER ',' {$$=new RegularDeclaration($1);}
                    | TYPE T_IDENTIFIER     {$$=new RegularDeclaration($1);}

//struct声明
STRUCT_DECLARATION : T_STRUCT EXPR EXPR ';' {$$=new StructDeclaration($2,$3);}


//赋值语句
ASSIGNMENT_STATEMENT : EXPR T_ASSIGN EXPR ';' {$$=new AssignmentStatement($1,$3);}
                     | EXPR T_ASSIGN EXPR ',' {$$=new AssignmentStatement($1,$3);}
                     | EXPR T_ASSIGN EXPR      {$$=new AssignmentStatement($1,$3);}
                     | ASSIGNMENT_STATEMENT  ASSIGNMENT_DEFINITION {$$=new AssignmentStatement($1,$2);}
                     | ASSIGNMENT_DEFINITION  {$$=$1;}
//
ASSIGNMENT_DEFINITION : TYPE T_IDENTIFIER T_ASSIGN EXPR {$$=new AssignDefinition($1,$4);}


// 比较语句
COMPARE_STATEMENT : EXPR T_OP_LT EXPR ';' {$$= new CompareStatement($1,$3);}

//if-else语句
IF_ELSE_STATEMENT : T_IF T_L_BRACKET EXPR T_R_BRACKET T_L_BRACE STATEMENT T_R_BRACE T_ELSE T_L_BRACE STATEMENT T_R_BRACE {$$=new IfelseStatment($3,$6,$10);}
                  | T_IF T_L_BRACKET EXPR T_R_BRACKET T_L_BRACE STATEMENT T_R_BRACE {$$=new IfelseStatment($3,$6);}

//while 语句
WHILE_STATEMENT : T_WHILE T_L_BRACKET EXPR T_R_BRACKET T_L_BRACE STATEMENT T_R_BRACE {$$=new WhileStatement($3,$6);}



// for 语句
FOR_STATEMENT : T_FOR T_L_BRACE LIST T_R_BRACE T_L_BRACKET STATEMENT T_R_BRACKET {$$=new ForStatement($3,$6);}

//enum语句
ENUM_STATEMENT : T_ENUM T_IDENTIFIER T_L_BRACE STATEMENT T_R_BRACE ';' {$$=$4;}


// swtich语句
SWITCH_STATEMENT : T_SWITCH T_L_BRACKET EXPR T_R_BRACKET T_L_BRACE CASE_STATEMENT T_R_BRACE {$$=new SwitchStatement($3,$6);}


//case语句
CASE_STATEMENT : T_CASE EXPR ':' T_L_BRACE STATEMENT T_R_BRACE {$$=new CaseStatement($2,$5);}
               | T_CASE EXPR ':' STATEMENT {$$=new CaseStatement($2,$4);}


//break语句
BREAK_STATEMENT : T_BREAK ";" {$$=new Break("break");}

// typedef 语句
TYPEDEF_STATEMENT : T_TYPEDEF TYPE TYPE  {$$=new TypedefStatement($2,$3);}
                  | T_TYPEDEF TYPE POINTER TYPE {$$=new TypedefStatement($2,$3);}

// += -= *= /= %=
TWO_OP_STATEMENT : EXPR T_ADD_ASSIGN EXPR ';' {$$=new TwoOpStatement($1,$3);}
                 | EXPR T_MOD_ASSIGN EXPR ';' {$$=new TwoOpStatement($1,$3);}
                 | EXPR T_MUL_ASSIGN EXPR ';' {$$=new TwoOpStatement($1,$3);}
                 | EXPR T_SUB_ASSIGN EXPR ';' {$$=new TwoOpStatement($1,$3);}
                 | EXPR T_DIV_ASSIGN EXPR ';' {$$=new TwoOpStatement($1,$3);}


//-- ++
INCREASE_STATEMENT : T_OP_INC STATEMENT {$$=$2;}
                   | T_OP_DEC STATEMENT {$$=$2;}

//struct 语句
STRUCT_STATEMENT : T_STRUCT T_IDENTIFIER T_L_BRACE STATEMENT T_R_BRACE ';' {$$=new StructStatement($4);}

//sizeof 语句
SIZEOF_STATEMENT : T_SIZEOF T_L_BRACKET EXPR T_R_BRACKET ';' {$$=new SizeofStatement($3);}

//--------------------------------------------------
//表达式
EXPR : SINGLE_EXPR  {$$=$1;}
     | LOGIC_EXPR  {$$=$1;}
     | OP_EXPR {$$=$1;}
     | T_L_BRACKET EXPR T_R_BRACKET {$$=$2;}
     | EXPR {$$=$1;}
     | EXPR ',' {$$=$1;}

//操作符表达式
OP_EXPR : EXPR T_OP_EQ EXPR   {$$=new OpExpression($1,$3);}
        | EXPR T_OP_PLUS EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_MINUS EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_MUL EXPR {$$=new OpExpression($1,$3);}
        | OP_EXPR {$$=$1;}
        | EXPR T_OP_BAND EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_BOR EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_BXOR EXPR  {$$=new OpExpression($1,$3);}
        | EXPR T_OP_NE EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_LE EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_LT EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_LAND EXPR {$$=new OpExpression($1,$3);}
        | EXPR T_OP_LOR EXPR {$$=new OpExpression($1,$3);}

//单独的
SINGLE_EXPR : NUMBER {$$=$1; }
            | FUNCTION_CALL {$$=$1;}
            | T_IDENTIFIER T_L_SQUARE EXPR T_R_SQUARE {/*数组*/ $$=$3;}
            | T_IDENTIFIER {$$=new Identify($1);}
            | POINTER EXPR {$$=new SingleExpression($1,$2);}
            | T_OP_BAND EXPR  {$$=$2;}
            | CHARACTOR {$$=$1;}
            | DOT {$$=$1;}


//逻辑表达式: ! 表达式
LOGIC_EXPR : T_OP_LNOT EXPR  {$$=$2;}


//--------------------------------------------------
//数
NUMBER : INTEGER  {$$=$1;}
       | T_OP_MINUS INTEGER  {$$=$2;}
       | FLOAT  {$$=$1;}

CHARACTOR : T_CHARACTER_CONSTANT {$$=new Charator($1);}
          | T_STRING_LITERAL {$$=new String($1);}

INTEGER : T_INT_CONSTANT {$$=new Integer($1);}

FLOAT : T_FLOAT_CONSTANT {$$=new Float($1);}

DOT : EXPR '.' EXPR  {$$=new Dot($1,$3);}

//函数调用:函数名-标识符 ( 参数列表 )
FUNCTION_CALL : T_IDENTIFIER T_L_BRACKET LIST T_R_BRACKET {$$=$3;}

//类型
TYPE : T_INT {$$ = new TypeInt("int");}
     | T_DOUBLE {$$ = new TypeDouble("double");}
     | T_FLOAT {$$ = new TypeFloat("float");}
     | T_IDENTIFIER {$$ = new Identify($1);}
     | POINTER {$$ = $1;}
     | TYPE  {$$ = $1;}

// 指针
POINTER : POINTER T_OP_MUL {$$=$1;}
        | T_OP_MUL {$$ = new TypeStar("*");}

//各种列表
LIST : ARG_LIST {$$=$1;}
     | FOR_LIST {$$=$1;}
     ;


//参数列表 
ARG_LIST : ARG_LIST STATEMENT {$$=new ArgList($1,$2);}
         | STATEMENT {$$=$1;}
         | ARG_LIST EXPR {$$=new ArgList($1,$2);}
         | EXPR {$$=$1;}
         ;

//for 列表
FOR_LIST : FOR_LIST STATEMENT {$$=new ForList($1,$2);}
         | STATEMENT {$$=$1;}
         | T_ENDLESS_LOOP {$$=new String($1);}

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

