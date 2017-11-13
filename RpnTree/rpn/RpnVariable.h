#ifndef RPNTREE_RPNVARIABLE_H
#define RPNTREE_RPNVARIABLE_H

#include <string>
#include <utility>
#include "RpnElem.h"

class RpnVariable : public RpnElem {
public:
    explicit RpnVariable(std::string variable): var(std::move(variable)) {}

    bool isOperator() override;
    std::string toString() const override;

private:
    const std::string var;
};


#endif //RPNTREE_RPNVARIABLE_H
