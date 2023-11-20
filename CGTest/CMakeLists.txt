cmake_minimum_required(VERSION 3.8)
project (ConsoleGraphicsUnitTests)


add_executable ( 
	tests
	test.cpp
	Testcase.cpp
)
target_link_libraries(tests ConsoleGraphics)