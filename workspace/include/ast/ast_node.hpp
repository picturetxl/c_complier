
#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
using namespace std;

class Node;

typedef const Node *NodePtr;

class Node
{
public:
    virtual ~Node()
    {}
    virtual void print(std::ostream &dst) const =0;
    virtual void translate(std::ostream &dst,TranslateContext & context) const =0;

    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


class Program;

typedef const Program *ProgramPtr;
/**
PROGRAM : EXTERNAL_OBJECT           {$$=$1;}
        | PROGRAM EXTERNAL_OBJECT   {$$=new Program($1,$2);} 
 */
class Program : public Node
{
private:
    NodePtr statement;
    NodePtr next;
public:
    virtual ~Program()
    {}
    Program(NodePtr arg1,NodePtr arg2)
    {
        next = arg1;
        statement = arg2;
    }
    virtual void print(std::ostream &dst) const override
    {
        dst<<"in program"<<endl;
        next->print(dst);
        statement->print(dst);
    }
    virtual void translate(std::ostream &dst,TranslateContext & context) const
    {
        cerr<<"in program"<<endl;
        // dst<<endl;
        next->translate(dst,context);
        dst<<endl;
        statement->translate(dst,context);
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


/*
    FUNCTION : TYPE_PART DECLARATOR T_FH        {$$=new Function($1,$2);}
         | TYPE_PART DECLARATOR STATEMENTS  {$$=new Function($1,$2,$3);}
*/
class Function : public Node
{
private:
    NodePtr node1;//TYPE_PART
    NodePtr node2;//DECLARATOR
    NodePtr node3;//STATEMENTS
public:
    virtual ~Function()
    {}
    Function(NodePtr arg1,NodePtr arg2)
        :node1(arg1),node2(arg2),node3(nullptr){}
    
    Function(NodePtr arg1,NodePtr arg2,NodePtr arg3)
        :node1(arg1),node2(arg2),node3(arg3){}
         
    virtual void print(std::ostream &dst) const override
    {
        dst<<"in Function"<<endl;
        node1->print(dst);
        node2->print(dst);
        if(node3)
        {
            node3->print(dst);
        }
    }
    virtual void translate(std::ostream &dst,TranslateContext & context) const
    {
        cerr<<"in Function"<<endl;

      
        if(node3)
        {//在函数里面了
            node1->translate(dst,context);
            node2->translate(dst,context);
            context.turn_on_function_flag();//在函数里
            context.clear_indent();
            context.increase_indent();
            node3->translate(dst,context);  
            context.decrease_indent();
            context.shutdown_function_flag();//不在函数
        }
        else
        {
            cerr<<"in globar"<<endl;
            context.turn_on_function_flag();//在函数里
            node1->translate(dst,context);
            node2->translate(dst,context);
            dst<<"=0";
            dst<<endl;
            context.shutdown_function_flag();//不在函数
        }
        
    }
    virtual double complier(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif
