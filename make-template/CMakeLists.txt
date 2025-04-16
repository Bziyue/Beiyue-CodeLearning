cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CPP_Practice VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable with source files
add_executable(cpp_program src/main.cpp)