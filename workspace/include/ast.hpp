#ifndef ast_hpp
#define ast_hpp
#include <vector>
#include <map>

#include "ast/ast_expression.hpp"


extern const Expression *parseAST(char* filename);

#endif