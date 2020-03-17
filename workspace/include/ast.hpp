#ifndef ast_hpp
#define ast_hpp
#include <vector>
#include <map>

#include "ast/ast_node.hpp"
#include "ast/ast_program.hpp"
#include "ast/ast_function.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_other.hpp"
#include "ast/ast_type.hpp"

extern const Node *parseAST(char* filename);

#endif