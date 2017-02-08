#pragma once

#include <memory>

enum CalcResult {
    OK,
    ParsingError,
    NotEnoughOperandsError,
    InvalidOperator,
};

bool is_error(CalcResult result);