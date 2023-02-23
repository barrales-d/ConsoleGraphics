all: example test

CC = g++ # clang++
CFLAGS = -g -std=c++17 -Wno-everything -Werror -Wall -pedantic
SRC = ./CG/*.cpp

example: $(SRC) examples.cpp 
	$(CC) $(CFLAGS) $(SRC) examples.cpp -o example

test: $(SRC) TestCase.cpp
	$(CC) $(CFLAGS) ../CG/*.cpp TestCase.cpp tests.cpp -o ../test

clean:
	rm -f example test