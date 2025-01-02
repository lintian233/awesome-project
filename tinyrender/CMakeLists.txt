cmake_minimum_required(VERSION 3.22)

project(tinyrender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES 
	src/tgaimage.cpp
	src/hello_tga.cpp
)


include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(tinyrender ${SOURCES})

target_compile_options(tinyrender PRIVATE
	-O0
	-ggdb
	-g
	-pg
)

