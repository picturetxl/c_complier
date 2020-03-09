#ifndef ast_arg_list_hpp
#define ast_arg_list_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Arg_list;

typedef const Arg_list *Arg_listPtr;

class Arg_list:public Node
{
private:
    Arg_listPtr next;
    Arg_listPtr ex_var_declatation;
public:
    virtual ~Arg_list()
    {}

    Arg_list(NodePtr _arg1, NodePtr _arg2)
            : next(_arg1)
            , ex_var_declatation(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        next->translate(dst);
        ex_var_declatation->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif