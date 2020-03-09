#ifndef ast_ex_var_declaration_hpp
#define ast_ex_var_declaration_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Ex_var_declaration;

typedef const Ex_var_declaration *Ex_var_declarationPtr;

class Ex_var_declaration:public Node
{
private:
    Ex_var_declarationPtr type;
    Ex_var_declarationPtr id;
    Ex_var_declarationPtr value;
public:
    virtual ~Ex_var_declaration()
    {}

    Ex_var_declaration(NodePtr _arg1, NodePtr _arg2)
            : type(_arg1)
            , id(_arg2)
    {}
    Ex_var_declaration(NodePtr _arg1, NodePtr _arg2,NodePtr _arg3)
            : type(_arg1)
            , id(_arg2)
            , value(_arg3)
    {}
    virtual void translate(std::ostream &dst) const
    {
        type->translate(dst);
        id->translate(dst);
        if (value!=nullptr)
        {
            value->translate(dst);
        }
        
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif