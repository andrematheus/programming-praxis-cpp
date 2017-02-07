set(RPNCALCULATOR_SOURCE_FILES RpnCalculator.cpp RpnCalculator.h)
add_library(rpncalculator ${RPNCALCULATOR_SOURCE_FILES})
add_executable(rpncalculator-bin ${RPNCALCULATOR_SOURCE_FILES} rpncmain.cpp)
set_target_properties(rpncalculator-bin PROPERTIES OUTPUT_NAME rpncalculator)