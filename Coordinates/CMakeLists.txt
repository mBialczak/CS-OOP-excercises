cmake_minimum_required(VERSION 3.14)
project(coordinates
        LANGUAGES CXX
       )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Ship class lib target
add_library(coordinates-lib
           Coordinates.cpp)
target_compile_options(${PROJECT_NAME}-lib PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_20)

# prepare Google Test
include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest
   GIT_TAG main)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add test-target
add_executable(${PROJECT_NAME}-ut Coordinates-UT.cpp)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -pedantic)
target_compile_features(${PROJECT_NAME}-ut PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
