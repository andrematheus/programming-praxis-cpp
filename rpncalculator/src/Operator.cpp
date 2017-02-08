#include "Operator.h"

CalcResult Operator::operate(std::stack<double> &stack) {
    return this->delegate(stack);
}

Operator::Operator(const std::function<CalcResult(std::stack<double> &)> &delegate)
        : delegate(delegate) {}

Operator::Operator() {
    delegate = [](std::stack<double> &) {
        return CalcResult::InvalidOperator;
    };
}
