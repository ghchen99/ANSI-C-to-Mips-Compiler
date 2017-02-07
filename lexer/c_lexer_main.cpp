#include "c_lexer.hpp"

#include <vector>
#include <regex>
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
    std::string tmp;
    std::__cxx11::smatch match;
    int x;
    int count  = 0;
    std::string SourceFile;
    std::cout << "[" << std::endl;
    while(1){
        TokenType type=(TokenType)yylex();
        //std::cout << "\"Class\": ";
        if(type==None){
            break; // No more tokens
        }else if(type==Keyword){
            std::cout << "{\"Class\": " << "\"Keyword\",\t\"Text\": " << "\"" << *yylval.wordValue << "\",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
          s = *yylval.wordValue;
          delete yylval.wordValue;
          count++;
          if(!SourceFile.empty()){
              std::cout << "\t\"SourceLine\": " << x << ",";
              std::cout << "\t\"SourceFile\": " << SourceFile << ",";
          }
         std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==Identifier){
            std::cout << "{\"Class\": " << "\"Identifier\",\t\"Text\": " << "\"" << *yylval.wordValue << "\",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
            s = *yylval.wordValue;
            delete yylval.wordValue;
            count++;
            if(!SourceFile.empty()){
                std::cout << "\t\"SourceLine\": " << x << ",";
                std::cout << "\t\"SourceFile\": " << SourceFile << ",";
            }
            std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==Operator){
            std::cout << "{\"Class\": " << "\"Operator\",\t\"Text\": " << "\"" << *yylval.wordValue << "\",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
            s = *yylval.wordValue;
            delete yylval.wordValue;
            count++;
            if(!SourceFile.empty()){
                std::cout << "\t\"SourceLine\": " << x << ",";
                std::cout << "\t\"SourceFile\": " << SourceFile << ",";
            }
            std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==Constant){
            std::cout << "{\"Class\": " << "\"Constant\",\t\"Text\": " << "\"" << *yylval.wordValue << "\",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
            s = *yylval.wordValue;
            delete yylval.wordValue;
            count++;
            if(!SourceFile.empty()){
                std::cout << "\t\"SourceLine\": " << x <<",";
                std::cout << "\t\"SourceFile\": " << SourceFile <<",";
            }
            std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==StringLiteral){
            std::cout << "{\"Class\": " << "\"StringLiteral\",\t\"Text\": " << *yylval.wordValue << ",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
            s = *yylval.wordValue;
            delete yylval.wordValue;
            count++;
            if(!SourceFile.empty()){
                std::cout << "\t\"SourceLine\": " << x << ",";
                std::cout << "\t\"SourceFile\": " << SourceFile << "," ;
            }
            std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==Invalid){
            std::cout << "{\"Class\": " << "\"Invalid\",\t\"Text\": " << "\"" << *yylval.wordValue << "\",";
            std::cout << "\t\"StreamLine\": " << LineNum << ",";
            s = *yylval.wordValue;
            delete yylval.wordValue;
            count++;
            if(!SourceFile.empty()){
                std::cout << "\t\"SourceLine\": " << x << ",";
                std::cout << "\t\"SourceFile\": " << SourceFile << ",";
            }
                std::cout << "\t\"SourceCol\" : " << ColNum - s.size() + 1 << "}," << std::endl;
        }else if(type==Prepo){
            s = *yylval.wordValue;
            //std::cout << std::endl << s << std::endl;
            size_t startOfFileName = s.find_first_of('"');
            size_t endOfFileName = s.find_last_of('"');
            size_t fileNameSize = endOfFileName - startOfFileName;
            tmp = strdup(s.substr(startOfFileName,fileNameSize+1).c_str());
            SourceFile = tmp;
            size_t startOfSourceLine = s.find_first_of('#');
            size_t endOfSourceLine = s.find_first_of('"');
            size_t SourceLineSize = endOfSourceLine - startOfSourceLine;
            tmp = strdup(s.substr(startOfSourceLine+2,SourceLineSize-3).c_str());
            //std::cout << std::endl << tmp << std::endl;
            x = stoi(tmp);
            delete yylval.wordValue;
            count++;
        }
        else{
            assert(0); // There are only three token types.
            return 1;
        }
    }
    std::cout << "{}" << std::endl;
    std::cout << "]" << std::endl;
    //std::cout << count << '\n'; //total number of lex captured
    return 0;
}
