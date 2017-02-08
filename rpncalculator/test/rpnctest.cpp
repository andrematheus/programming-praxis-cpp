#include <iostream>
#include <gtest/gtest.h>
#include "../src/RpnCalculator.h"

TEST(RpnCalculator, CreatesACalculator) {
    auto calc = RpnCalculator();
    ASSERT_TRUE(true);
}

TEST(RpnCalculator, ShouldAddADoubleToTheStack) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5");
    ASSERT_FALSE(is_error(result));
    ASSERT_EQ(2.5, calc.top());
}

TEST(RpnCalculator, ShouldReturnErrorWhenEvaluatingGarbage) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("garbage");
    ASSERT_TRUE(is_error(result));
}

TEST(RpnCalculator, ShouldAddTwoDoublesToTheStack) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5 3.4");
    ASSERT_FALSE(is_error(result));
    ASSERT_EQ(3.4, calc.top());
    calc.pop();
    ASSERT_EQ(2.5, calc.top());
}

TEST(RpnCalculator, ShouldSumTwoOperandsInTheStack) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5 3.4 +");
    ASSERT_FALSE(is_error(result));
    ASSERT_EQ(2.5 + 3.4, calc.top());
}

TEST(RpnCalculator, ShouldReturnErrorWhenTheresNotEnoughOperandsInStack) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("+");
    ASSERT_TRUE(is_error(result));
    ASSERT_EQ(CalcResult::NotEnoughOperandsError, result);
}

TEST(RpnCalculator, ShouldAcceptOperatorsPassedToConstructor) {
    auto ops = std::map<std::string, Operator>();
    ops["?"] = Operator([](std::stack<double> &s) {
        s.push(10.0);
        return CalcResult::OK;
    });
    auto calc = RpnCalculator(ops);
    CalcResult result = calc.evaluate("?");
    ASSERT_FALSE(is_error(result));
    ASSERT_EQ(10.0, calc.top());
}