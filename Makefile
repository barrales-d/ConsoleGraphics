# variables
CC = g++ #	clang++
CFLAGS = -g -std=c++17 -Werror -Wall
CG = ./CG/
CG_OBJS = Animation.o Image.o Glyph.o Color.o

TARGET_E = examples
TARGET_T = tests
TARGET_A = animations

REBUILDABLES = $(TARGET_E) $(TARGET_T) $(TARGET_A)

all: $(REBUILDABLES)

$(TARGET_E): $(TARGET_E).cpp $(CG_OBJS) 
	$(CC) $(CFLAGS) $(CG_OBJS) $(TARGET_E).cpp -o $(TARGET_E)

$(TARGET_T): ./Tests/$(TARGET_T).cpp ./Tests/TestCase.cpp $(CG_OBJS)
	$(CC) $(CFLAGS) $(CG_OBJS) ./Tests/TestCase.cpp ./Tests/$(TARGET_T).cpp -o $(TARGET_T)

$(TARGET_A): ./CG/Animations/$(TARGET_A).cpp $(CG_OBJS)
	$(CC) $(CFLAGS) $(CG_OBJS) ./CG/Animations/$(TARGET_A).cpp -o $(TARGET_A)


Animation.o: $(CG)Animation.cpp $(CG)Animation.hpp
	$(CC) $(CFLAGS) -c $(CG)Animation.cpp

Image.o: $(CG)Image.cpp $(CG)Image.hpp
	$(CC) $(CFLAGS) -c $(CG)Image.cpp

Glyph.o: $(CG)Glyph.cpp $(CG)Glyph.hpp
	$(CC) $(CFLAGS) -c $(CG)Glyph.cpp

Color.o: $(CG)Color.cpp $(CG)Color.hpp
	$(CC) $(CFLAGS) -c $(CG)Color.cpp

clean:
	rm -f *.o $(REBUILDABLES)