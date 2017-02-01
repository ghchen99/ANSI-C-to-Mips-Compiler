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
    std::cout << "[" << std::endl;
    while(1){
        TokenType type=(TokenType)yylex();
        //std::cout << "\"Class\": ";
        if(type==None){
            break; // No more tokens
        }else if(type==Keyword){
            std::cout << "{\"Class\": " << "\"Keyword\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
          s = *yylval.wordValue;
        }else if(type==Identifier){
            std::cout << "{\"Class\": " << "\"Identifier\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else if(type==Operator){
            std::cout << "{\"Class\": " << "\"Operator\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else if(type==Constant){
            std::cout << "{\"Class\": " << "\"Constant\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else if(type==StringLiteral){
            std::cout << "{\"Class\": " << "\"StringLiteral\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else if(type==Invalid){
            std::cout << "{\"Class\": " << "\"Invalid\"\t\"Text\": " << "\"" << *yylval.wordValue << "\"";
            s = *yylval.wordValue;
        }else{
            assert(0); // There are only three token types.
            return 1;
        }
        std::cout << "\t\"sourceline\": " << LineNum;
        std::cout << "\t\"colume\" : " << ColNum - s.size() + 1 << "}," << std::endl;
    }
    std::cout << "{}" << std::endl;
    std::cout << "]" << std::endl;
    return 0;
}
