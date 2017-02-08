find_package(PkgConfig)
pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
pkg_check_modules(GMOCK REQUIRED gmock>=1.7.0)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)

add_executable(rpnctest rpnctest.cpp)
target_link_libraries(rpnctest rpncalculator gtest gtest_main)
add_test(rpnctest rpnctest)