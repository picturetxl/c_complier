%{
  #include <cassert>
  #include "ast.hpp"
  extern const Node *g_root; // A way of getting the AST out

   extern FILE* yyin;
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
%}


// Represents the value associated with any kind of
// AST node.
// 列举出所需要的类型 bison默认将所有的类型设置为int，所以需要用%union将所有的类型列举出来
// 可以通过定义宏YYSTYPE来改变值的类型
%union{
  const Node *node;
  double doubletype;
  int inttype;
  char chartype;
  std::string *str;
}


%token T_K_INT  T_K_RETURN T_K_STRUCT T_K_FOR T_K_DOUBLE T_K_FLOAT T_K_IF T_K_ELSE
       T_K_SWITCH T_K_WHILE T_K_DEFAULT T_K_TYPEDEF T_K_SIZEOF T_K_STATIC T_K_EXTERN T_K_VOID
       T_K_CHAR T_K_SHORT T_K_LONG T_K_SIGNED T_K_UNSIGNED T_K_UNION T_K_ENUM T_K_CONST T_K_VOLATILE
       T_K_CASE T_K_DO T_K_GOTO T_K_CONTINUE T_K_BREAK T_ID

%token T_JH T_AND T_OR T_XOR T_QF T_NOT T_LAND T_LOR T_SHIFT_LEFT T_SHIFT_RIGHT T_K_AUTO

%token T_LDKH  T_RDKH T_LXKH T_RXKH T_LZKH T_RZKH T_FH T_WH T_MH T_ARROW T_EQ T_NEQ  T_RFKH
       T_LT  T_GT T_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_OR_ASSIGN T_AND_ASSIGN

%token T_XLH T_MINUS T_ADD T_MUL T_DH T_LE T_GE T_ADDADD T_SUBSUB T_DOT T_DIV T_MOD 

%token T_V_CHAR T_V_FLOAT T_V_INTEGER T_V_STRING 
 
%type <node> ROOT PROGRAM EXTERNAL_OBJECT  FUNCTION

%type <node> BASIC_EXPR POSTFIX_EXPR AGR_LIST UNARY_EXPR OPR_UNARY CAST_EXPR
             MUL_EXPR  ADD_EXPR SHIFT_EXPR RELATION_EXPR EQ_EXPR AND_EXPR
             XOR_EXPR  OR_EXPR LOGIC_AND_EXPR LOGIC_OR_EXPR CONDITION_EXPR
             ASSIGN_EXPR  ASSIGN EXPR REGULAR_EXPR

%type <node>  DECLARATION TYPE_PART TERMS_LIST TERM STORE_CLASS REGULAR_TYPE
              STRUCT_UNION_TYPE  STRUCT_UNION STRUCT_UNION_LIST STRUCT_UNION_DECLARATION
              LIST_SPEC_QUAL  LIST_STRUCT_DECLARATOR STRUCT_DECLARATOR SPECIFIER_ENUM
              LIST_ENUMERATOR  ENUMERATOR QUALIFIER_TYPE DECLARATOR DECLARATOR_DIRECT
              POINTER  LIST_QUALIFIER_TYPE LIST_PARAM_TYPE LIST_PARAMETER DECLARATION_PARAMETER
              LIST_IDENTIFIER  TYPE DECLARATOR_ABSTRACT DECLARATOR_DIRECT_ABSTRACT
              INITIALIZER  LIST_INITIALIZER

%type <node> STATEMENT CASE_STATEMENT STATEMENTS LIST_DECLARATION STATEMENT_SEQUENCE
             EXPR_STATEMENT SELECTION_STATEMENT ITERATION_STATEMENT  JUMP_STATEMENT
 
%type <doubletype> T_V_FLOAT
%type <inttype> T_V_INTEGER
%type <str> T_ID T_V_STRING
%type <chartype> T_V_CHAR

%start ROOT

%%

ROOT : PROGRAM {g_root = $1;}

//---------------------EXPRESSION-PART-------------------------

