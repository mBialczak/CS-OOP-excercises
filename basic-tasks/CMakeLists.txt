cmake_minimum_required(VERSION 3.14)
project(basic-OOP-task-0x07
        LANGUAGES CXX )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
include_directories( ${CMAKE_SOURCE_DIR}/include)

# prepare Google Test
include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest
   GIT_TAG main)
# For Windows: Prevent overriding the parent projec's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Ship class lib target
add_library(Ship-lib src/Ship.cpp)
target_compile_options(Ship-lib PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_compile_features(Ship-lib PRIVATE cxx_std_20)

# Cargo class lib target
add_library(Cargo-lib src/Cargo.cpp)
target_compile_options(Cargo-lib PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_compile_features(Cargo-lib PRIVATE cxx_std_20)

# main app target
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Ship-lib Cargo-lib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set(Test_Files
    src/ShipTest.cpp
    src/CargoTest.cpp)
# test target
add_executable(${PROJECT_NAME}-ut ${Test_Files})
target_link_libraries(${PROJECT_NAME}-ut Ship-lib Cargo-lib gtest_main)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -pedantic)
target_compile_features(${PROJECT_NAME}-ut PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)