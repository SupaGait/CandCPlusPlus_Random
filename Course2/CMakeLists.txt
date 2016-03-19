set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/_Projects/Output")

set(SOURCE_FILES Array.cpp Array.h Stack.cpp Stack.h main.cpp StackLinked.cpp StackLinked.h)
add_executable(course2 ${SOURCE_FILES})

set(SOURCE_FILES Array.cpp Array.h sortTestMain.cpp)
add_executable(testSort ${SOURCE_FILES})

#add_definitions(-DDEBUG)