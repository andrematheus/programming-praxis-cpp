add_executable(rpnctest rpnctest.cpp)
target_link_libraries(rpnctest rpncalculator)
add_test(rpnctest rpnctest)
add_dependencies(check rpnctest)