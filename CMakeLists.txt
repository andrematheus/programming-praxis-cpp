cmake_minimum_required(VERSION 3.7)
project(programming_praxis_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Werror")

option(BUILD_TEST "Build the tests" FALSE)

if (BUILD_TEST)
    enable_testing()
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
endif ()

add_subdirectory(rpncalculator)