all: build

CC = clang++

CFLAGS = -g -Wno-everything -Werror -Wall
build: main  
	$(CC) $(CFLAGS) *.cpp -o main

clean:
	rm -f main
