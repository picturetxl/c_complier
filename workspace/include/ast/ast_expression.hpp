/*
 * @Author: your name
 * @Date: 2020-03-22 12:07:13
 * @LastEditTime: 2020-03-22 23:00:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /complier/include/ast/ast_expression.hpp
 */
#ifndef ast_expression_hpp
#define ast_expression_hpp

#include "ast.hpp"
#include <iostream>
#include <string>
using namespace std;

class Expression : public Node
{
    public:
        virtual ~Expression()
        {}
        virtual void print(std::ostream &dst) const =0;
        virtual void translate(std::ostream &dst) const
        {};
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/**
 BASIC_EXPR : T_ID                 {$$=new BasicExpression($1,2);}
           | T_V_INTEGER          {$$=new BasicExpression($1);}
           | T_V_FLOAT            {$$=new BasicExpression($1);}
           | T_V_CHAR             {$$=new BasicExpression($1);}
           | T_V_STRING           {$$=new BasicExpression($1,1);}
           | T_LXKH EXPR T_RXKH   {$$=new BasicExpression($2);}
 */
class BasicExpression : public Expression
{
    private:
        string type;
        int flag ;//1 for string literal 2 for identify 0 for other
        int intValue;
        double doubleValue;
        string * stringValue;
        NodePtr node;
    public:
        virtual ~BasicExpression()
        {}
        BasicExpression(string* arg,int flag) :stringValue(arg),type("string"),flag(flag){}
        BasicExpression(int arg) :intValue(arg),type("int"),flag(0){}
        BasicExpression(double arg) :doubleValue(arg), type("double"),flag(0){}
        BasicExpression(NodePtr arg) :node(arg),type("node"),flag(0){}
        
        virtual void print(std::ostream &dst) const
        {
            dst<<"in BasicExpression"<<endl;
            if(flag == 0)
            {
                if(type == "int")
                {
                    dst<<"int value:"<<intValue<<endl;
                }
                if(type == "double")
                {
                    dst<<"double value:"<<doubleValue<<endl;
                }
                if(type == "node")
                {
                    node->print(dst);
                }
            }
            else
            {
                if(flag == 1)
                {
                    dst<<"string literal:"<<*stringValue<<endl;
                }
                if(flag == 2)
                {
                    dst<<"identify:"<<*stringValue<<endl;
                }
                
            }
            

        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in BasicExpression"<<endl;
            if(flag == 0)
            {
                if(type == "int")
                {
                    dst<<intValue;
                }
                if(type == "double")
                {
                    dst<<doubleValue;
                }
                if(type == "node")
                {
                    dst<<"(";
                    node->translate(dst,context);
                    dst<<")";
                }
            }
            else
            {
                if(flag == 1)
                {
                    dst<<*stringValue;
                }
                if(flag == 2)
                {
                    dst<<*stringValue;
                }
                
            }
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};



/*
POSTFIX_EXPR : BASIC_EXPR                          {$$=$1;}
             | POSTFIX_EXPR T_LZKH EXPR T_RZKH     {$$=new PostfixExpression($1,$3,"expr");}
             | POSTFIX_EXPR T_LXKH T_RXKH          {$$=new PostfixExpression($1,"fc no args");}
             | POSTFIX_EXPR T_LXKH AGR_LIST T_RXKH {$$=new PostfixExpression($1,$3,"fc with args");}
             | POSTFIX_EXPR T_DOT T_ID             {$$=new PostfixExpression($1,$3,".");}
             | POSTFIX_EXPR T_ARROW T_ID           {$$=new PostfixExpression($1,$3,"->");}
             | POSTFIX_EXPR T_ADDADD               {$$=new PostfixExpression($1,"++");}
             | POSTFIX_EXPR T_SUBSUB               {$$=new PostfixExpression($1,"--");}
*/
class PostfixExpression : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
        string type;
        string *stringValue;
    public:
        virtual ~PostfixExpression()
        {}
        PostfixExpression(NodePtr arg1,string arg2)
            :node1(arg1),type(arg2){}
        PostfixExpression(NodePtr arg1,NodePtr arg2,string arg3)
            :node1(arg1),node2(arg2),type(arg3){}
        PostfixExpression(NodePtr arg1,string* arg2,string arg3)
            :node1(arg1),stringValue(arg2),type(arg3){}
        

