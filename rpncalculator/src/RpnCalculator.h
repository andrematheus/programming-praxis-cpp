#pragma once

#include <string>
#include <stack>

class RpnCalculator {

public:
    void evaluate(std::string input);

    double top();

private:
    std::stack<double> stack;
};