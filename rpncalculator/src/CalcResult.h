#pragma once

#include <memory>

enum CalcError {
    ParsingError,
};

class CalcResultS;

typedef std::unique_ptr<CalcResultS> CalcResult;

class CalcResultS {
public:
    static CalcResult ok();

    static CalcResult error(const CalcError error);

    virtual bool is_error()= 0;
};