%code requires{
  #include "header.hpp"

  #include <cassert>

  extern const Program *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Program *prog;
  std::string *string;
}

%token T_COMMA T_LCURLYBRACKET T_RCURLYBRACKET T_LBRACKET T_RBRACKET T_SIMICOLOUMN T_INT T_CONTROL_FLOW T_VARIABLE
%token T_EQUAL T_RETURN

%type <prog> PROGRAM external_declearation function_definition declaration
%type <prog>
%type <string> T_SIMICOLOUMN

%start ROOT

%%

ROOT : PROGRAM

PROGRAM: external_declearation
       | PROGRAM external_declearation

external_declearation : function_definition
                      | declaration

function_definition : declaration_specifiers declarator declaration_list compound_statement
                    | declaration_specifiers declarator compound_statement
                    | declarator declaration_list compound_statement
                    | declarator compound_statement

declaration : declaration_specifiers T_SIMICOLOUMN
            | declaration_specifiers init_declartor_list T_SIMICOLOUMN

declaration_specifiers : storage_class_specifier
                       | storage_class_specifier declaration_specifiers
                       | type_specifier
                       | type_specifier declaration_specifiers

declarator : pointer direct_declarator
           | direct_declarator

direct_declarator : T_VARIABLE
                  | T_LBRACKET declarator T_RBRACKET
                  | direct_declarator '[' const_experssion ']'
                  | direct_declarator '['  ']'
                  | direct_declarator '(' Parameter_type_list ')'
                  | direct_declarator '(' identifier_list ')'
                  | direct_declarator '('  ')'

const_experssion : conditional_expression //it could be every non_terminal

identifier_list : T_VARIABLE
	            | identifier_list ',' T_VARIABLE

parameter_type_list : parameter_list
                	| parameter_list ',' ELLIPSIS

parameter_list  : parameter_declaration
                | parameter_list ',' parameter_declaration

parameter_declaration : declaration_specifiers declarator
                	  | declaration_specifiers abstract_declarator
                	  | declaration_specifiers

compound_statement 	: '{' '}'
                    | '{' statement_list '}'
                    | '{' declaration_list '}'
                    | '{' declaration_list statement_list '}'

storage_class_specifier : TYPEDEF | EXTERN | STATIC | AUTO | REGISTER

type_specifier : VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED | UNSIGNED | TYPE_NAME

TYPE_NAME : T_VARIABLE
%%

const Program *g_root; // Definition of variable (to match declaration earlier)


const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
