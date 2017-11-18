#include "RpnVariable.h"

bool RpnVariable::isOperator() const {
    return false;
}

std::string RpnVariable::toString() const {
    return var;
}