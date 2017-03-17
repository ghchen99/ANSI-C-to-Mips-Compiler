#ifndef header_hpp
#define header_hpp

#include "ast_toplevel.hpp"
#include "ast_variable.hpp"
#include "ast_declaration.hpp"
#include "ast_declaration_specifiers.hpp"
#include "ast_all_declaration.hpp"
#include "ast_number.hpp"
#include "ast_init_declarator.hpp"
#include "ast_unary_expression.hpp"
#include "ast_function.hpp"
#include "ast_parameter.hpp"
#include "ast_scope.hpp"
#include "ast_direct_declarator.hpp"
#include "ast_if.hpp"
#include "ast_postfix.hpp"

extern const Program *parseAST();

#endif
