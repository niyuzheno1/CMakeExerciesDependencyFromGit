cmake_minimum_required(VERSION 3.0)

project(CMakeExercises VERSION 1.0.0)
include(FetchContent)

FetchContent_Declare(
    FSP
    GIT_REPOSITORY https://github.com/niyuzheno1/FSP.git
    GIT_TAG        f8712a320039d8569a70e7e1c0af46ebe1d63a48 # release-1.0.0
)

FetchContent_Declare(
    FIOU
    GIT_REPOSITORY https://github.com/niyuzheno1/FIOU.git
    GIT_TAG        ee431a6258151c96911eb401d92de921b457867e # release-1.0.1
)


FetchContent_MakeAvailable(FIOU)
FetchContent_MakeAvailable(FSP)

# add header dependencies from fiou 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add all the cpp files from src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add all the header files from include directory
file(GLOB_RECURSE HEADERS "include/*.h")

# add the executable
add_executable(CMakeExercises ${SOURCES} ${HEADERS})
target_include_directories(CMakeExercises PUBLIC ${FIOU_SOURCE_DIR}/export_headers)
target_link_libraries(CMakeExercises FIOU_Library)

target_include_directories(CMakeExercises PUBLIC ${FSP_SOURCE_DIR}/export_headers)
target_link_libraries(CMakeExercises FSP_Library)

target_include_directories(CMakeExercises PUBLIC ${MMS_SOURCE_DIR}/export_headers)
target_link_libraries(CMakeExercises MMS_Library)
