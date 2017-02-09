#pragma once

#include <stack>
#include <functional>
#include "CalcResult.h"

class Operator {
public:
    Operator();

    Operator(const std::function<CalcResult(std::stack<double> &)> &delegate);

    CalcResult operate(std::stack<double> &);

private:
    std::function<CalcResult(std::stack<double> &)> delegate;
};