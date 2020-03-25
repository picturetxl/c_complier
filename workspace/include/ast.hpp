/*
 * @Author: your name
 * @Date: 2020-03-21 02:30:53
 * @LastEditTime: 2020-03-22 17:42:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /complier/include/ast.hpp
 */
#ifndef ast_hpp
#define ast_hpp

#include "ast/translate_context.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_declaration.hpp"

extern const Node *parseAST(char *filename);

#endif