// The smallest unit of an expression
BASIC_EXPR : T_ID                 {$$=new BasicExpression($1,2);}
           | T_V_INTEGER          {$$=new BasicExpression($1);}
           | T_V_FLOAT            {$$=new BasicExpression($1);}
           | T_V_CHAR             {$$=new BasicExpression($1);}
           | T_V_STRING           {$$=new BasicExpression($1,1);}
           | T_LXKH EXPR T_RXKH   {$$=new BasicExpression($2);}

//Postfix Expression
POSTFIX_EXPR : BASIC_EXPR                          {$$=$1;}
             | POSTFIX_EXPR T_LZKH EXPR T_RZKH     {$$=new PostfixExpression($1,$3,"expr");}
             | POSTFIX_EXPR T_LXKH T_RXKH          {$$=new PostfixExpression($1,"fc no args");}
             | POSTFIX_EXPR T_LXKH AGR_LIST T_RXKH {$$=new PostfixExpression($1,$3,"fc with args");}
             | POSTFIX_EXPR T_DOT T_ID             {$$=new PostfixExpression($1,$3,".");}
             | POSTFIX_EXPR T_ARROW T_ID           {$$=new PostfixExpression($1,$3,"->");}
             | POSTFIX_EXPR T_ADDADD               {$$=new PostfixExpression($1,"++");}
             | POSTFIX_EXPR T_SUBSUB               {$$=new PostfixExpression($1,"--");}

  AGR_LIST : ASSIGN_EXPR                {$$=new ArgList($1);}
          | AGR_LIST T_DH ASSIGN_EXPR  {$$=new ArgList($1,$3);}

UNARY_EXPR : POSTFIX_EXPR                         {$$=$1;}
           | T_ADDADD UNARY_EXPR                  {$$=new UnaryExpression("++",$2);}
           | T_SUBSUB UNARY_EXPR                  {$$=new UnaryExpression("--",$2);}
           | OPR_UNARY CAST_EXPR                  {$$=new UnaryExpression($1,$2);}
           | T_K_SIZEOF UNARY_EXPR                {$$=new UnaryExpression("sizeof",$2);}
           | T_K_SIZEOF T_LXKH TYPE T_RXKH        {$$=new UnaryExpression("sizeof",$3);}

OPR_UNARY : T_AND   { $$ = new OprUnary("&"); }  
          | T_QF    { $$ = new OprUnary("~"); }  
          | T_NOT   { $$ = new OprUnary("!"); }
          | T_MUL   { $$ = new OprUnary("*"); }  
          | T_ADD   { $$ = new OprUnary("+"); }  
          | T_MINUS { $$ = new OprUnary("-"); }  
         
CAST_EXPR : UNARY_EXPR                    {$$=$1;}
          | T_LXKH TYPE T_RXKH CAST_EXPR  {$$=new CastExpr($2,$4);}

MUL_EXPR : CAST_EXPR                  {$$=$1;}
         | MUL_EXPR T_MUL CAST_EXPR   {$$=new BinaryExpression($1,$3,"*");}
         | MUL_EXPR T_DIV CAST_EXPR   {$$=new BinaryExpression($1,$3,"/");}
         | MUL_EXPR T_MOD CAST_EXPR   {$$=new BinaryExpression($1,$3,"%");}

ADD_EXPR : MUL_EXPR                   {$$=$1;}
         | ADD_EXPR T_ADD MUL_EXPR    {$$=new BinaryExpression($1,$3,"+");}
         | ADD_EXPR T_MINUS MUL_EXPR  {$$=new BinaryExpression($1,$3,"-");}

SHIFT_EXPR : ADD_EXPR                           {$$=$1;}
           | SHIFT_EXPR T_SHIFT_LEFT ADD_EXPR   {$$=new BinaryExpression($1,$3,"<<");}
           | SHIFT_EXPR T_SHIFT_RIGHT ADD_EXPR  {$$=new BinaryExpression($1,$3,">>");}

RELATION_EXPR : SHIFT_EXPR                      {$$=$1;}
              | RELATION_EXPR T_LT SHIFT_EXPR   {$$=new BinaryExpression($1,$3,"<");}
              | RELATION_EXPR T_GT SHIFT_EXPR   {$$=new BinaryExpression($1,$3,">");}
              | RELATION_EXPR T_LE SHIFT_EXPR   {$$=new BinaryExpression($1,$3,"<=");}
              | RELATION_EXPR T_GE SHIFT_EXPR   {$$=new BinaryExpression($1,$3,">=");}

