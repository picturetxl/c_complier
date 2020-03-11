#ifndef ast_ex_declaration_hpp
#define ast_ex_declaration_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Ex_declaration;
class Ex_non_function_declaration;
class Ex_function_declaration;
typedef const Ex_declaration *Ex_declarationPtr;
typedef const Ex_non_function_declaration *Ex_non_function_declarationPtr;
typedef const Ex_function_declaration *Ex_function_declarationPtr;

//外部声明类
class Ex_declaration:public Node
{
private:
    NodePtr ex_non_function_declaration;
    NodePtr ex_function_declaration;
public:
    virtual ~Ex_declaration()
    {}

    Ex_declaration(NodePtr _arg1, NodePtr _arg2)
            : ex_non_function_declaration(_arg1)
            , ex_function_declaration(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        ex_non_function_declaration->translate(dst);
        ex_function_declaration->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


// 外部非函数声明类
class Ex_non_function_declaration:public Node
{
private:
    NodePtr ex_var_declatation;
    NodePtr ex_var_definition;
public:
    virtual ~Ex_non_function_declaration()
    {}

    Ex_non_function_declaration(NodePtr _arg1, NodePtr _arg2)
            : ex_var_declatation(_arg1)
            , ex_var_definition(_arg2)
    {}
    virtual void translate(std::ostream &dst) const
    {
        ex_var_declatation->translate(dst);
        ex_var_definition->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};

// 函数声明类
class Ex_function_declaration:public Node
{
private:
    NodePtr special;
    NodePtr type;
    NodePtr id;
    NodePtr arglist;
   
public:
    virtual ~Ex_function_declaration()
    {}

    Ex_function_declaration(NodePtr _arg1, NodePtr _arg2,NodePtr _arg3)
            : type(_arg1)
            , id(_arg2)
            , arglist(_arg2)
    {}
    Ex_function_declaration(NodePtr _arg1, NodePtr _arg2,NodePtr _arg3,NodePtr _arg4)
            : special(_arg1)
            , type(_arg2)
            , id(_arg3)
            , arglist(_arg4)
    {}
    virtual void translate(std::ostream &dst) const
    {
        if(special!=nullptr)
        {
            special->translate(dst);
        }
        type->translate(dst);
        id->translate(dst);
        arglist->translate(dst);
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};



#endif