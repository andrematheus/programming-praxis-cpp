#include <iostream>
#include "RpnCalculator.h"

int main() {
    auto calc = RpnCalculator();
    std::cout << "> ";
    for (std::string line; std::getline(std::cin, line);) {
        auto result = calc.evaluate(line);
        if (is_ok(result)) {
            std::cout << calc.top() << std::endl;
        } else {
            std::cout << "Error: " << result << std::endl;
        }
        std::cout << "> ";
    }
    return 0;
}