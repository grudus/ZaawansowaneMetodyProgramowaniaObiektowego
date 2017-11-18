#include "RpnOperator.h"

#include <utility>

std::string RpnOperator::getOperator() {
    return oper;
}

RpnOperator::RpnOperator(std::string _operator, int numberOfChildren)
        : oper(std::move(_operator)), numberOfChildren(numberOfChildren) {}

std::string RpnOperator::toString() const {
    return oper;
}

RpnOperator::RpnOperator(std::string _operator)
        : oper(std::move(_operator)), numberOfChildren(2) {}

int RpnOperator::getNumberOfChildren() const {
    return numberOfChildren;
}

RpnElem::Type RpnOperator::getType() const {
    return RpnElem::Type::OPERATOR;
}
