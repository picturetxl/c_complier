
#ifndef ast_program_hpp
#define ast_program_hpp

#include "../ast.hpp"

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Program;

typedef const Program *ProgramPtr;

class Program : public Node
{
private:
    NodePtr program;
    NodePtr external_object;

public:
    virtual ~Program()
    {
    }
    Program(NodePtr _argv1,NodePtr _argv2)
    {
        program = _argv1;
        external_object  = _argv2;
    }

    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const override
    {
        program->PrettyPrint(dst);
        external_object->PrettyPrint(dst);
    }

    virtual void translate(std::ostream &dst, TranslateContext &context) const override {}

    virtual void compile(std::ostream &dst, CompileContext &context) const override {}
};

#endif
