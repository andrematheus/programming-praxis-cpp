add_executable(rpnctest rpnctest.cpp)
target_link_libraries(rpnctest rpncalculator gtest gtest_main)
add_test(rpnctest rpnctest)
add_dependencies(rpnctest googletest)