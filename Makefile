# variables
CC = g++ #	clang++
CFLAGS = -g -std=c++17 -Wno-everything -Werror -Wall -pedantic
SRC = ./CG/*.cpp
OBJS = Color.o Animation.o Image.o
EXAM_T = examples
TEST_T = tests

REBUILDABLES = $(EXAM_T) $(TEST_T) $(OBJS)

all: $(EXAM_T) $(TEST_T)

# dependencies
$(EXAM_T): $(EXAM_T).cpp
$(TEST_T): ./Tests/TestCase.cpp ./Tests/$(TEST_T).cpp

#	build commands
$(EXAM_T): $(OBJS) 
	$(CC) $(CFLAGS) examples.cpp -o $(EXAM_T) $(OBJS)

$(TEST_T): $(OBJS)
	$(CC) $(CFLAGS) ./Tests/TestCase.cpp ./Tests/tests.cpp -o $(TEST_T) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(REBUILDABLES)