# variables
CC = g++ #	clang++
CFLAGS = -g -std=c++17 -Wno-everything -Werror -Wall -pedantic
SRC = ./CG/*.cpp
LINK_CG = Color.o Image.o Animation.o
TARGET_E = examples
TARGET_T = tests
TARGET_A = animations

REBUILDABLES = $(TARGET_E) $(TARGET_T) $(TARGET_A) $(LINK_CG)

all: $(TARGET_E) $(TARGET_T) $(TARGET_A)

# dependencies for rebuilding when edits are made
$(TARGET_E): $(TARGET_E).cpp
$(TARGET_T): ./Tests/TestCase.cpp ./Tests/$(TARGET_T).cpp
$(TARGET_E): ./CG/Animations/$(TARGET_A).cpp


#	build commands
$(TARGET_E): $(LINK_CG) 
	$(CC) $(CFLAGS) examples.cpp -o $(TARGET_E) $(LINK_CG)

$(TARGET_T): $(LINK_CG)
	$(CC) $(CFLAGS) ./Tests/TestCase.cpp ./Tests/tests.cpp -o $(TARGET_T) $(LINK_CG)

$(TARGET_A): $(LINK_CG)
	$(CC) $(CFLAGS) ./CG/Animations/$(TARGET_A).cpp -o $(TARGET_A) $(LINK_CG)

$(LINK_CG):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(REBUILDABLES)