EQ_EXPR : RELATION_EXPR               {$$=$1;}
        | EQ_EXPR T_EQ RELATION_EXPR  {$$=new BinaryExpression($1,$3,"==");}
        | EQ_EXPR T_NEQ RELATION_EXPR {$$=new BinaryExpression($1,$3,"!=");}

AND_EXPR : EQ_EXPR                      {$$=$1;}
         | AND_EXPR T_AND EQ_EXPR       {$$=new BinaryExpression($1,$3,"&");}

XOR_EXPR : AND_EXPR                   {$$=$1;}
         | XOR_EXPR T_XOR AND_EXPR    {$$=new BinaryExpression($1,$3,"^");}

OR_EXPR : XOR_EXPR               {$$=$1;}                   
        | OR_EXPR T_OR XOR_EXPR  {$$=new BinaryExpression($1,$3,"|");}

LOGIC_AND_EXPR : OR_EXPR                        {$$=$1;}
               | LOGIC_AND_EXPR T_LAND OR_EXPR  {$$=new BinaryExpression($1,$3,"&&");}

LOGIC_OR_EXPR : LOGIC_AND_EXPR                      {$$=$1;}
              | LOGIC_OR_EXPR T_LOR LOGIC_AND_EXPR  {$$=new BinaryExpression($1,$3,"||");}

CONDITION_EXPR : LOGIC_OR_EXPR                                    {$$=$1;}
               | LOGIC_OR_EXPR T_WH EXPR T_MH CONDITION_EXPR      {$$=new ConditionExpr($1,$3,$5);}

ASSIGN_EXPR : CONDITION_EXPR                 {$$=$1;}
            | UNARY_EXPR ASSIGN ASSIGN_EXPR  {$$=new AssignExpression($1,$2,$3);} 

ASSIGN : T_ASSIGN       {$$=new Assign("=");}
       | T_ADD_ASSIGN   {$$=new Assign("+=");}
       | T_SUB_ASSIGN   {$$=new Assign("-=");}
       | T_MUL_ASSIGN   {$$=new Assign("*=");}
       | T_DIV_ASSIGN   {$$=new Assign("/=");}
       | T_AND_ASSIGN   {$$=new Assign("&=");}
       | T_OR_ASSIGN    {$$=new Assign("|=");}

EXPR : ASSIGN_EXPR            {$$=$1;}
     | EXPR T_DH ASSIGN_EXPR  {$$=new Expr($1,$3);}

REGULAR_EXPR : CONDITION_EXPR   {$$=$1;}


//-------------------------DECLARATION-MOST-PART-------------------------------------

DECLARATION : TYPE_PART T_FH            {$$=new Declaration($1);}
            | TYPE_PART TERMS_LIST T_FH {$$=new Declaration($1,$2);}

TYPE_PART : STORE_CLASS               {$$=$1;}
          | STORE_CLASS TYPE_PART     {$$ = new TypePart($1, $2);}
          | REGULAR_TYPE              {$$=$1;}
          | REGULAR_TYPE TYPE_PART    {$$ = new TypePart($1, $2);}
          | QUALIFIER_TYPE            {$$=$1;}
          | QUALIFIER_TYPE TYPE_PART  {$$ = new TypePart($1, $2);}

TERMS_LIST : TERM                     {$$=$1;}
           | TERMS_LIST T_DH TERM      {$$ = new TermList($1, $3);}

TERM : DECLARATOR                       {$$=new Term($1);}
     | DECLARATOR T_ASSIGN INITIALIZER  {$$=new Term($1,$3,"=");}

STORE_CLASS : T_K_TYPEDEF {$$=new StoreClass("typedef");}
            | T_K_EXTERN  {$$=new StoreClass("extern");}  
            | T_K_STATIC  {$$=new StoreClass("static");}

