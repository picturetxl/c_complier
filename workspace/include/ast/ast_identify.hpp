#ifndef ast_identify_hpp
#define ast_identify_hpp

#include <map>
#include <iostream>
#include "ast_node.hpp"
class Identify:public Node
{
private:
    std::string* identify;
public:
    virtual ~Identify()
    {}
    Identify(std::string* type)
            : identify(type)
    {}
   
    virtual void translate(std::ostream &dst) const
    {
        std::cout<<*identify;
    }
    

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};

#endif