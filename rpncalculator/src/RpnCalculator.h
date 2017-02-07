#pragma once

#include <string>
#include <stack>
#include <memory>
#include "CalcResult.h"

enum class RpnCalculatorError {
    ParsingError,
};

class RpnCalculator {

public:
    std::unique_ptr<CalcResultS> evaluate(std::string input);

    double top();

private:
    std::stack<double> stack;
};