#include <iostream>
#include <sstream>
#include <map>
#include "RpnCalculator.h"

using namespace std;

CalcResult RpnCalculator::evaluate(string input) {
    istringstream is(input);
    string token;
    while (getline(is, token, ' ')) {
        try {
            CalcResult result;
            auto op = this->operators.find(token);
            if (op != this->operators.end()) {
                result = op->second.operate(this->stack);
            } else {
                auto operand = stod(token);
                this->stack.push(operand);
                result = CalcResult::OK;
            }

            if (result != CalcResult::OK) {
                return result;
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

RpnCalculator::RpnCalculator(const std::map<string, Operator> &operators)
        : operators(operators) {}

RpnCalculator::RpnCalculator() {
    this->operators = default_operators();
}

function<CalcResult(stack<double> &)>
binary_operator(function<double(double, double)> delegate) {
    return [delegate](stack<double> &s) {
        if (s.size() < 2) {
            return CalcResult::NotEnoughOperandsError;
        }
        auto x = s.top();
        s.pop();
        auto y = s.top();
        s.pop();
        auto result = delegate(x, y);
        s.push(result);
        return CalcResult::OK;
    };
}

#define OP(name, lambda) \
    {\
    auto __operator = Operator(\
        binary_operator(lambda)\
    );\
    ops[name] = __operator;\
    }

std::map<std::string, Operator> default_operators() {
    auto ops = map<string, Operator>();
    OP("+", [](double x, double y) { return y + x; });
    OP("-", [](double x, double y) { return y - x; });
    OP("*", [](double x, double y) { return y * x; });
    OP("/", [](double x, double y) { return y / x; });

    return ops;
}
