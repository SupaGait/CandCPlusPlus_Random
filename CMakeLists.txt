cmake_minimum_required(VERSION 3.3)

project(Test CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Directories with projects:
add_subdirectory(test)
add_subdirectory(course2)
