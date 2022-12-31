all: build

CC = clang++
CFLAGS = -g -Wno-everything -Werror -Wall
SRC = ./CG/*.cpp *.cpp

build:
	$(CC) $(CFLAGS) $(SRC) -o main

clean:
	rm -f main