#ifndef ast_program_hpp
#define ast_program_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Program;

typedef const Program *ProgramPtr;

class Program:public Node
{
private:
    ProgramPtr ex_declaration;
    ProgramPtr function;
public:
    virtual ~Program()
    {}

    Program(NodePtr _arg1, NodePtr _arg2)
            : ex_declaration(_arg1)
            , function(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        ex_declaration->translate(dst);
        function->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif