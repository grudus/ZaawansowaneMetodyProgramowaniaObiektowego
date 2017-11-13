#include "RpnNumber.h"

bool RpnNumber::isOperator() {
    return false;
}

int RpnNumber::getNumber() const {
    return number;
}

RpnNumber::RpnNumber(int number) : number(number) {}
