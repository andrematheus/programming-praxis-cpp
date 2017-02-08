#pragma once

#include <string>
#include <stack>
#include <memory>
#include <map>
#include "CalcResult.h"
#include "Operator.h"

class RpnCalculator {

public:
    RpnCalculator();

    RpnCalculator(const std::map<std::string, Operator> &operators);

    CalcResult evaluate(std::string input);

    double top();

    void pop();

private:
    std::stack<double> stack;
    std::map<std::string, Operator> operators;
};

std::map<std::string, Operator> default_operators();