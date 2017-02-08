#include "RpnCalculator.h"

bool is_error(CalcResult result) {
    return result != CalcResult::OK;
}

bool is_ok(CalcResult result) {
    return result == CalcResult::OK;
}

std::string descriptions[] = {
#define DEF(x) ""#x ,

#include "CalcResult.def"
#undef DEF
};

std::ostream &operator<<(std::ostream &os, CalcResult const &r) {
    int index = static_cast<int>(r);
    return os << descriptions[index];
}