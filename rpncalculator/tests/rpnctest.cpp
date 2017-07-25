#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/RpnCalculator.h"

TEST_CASE("Create a calculator", "[RpnCalculator]") {
    auto calc = RpnCalculator();
    REQUIRE(true);
}

TEST_CASE("Should add a double to the stack", "[RpnCalculator][Evaluator][Stack]") {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5");
    REQUIRE_FALSE(is_error(result));
    REQUIRE(calc.top() == Approx(2.5));
}

TEST_CASE("Should return error when evaluating garbage", "[RpnCalculator][Evaluator]") {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("garbage");
    REQUIRE(is_error(result));
}

TEST_CASE("Should add two doubles to the stack", "[RpnCalculator]") {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5 3.4");
    REQUIRE_FALSE(is_error(result));
    REQUIRE( calc.top() == Approx(3.4));
    calc.pop();
    REQUIRE( calc.top() == Approx(2.5));
}

TEST_CASE("Should sum two operands in the stack", "[RpnCalculator]") {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("2.5 3.4 +");
    REQUIRE_FALSE(is_error(result));
    REQUIRE( calc.top() == Approx(2.5 + 3.4));
}

TEST_CASE("Should return error when there's not enough operands in stack", "[RpnCalculator]") {
    auto calc = RpnCalculator();
    auto result = calc.evaluate("+");
    REQUIRE(is_error(result));
    REQUIRE(result == CalcResult::NotEnoughOperandsError);
}

TEST_CASE("Should accept operators passed to constructor", "[RpnCalculator]") {
    auto ops = std::map<std::string, Operator>();
    ops["?"] = Operator([](std::stack<double> &s) {
        s.push(10.0);
        return CalcResult::OK;
    });
    auto calc = RpnCalculator(ops);
    auto result = calc.evaluate("?");
    REQUIRE_FALSE(is_error(result));
    REQUIRE( calc.top() == Approx(10.0));
}

void check_calculation(std::string input, double expected) {
    auto calc = RpnCalculator();
    auto result = calc.evaluate(input);
    REQUIRE_FALSE(is_error(result));
    REQUIRE(calc.top() == Approx(expected));
}

TEST_CASE("Should calculate subtraction", "[RpnCalculator]") {
    check_calculation("6 2 -", 4.0);
}

TEST_CASE("Should calculate multiplication", "[RpnCalculator]") {
    check_calculation("6 2 *", 12.0);
}

TEST_CASE("Should calculate division", "[RpnCalculator]") {
    check_calculation("6 2 /", 3.0);
}

TEST_CASE("Should calculate example from site", "[RpnCalculator]") {
    check_calculation("19 2.14 + 4.5 2 4.3 / - *", 85.2974);
}