cmake_minimum_required(VERSION 3.0)

project(CNakeExercises VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add all the cpp files from src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add all the header files from include directory
file(GLOB_RECURSE HEADERS "include/*.h")

# add the executable
add_executable(CNakeExercises ${SOURCES} ${HEADERS})
