
#ifndef ast_other_hpp
#define ast_other_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Charator : public Node
{
private:
    char charactor;

public:
    virtual ~Charator()
    {
    }
    Charator(char _argv1)
    {
        charactor = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<charactor<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};



class String : public Node
{
private:
    std::string* str;

public:
    virtual ~String()
    {
    }
    String(std::string* _argv1)
    {
        str = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<*str<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};





class Integer : public Node
{
private:
    int intNumber;

public:
    virtual ~Integer()
    {
    }
    Integer(int _argv1)
    {
        intNumber = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<intNumber<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};




class Float : public Node
{
private:
    double intNumber;

public:
    virtual ~Float()
    {
    }
    Float(int _argv1)
    {
        intNumber = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        dst<<intNumber<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};


class AssignDefinition : public Node
{
private:
    NodePtr type;
    NodePtr expr;

public:
    virtual ~AssignDefinition()
    {
    }
    AssignDefinition(NodePtr _argv1,NodePtr _argv2)
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

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};


class Dot : public Node
{
private:
    NodePtr expr1;
    NodePtr expr2;

public:
    virtual ~Dot()
    {
    }
    Dot(NodePtr _argv1,NodePtr _argv2)
    {
        expr1 = _argv1;
        expr2 = _argv2;
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




class Pointer : public Node
{
private:
    NodePtr pointer;
    NodePtr star;

public:
    virtual ~Pointer()
    {
    }
    Pointer(NodePtr _argv1,NodePtr _argv2)
    {
        pointer = _argv1;
        star = _argv2;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        pointer->PrettyPrint(dst);
        star->PrettyPrint(dst);
    }

   virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};





class ArgList : public Node
{
private:
    NodePtr arglist;
    NodePtr statement;

public:
    virtual ~ArgList()
    {
    }
    ArgList(NodePtr _argv1,NodePtr _argv2)
    {
        arglist = _argv1;
        statement = _argv2;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override 
    {
        arglist->PrettyPrint(dst);
        statement->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};




class ForList : public Node
{
private:
    NodePtr forlist;
    NodePtr statement;

public:
    virtual ~ForList()
    {
    }
    ForList(NodePtr _argv1,NodePtr _argv2)
    {
        forlist = _argv1;
        statement = _argv2;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        forlist->PrettyPrint(dst);
        statement->PrettyPrint(dst);
    }

     virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};



class Identify : public Node
{
private:
    std::string *s;

public:
    virtual ~Identify()
    {
    }
    Identify(std::string* _argv1)
    {
        s = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    void PrettyPrint(std::ostream &dst) const override
    {
        dst<<*s<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};


class Break : public Node
{
private:
    std::string s;

public:
    virtual ~Break()
    {
    }
    Break(std::string _argv1)
    {
        s = _argv1;
    }

    //! Tell and expression to print itself to the given stream
    void PrettyPrint(std::ostream &dst) const
    {
        dst<<"break"<<std::endl;
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};





typedef const Break *BreakPtr;

typedef const Identify *IdentifyPtr;

typedef const ForList *ForListPtr;
typedef const ArgList *ArgListPtr;
typedef const Pointer *PointerPtr;
typedef const Dot *DotPtr;
typedef const Charator *CharatorPtr;
typedef const String *StringPtr;
typedef const Float *FloatPtr;
typedef const Integer *IntegerPtr;
typedef const AssignDefinition*AssignDefinitionPtr;
#endif
