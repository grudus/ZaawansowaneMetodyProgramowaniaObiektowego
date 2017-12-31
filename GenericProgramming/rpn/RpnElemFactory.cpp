#include "RpnElemFactory.h"

RpnElem *RpnElemFactory::create(const std::string &elem) const {
    if (isNumber(elem))
        return new RpnNumber(std::stoi(elem));

    if (isOperator(elem))
        return new RpnOperator(elem, getNumberOfChildren(elem));

    return new RpnVariable(elem);
}

int RpnElemFactory::getNumberOfChildren(const std::string &elem) const {
    return OPERATORS_TO_CHILDREN.find(elem)->second;
}

bool RpnElemFactory::isOperator(const std::string &elem) const {
    return OPERATORS_TO_CHILDREN.find(elem) != OPERATORS_TO_CHILDREN.end();
}
