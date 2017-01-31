#include "c_lexer.hpp"

#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>


// Define the instance of the variable that is declared in the header
TokenValue yylval;
int LineNum = 1;
int ColNum = 0;
int main()
{
    std::string s;
    while(1){
        TokenType type=(TokenType)yylex();
        std::cout << "\"Class\": ";
        if(type==None){
            break; // No more tokens
        }else if(type==Keyword){
          std::cout << "\"Keyword\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
          s = *yylval.wordValue;
        }else if(type==Identifier){
            std::cout << "\"Identifier\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else if(type==Operator){
        }else if(type==Constant){
        }else if(type==StringLiteral){
        }else if(type==Invalid){
        }else{
            assert(0); // There are only three token types.
            return 1;
        }
        std::cout << "\t\"sourceline\": " << LineNum;
        std::cout << "\t\"colume\" : " << ColNum - s.size() + 1 <<std::endl;
    }
    return 0;
}
