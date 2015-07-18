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

set(HEADER_FILES
    include/Main.h
    include/PerlinNoise.h
    include/PPM.h
)

set(SOURCE_FILES
    src/Main.cpp
    src/PerlinNoise.cpp
    src/PPM.cpp
)

set(COMPILE_FILES
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

# Add the executable
add_executable(Test ${COMPILE_FILES})

#define a macro to simplify adding tests, then use it
macro (do_test arg result)
  add_test (TestComp${arg} Test ${arg})
  set_tests_properties (TestComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# does the application run
#add_test(TestRuns Test 0.0.1)

# build a CPack driven installer package
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "{Test_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "{Test_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "{Test_VERSION_PATCH}")
include(CPack)
