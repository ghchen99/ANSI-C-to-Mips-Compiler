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
  double number;
}

%token T_FOR T_IF T_INT T_RETURN T_WHILE
%token T_NUMBER T_VARIABLE
%token T_ELLIPSIS T_RIGHT_ASSIGN T_LEFT_ASSIGN T_ADD_ASSIGN
%token T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%token T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN T_RIGHT_OP T_LEFT_OP
%token T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP T_LE_OP T_GE_OP
%token T_EQ_OP T_NE_OP T_INEXCLUS_OR T_EXCLUS_OR
%token T_SIMICOLOUMN T_LCURLYBRACKET T_RCURLYBRACKET T_COMMA T_COLOUMN
%token T_EQUAL T_LBRACKET T_RBRACKET T_LSQUAREBRACKET T_RSQUAREBRACKET
%token T_DOT T_AMPERSAND T_EXCLAMATION T_TILDE
%token T_MINUS T_PLUS T_STAR T_DIVIDE T_MOD T_QUESTIONMARK
%token T_GOTO T_BREAK T_CONTINUE T_DO T_SIZEOF T_CONST T_VOLATILE
%token T_VOID T_CHAR T_LONG T_SIGNED T_UNSIGNED T_FLOAT T_DOUBLE T_STRUCT T_UNION
%token T_TYPEDEF T_AUTO T_REGISTER T_EXTERN T_STATIC

// Precedences go increasing, so "then" < "else".
%nonassoc "then"
%nonassoc T_ELSE

%type <prog> PROGRAM ALL_DECLEARARION DECLARATION FUNCTION
%type <prog> INIT_DECLARATOR_LIST DECLARATOR
%type <prog> DIRECT_DECLARATOR
%type <prog> INITIALIZER ADDITIVE_EXPRESSION
%type <prog> MULTIPLICATIVE_EXPRESSION UNARY_EXPRESSION
%type <prog> POSTFIX_EXPRESSION PRIMARY_EXPRESSION
//under function
%type <prog> COMPOUND_STATEMENT DECLARATION_LIST JUMP_STATEMENT
%type <prog> STATEMENT_LIST STATEMENT EXPRESSION_STATEMENT EXPRESSION
%type <prog> ASSIGNMENT_EXPRESSION

%type <string> T_VARIABLE TYPE_SPECIFIER DECLARATION_SPECIFIERS ASSIGNMENT_OPERATOR
%type <number> T_NUMBER

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM: ALL_DECLEARARION { $$ = $1;}
       | PROGRAM ALL_DECLEARARION { $$ = new Program_call($1,$2);}

ALL_DECLEARARION : DECLARATION { $$ = new GlobalVariable($1); }
                 | FUNCTION { $$ = $1; }

DECLARATION : DECLARATION_SPECIFIERS T_SIMICOLOUMN { $$ = new Empty();}
            | DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST T_SIMICOLOUMN { $$ = new declaration(*$1,$2); }

DECLARATION_SPECIFIERS : TYPE_SPECIFIER { $$ = $1; }

TYPE_SPECIFIER : T_INT { $$ = new std::string("int"); }

INIT_DECLARATOR_LIST : DECLARATOR { $$ = new Init_deco_list1($1);}
                     | DECLARATOR T_EQUAL INITIALIZER { $$ = new Init_deco_list2($1,$3); }

DECLARATOR : DIRECT_DECLARATOR { $$ = $1; }

DIRECT_DECLARATOR : T_VARIABLE { $$ = new Variable(*$1); }

INITIALIZER : ADDITIVE_EXPRESSION { $$ = new Initializer($1);}
            /*| INITIALIZER_LIST { $$ = $1; }

INITIALIZER_LIST : INITIALIZER { $$ = $1; }
                 | INITIALIZER_LIST T_COMMA INITIALIZER { $$ = new Program_call($1,$3);}*/

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION { $$ = $1;}
                    | ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION { $$ = new AddOperator($1,$3);}
                    | ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION { $$ =  new SubOperator($1,$3);}

MULTIPLICATIVE_EXPRESSION : UNARY_EXPRESSION { $$ = $1;}
                          | MULTIPLICATIVE_EXPRESSION T_STAR UNARY_EXPRESSION {$$ = new MulOperator($1,$3);}
                          | MULTIPLICATIVE_EXPRESSION T_DIVIDE UNARY_EXPRESSION {$$ = new DivOperator($1,$3);}
                          | MULTIPLICATIVE_EXPRESSION T_MOD UNARY_EXPRESSION {$$ = new ModOperator($1,$3);}

UNARY_EXPRESSION : POSTFIX_EXPRESSION { $$ = $1; }

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION { $$ = $1; }

PRIMARY_EXPRESSION : T_VARIABLE { $$ = new Variable(*$1); }
                   | T_NUMBER { $$ = new Number($1);}

FUNCTION : DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT { $$ = new FunctionDeclare($2,$5);}
         | DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT {$$ = new FunctionDeclare($1,$4);}

COMPOUND_STATEMENT : T_LCURLYBRACKET T_RCURLYBRACKET {$$ = new Empty();}
                   | T_LCURLYBRACKET DECLARATION_LIST T_RCURLYBRACKET {$$ = $2;}
                   | T_LCURLYBRACKET STATEMENT_LIST T_RCURLYBRACKET {$$ = $2;}
                   | T_LCURLYBRACKET DECLARATION_LIST STATEMENT_LIST T_RCURLYBRACKET {$$ = new Program_call($2,$3);}

DECLARATION_LIST : DECLARATION { $$ = $1; }
                 | DECLARATION_LIST DECLARATION { $$ = new Program_call($1,$2); }

STATEMENT_LIST : STATEMENT { $$ = $1; }
               | STATEMENT_LIST STATEMENT { $$ = new Program_call($1,$2); }

STATEMENT : COMPOUND_STATEMENT { $$ = $1;}
          | JUMP_STATEMENT { $$ = $1;}
          | EXPRESSION_STATEMENT { $$ = $1; }

JUMP_STATEMENT : T_RETURN T_SIMICOLOUMN { $$ = new Empty();}
               | T_RETURN EXPRESSION T_SIMICOLOUMN { $$ = new Empty();}

EXPRESSION_STATEMENT : T_SIMICOLOUMN { $$ = new Empty();}
                     | EXPRESSION T_SIMICOLOUMN { $$ = $1; }

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1; }
           | EXPRESSION T_COMMA ASSIGNMENT_EXPRESSION { $$ = new Program_call($1,$3);}

ASSIGNMENT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1;}
                      | UNARY_EXPRESSION ASSIGNMENT_OPERATOR ASSIGNMENT_EXPRESSION { $$  = new Program_call($1,$3); }

ASSIGNMENT_OPERATOR :  T_EQUAL {$$ = new std::string("=");}

%%
const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
