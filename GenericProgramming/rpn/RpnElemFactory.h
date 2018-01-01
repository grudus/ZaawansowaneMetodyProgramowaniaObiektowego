
#ifndef RPNTREE_RPNELEMFACTORY_H
#define RPNTREE_RPNELEMFACTORY_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include "RpnElem.h"
#include "../utils/Errorable.h"
#include "../utils/NumberUtils.h"
#include "../utils/StringUtils.h"
#include "RpnNumber.h"
#include "RpnOperator.h"
#include "RpnVariable.h"
#include "operators.h"

class RpnElemFactory {

public:
    RpnElem *create(const std::string &elem) const;


private:

    bool isOperator(const std::string &elem) const;

    int getNumberOfChildren(const std::string &elem) const;
};


#endif //RPNTREE_RPNELEMFACTORY_H