        virtual void print(std::ostream &dst) const
        {
            dst<<"in PostfixExpression"<<endl;
            if(type == "++")
            {
                dst<<"++"<<endl;
                node1->print(dst);
            }
            if(type == "--")
            {
                 dst<<"--"<<endl;
                node1->print(dst);
            }
            if(type == "fc no args")
            {
                 dst<<"funciton call with no args"<<endl;
                node1->print(dst);
            }
            if(type == "expr")
            {
                dst<<"expr"<<endl;
                node1->print(dst);
                node2->print(dst);
            }
            if(type == "fc with args")
            {
                 dst<<"function call with args"<<endl;
                node1->print(dst);
                node2->print(dst);
            }
            if(type == ".")
            {
                dst<<"dot"<<endl;
                node1->print(dst);
                dst<<".";
                dst<<*stringValue<<endl;
            }
            if(type == "->")
            {
                 dst<<"->"<<endl;
                node1->print(dst);
                dst<<"->";
                dst<<*stringValue<<endl;
            }

        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in PostfixExpression"<<endl;
            if(type == "++")
            {
                node1->translate(dst,context);
                dst<<"++";
            }
            if(type == "--")
            {
                node1->translate(dst,context);
                dst<<"--";
            }
            if(type == "fc no args")
            {
                node1->translate(dst,context);
                dst<<"()";
            }
            if(type == "expr")
            {
                throw std::runtime_error("python not support ."); 
            }
            if(type == "fc with args")
            {
                node1->translate(dst,context);
                dst<<"(";
                node2->translate(dst,context);
                dst<<")";
            }
            if(type == ".")
            {
               throw std::runtime_error("python not support."); 
            }
            if(type == "->")
            {
                throw std::runtime_error("python not support."); 
            }

        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/**
   AGR_LIST : ASSIGN_EXPR                {$$=new ArgList($1);}
          | AGR_LIST T_DH ASSIGN_EXPR  {$$=new ArgList($1,$3);}
*/
class ArgList : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ArgList()
        {}
        ArgList(NodePtr arg1)
            :node1(arg1),node2(nullptr){}

        ArgList(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
      

        virtual void print(std::ostream &dst) const
        {
            dst<<"in ArgList"<<endl;
            node1->print(dst);
            if(node2!=nullptr)
            {
                dst<<",";
                node2->print(dst);
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in ArgList"<<endl;
            context.turn_on_in_arglist_flag();
            node1->translate(dst,context);
            if(node2!=nullptr)
            {
                dst<<",";
                node2->translate(dst,context);
            }
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
UNARY_EXPR : POSTFIX_EXPR                         {$$=$1;}
           | T_ADDADD UNARY_EXPR                  {$$=new UnaryExpression("++",$2);}
           | T_SUBSUB UNARY_EXPR                  {$$=new UnaryExpression("--",$2);}
           | OPR_UNARY CAST_EXPR                  {$$=new UnaryExpression($1,$2);}
           | T_K_SIZEOF UNARY_EXPR                {$$=new UnaryExpression("sizeof",$2);}
           | T_K_SIZEOF T_LXKH TYPE T_RXKH        {$$=new UnaryExpression("sizeof",$3);}
*/
class UnaryExpression : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
        string type;
    public:
        virtual ~UnaryExpression()
        {}
        UnaryExpression(string arg1,NodePtr arg2)
            :type(arg1),node2(arg2),node1(nullptr){}

        UnaryExpression(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2),type("null"){}
      

        virtual void print(std::ostream &dst) const
        {
            dst<<"in UnaryExpression"<<endl;
            if(type == "++")
            {
                dst<<"++";
                node2->print(dst);
            }
            if(type == "--")
            {
                dst<<"-";
                node2->print(dst);
            }
            if(type == "null")
            {
                node1->print(dst);
                node2->print(dst);
            }
            if(type == "sizeof")
            {
                dst<<"sizeof";
                node2->print(dst);
            }

        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in UnaryExpression"<<endl;
            if(type == "++")
            {
                context.indent_output(dst);
                dst<<"++";
                node2->translate(dst,context);
            }
            if(type == "--")
            {
                context.indent_output(dst);
                dst<<"-";
                node2->translate(dst,context);
            }
            if(type == "null")
            {
                node1->translate(dst,context);
                node2->translate(dst,context);
            }
            if(type == "sizeof")
            {
               throw std::runtime_error("python Not support.");
            }
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
OPR_UNARY : T_AND   { $$ = new OprUnary("&"); }  
          | T_QF    { $$ = new OprUnary("~"); }  
          | T_NOT   { $$ = new OprUnary("!"); }
          | T_MUL   { $$ = new OprUnary("*"); }  
          | T_ADD   { $$ = new OprUnary("+"); }  
          | T_MINUS { $$ = new OprUnary("-"); }  
*/
class OprUnary : public Expression
{
    private:
        string type;
    public:
        virtual ~OprUnary()
        {}
        OprUnary(string arg1)
            :type(arg1){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in OprUnary"<<endl;
            dst<<type<<endl;

        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in OprUnary"<<endl;
            dst<<type;
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
CAST_EXPR : UNARY_EXPR                    {$$=$1;}
          | T_LXKH TYPE T_RXKH CAST_EXPR  {$$=new CastExpr($2,$4);}
*/
class CastExpr : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~CastExpr()
        {}
        CastExpr(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in CastExpr"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext &context) const override
        {
            // cout<<"in CastExpr"<<endl;
            dst<<"(";
            node1->translate(dst,context);
            dst<<")";
            node2->translate(dst,context);
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
MUL_EXPR : CAST_EXPR                  {$$=$1;}
         | MUL_EXPR T_MUL CAST_EXPR   {$$=new BinaryExpression($1,$3,"*");}
         | MUL_EXPR T_DIV CAST_EXPR   {$$=new BinaryExpression($1,$3,"/");}
         | MUL_EXPR T_MOD CAST_EXPR   {$$=new BinaryExpression($1,$3,"%");}
*/
/*
ADD_EXPR : MUL_EXPR                   {$$=$1;}
         | ADD_EXPR T_ADD MUL_EXPR    {$$=new BinaryExpression($1,$3,"+");}
         | ADD_EXPR T_MINUS MUL_EXPR  {$$=new BinaryExpression($1,$3,"-");}
*/
/*
SHIFT_EXPR : ADD_EXPR                           {$$=$1;}
           | SHIFT_EXPR T_SHIFT_LEFT ADD_EXPR   {$$=new BinaryExpression($1,$3,"<<");}
           | SHIFT_EXPR T_SHIFT_RIGHT ADD_EXPR  {$$=new BinaryExpression($1,$3,">>");}
*/
/*
RELATION_EXPR : SHIFT_EXPR                      {$$=$1;}
              | RELATION_EXPR T_LT SHIFT_EXPR   {$$=new BinaryExpression($1,$3,"<");}
              | RELATION_EXPR T_GT SHIFT_EXPR   {$$=new BinaryExpression($1,$3,">");}
              | RELATION_EXPR T_LE SHIFT_EXPR   {$$=new BinaryExpression($1,$3,"<=");}
              | RELATION_EXPR T_GE SHIFT_EXPR   {$$=new BinaryExpression($1,$3,">=");}
*/
/*

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

*/
class BinaryExpression : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
        string type;
    public:
        virtual ~BinaryExpression()
        {}
        BinaryExpression(NodePtr arg1,NodePtr arg2,string arg3)
            :node1(arg1),node2(arg2),type(arg3){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in BinaryExpression"<<endl;
            node1->print(dst);
            dst<<type;
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in BinaryExpression"<<endl;
            // context.indent_output(dst);
            node1->translate(dst,context);
            dst<<type;
            node2->translate(dst,context);
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
CONDITION_EXPR : LOGIC_OR_EXPR                                    {$$=$1;}
               | LOGIC_OR_EXPR T_WH EXPR T_MH CONDITION_EXPR      {$$=new ConditionExpr($1,$3,$5);}
*/
class ConditionExpr : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
        NodePtr node3;
    public:
        virtual ~ConditionExpr()
        {}
        ConditionExpr(NodePtr arg1,NodePtr arg2,NodePtr arg3)
            :node1(arg1),node2(arg2),node3(arg3){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in ConditionExpr"<<endl;
            node1->print(dst);
            node2->print(dst);
            node3->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in ConditionExpr"<<endl;
            node1->translate(dst,context);
            dst<<"?";
            node2->translate(dst,context);
            dst<<":";
            node3->translate(dst,context);
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*

ASSIGN_EXPR : CONDITION_EXPR                 {$$=$1;}
            | UNARY_EXPR ASSIGN ASSIGN_EXPR  {$$=new AssignExpression($1,$2,$3);} 
*/
class AssignExpression : public Expression
{
    private:
        NodePtr node1;
        NodePtr node2;
        NodePtr node3;
    public:
        virtual ~AssignExpression()
        {}
        AssignExpression(NodePtr arg1,NodePtr arg2,NodePtr arg3)
            :node1(arg1),node2(arg2),node3(arg3){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in AssignExpression"<<endl;
            node1->print(dst);
            node2->print(dst);
            node3->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in AssignExpression"<<endl;
            node1->translate(dst,context);
            node2->translate(dst,context);
            node3->translate(dst,context);
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
ASSIGN : T_ASSIGN       {$$=new Assign("=");}
       | T_ADD_ASSIGN   {$$=new Assign("+=");}
       | T_SUB_ASSIGN   {$$=new Assign("-=");}
       | T_MUL_ASSIGN   {$$=new Assign("*=");}
       | T_DIV_ASSIGN   {$$=new Assign("/=");}
       | T_AND_ASSIGN   {$$=new Assign("&=");}
       | T_OR_ASSIGN    {$$=new Assign("|=");}
*/
class Assign : public Expression
{
    private:
       string type;
    public:
        virtual ~Assign()
        {}
        Assign(string arg)
            :type(arg){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in Assign"<<endl;
            dst<<type;
        }
        virtual void translate(std::ostream &dst,TranslateContext &context) const override
        {
            // cout<<"in Assign"<<endl;
            dst<<type;
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
EXPR : ASSIGN_EXPR            {$$=$1;}
     | EXPR T_DH ASSIGN_EXPR  {$$=new Expr($1,$3);}
*/
class Expr : public Expression
{
    private:
       NodePtr node1;
       NodePtr node2;
    public:
        virtual ~Expr()
        {}
        Expr(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in Expr"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const override
        {
            // cout<<"in Expr"<<endl;
            node1->translate(dst,context);
            dst<<",";
            node2->translate(dst,context);
        }

        virtual double complier(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};



#endif