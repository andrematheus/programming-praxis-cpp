#include <iostream>
#include <sstream>
#include "RpnCalculator.h"

using namespace std;

CalcResult sum_operator(stack<double> &stack) {
    if (stack.size() < 2) {
        return CalcResult::NotEnoughOperandsError;
    }
    auto x = stack.top();
    stack.pop();
    auto y = stack.top();
    stack.pop();
    auto result = x + y;
    stack.push(result);
    return CalcResult::OK;
}

CalcResult RpnCalculator::evaluate(string input) {
    istringstream is(input);
    string token;
    while (getline(is, token, ' ')) {
        try {
            switch (token[0]) {
                case '+':
                    sum_operator(this->stack);
                    break;
                default:
                    auto operand = stod(token);
                    this->stack.push(operand);
                    break;
            }
        } catch (const exception &e) {
            return CalcResult::ParsingError;
        }
    }
    return CalcResult::OK;
}

double RpnCalculator::top() {
    return this->stack.top();
}

void RpnCalculator::pop() {
    this->stack.pop();
}
