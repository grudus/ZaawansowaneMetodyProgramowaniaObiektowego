#ifndef RPNTREE_RPNELEM_H
#define RPNTREE_RPNELEM_H

#include <string>
#include "RpnElem.h"

class RpnElem {

public:
    enum class Type {
        CONSTANT,
        OPERATOR,
        VARIABLE
    };

    virtual ~RpnElem() = default;;

    bool isOperator() const {
        return this->getType() == Type::OPERATOR;
    }

    virtual std::string toString() const = 0;

    virtual Type getType() const = 0;
};

#endif //RPNTREE_RPNELEM_H
