
#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Declaration;

typedef const Declaration *DeclarationPtr;

class Declaration : public Node
{

public:
    virtual ~Declaration()
    {
    }
    Declaration()
    {
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const =0;

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {};

    virtual void compile(std::ostream &dst, CompileContext &context) const override {};
};

//-----------------------------------------Array_declaration-------------------------------------------------
class ArrayDeclaration;

typedef const ArrayDeclaration *ArrayNodePtr;

class ArrayDeclaration : public Declaration
{
private:
    NodePtr type;
    NodePtr expr;
public:
    virtual ~ArrayDeclaration()
    {
    }
    ArrayDeclaration(NodePtr _argv1,NodePtr _argv2)
    {
        type = _argv1;
        expr = _argv2;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        type->PrettyPrint(dst);
          expr->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {};

    virtual void compile(std::ostream &dst, CompileContext &context) const override {};
};

//++++++++++++++++++++++++++++++++++++++++Array_declaration++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------Function_declaration----------------------------------------------------
class FunctionDeclaration;

typedef const FunctionDeclaration *FunctionNodePtr;

class FunctionDeclaration : public Declaration
{
private:
    NodePtr id;
    NodePtr function_call;
public:
    virtual ~FunctionDeclaration()
    {
    }
    FunctionDeclaration(NodePtr _argv1,NodePtr _argv2)
    {
        id = _argv1;
        function_call = _argv2;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        id->PrettyPrint(dst);
        function_call->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++Function_declaration+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//--------------------------------------Regular_declaration----------------------------------------------------
class RegularDeclaration;

typedef const RegularDeclaration *RegularNodePtr;

class RegularDeclaration : public Declaration
{
private:
    NodePtr type;
    
public:
    virtual ~RegularDeclaration()
    {
    }
    RegularDeclaration(NodePtr _argv1)
    {
        type = _argv1;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        type->PrettyPrint(dst);
       
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++Regular_declaration+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------StructDeclaration----------------------------------------------------
class StructDeclaration;

typedef const StructDeclaration *StructNodePtr;

class StructDeclaration : public Declaration
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~StructDeclaration()
    {
    }
    StructDeclaration(NodePtr _argv1,NodePtr _argv2)
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









#endif
