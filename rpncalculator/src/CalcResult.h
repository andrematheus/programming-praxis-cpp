#pragma once

#include <memory>

enum class CalcResult {
#define DEF(x) x,

#include "CalcResult.def"
#undef DEF
};

bool is_error(CalcResult result);

bool is_ok(CalcResult result);

std::ostream &operator<<(std::ostream &os, const CalcResult r);