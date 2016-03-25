set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/_Projects/Output")

set(SOURCE_FILES main.cpp StackLinkedGeneric.cpp StackLinkedGeneric.h Status.cpp Status.h)
add_executable(course3 ${SOURCE_FILES})

#add_definitions(-DDEBUG)