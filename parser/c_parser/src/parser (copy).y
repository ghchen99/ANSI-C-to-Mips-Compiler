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
%token T_EQUAL

%type <prog> PROGRAM VARIABLE FUNCTION SCOPE PARAMETER
%type <string> T_VARIABLE T_CONTROL_FLOW T_INT TYPE_SPECIFIER

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM : VARIABLE { $$ = $1; }
        | FUNCTION { $$ = $1; }
        | SCOPE { $$ = $1;}

FUNCTION : TYPE_SPECIFIER T_VARIABLE PARAMETER SCOPE { $$ = new Function(*$1,*$2,$3,$4);}

PARAMETER : T_LBRACKET TYPE_SPECIFIER T_VARIABLE T_RBRACKET { $$ = new Parameter(*$2,*$3);}
          /*|
SUBPARAMETER : TYPE_SPECIFIER T_VARIABLE
             | SUBPARAMETER T_COMMA SUBPARAMETER
                          */
SCOPE : T_LCURLYBRACKET T_RCURLYBRACKET { $$ = new Scope(NULL);}
      | T_LCURLYBRACKET VARIABLE T_RCURLYBRACKET { $$ = new Scope($2);}

VARIABLE : TYPE_SPECIFIER T_VARIABLE T_SIMICOLOUMN { $$ = new Variable(*$1,*$2);}
         | TYPE_SPECIFIER T_VARIABLE T_EQUAL T_VARIABLE T_SIMICOLOUMN { $$ = new Variable(*$1,*$2);}

TYPE_SPECIFIER : T_INT { $$ = new std::string("int");}

%%
const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
