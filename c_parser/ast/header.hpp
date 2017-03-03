#ifndef ast_hpp
#define ast_hpp

#include "ast_toplevel.hpp"
#include "ast_variable.hpp"
#include "ast_declaration.hpp"
#include "ast_declaration_specifiers.hpp"
#include "ast_all_declaration.hpp"
#include "ast_number.hpp"
#include "ast_init_declarator.hpp"
#include "ast_unary_expression.hpp"




extern const Program *parseAST();

#endif
