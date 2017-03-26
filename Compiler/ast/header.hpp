#ifndef header_hpp
#define header_hpp

//static const Program *parseAST();


#include "ast_toplevel.hpp"
#include "ast_declaration.hpp"
#include "ast_globalvariable.hpp"
#include "ast_addictive.hpp"
#include "ast_initializer.hpp"
#include "ast_operator.hpp"
#include "ast_function.hpp"
#include "ast_return.hpp"
#include "ast_redeclare.hpp"
#include "ast_parameter.hpp"
#include "ast_if.hpp"
#include "ast_while.hpp"

extern const Program *parseAST();

#endif
