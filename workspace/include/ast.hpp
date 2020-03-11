#ifndef ast_hpp
#define ast_hpp
#include <vector>
#include <map>

#include "ast/ast_arg_list.hpp"
#include "ast/ast_ex_declaration.hpp"
#include "ast/ast_ex_var_declaration.hpp"

#include "ast/ast_expression.hpp"
#include "ast/ast_identify.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_number.hpp"
#include "ast/ast_program.hpp"
#include "ast/ast_type.hpp"

extern const Node *parseAST(char* filename);

#endif