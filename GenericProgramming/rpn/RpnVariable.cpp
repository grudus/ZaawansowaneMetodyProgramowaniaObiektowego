#include "RpnVariable.h"

std::string RpnVariable::toString() const {
    return var;
}

RpnElem::Type RpnVariable::getType() const {
    return RpnElem::Type::VARIABLE;
}
