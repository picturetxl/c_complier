
#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Node;

typedef const Node *NodePtr;


typedef struct translate_context{

}TranslateContext;

typedef struct complier_context{

}CompileContext;
class Node
{
public:
    virtual ~Node()
    {}
    Node(){}
    //! Tell and expression to print itself to the given stream
    virtual void PrettyPrint(std::ostream &dst) const =0;

    virtual void translate(std::ostream &dst, TranslateContext &context) const =0;

    virtual void compile(std::ostream &dst, CompileContext &context) const =0;
};


#endif
