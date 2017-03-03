%option noyywrap

%{
// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}
VARIABLE [A-Za-z/_]([A-Za-z/_]|[0-9])*
%%
[=]             { return T_EQUAL;}
[*]             { return T_STAR;}
[,]             { return T_COMMA;}
[{]             { return T_LCURLYBRACKET;}
[}]             { return T_RCURLYBRACKET;}
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[;]             { return T_SIMICOLOUMN; }
int             { return T_INT; }
if              { return T_CONTROL_FLOW; }
while           { return T_CONTROL_FLOW; }
for             { return T_CONTROL_FLOW; }
{VARIABLE}      { yylval.string=new std::string(yytext);return T_VARIABLE; }
[ \t\r\n]+		{;}
.               {exit(1);}
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
