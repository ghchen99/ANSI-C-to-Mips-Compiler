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
%token T_EQUAL T_RETURN T_STAR

%type <prog> PROGRAM ALL_DECLEARARION DECLARATION DIRECT_DECLARATOR DECLARATOR
%type <prog> INIT_DECLARATOR INIT_DECLARATOR_LIST
%type <string> T_INT  T_VARIABLE TYPE_SPECIFIER DECLARATION_SPECIFIERS

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM: ALL_DECLEARARION { $$ = $1;}
       | PROGRAM ALL_DECLEARARION { $$ = new Program_call($1,$2);}

ALL_DECLEARARION : DECLARATION { $$ = $1;}

DECLARATION : DECLARATION_SPECIFIERS T_SIMICOLOUMN { $$ = new Empty();}
            | DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST T_SIMICOLOUMN { $$ = new declaration($2);}

DECLARATION_SPECIFIERS : TYPE_SPECIFIER { $$ = $1;}
                      // | TYPE_SPECIFIER DECLARATION_SPECIFIERS { $$ = new declaration_specifiers(*$1,*$2);}

INIT_DECLARATOR_LIST : INIT_DECLARATOR { $$ = $1;}
                     //| INIT_DECLARATOR T_COMMA INIT_DECLARATOR_LIST

INIT_DECLARATOR : DECLARATOR { $$ = $1;}
                //| DECLARATOR T_EQUAL INITIALIZER

DECLARATOR : T_STAR DIRECT_DECLARATOR { $$ = $2;}
           | DIRECT_DECLARATOR {$$ = $1;}

DIRECT_DECLARATOR : T_VARIABLE { $$ = new Variable(*$1);}

TYPE_SPECIFIER : T_INT { $$ = new std::string("int"); }


%%

const Program *g_root; // Definition of variable (to match declaration earlier)


const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
