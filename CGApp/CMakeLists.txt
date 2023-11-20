cmake_minimum_required(VERSION 3.8)
project (ConsoleGraphicsApplication)

# Add source to this project's executable.
add_executable ( 
	examples
	example.cpp
)


# reference ConsoleGraphics
target_link_libraries(examples ConsoleGraphics)