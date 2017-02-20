CPPFLAGS += -W -Wall -g -std=gnu++11
CPPFLAGS1 += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS1 += -I include


c_lexer.yy.cpp : lexer/c_lexer.flex
	flex -o lexer/c_lexer.yy.cpp lexer/c_lexer.flex

main : lexer/c_lexer.yy.cpp lexer/c_lexer_main.cpp
	g++ $(CPPFLAGS) -o bin/c_lexer lexer/c_lexer.yy.cpp lexer/c_lexer_main.cpp

bin/c_lexer: c_lexer.yy.cpp main


parser/parser.tab.cpp parser/parser.tab.hpp : parser/parser.y
	bison -v -d parser/parser.y -o parser/parser.tab.cpp

parser/lexer.yy.cpp : parser/lexer.flex parser/parser.tab.hpp
	flex -o parser/lexer.yy.cpp  parser/lexer.flex



clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
