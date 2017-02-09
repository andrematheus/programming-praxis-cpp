#include "RpnCalculator.h"

#include <iostream>

bool is_error(CalcResult result) {
    return result != CalcResult::OK;
}

bool is_ok(CalcResult result) {
    return result == CalcResult::OK;
}

std::string descriptions[] = {
#define DEF(x) std::string(#x),
#include "CalcResult.def"
#undef DEF
};

std::ostream &operator<<(std::ostream &os, CalcResult r) {
    int index = static_cast<int>(r);
    std::string desc = descriptions[index];
    os << desc;
    return os;
}