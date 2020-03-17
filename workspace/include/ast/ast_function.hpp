
#ifndef ast_function_hpp
#define ast_function_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Function;

typedef const Function *FunctionPtr;

class Function : public Node
{
private:
    NodePtr type;
    NodePtr function_call;
    NodePtr statement;

public:
    virtual ~Function()
    {
    }
    Function(NodePtr _argv1,NodePtr _argv2,NodePtr _argv3)
    {
        type = _argv1;
        function_call = _argv2;
        statement = _argv3;
    }
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        type->PrettyPrint(dst);
        function_call->PrettyPrint(dst);
        statement->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

#endif
