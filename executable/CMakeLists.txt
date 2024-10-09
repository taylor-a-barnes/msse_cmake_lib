cmake_minimum_required(VERSION 3.14)

# Project name and version
project(test_executable VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(test_executable src/main.cpp)
