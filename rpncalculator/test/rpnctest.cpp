#include <iostream>
#include <gtest/gtest.h>
#include "../src/RpnCalculator.h"

TEST(RpnCalculatorTest, CreatesACalculator) {
    auto calc = RpnCalculator();
    ASSERT_TRUE(true);
}