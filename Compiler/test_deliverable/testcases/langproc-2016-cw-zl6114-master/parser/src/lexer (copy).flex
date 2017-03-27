%option noyywrap

%{
// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

VARIABLE [A-Za-z/_]([A-Za-z/_]|[0-9])*
NUMBER [-]?[0-9]+([.][0-9]*)?
HEX 0[xX][A-Fa-f0-9]+([u|U|l|L]*)?
OCT [0-7]+([u|U|l|L]*)?

%%

[...]			{ return(T_ELLIPSIS); }
[=]             { return T_EQUAL;}
[*]             { return T_STAR;}
[+]             { return T_PLUS;}
[-]             { return T_MINUS;}
[/]             { return T_DIVIDE;}
[%]             { return T_MOD;}
[,]             { return T_COMMA;}
[{]             { return T_LCURLYBRACKET;}
[}]             { return T_RCURLYBRACKET;}
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[;]             { return T_SIMICOLOUMN; }
int             { return T_INT; }
if              { return T_IF; }
while           { return T_WHILE; }
else            { return T_ELSE;}
for             { return T_FOR; }
{NUMBER}        { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{HEX}        { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{OCT}        { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{VARIABLE}      { yylval.string=new std::string(yytext);return T_VARIABLE; }
[ \t\r\n]+		{;}
.               {exit(1);}
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
