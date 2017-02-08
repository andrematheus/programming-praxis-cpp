cmake_minimum_required(VERSION 3.7)
project(programming_praxis_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Werror")

option(BUILD_TEST "Build the tests" FALSE)

IF(BUILD_TEST)
add_subdirectory(vendor/googletest-release-1.8.0/googletest)
ENDIF()

add_subdirectory(rpncalculator)