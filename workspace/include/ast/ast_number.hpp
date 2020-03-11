#ifndef ast_number_hpp
#define ast_number_hpp

#include "ast_node.hpp"
#include <map>
#include <iostream>

class Number;
class Integer;
class Float;
class Mystring;

typedef const Number *NumberPtr;
typedef const Integer *IntegerPtr;
typedef const Float *FloatPtr;
typedef const Mystring *MystringPtr;
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




class Integer:public Node
{
private:
    int integer;
public:
    virtual ~Integer()
    {}

    Integer(int _arg1)
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

class Float:public Number
{
private:
    float floatptr;
public:
    virtual ~Float()
    {}

    Float(float _arg1)
            : floatptr(_arg1)
    {}
    virtual void translate(std::ostream &dst) const
    {
        dst<<"float";
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


class Mystring:public Node
{
private:
   std::string mystring;
public:
    virtual ~Mystring()
    {}

    Mystring(std::string _arg1)
            : mystring(_arg1)
    {}
    virtual void translate(std::ostream &dst) const
    {
        dst<<mystring;
    }

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};




#endif