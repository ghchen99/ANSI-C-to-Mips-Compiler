#sadasdsaasda
#
#asdasdas

z="wibble"
delete *yylval.wordValue;
#([ ][0-9]+[ ])(/"(.*)/")[ 0-4]*
LineNum = atoi(&yytext[2])-1;
size_t startOfFileName = s.find_first_of('"');
size_t endOfFileName = s.find_last_of('"');
size_t fileNameSize = endOfFileName - startOfFileName;
yylval.wordValue = new std::string();
*yylval.wordValue = strdup(sourceline.substr(startOfFileName,fileNameSize+1).c_str());
