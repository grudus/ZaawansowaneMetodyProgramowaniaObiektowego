
#ifndef RPNTREE_RPNELEMFACTORY_H
#define RPNTREE_RPNELEMFACTORY_H

#include <algorithm>
#include <string>
#include <vector>
#include "RpnElem.h"
#include "../utils/ErrorableValue.h"
#include "../utils/NumberUtils.h"
#include "../utils/StringUtils.h"
#include "RpnNumber.h"
#include "RpnOperator.h"
#include "RpnVariable.h"

class RpnElemFactory {

public:
    RpnElem* create(const  std::string& elem) const;


private:
    const std::vector<std::string> POSSIBLE_OPERATORS = split("+|-|*|/|sin|cos", '|');

    bool isOperator(const std::string &elem) const;
};


#endif //RPNTREE_RPNELEMFACTORY_H