REGULAR_TYPE : T_K_VOID           {$$=new RegularType("void");}
             | T_K_CHAR           {$$=new RegularType("char");}
             | T_K_SHORT          {$$=new RegularType("short");}
             | T_K_INT            {$$=new RegularType("int");}
             | T_K_LONG           {$$=new RegularType("long");}
             | T_K_FLOAT          {$$=new RegularType("float");}
             | T_K_DOUBLE         {$$=new RegularType("double");}
             | T_K_SIGNED         {$$=new RegularType("signed");}
             | T_K_UNSIGNED       {$$=new RegularType("unsigned");}
             | STRUCT_UNION_TYPE  {$$=$1;}
             | SPECIFIER_ENUM     {$$=$1;}

STRUCT_UNION_TYPE : STRUCT_UNION T_ID T_LDKH STRUCT_UNION_LIST T_RDKH {$$=new StructUnionType($1,$2,$4);}
                  | STRUCT_UNION T_LDKH STRUCT_UNION_LIST T_RDKH      {$$=new StructUnionType($1,$3);}
                  | STRUCT_UNION T_ID                                 {$$=new StructUnionType($1,$2);}

STRUCT_UNION : T_K_STRUCT {$$=new RegularType("struct");}
             | T_K_UNION  {$$=new RegularType("union");}

STRUCT_UNION_LIST : STRUCT_UNION_DECLARATION                    {$$=$1;}
                  | STRUCT_UNION_LIST STRUCT_UNION_DECLARATION  {$$=new StructUnionList($1,$2);}

STRUCT_UNION_DECLARATION : LIST_SPEC_QUAL LIST_STRUCT_DECLARATOR T_FH {$$=new StructUnionDeclaration($1,$2);}



LIST_SPEC_QUAL : REGULAR_TYPE LIST_SPEC_QUAL    {$$=new ListSpecQual($1,$2);}
               | REGULAR_TYPE                   {$$=$1;}
               | QUALIFIER_TYPE LIST_SPEC_QUAL  {$$=new ListSpecQual($1,$2);}
               | QUALIFIER_TYPE                 {$$=$1;}

LIST_STRUCT_DECLARATOR : STRUCT_DECLARATOR                              {$$=$1;}
                       | LIST_STRUCT_DECLARATOR T_DH STRUCT_DECLARATOR  {$$=new ListStructDeclaration($1,$3);}

STRUCT_DECLARATOR : DECLARATOR                    {$$=$1;}
                  | T_MH REGULAR_EXPR             {$$=new StructDeclaration($2);}
                  | DECLARATOR T_MH REGULAR_EXPR  {$$=new StructDeclaration($1,$3);}

SPECIFIER_ENUM : T_K_ENUM T_LDKH LIST_ENUMERATOR T_RDKH       {$$=new SpecifierEnum($3);}
               | T_K_ENUM T_ID T_LDKH LIST_ENUMERATOR T_RDKH  {$$=new SpecifierEnum($2,$4);}
               | T_K_ENUM T_ID                                {$$=new SpecifierEnum($2);}

LIST_ENUMERATOR : ENUMERATOR                        {$$=$1;}
                | LIST_ENUMERATOR T_DH ENUMERATOR   {$$=new ListEnumerator($1,$3);}

ENUMERATOR : T_ID                       {$$=new Enumerator($1);}
           | T_ID T_ASSIGN REGULAR_EXPR   {$$=new Enumerator($1,$3);}

QUALIFIER_TYPE : T_K_CONST        {$$=new QualifierType("const");}
               | T_K_VOLATILE     {$$=new QualifierType("valatile");}

DECLARATOR : POINTER DECLARATOR_DIRECT  {$$=new Declarator($1,$2);}
           | DECLARATOR_DIRECT          {$$=$1;}

DECLARATOR_DIRECT : T_ID                                              {$$=new DeclaratorDirect($1);}
                  | T_LXKH DECLARATOR T_RXKH                          {$$=new DeclaratorDirect($2,"(d)");}
                  | DECLARATOR_DIRECT T_LZKH REGULAR_EXPR T_RZKH      {$$=new DeclaratorDirect($1,$3,"[]");}
                  | DECLARATOR_DIRECT T_LZKH T_RZKH                   {$$=new DeclaratorDirect($1,"[]");}
                  | DECLARATOR_DIRECT T_LXKH LIST_PARAM_TYPE T_RXKH   {$$=new DeclaratorDirect($1,$3,"(p)");}
                  | DECLARATOR_DIRECT T_LXKH LIST_IDENTIFIER T_RXKH   {$$=new DeclaratorDirect($1,$3,"(l)");}
                  | DECLARATOR_DIRECT T_LXKH T_RXKH                   {$$=new DeclaratorDirect($1,"()");}

