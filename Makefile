all: main

CC = clang++
CFLAGS = -g -Wno-everything -Werror -Wall

main: 
 $(CC) $(CFLAGS) *.cpp -o main

clean: 
rm -f main
