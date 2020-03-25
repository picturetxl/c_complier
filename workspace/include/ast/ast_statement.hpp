#ifndef ast_statement_hpp
#define ast_statement_hpp


#include "ast.hpp"

#include <iostream>
#include <string>

using namespace std;

/*

CASE_STATEMENT : T_ID T_MH STATEMENT                    {$$=new CaseStatement($1,$3);}
               | T_K_CASE REGULAR_EXPR T_MH STATEMENT   {$$=new CaseStatement($2,$4,"case");}
               | T_K_DEFAULT T_MH STATEMENT             {$$=new CaseStatement($3,"default");}
*/
class CaseStatement : public Node
{
private:
    NodePtr node1;
    NodePtr node2;
    string * id;
    string type;
public:
    virtual ~CaseStatement()
    {}
    CaseStatement(string* arg1,NodePtr arg2)
        :id(arg1),node1(arg2),node2(nullptr),type(nullptr){}
    
    CaseStatement(NodePtr arg1,NodePtr arg2,string arg3)
        :type(arg3),node1(arg2),node2(arg2),id(nullptr){}
     
    CaseStatement(NodePtr arg1,string arg2)
        :node1(arg1),node2(nullptr),id(nullptr),type(arg2){}
    
    virtual void print(std::ostream &dst) const override
    {
        dst<<"in CaseStatement"<<endl;
        if(id)
        {
            dst<<*id<<endl;
        }

        if(node1)
        {
            node1->print(dst);
        }

        if(node2)
        {
            node2->print(dst);
        }

        if(type == "case")
        {
            dst<<"case"<<endl;
        }

        if(type == "default")
        {
            dst<<"default"<<endl;
        }

    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        throw std::runtime_error("python Not supported.");
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};

/*
STATEMENTS : T_LDKH T_RDKH                      {$$=new Statements();}
           | T_LDKH STATEMENT_SEQUENCE T_RDKH   {$$=new Statements($2);}
*/
class Statements : public Node
{
private:
    NodePtr node;
public:
    virtual ~Statements()
    {}
    Statements(NodePtr arg)
        :node(arg){}

    Statements(){}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"in Statements"<<endl;
        if(node)
        {
            node->print(dst);
        }
       
    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in Statements"<<endl;
        dst<<endl;
        if(node)
        {
            node->translate(dst,context);
            dst<<endl;
        }

    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};

/*
LIST_DECLARATION : DECLARATION                  {$$=$1;}           
                 | LIST_DECLARATION DECLARATION {$$=new ListDeclaration($1,$2);}
*/
class ListDeclaration : public Node
{
private:
    NodePtr node1;
    NodePtr node2;
public:
    virtual ~ListDeclaration()
    {}
    ListDeclaration(NodePtr arg1,NodePtr arg2)
        :node1(arg1),node2(arg2){}


