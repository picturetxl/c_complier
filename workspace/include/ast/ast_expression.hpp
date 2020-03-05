#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Expression;

typedef const Expression *ExpressionPtr;

class Expression
{
public:
    virtual ~Expression(){}

    //将c解释成python
    virtual void interpret(std::ostream &dst) const =0
    { 
        throw std::runtime_error("interpret Not implemented."); 
    }



    
};


#endif
