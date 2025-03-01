cmake_minimum_required(VERSION 3.30)
project(ExpressionTreeVisitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files for the main program
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the main executable
add_executable(expression_tree ${SOURCES})

# Test files
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "src/Elements/*.cpp" "src/Visitors/*.cpp")

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})
