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
%type <prog> DIRECT_DECLARATOR INIT_DECLARATOR
%type <prog> INITIALIZER ADDITIVE_EXPRESSION
%type <prog> MULTIPLICATIVE_EXPRESSION UNARY_EXPRESSION
%type <prog> POSTFIX_EXPRESSION PRIMARY_EXPRESSION
//under function
%type <prog> COMPOUND_STATEMENT DECLARATION_LIST JUMP_STATEMENT
%type <prog> STATEMENT_LIST STATEMENT EXPRESSION_STATEMENT EXPRESSION
%type <prog> ASSIGNMENT_EXPRESSION PARAM_DECLARATION_LIST
%type <prog> CONDITIONAL_EXPRESSION LOGICAL_OR_EXPRESSION LOGICAL_AND_EXPRESSION
%type <prog> INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION
%type <prog> EQUALITY_EXPRESSION RELATIONAL_EXPRESSION SHIFT_EXPRESSION

%type <prog> IF_STATEMENT ITERATION_STATEMENT

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

INIT_DECLARATOR_LIST : INIT_DECLARATOR { $$ = $1;}
                     | INIT_DECLARATOR_LIST T_COMMA INIT_DECLARATOR { $$ = new Init_deco_list($1,$3); }

INIT_DECLARATOR :  DECLARATOR { $$ = new Init_deco_list1($1);}
                | DECLARATOR T_EQUAL INITIALIZER { $$ = new Init_deco_list2($1,$3); }

DECLARATOR : DIRECT_DECLARATOR { $$ = $1; }

DIRECT_DECLARATOR : T_VARIABLE { $$ = new Variable(*$1); }

INITIALIZER : ASSIGNMENT_EXPRESSION { $$ = new Initializer($1);}
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
                   | POSTFIX_EXPRESSION T_LBRACKET T_RBRACKET  { $$ = new PostFixFunction($1); }
                   | POSTFIX_EXPRESSION T_LBRACKET INIT_DECLARATOR_LIST T_RBRACKET { $$ = new PostFixFunctionParam($1,$3);}
                   | POSTFIX_EXPRESSION T_INC_OP  { $$ = new PostFixIncrement($1); }
                   | POSTFIX_EXPRESSION T_DEC_OP { $$ = new PostFixDecrement($1); }

PRIMARY_EXPRESSION : T_VARIABLE { $$ = new Variable(*$1); }
                   | T_NUMBER { $$ = new Number($1);}
                   | T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2;}

FUNCTION : DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT { $$ = new FunctionDeclare($2,$5);}
         | DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT {$$ = new FunctionDeclare($1,$4);}
         | DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET PARAM_DECLARATION_LIST T_RBRACKET COMPOUND_STATEMENT {$$ = new FunctionDeclareParam($2,$4,$6);}
         | DECLARATOR T_LBRACKET PARAM_DECLARATION_LIST T_RBRACKET COMPOUND_STATEMENT {$$ = new FunctionDeclareParam($1,$3,$5);}
         | DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET T_RBRACKET T_SIMICOLOUMN  {$$ = new FunctionDeclareNoCompound($2);}
         | DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET PARAM_DECLARATION_LIST T_RBRACKET T_SIMICOLOUMN { $$ = new FunctionDeclareNoCompound($2);}

PARAM_DECLARATION_LIST : DECLARATION_SPECIFIERS DECLARATOR { $$ = new ParameterDeclare(*$1,$2);}
                       | DECLARATION_SPECIFIERS DECLARATOR T_COMMA PARAM_DECLARATION_LIST { $$ = new ParameterDeclareMore($2,$4);}

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
          | IF_STATEMENT { $$ = $1; }
          | ITERATION_STATEMENT { $$ = $1;}

IF_STATEMENT : T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT { $$ = new If($3,$5);}   %prec "then" //https://www.gnu.org/software/bison/manual/html_node/Precedence-Decl.html
             | T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT T_ELSE STATEMENT {$$ = new IfElse($3,$5,$7);}

ITERATION_STATEMENT : T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STATEMENT {$$ = new While($3,$5);}
                    | T_DO STATEMENT T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_SIMICOLOUMN {$$ = new DoWhile($2,$5);}
                    | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT T_RBRACKET STATEMENT {$$ = new ForLoopNoIncre($3,$4,$6);}
                    | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION T_RBRACKET STATEMENT {$$ = new ForLoop($3,$4,$5,$7);}

