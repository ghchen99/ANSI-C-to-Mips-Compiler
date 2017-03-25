%code requires{
  #include "ast.hpp"

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
  const Program *expr;
  double number;
  std::string *string;
}

%token T_NUMBER T_VARIABLE T_INT T_LBRACKET T_RBRACKET

%type <expr> PROGRAM VARIABLE
%type <number> T_NUMBER
%type <string> T_VARIABLE T_INT

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM : VARIABLE { $$ = $1; }

VARIABLE : T_INT T_VARIABLE {$$ = new Variable(*$2);}

%%

const Program *g_root; // Definition of variable (to match declaration earlier)

const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
