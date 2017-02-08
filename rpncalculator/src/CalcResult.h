#pragma once

#include <memory>

enum CalcResult {
    OK,
    ParsingError,
    NotEnoughOperandsError,
};

bool is_error(CalcResult result);