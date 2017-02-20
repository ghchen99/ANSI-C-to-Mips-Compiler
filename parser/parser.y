%code requires{
  #include "header.hpp"

  #include <cassert>

  extern const Program g_root; // A way of getting the AST out

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

%type <prog> PROGRAM VARIABLE FUNCTION SCOPE PARAMETER
%type <string> T_VARIABLE T_CONTROL_FLOW T_INT

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM : VARIABLE { $$ = $1; }

VARIABLE : T_INT T_VARIABLE { $$ = new Variable($1,$2); }


ROOT : EXPR { g_root = $1; }

EXPR : TERM                 { $$ = $1; }
     | EXPR T_PLUS TERM       { $$ = new AddOperator($1,$3);}
     | EXPR T_MINUS TERM       { $$ = new SubOperator($1,$3);}

TERM : FACTOR               { $$ = $1; }
     | TERM T_DIVIDE FACTOR     { $$ = new DivOperator($1,$3);}
     | TERM T_TIMES FACTOR     { $$ = new MulOperator($1,$3);}

FACTOR : T_NUMBER           { $$ = new Number( $1 ); }
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2 ; }
       | T_VARIABLE         { $$ = new Variable(*$1);}
       | FUNCTION_NAME T_LBRACKET EXPR T_RBRACKET     { if(*$1 == "log"){ $$ = new LogFunction($3);}else if(*$1 == "exp"){ $$ = new ExpFunction($3);}else if(*$1 == "sqrt"){ $$ = new SqrtFunction($3);}}

FUNCTION_NAME : T_LOG { $$ = new std::string("log"); }
              | T_EXP { $$ = new std::string("exp"); }
              | T_SQRT{ $$ = new std::string("sqrt");}

%%

const Program *g_root; // Definition of variable (to match declaration earlier)

const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
