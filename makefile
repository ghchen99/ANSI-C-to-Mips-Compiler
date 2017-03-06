CPPFLAGS += -W -Wall -g -std=gnu++11
CPPFLAGS1 += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS1 += -I ast

c_lexer.yy.cpp : lexer/c_lexer.flex
	flex -o lexer/c_lexer.yy.cpp lexer/c_lexer.flex

main : lexer/c_lexer.yy.cpp lexer/c_lexer_main.cpp
	g++ $(CPPFLAGS) -o bin/c_lexer lexer/c_lexer.yy.cpp lexer/c_lexer_main.cpp

bin/c_lexer: c_lexer.yy.cpp main
