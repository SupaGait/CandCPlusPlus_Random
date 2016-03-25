set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/_Projects/Output")

set(SOURCE_FILES main.cpp Status.cpp Status.h StackLinkedGeneric.cpp StackLinkedGeneric.h)
add_executable(course3_genericLinkedStack ${SOURCE_FILES})

set(SOURCE_FILES main.cpp Status.cpp Status.h genericStackV2.cpp genericStackV2.h)
add_executable(course3_genericStackV2 ${SOURCE_FILES})

set(SOURCE_FILES_V2 main.cpp Status.cpp Status.h genericStackV2Opt.cpp genericStackV2Opt.h)
add_executable(course3_genericStackV2Opt ${SOURCE_FILES_V2})


#add_definitions(-DDEBUG)