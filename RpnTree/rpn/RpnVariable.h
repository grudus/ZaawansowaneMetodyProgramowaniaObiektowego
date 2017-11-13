#ifndef RPNTREE_RPNVARIABLE_H
#define RPNTREE_RPNVARIABLE_H

#include <string>
#include <utility>
#include "RpnElem.h"

class RpnVariable: RpnElem {
public:
    explicit RpnVariable(std::string variable): var(std::move(variable)) {}


private:
    const std::string var;
};


#endif //RPNTREE_RPNVARIABLE_H
