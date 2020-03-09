#ifndef ast_number_hpp
#define ast_number_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Number;
class Integer;
typedef const Number *NumberPtr;
typedef const Integer *IntegerPtr;


class Number:public Node
{

public:
    virtual ~Number()
    {}

    virtual void translate(std::ostream &dst) const = 0;
   

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};




class Integer:public Number
{
private:
    IntegerPtr integer;
public:
    virtual ~Integer()
    {}

    Integer(NumberPtr _arg1)
            : integer(_arg1)
    {}
    virtual void translate(std::ostream &dst) const
    {
        dst<<"int";
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif