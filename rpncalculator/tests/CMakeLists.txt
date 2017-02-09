set(GTEST_VERSION "1.8.0")
set(GTEST_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest-${GTEST_VERSION}")
set(GTEST_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}}/gtest-${GTEST_VERSION}")
ExternalProject_Add(googletest
        URL https://github.com/google/googletest/archive/release-1.8.0.zip
        PREFIX ${GTEST_DIR}
        INSTALL_DIR ${GTEST_INSTALL_DIR}
)
ExternalProject_Get_Property(googletest source_dir)
ExternalProject_Get_Property(googletest binary_dir)

include_directories(${source_dir}/googletest/include)
add_library(gtest STATIC IMPORTED)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${binary_dir}/googlemock/gtest/libgtest.a)
add_library(gtest_main STATIC IMPORTED)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${binary_dir}/googlemock/gtest/libgtest_main.a)

add_executable(rpnctest rpnctest.cpp)
target_link_libraries(rpnctest rpncalculator gtest gtest_main)
add_test(rpnctest rpnctest)
add_dependencies(rpnctest googletest)