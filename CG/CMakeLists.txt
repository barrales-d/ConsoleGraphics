# CMakeList.txt : CMake project for ConsoleGraphics

cmake_minimum_required(VERSION 3.8)
project (ConsoleGraphics)
# Create ConsoleGraphics library
add_library( 
	ConsoleGraphics
	src/Ansi.cpp
	src/Image.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
	$<INSTALL_INTERFACE:include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_directories(${PROJECT_NAME} PUBLIC include)
