#include "RpnNumber.h"

bool RpnNumber::isOperator() const {
    return false;
}

int RpnNumber::getNumber() const {
    return number;
}

RpnNumber::RpnNumber(int number) : number(number) {}

std::string RpnNumber::toString() const {
    return std::to_string(number);
}
