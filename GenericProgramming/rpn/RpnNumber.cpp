#include "RpnNumber.h"

int RpnNumber::getNumber() const {
    return number;
}

RpnNumber::RpnNumber(int number) : number(number) {}

std::string RpnNumber::toString() const {
    return std::to_string(number);
}

RpnElem::Type RpnNumber::getType() const {
    return RpnElem::Type::CONSTANT;
}
