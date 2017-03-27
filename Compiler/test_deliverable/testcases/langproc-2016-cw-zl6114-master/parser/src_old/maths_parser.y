%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_INT T_LBRACKET T_RBRACKET T_NUMBER T_VARIABLE

%type <expr> EXPR TERM FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT TYPE_NAME

%start ROOT

%%

ROOT : EXPR { g_root = $1; }

EXPR : TERM                 { $$ = $1; }

TERM : FACTOR               { $$ = $1; }

FACTOR : T_NUMBER           { $$ = new Number( $1 ); }
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2 ; }
       | T_VARIABLE         { $$ = new Variable(*$1);}
       | TYPE_NAME EXPR {$$ = new Int($2);}

TYPE_NAME : | T_INT { $$ = new std::string("int");}

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
