
#ifndef ast_type_hpp
#define ast_type_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class TYPE;

typedef const TYPE *TYPEPtr;

class TYPE : public Node
{
private:
    NodePtr expr;

public:
    virtual ~TYPE()
    {
    }
    TYPE()
    {
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const =0;
    virtual void translate(std::ostream &dst, TranslateContext &context) const override{}

    virtual void compile(std::ostream &dst, CompileContext &context) const override{}
};

class TypeInt;

typedef const TypeInt *TypeIntPtr;

class TypeInt : public Node
{
private:
    std::string s;

public:
    virtual ~TypeInt()
    {
    }
    TypeInt(std::string str)
    {
       s = str;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const
    {
        dst<<s<<std::endl;
    }
    virtual void translate(std::ostream &dst, TranslateContext &context) const override{}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};


class TypeDouble;

typedef const TypeDouble *TypeDoublePtr;

class TypeDouble : public Node
{
private:
    std::string s;

public:
    virtual ~TypeDouble()
    {
    }
    TypeDouble(std::string str)
    {
       s = str;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<s<<std::endl;
    }
    virtual void translate(std::ostream &dst, TranslateContext &context) const override{}

    virtual void compile(std::ostream &dst, CompileContext &context) const override{}
};


class TypeFloat;

typedef const TypeFloat *TypeFloatPtr;

class TypeFloat : public Node
{
private:
    std::string s;

public:
    virtual ~TypeFloat()
    {
    }
    TypeFloat(std::string str)
    {
       s = str;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<s<<std::endl;
    }
    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

class TypeStar;

typedef const TypeStar *TypeStarPtr;

class TypeStar : public Node
{
private:
    std::string s;

public:
    virtual ~TypeStar()
    {
    }
    TypeStar(std::string str)
    {
       s = str;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<s<<std::endl;
    }
    virtual void translate(std::ostream &dst, TranslateContext &context) const override{}

    virtual void compile(std::ostream &dst, CompileContext &context) const override{}
};





#endif