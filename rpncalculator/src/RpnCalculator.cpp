#include <iostream>
#include "RpnCalculator.h"

using namespace std;

void RpnCalculator::evaluate(string input) {
    try {
        auto operand = stod(input);
        this->stack.push(operand);
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

double RpnCalculator::top() {
    return this->stack.top();
}
