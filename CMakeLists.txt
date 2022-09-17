cmake_minimum_required(VERSION 3.0)

project(CNakeExercises VERSION 1.0.0)
include(FetchContent)
FetchContent_Declare(
    FIOU
    GIT_REPOSITORY https://github.com/niyuzheno1/FIOU.git
    GIT_TAG        4545dcfa6487589b0f0903ae5245f44f91b8be6c # release-1.10.0
)

FetchContent_MakeAvailable(FIOU)

# add header dependencies from fiou 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add all the cpp files from src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add all the header files from include directory
file(GLOB_RECURSE HEADERS "include/*.h")

# add the executable
add_executable(CNakeExercises ${SOURCES} ${HEADERS})
target_include_directories(CNakeExercises PUBLIC ${FIOU_SOURCE_DIR}/export_headers)
# add the library from fiou
target_link_libraries(CNakeExercises FIOU_Library)