POINTER : T_MUL                               {$$=new Pointer();}
        | T_MUL LIST_QUALIFIER_TYPE           {$$=new Pointer($2);}
        | T_MUL POINTER                       {$$=new Pointer($2);}
        | T_MUL LIST_QUALIFIER_TYPE POINTER   {$$=new Pointer($2,$3);}

LIST_QUALIFIER_TYPE : QUALIFIER_TYPE                      {$$=$1;}  
                    | LIST_QUALIFIER_TYPE QUALIFIER_TYPE  {$$=new ListQualifierType($1,$2);}  

LIST_PARAM_TYPE : LIST_PARAMETER              {$$=$1;}           
                | LIST_PARAMETER T_DH T_XLH   {$$=new ListParamType($1);}

LIST_PARAMETER : DECLARATION_PARAMETER                        {$$=$1;}
               | LIST_PARAMETER T_DH DECLARATION_PARAMETER    {$$=new ListParameter($1,$3);}

DECLARATION_PARAMETER : TYPE_PART DECLARATOR            {$$=new DeclarationParameter($1,$2);}
                      | TYPE_PART DECLARATOR_ABSTRACT   {$$=new DeclarationParameter($1,$2);}
                      | TYPE_PART                       {$$=$1;}

LIST_IDENTIFIER : T_ID                        {$$=new ListIdentifier($1);}
                | LIST_IDENTIFIER T_DH T_ID   {$$=new ListIdentifier($1,$3);}

TYPE : LIST_SPEC_QUAL                     {$$=$1;}
     | LIST_SPEC_QUAL DECLARATOR_ABSTRACT {$$=new Type($1,$2);}

DECLARATOR_ABSTRACT : POINTER                             {$$=$1;}
                    | DECLARATOR_DIRECT_ABSTRACT          {$$=$1;}
                    | POINTER DECLARATOR_DIRECT_ABSTRACT  {$$=new DeclarationAbstract($1,$2);}

DECLARATOR_DIRECT_ABSTRACT : T_LXKH DECLARATOR_ABSTRACT T_RXKH                          {$$=new DeclarationDirectAbstract($2,"(k)");}
                           | T_LZKH REGULAR_EXPR T_RZKH                                 {$$=new DeclarationDirectAbstract($2,"[r]");}
                           | DECLARATOR_DIRECT_ABSTRACT T_LZKH T_RZKH                   {$$=new DeclarationDirectAbstract($1,"[]");}
                           | DECLARATOR_DIRECT_ABSTRACT T_LXKH T_RXKH                   {$$=new DeclarationDirectAbstract($1,"()");}
                           | T_LXKH LIST_PARAM_TYPE T_RXKH                              {$$=new DeclarationDirectAbstract($2,"k()");}
                           | T_LZKH T_RZKH                                              {$$=new DeclarationDirectAbstract("[]");}
                           | T_LXKH T_RXKH                                              {$$=new DeclarationDirectAbstract("()");}
                           | DECLARATOR_DIRECT_ABSTRACT T_LZKH REGULAR_EXPR T_RZKH      {$$=new DeclarationDirectAbstract($1,$3,"[r]");}
                           | DECLARATOR_DIRECT_ABSTRACT T_LXKH LIST_PARAM_TYPE T_RXKH   {$$=new DeclarationDirectAbstract($1,$3,"(r)");}

INITIALIZER : ASSIGN_EXPR                           {$$=$1;}
            | T_LXKH LIST_INITIALIZER T_RXKH        {$$=new Initializer($2,"()");}
            | T_LXKH LIST_INITIALIZER T_DH T_RXKH   {$$=new Initializer($2,"(,)");}

LIST_INITIALIZER : INITIALIZER                        {$$=$1;}
                 | LIST_INITIALIZER T_DH INITIALIZER  {$$=new ListInitializer($1,$3);}

