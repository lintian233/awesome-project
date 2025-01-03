cmake_minimum_required(VERSION 3.22)

project(tinyrender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

#tests
file(GLOB TESTS "tests/*.cpp")

# Include FetchContent module
include(FetchContent)

#-----------------GOOGLETEST-----------------#
# Fetch GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

#-----------------GOOGLETEST-----------------#

# DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -g -pg")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -pg")

# RELEASE
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(include)


#set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable
add_executable(tinyrender ${SOURCES})

# 启用编译命令导出
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")

#-------------------TEST-------------------#
# Add test executable
add_executable(tiny_render_tests ${TESTS})

# Link GoogleTest to the test executable
target_link_libraries(tiny_render_tests gtest_main)

include(GoogleTest)
#gtest_discover_tests(tiny_render_tests)
# Add a test

#需要启用测试
#add_test(
#  NAME tiny_render_tests
#  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tiny_render_tests
#)

enable_testing()
add_test(
  NAME tiny_render_tests
  COMMAND tiny_render_tests
)
#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
#CMAKE_EXPORT_COMPILE_COMMANDS=ON

