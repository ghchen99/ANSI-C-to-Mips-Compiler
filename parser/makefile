CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

src/maths_parser.tab.cpp src/maths_parser.tab.hpp : src/maths_parser.y
	bison -v -d src/maths_parser.y -o src/maths_parser.tab.cpp

src/maths_lexer.yy.cpp : src/maths_lexer.flex src/maths_parser.tab.hpp
	flex -o src/maths_lexer.yy.cpp  src/maths_lexer.flex

bin/print_canonical : src/print_canonical.o src/maths_parser.tab.o src/maths_lexer.yy.o src/maths_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_canonical $^


clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
	rm src/*.tab.hpp
	rm src/*.tab.cpp
	rm src/*.output
