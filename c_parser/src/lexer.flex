%option noyywrap

%{
// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

VARIABLE [A-Za-z_]([A-Za-z_]|[0-9])*
NUMBER [-]?[0-9]+([.][0-9]*)?
HEX 0[xX][A-Fa-f0-9]+([u|U|l|L]*)?
OCT [0-7]+([u|U|l|L]*)?

%%
continue        { return(T_CONTINUE); }
break           { return(T_BREAK); }
goto            { return(T_GOTO); }
else			{ return(T_ELSE); }
for			    { return(T_FOR); }
if		    	{ return(T_IF); }
int		       	{ return(T_INT); }
return   		{ return(T_RETURN); }
while			{ return(T_WHILE); }
{NUMBER}        { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{HEX}           { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{OCT}           { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{VARIABLE}      { yylval.string=new std::string(yytext);return T_VARIABLE; }
(\.\.\.)			      { return(T_ELLIPSIS); }
(\>\>\=)		       	{ return(T_RIGHT_ASSIGN); }
(\<\<\=)	       	{ return(T_LEFT_ASSIGN); }
(\+\=)		       	{ return(T_ADD_ASSIGN); }
(\-\=)		       	{ return(T_SUB_ASSIGN); }
(\*\=)		       	{ return(T_MUL_ASSIGN); }
(\/\=)			{ return(T_DIV_ASSIGN); }
(\%\=)			{ return(T_MOD_ASSIGN); }
(\&\=)			{ return(T_AND_ASSIGN); }
(\^\=)			{ return(T_XOR_ASSIGN); }
(\|\=)			{ return(T_OR_ASSIGN); }
(\>\>)			{ return(T_RIGHT_OP); }
(\<\<)			{ return(T_LEFT_OP); }
(\+\+)			{ return(T_INC_OP); }
(\-\-)			{ return(T_DEC_OP); }
(\-\>)			{ return(T_PTR_OP); }
(\&\&)			{ return(T_AND_OP); }
(\|\|)			{ return(T_OR_OP); }
(\<\=)			{ return(T_LE_OP); }
(\>\=)			{ return(T_GE_OP); }
(\=\=)			{ return(T_EQ_OP); }
(\!\=)			{ return(T_NE_OP); }
(\/)		   	{ return(T_DIVIDE);}
(\;)		    { return(T_SIMICOLOUMN); }
(\{)	        { return(T_LCURLYBRACKET); }
(\})     		{ return(T_RCURLYBRACKET); }
(\,)			    { return(T_COMMA); }
(\:)		        { return(T_COLOUMN); }
(\=)			    { return(T_EQUAL); }
(\()		    	{ return(T_LBRACKET); }
(\))			    { return(T_RBRACKET); }
(\[)     		{ return(T_LSQUAREBRACKET); }
(\])		    { return(T_RSQUAREBRACKET); }
(\.)			    { return(T_DOT); }
(\&)			    { return(T_AMPERSAND); }
(\!)			    { return(T_EXCLAMATION); }
(\~)		       	{ return(T_TILDE); }
(\-)		       	{ return(T_MINUS); }
(\+)		       	{ return(T_PLUS); }
(\*)		       	{ return(T_STAR); }
(\%)			    { return(T_MOD); }
(\?)             { return(T_QUESTIONMARK); }
("<")			    { return('<'); }
(">")		    { return('>'); }
(\^)			    { return(T_EXCLUS_OR); }
(\|)			    { return(T_INEXCLUS_OR); }

[ \t\v\n\f]		{ ; }
.			    { exit(1); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
