#ifndef ast_expression_hpp
#define ast_expression_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Expression;
class Funciton_node;
typedef const Expression *ExpressionPtr;
typedef const Funciton_node *Funciton_nodePtr;

class Expression:public Node
{
private:
    NodePtr left;
    std::string op;
    NodePtr right;
public:
    virtual ~Expression()
    {}

    Expression(NodePtr _arg1, std::string op,NodePtr _arg2)
            : left(_arg1)
            ,op(op)
            , right(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        left->translate(dst);
        right->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


class Funciton_node:public Node
{
private:
    NodePtr ex_function_declaration;
    NodePtr expr;
public:
    virtual ~Funciton_node()
    {}

    Funciton_node(NodePtr _arg1,NodePtr _arg2)
            : ex_function_declaration(_arg1)
            , expr(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        ex_function_declaration->translate(dst);
        expr->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif