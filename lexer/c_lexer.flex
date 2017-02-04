%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include "c_lexer.hpp"
std::string sourceline;
void count();

/* End the embedded code section. */
%}
KEYWORD (auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while)
OPERATOR (\.\.\.)|(\>\>\=)|(\<\<\=)|(\+\=)|(\-\=)|(\*\=)|(\/\=)|(\%\=)|(\&\=)|(\^\=)|(\|\=)|(\>\>)|(\<\<)|(\+\+)|(\-\-)|(\-\>)|(\&\&)|(\|\|)|(\<\=)|(\>\=)|(\=\=)|(\!\=)|(\;)|(\{)|(\})|(\,)|(\:)|(\=)|(\()|(\))|(\[)|(\])|(\.)|(\&)|(\!)|(\~)|(\-)|(\+)|(\*)|(\/)|(\%)|(\<)|(\>)|(\^)|(\|)|(\?)
CHAR '(.)'
STRINGLITERAL \"(\\.|[^\\"])*\"
HEX 0[xX][A-Fa-f0-9]+([u|U|l|L]*)?
OCT [0-7]+([u|U|l|L]*)?
INTEGER [0-9]+([u|U|l|L]*)?
FLOAT [0-9]*\.[0-9]+([eE][+-][0-9]+)?(F|f|l|L)?|[0-9]+[eE][+-][0-9]+(F|f|l|L)?
PREPROCESS \#([ ][0-9]+[ ])(\"(.*)\")[ 0-4]*
%%
{KEYWORD} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Keyword;}
{PREPROCESS}	{count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Prepo;}
[A-Za-z/_]([A-Za-z/_]|[0-9])*	{count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Identifier;}
{INTEGER} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Constant;}
{CHAR} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Constant;}
{HEX} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Constant;}
{FLOAT} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Constant;}
{STRINGLITERAL} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return StringLiteral;}
{OPERATOR} {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Operator;}

[\n] {LineNum += 1; ColNum = 0;}
[ \t\v\f]		{count();}
. {count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Invalid;}


%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
if (yytext[i] == '\t'){
			ColNum += 8 - (ColNum % 8);
    }else{
			ColNum++;
    }
  }
}
