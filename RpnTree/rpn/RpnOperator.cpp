#include "RpnOperator.h"

#include <utility>

bool RpnOperator::isOperator() {
    return true;
}

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
