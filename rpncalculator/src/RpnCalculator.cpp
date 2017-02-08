#include <iostream>
#include <sstream>
#include "RpnCalculator.h"

using namespace std;

std::unique_ptr<CalcResultS> RpnCalculator::evaluate(string input) {
    istringstream is(input);
    string token;
    while (getline(is, token, ' ')) {
        try {
            auto operand = stod(token);
            this->stack.push(operand);
        } catch (const exception &e) {
            return CalcResultS::error(CalcError::ParsingError);
        }
    }
    return CalcResultS::ok();
}

double RpnCalculator::top() {
    return this->stack.top();
}

void RpnCalculator::pop() {
    this->stack.pop();
}
