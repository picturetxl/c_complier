
#ifndef ast_expression_hpp
#define ast_expression_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Expression;

typedef const Expression *ExpresionPtr;

class Expression : public Node
{
private:

public:
    virtual ~Expression()
    {
    }
    Expression()
    {
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const =0;

    virtual void translate(std::ostream &dst, TranslateContext &context) const =0;

    virtual void compile(std::ostream &dst, CompileContext &context) const =0;
};

//--------------------------------------OpExpression----------------------------------------------------
class OpExpression;

typedef const OpExpression *OpExpressionPtr;

class OpExpression : public Expression
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~OpExpression()
    {
    }
    OpExpression(NodePtr _argv1,NodePtr _argv2)
    {
        expr1 = _argv1;
        expr2 =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr1->PrettyPrint(dst);
        expr2->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++StructDeclaration+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//--------------------------------------SingleExpression----------------------------------------------------
class SingleExpression;

typedef const SingleExpression *SingleExpressionPtr;

class SingleExpression : public Expression
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~SingleExpression()
    {
    }
    SingleExpression(NodePtr _argv1,NodePtr _argv2)
    {
        expr1 = _argv1;
        expr2 =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr1->PrettyPrint(dst);
        expr2->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++SingleExpression+++++++++++++++++++++++++++++++++++++++++++++++++++++++





#endif