    virtual void print(std::ostream &dst) const override
    {
        dst<<"in ListDeclaration"<<endl;
        node1->print(dst);
        node2->print(dst);
    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in ListDeclaration"<<endl;
        node1->translate(dst,context);
        node2->translate(dst,context);
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


/*
STATEMENT_SEQUENCE : STATEMENT                      {$$=$1;}
                   | STATEMENT_SEQUENCE STATEMENT   {$$=new StatementSequence($1,$2);}
*/
class StatementSequence : public Node
{
private:
    NodePtr node1;
    NodePtr node2;
public:
    virtual ~StatementSequence()
    {}
    StatementSequence(NodePtr arg1,NodePtr arg2)
        :node1(arg1),node2(arg2){}


    virtual void print(std::ostream &dst) const override
    {
        dst<<"in StatementSequence"<<endl;
        node1->print(dst);
        node2->print(dst);
    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in StatementSequence"<<endl;
        node1->translate(dst,context);
        node2->translate(dst,context);
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


/*
EXPR_STATEMENT : T_FH       {$$=new ExprStatement();}
               | EXPR T_FH  {$$=new ExprStatement($1);}
*/
class ExprStatement : public Node
{
private:
    NodePtr node;
public:
    virtual ~ExprStatement()
    {}
    ExprStatement(NodePtr arg)
        :node(arg){}

    ExprStatement(){}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"in ExprStatement"<<endl;
        if(node)
            node->print(dst);
    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        if(node)
        {
            cerr<<"in ExprStatement"<<endl;
            context.indent_output(dst);
            node->translate(dst,context);
            dst<<endl;
        }
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};



/*
SELECTION_STATEMENT : T_K_IF T_LXKH EXPR T_RXKH STATEMENT                     {$$=new SelectionStatement($3,$5,"if");}
                    | T_K_IF T_LXKH EXPR T_RXKH STATEMENT T_K_ELSE STATEMENT  {$$=new SelectionStatement($3,$5,$7,"ifelse");}
                    | T_K_SWITCH T_LXKH EXPR T_RXKH STATEMENT                 {$$=new SelectionStatement($3,$5,"switch");}
*/
class SelectionStatement : public Node
{
private:
    NodePtr node1;
    NodePtr node2;
    NodePtr node3;
    string type;
public:
    virtual ~SelectionStatement()
    {}
    SelectionStatement(NodePtr arg1,NodePtr arg2,string arg3)
        :node1(arg1),node2(arg2),type(arg3),node3(nullptr){}

    SelectionStatement(NodePtr arg1,NodePtr arg2,NodePtr arg3,string arg4)
        :node1(arg1),node2(arg2),type(arg4),node3(arg3){}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"in SelectionStatement"<<endl;
        node1->print(dst);
        node2->print(dst);
        if(node3)
        {
            node3->print(dst);
        }
        if(type == "if")
        {
            dst<<type<<endl;
        }
        if(type == "ifelse")
        {
            dst<<type<<endl;
        }
        if(type == "switch")
        {
            dst<<type<<endl;
        }
        

    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in SelectionStatement"<<endl;
        /*
            if(node1):
                node2
        */
         if(type == "if")
        {
            context.indent_output(dst);
            dst<<"if(";
            node1->translate(dst,context);
            dst<<"):";
            // dst<<endl;
            context.increase_indent();
            context.indent_output(dst);
            node2->translate(dst,context);
            // dst<<endl;
            context.decrease_indent();
        }
        if(type == "ifelse")
        {
            /*
                if node1:
                    node2
                else
                    node3
            */
            context.indent_output(dst);
            dst<<"if(";
            node1->translate(dst,context);
            dst<<"):";
            // dst<<endl;
            context.increase_indent();
            context.indent_output(dst);
            node2->translate(dst,context);
            context.decrease_indent();
            // dst<<endl;
            dst<<"else"<<endl;
            context.increase_indent();
            context.indent_output(dst);
            node3->translate(dst,context);
            context.decrease_indent();
            // dst<<endl;
        }
        if(type == "switch")
        {
            throw std::runtime_error("python Not supported.");
        }
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


/*
ITERATION_STATEMENT : T_K_WHILE T_LXKH EXPR T_RXKH STATEMENT                           {$$=new IterationStatement($3,$5,"while");}
                    | T_K_DO STATEMENT T_K_WHILE T_LXKH EXPR T_RXKH T_FH                  {$$=new IterationStatement($2,$5,"dowhile");}
                    | T_K_FOR T_LXKH EXPR_STATEMENT EXPR_STATEMENT T_RXKH STATEMENT       {$$=new IterationStatement($3,$4,$6,"for");}
                    | T_K_FOR T_LXKH EXPR_STATEMENT EXPR_STATEMENT EXPR T_RXKH STATEMENT  {$$=new IterationStatement($3,$4,$5,$7,"for");}
*/
class IterationStatement : public Node
{
private:
    NodePtr node1;
    NodePtr node2;
    NodePtr node3;
    NodePtr node4;
    string type;
public:
    virtual ~IterationStatement()
    {}
    IterationStatement(NodePtr arg1,NodePtr arg2,string arg3)
        :node1(arg1),node2(arg2),type(arg3),node3(nullptr),node4(nullptr){}

    IterationStatement(NodePtr arg1,NodePtr arg2,NodePtr arg3,string arg4)
        :node1(arg1),node2(arg2),type(arg4),node3(arg3),node4(nullptr){}

    IterationStatement(NodePtr arg1,NodePtr arg2,NodePtr arg3,NodePtr arg4,string arg5)
        :node1(arg1),node2(arg2),type(arg5),node3(arg3),node4(arg4){}




    virtual void print(std::ostream &dst) const override
    {
        dst<<"in IterationStatement"<<endl;
        node1->print(dst);
        node2->print(dst);
        if(node3)
        {
            node3->print(dst);
        }
        if(node4)
        {
            node4->print(dst);
        }
        if(type == "while")
        {
            dst<<type<<endl;
        }
        if(type == "dowhile")
        {
            dst<<type<<endl;
        }
        if(type == "for")
        {
            dst<<type<<endl;
        }
    }

    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in IterationStatement"<<endl;
        if(type == "while")
        {
            /*
                while(node1):
                    node2
            */
            context.indent_output(dst);
            dst<<type<<"(";
            node1->translate(dst,context);
            dst<<"):"<<endl;
            context.increase_indent();
            context.indent_output(dst);
            node2->translate(dst,context);
            context.decrease_indent();
            dst<<endl;
        }
        if(type == "dowhile")
        {
            throw std::runtime_error("python Not implemented.");
        }
        if(type == "for")
        {
            //! todo
            dst<<type<<endl;
        }
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


/*
JUMP_STATEMENT : T_K_GOTO T_ID T_FH     {$$=new JumpStatement($2,"goto");}
               | T_K_CONTINUE T_FH      {$$=new JumpStatement("continue");}
               | T_K_BREAK T_FH         {$$=new JumpStatement("break");}
               | T_K_RETURN T_FH        {$$=new JumpStatement("return");}
               | T_K_RETURN EXPR T_FH   {$$=new JumpStatement($2,"return");}
*/
class JumpStatement : public Node
{
private:
    NodePtr node1;
    string type;
    string *id;
public:
    virtual ~JumpStatement()
    {}
    JumpStatement(NodePtr arg1,string arg2)
        :node1(arg1),type(arg2){}

    JumpStatement(string arg1)
        :type(arg1),node1(nullptr){}
    JumpStatement(string* arg1,string arg2)
        :id(arg1),type(arg2),node1(nullptr){}


    virtual void print(std::ostream &dst) const override
    {
        dst<<"in JumpStatement"<<endl;
        if(node1)
        {
            node1->print(dst);
        }
        if(id)
        {
            dst<<*id<<endl;
        }
        if(type == "goto")
        {
            dst<<type<<endl;
        }
        if(type == "continue")
        {
            dst<<type<<endl;
        }
        if(type == "return")
        {
            dst<<type<<endl;
        }
        
        if(type == "break")
        {
            dst<<type<<endl;
        }

    }
    virtual void translate(std::ostream &dst,TranslateContext&context) const
    {
        cerr<<"in JumpStatement"<<endl;
        if(type == "goto")
        {
            throw std::runtime_error("Not implemented.");
        }
        if(type == "continue")
        {
            context.indent_output(dst);
            dst<<type;
        }
        if(type == "return")
        {
            cerr<<"in return "<<endl;
            cerr<<"indent:"<<context.get_indent()<<endl;
            context.indent_output(dst);
            dst<<type<<" ";
            node1->translate(dst,context);
        //    dst<<endl;
        }
        
        if(type == "break")
        {
            context.indent_output(dst);
            dst<<type;

        }

    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};





#endif