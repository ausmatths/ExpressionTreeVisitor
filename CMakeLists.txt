cmake_minimum_required(VERSION 3.10)
project(ExpressionTreeVisitor)

# Set C++ standard (explicitly set to C++11 to fix compilation errors)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Include directories
include_directories(include)

# Source files for the main program
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the main executable (named ExpressionTreeVisitor to match the project name)
add_executable(ExpressionTreeVisitor ${SOURCES})

# Test files
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "src/Elements/*.cpp" "src/Visitors/*.cpp")

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})