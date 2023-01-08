all: build

CC = clang++
CFLAGS = -g -Wno-everything -Werror -Wall
SRC = ./CG/*.cpp

build: $(SRC) examples.cpp 
	$(CC) $(CFLAGS) $(SRC) examples.cpp -o example

test: $(SRC) TestCase.cpp
	$(CC) $(CFLAGS) $(SRC) TestCase.cpp tests.cpp -o test

clean:
	rm -f example test