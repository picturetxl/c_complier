#ifndef ast_node_hpp
#define ast_node_hpp

#include <map>
#include <iostream>

class Node;

typedef const Node *NodePtr;
/*
    抽象基类
*/
class Node
{

public:
    virtual ~Node()
    {}

    virtual void translate(std::ostream &dst) const = 0;

    virtual double complie(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif