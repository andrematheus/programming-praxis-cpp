#include <iostream>
#include <gtest/gtest.h>
#include "../src/RpnCalculator.h"

TEST(RpnCalculatorTest, CreatesACalculator) {
    auto calc = RpnCalculator();
    ASSERT_TRUE(true);
}

TEST(RpnCalculatorTest, ShouldAddADoubleToTheStack) {
    auto calc = RpnCalculator();
    calc.evaluate("2.5");
    ASSERT_EQ(2.5, calc.top());
}

TEST(RpnCalculator, ShouldReturnErrorWhenEvaluatingGarbage) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("garbage");
    ASSERT_TRUE(result->is_error());
}

TEST(RpnCalculator, ShouldAddTwoDoublesToTheStack) {
    auto calc = RpnCalculator();
    calc.evaluate("2.5 3.4");
    ASSERT_EQ(3.4, calc.top());
    calc.pop();
    ASSERT_EQ(2.5, calc.top());
}