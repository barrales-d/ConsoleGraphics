all: build

CC = clang++

CFLAGS = -g -Wno-everything -Werror -Wall
build: main  
	$(CC) $(CFLAGS) ./CG/*.cpp *.cpp -o main

clean:
	rm -f main
