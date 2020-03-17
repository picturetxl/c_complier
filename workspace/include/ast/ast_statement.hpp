
#ifndef ast_statement_hpp
#define ast_statement_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>



class Statement : public Node
{

public:
    virtual ~Statement()
    {
    }
    Statement()
    {
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const =0;

    virtual void translate(std::ostream &dst, TranslateContext &context) const = 0;

    virtual void compile(std::ostream &dst, CompileContext &context) const = 0;
};



//--------------------------------------AssignmentStatement----------------------------------------------------


class AssignmentStatement : public Statement
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~AssignmentStatement()
    {
    }
    AssignmentStatement(NodePtr _argv1,NodePtr _argv2)
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

//+++++++++++++++++++++++++++++++AssignmentStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------CompareStatement----------------------------------------------------



class CompareStatement : public Statement
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~CompareStatement()
    {
    }
    CompareStatement(NodePtr _argv1,NodePtr _argv2)
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

//+++++++++++++++++++++++++++++++CompareStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------IfelseStatment----------------------------------------------------


class IfelseStatment : public Statement
{
private:
    NodePtr expr1;
    NodePtr statement1;
    NodePtr statement2;
public:
    virtual ~IfelseStatment()
    {
    }
    IfelseStatment(NodePtr _argv1,NodePtr _argv2)
    {
        expr1 = _argv1;
        statement1 =_argv2;
       
    }
    IfelseStatment(NodePtr _argv1,NodePtr _argv2,NodePtr _argv3)
    {
        expr1 = _argv1;
        statement1 =_argv2;
        statement2 =_argv3;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr1->PrettyPrint(dst);
        statement1->PrettyPrint(dst);
        if(statement2)
        {
            statement2->PrettyPrint(dst);
        }

    }

     virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++IfelseStatment+++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------WhileStatement----------------------------------------------------



class WhileStatement : public Statement
{
private:
    NodePtr expr1;
    NodePtr statement1;
public:
    virtual ~WhileStatement()
    {
    }
    WhileStatement(NodePtr _argv1,NodePtr _argv2)
    {
        expr1 = _argv1;
        statement1 =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr1->PrettyPrint(dst);
        statement1->PrettyPrint(dst);

    }

      virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++WhileStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------ForStatement----------------------------------------------------


class ForStatement : public Statement
{
private:
    NodePtr list;
    NodePtr statement;
public:
    virtual ~ForStatement()
    {
    }
    ForStatement(NodePtr _argv1,NodePtr _argv2)
    {
        list = _argv1;
        statement =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        list->PrettyPrint(dst);
        statement->PrettyPrint(dst);

    }

     virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++ForStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------EnumStatement----------------------------------------------------




class EnumStatement : public Statement
{
private:
    NodePtr list;
    NodePtr statement;
public:
    virtual ~EnumStatement()
    {
    }
    EnumStatement(NodePtr _argv1,NodePtr _argv2)
    {
        list = _argv1;
        statement =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        list->PrettyPrint(dst);
        statement->PrettyPrint(dst);

    }

     virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++EnumStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------SwitchStatement----------------------------------------------------


class SwitchStatement : public Statement
{
private:
    NodePtr expr;
    NodePtr case_statement;
public:
    virtual ~SwitchStatement()
    {
    }
    SwitchStatement(NodePtr _argv1,NodePtr _argv2)
    {
        expr = _argv1;
        case_statement =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr->PrettyPrint(dst);
        case_statement->PrettyPrint(dst);

    }

     virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++SwitchStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++




//--------------------------------------CaseStatement----------------------------------------------------



class CaseStatement : public Statement
{
private:
    NodePtr expr;
    NodePtr statement;
public:
    virtual ~CaseStatement()
    {
    }
    CaseStatement(NodePtr _argv1,NodePtr _argv2)
    {
        expr = _argv1;
        statement =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr->PrettyPrint(dst);
        statement->PrettyPrint(dst);

    }

      virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++CaseStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------TypedefStatement----------------------------------------------------

class TypedefStatement : public Statement
{
private:
    NodePtr type1;
    NodePtr type2;
public:
    virtual ~TypedefStatement()
    {
    }
    TypedefStatement(NodePtr _argv1,NodePtr _argv2)
    {
        type1 = _argv1;
        type2 =_argv2;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        type1->PrettyPrint(dst);
        type2->PrettyPrint(dst);

    }

      virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++TypedefStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------TwoOpStatement----------------------------------------------------



class TwoOpStatement : public Statement
{
private:
    NodePtr expr1;
    NodePtr expr2;
public:
    virtual ~TwoOpStatement()
    {
    }
    TwoOpStatement(NodePtr _argv1,NodePtr _argv2)
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

//+++++++++++++++++++++++++++++++TwoOpStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------StructStatement----------------------------------------------------


class StructStatement : public Statement
{
private:
    NodePtr statement;
public:
    virtual ~StructStatement()
    {
    }
    StructStatement(NodePtr _argv1)
    {
        statement = _argv1;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        statement->PrettyPrint(dst);

    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++StructStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++



//--------------------------------------SizeofStatement----------------------------------------------------



class SizeofStatement : public Statement
{
private:
    NodePtr expr;
public:
    virtual ~SizeofStatement()
    {
    }
    SizeofStatement(NodePtr _argv1)
    {
        expr = _argv1;
       
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        expr->PrettyPrint(dst);

    }

      virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

//+++++++++++++++++++++++++++++++SizeofStatement+++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef const SizeofStatement *SizeofStatementPtr;
typedef const StructStatement *StructStatementPtr;
typedef const TwoOpStatement *TwoOpStatementPtr;


typedef const TypedefStatement *TypedefStatementPtr;
typedef const CaseStatement *SwitchStatementPtr;

typedef const ForStatement *ForStatementPtr;
typedef const WhileStatement *WhileStatementPtr;

typedef const CompareStatement *CompareStatementPtr;

typedef const AssignmentStatement *AssignmentStatementPtr;

typedef const Statement *StatementPtr;
typedef const EnumStatement *EnumStatementPtr;


#endif
