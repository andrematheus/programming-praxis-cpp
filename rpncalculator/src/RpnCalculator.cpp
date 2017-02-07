#include <iostream>
#include "RpnCalculator.h"

using namespace std;

std::unique_ptr<CalcResultS> RpnCalculator::evaluate(string input) {
    try {
        auto operand = stod(input);
        this->stack.push(operand);
        return CalcResultS::ok();
    } catch (const exception &e) {
        return CalcResultS::error(CalcError::ParsingError);
    }
}

double RpnCalculator::top() {
    return this->stack.top();
}
