#include "RpnVariable.h"

bool RpnVariable::isOperator() {
    return false;
}

std::string RpnVariable::toString() const {
    return var;
}