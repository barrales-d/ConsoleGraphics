# variables
CC = g++
DIRECTORIES = . CG Tests
INCLUDES = . ./CG/ ./Tests/
DEP = -MD -MP
FLAGS = -g -std=c++17 -Werror -Wall $(foreach Dir, $(INCLUDES), -I$(Dir)) $(DEP)

CPPFILES = $(foreach Dir, $(DIRECTORIES), $(wildcard $(Dir)/*.cpp))

OBJECTS = $(patsubst %.cpp,%.o, $(CPPFILES))
DEPFILES = $(patsubst %.cpp,%.d, $(CPPFILES))

EXEFOLDER = bin/
# TODO: create make rule for ./bin/animations
EXECUTABLES = $(EXEFOLDER)examples $(EXEFOLDER)tests

# target rules
all: $(EXECUTABLES)

examples: $(OBJECTS)
	$(CC) $(FLAGS) $^ $(EXEFOLDER)$@.cpp -o $(EXEFOLDER)$@

tests: $(OBJECTS) 
	$(CC) $(FLAGS) $^ $(EXEFOLDER)$@.cpp -o $(EXEFOLDER)$@

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(EXECUTABLES) $(OBJECTS) $(DEPFILES) *.d *.o $(EXEFOLDER)*.o $(EXEFOLDER)*.d

# for changes in .hpp files to be recognize
-include $(DEPFILES)