#ifndef ast_type_hpp
#define ast_type_hpp

#include <map>
#include <iostream>
#include "ast_node.hpp"
class Type;
class Special;
typedef const Type *TypePtr;
typedef const Special *SpecialPtr;
/*
    抽象基类
*/
class Type:public Node
{
private:
    std::string* type;
    NodePtr special;
    NodePtr next_type;
public:
    virtual ~Type()
    {}
    Type(std::string* type)
            : type(type)
    {}
    Type(NodePtr special,NodePtr next_type)
            : special(special)
            , next_type(next_type)
    {}
    virtual void translate(std::ostream &dst) const
    {
        if(special==nullptr or next_type == nullptr)
        {
            std::cout<<*type;
        }
        else
        {
            special->translate(dst);
            next_type->translate(dst);
        }
        
       
    }
    

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


class Special:public Node
{
private:
    std::string* special;
public:
    virtual ~Special()
    {}
    Special(std::string* type)
            : special(type)
    {}
   
    virtual void translate(std::ostream &dst) const
    {
        std::cout<<*special;
    }
    

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};



#endif