add_executable(rpnctest rpnctest.cpp)
target_link_libraries(rpnctest rpncalculator ${GTEST_LIBRARIES})
add_test(rpnctest rpnctest)
add_dependencies(rpnctest googletest)