//-------------------------STATEMENTS-PART--------------------------

STATEMENT : CASE_STATEMENT        {$$=$1;}
          | STATEMENTS            {$$=$1;}
          | EXPR_STATEMENT        {$$=$1;}
          | SELECTION_STATEMENT   {$$=$1;}
          | ITERATION_STATEMENT   {$$=$1;}
          | JUMP_STATEMENT        {$$=$1;}
          | LIST_DECLARATION      {$$=$1;}

CASE_STATEMENT : T_ID T_MH STATEMENT                    {$$=new CaseStatement($1,$3);}
               | T_K_CASE REGULAR_EXPR T_MH STATEMENT   {$$=new CaseStatement($2,$4,"case");}
               | T_K_DEFAULT T_MH STATEMENT             {$$=new CaseStatement($3,"default");}
   
STATEMENTS : T_LDKH T_RDKH                      {$$=new Statements();}
           | T_LDKH STATEMENT_SEQUENCE T_RDKH   {$$=new Statements($2);}

LIST_DECLARATION : DECLARATION                  {$$=$1;}           
                 | LIST_DECLARATION DECLARATION {$$=new ListDeclaration($1,$2);}

STATEMENT_SEQUENCE : STATEMENT                      {$$=$1;}
                   | STATEMENT_SEQUENCE STATEMENT   {$$=new StatementSequence($1,$2);}

EXPR_STATEMENT : T_FH       {$$=new ExprStatement();}
               | EXPR T_FH  {$$=new ExprStatement($1);}

SELECTION_STATEMENT : T_K_IF T_LXKH EXPR T_RXKH STATEMENT                     {$$=new SelectionStatement($3,$5,"if");}
                    | T_K_IF T_LXKH EXPR T_RXKH STATEMENT T_K_ELSE STATEMENT  {$$=new SelectionStatement($3,$5,$7,"ifelse");}
                    | T_K_SWITCH T_LXKH EXPR T_RXKH STATEMENT                 {$$=new SelectionStatement($3,$5,"switch");}

ITERATION_STATEMENT : T_K_WHILE T_LXKH EXPR T_RXKH STATEMENT                           {$$=new IterationStatement($3,$5,"while");}
                    | T_K_DO STATEMENT T_K_WHILE T_LXKH EXPR T_RXKH T_FH                  {$$=new IterationStatement($2,$5,"dowhile");}
                    | T_K_FOR T_LXKH EXPR_STATEMENT EXPR_STATEMENT T_RXKH STATEMENT       {$$=new IterationStatement($3,$4,$6,"for");}
                    | T_K_FOR T_LXKH EXPR_STATEMENT EXPR_STATEMENT EXPR T_RXKH STATEMENT  {$$=new IterationStatement($3,$4,$5,$7,"for");}

JUMP_STATEMENT : T_K_GOTO T_ID T_FH     {$$=new JumpStatement($2,"goto");}
               | T_K_CONTINUE T_FH      {$$=new JumpStatement("continue");}
               | T_K_BREAK T_FH         {$$=new JumpStatement("break");}
               | T_K_RETURN T_FH        {$$=new JumpStatement("return");}
               | T_K_RETURN EXPR T_FH   {$$=new JumpStatement($2,"return");}

PROGRAM : EXTERNAL_OBJECT           {$$=$1;}
        | PROGRAM EXTERNAL_OBJECT   {$$=new Program($1,$2);}

EXTERNAL_OBJECT :DECLARATION {$$=$1;}
                | FUNCTION    {$$=$1;}

FUNCTION : TYPE_PART DECLARATOR T_FH        {$$=new Function($1,$2);}
         | TYPE_PART DECLARATOR STATEMENTS  {$$=new Function($1,$2,$3);}



%%

const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(char *filename)
{
  if(!filename)
  {
    cerr<<"file name is null"<<endl;
    exit(-1);
  }
  yyin = fopen(filename,"r");
  if(!yyin)
  {
    cerr<<"file can not open"<<endl;
    exit(-2);
  }
  // cout<<"work on it"<<endl;
  g_root=0;
  yyparse();
  return g_root;
}