JUMP_STATEMENT : T_RETURN T_SIMICOLOUMN { $$ = new ReturnZero();}
               | T_RETURN EXPRESSION T_SIMICOLOUMN { $$ = new Return($2);}

EXPRESSION_STATEMENT : T_SIMICOLOUMN { $$ = new Empty();}
                     | EXPRESSION T_SIMICOLOUMN { $$ = new declaration_call($1); }

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1; }
           | EXPRESSION T_COMMA ASSIGNMENT_EXPRESSION { $$ = new Program_call($1,$3);}

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION { $$ = $1;}
                      | UNARY_EXPRESSION ASSIGNMENT_OPERATOR ASSIGNMENT_EXPRESSION { $$  = new ReDeclare($1,*$2,$3); }

CONDITIONAL_EXPRESSION : LOGICAL_OR_EXPRESSION { $$ = $1;}
                       | LOGICAL_OR_EXPRESSION T_QUESTIONMARK EXPRESSION T_COLOUMN CONDITIONAL_EXPRESSION { $$ = new ConditionExpr($1,$3,$5);}

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION { $$ = $1;}
                      | LOGICAL_AND_EXPRESSION T_OR_OP INCLUSIVE_OR_EXPRESSION {$$ = new OroR($1,$3);}

LOGICAL_AND_EXPRESSION : INCLUSIVE_OR_EXPRESSION { $$ = $1;}
                       | LOGICAL_AND_EXPRESSION T_AND_OP INCLUSIVE_OR_EXPRESSION {$$ = new andand($1,$3);}

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION { $$ = $1;}
                        | INCLUSIVE_OR_EXPRESSION T_INEXCLUS_OR EXCLUSIVE_OR_EXPRESSION {$$ = new Or($1,$3);}

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION { $$ = $1;}
                        | EXCLUSIVE_OR_EXPRESSION T_EXCLUS_OR AND_EXPRESSION {$$ = new ExclusiveOr($1,$3);}

AND_EXPRESSION : EQUALITY_EXPRESSION { $$ = $1;}
               | AND_EXPRESSION T_AMPERSAND EQUALITY_EXPRESSION {$$ = new And($1,$3);}

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION { $$ = $1;}
                    | EQUALITY_EXPRESSION T_EQ_OP RELATIONAL_EXPRESSION {$$ = new double_equal($1,$3);}
                    | EQUALITY_EXPRESSION T_NE_OP RELATIONAL_EXPRESSION {$$ = new not_equal($1,$3);}

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION { $$ = $1;}
                      | RELATIONAL_EXPRESSION '>' SHIFT_EXPRESSION {$$ = new Greater($1,$3);}
                      | RELATIONAL_EXPRESSION '<' SHIFT_EXPRESSION {$$ = new Less($1,$3);}
                      | RELATIONAL_EXPRESSION T_LE_OP SHIFT_EXPRESSION { $$ = new LessEqual($1,$3);}
                      | RELATIONAL_EXPRESSION T_GE_OP SHIFT_EXPRESSION {$$ = new GreaterEqual($1,$3);}

SHIFT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1;}
                 | SHIFT_EXPRESSION T_LEFT_OP ADDITIVE_EXPRESSION { $$ =  new left_shift_operator($1,$3);}
                 | SHIFT_EXPRESSION T_RIGHT_OP ADDITIVE_EXPRESSION { $$ = new right_shift_opearator($1,$3);}

ASSIGNMENT_OPERATOR :  T_EQUAL {$$ = new std::string("=");}
                    | T_MUL_ASSIGN {$$ = new std::string("*=");}
                    | T_DIV_ASSIGN {$$ = new std::string("/=");}
                    | T_MOD_ASSIGN {$$ = new std::string("%=");}
                    | T_ADD_ASSIGN {$$ = new std::string("+=");}
                    | T_SUB_ASSIGN {$$ = new std::string("-=");}
                    | T_LEFT_ASSIGN {$$ = new std::string("<<=");}
                    | T_RIGHT_ASSIGN {$$ = new std::string(">>=");}
                    | T_AND_ASSIGN {$$ = new std::string("&=");}
                    | T_XOR_ASSIGN {$$ = new std::string("^=");}
                    | T_OR_ASSIGN {$$ = new std::string("|=");}

%%
const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
