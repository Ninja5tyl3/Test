cmake_minimum_required(VERSION 2.8.4)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The version number.
set(Test_VERSION_MAJOR 0)
set(Test_VERSION_MINOR 0)
set(Test_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
  "${PROJECT_SOURCE_DIR}/TestConfig.h.in"
  "${PROJECT_BINARY_DIR}/include/TestConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

# all files to be compiled

set(SOURCE_FILES
    src/Main.cpp
    src/Main.h
)

# Add the executable
add_executable(Test ${SOURCE_FILES})
