#include "RpnElemFactory.h"

RpnElem *RpnElemFactory::create(const std::string &elem) const {
    if (isNumber(elem))
        new RpnNumber(std::stoi(elem));

    if (isOperator(elem))
        return new RpnOperator(elem);

    return new RpnVariable(elem);
}

bool RpnElemFactory::isOperator(const std::string &elem) const {
    return find(POSSIBLE_OPERATORS.begin(), POSSIBLE_OPERATORS.end(), elem) != POSSIBLE_OPERATORS.end();
}
