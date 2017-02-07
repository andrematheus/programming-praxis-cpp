#include "CalcResult.h"

class CalcResultOk : public CalcResultS {
public:
    bool is_error() override;
};

class CalcResultError : public CalcResultS {
public:
    CalcResultError(const CalcError error);

    bool is_error() override;

private:
    const CalcError error;
};

bool CalcResultOk::is_error() {
    return false;
}

bool CalcResultError::is_error() {
    return true;
}

CalcResultError::CalcResultError(const CalcError error) : error(error) {}

CalcResult CalcResultS::ok() {
    return std::unique_ptr<CalcResultS>(new CalcResultOk());
}

CalcResult CalcResultS::error(const CalcError error) {
    return std::unique_ptr<CalcResultS>(new CalcResultError(error));
}
