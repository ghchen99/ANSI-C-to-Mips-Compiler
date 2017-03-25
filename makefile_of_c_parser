CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I ast

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/c_parser : src/c_parser.o src/parser.tab.o src/lexer.yy.o src/parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_parser $^


clean :
	rm src/*.o
	rm src/*.output
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
	rm src/*.tab.hpp
	rm src/*.tab.cpp
