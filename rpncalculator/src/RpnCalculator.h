#pragma once

#include <string>
#include <stack>
#include <memory>
#include "CalcResult.h"

class RpnCalculator {

public:
    std::unique_ptr<CalcResultS> evaluate(std::string input);

    double top();

    void pop();

private:
    std::stack<double> stack;
};