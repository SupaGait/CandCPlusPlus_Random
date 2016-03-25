cmake_minimum_required(VERSION 3.3)

project(Advanced_C_Class)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

# Directories with projects:
add_subdirectory(course2)
add_subdirectory(course3)
add_subdirectory(course3_list)
