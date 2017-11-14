
#ifndef RPNTREE_RPNTREEFACTORY_H
#define RPNTREE_RPNTREEFACTORY_H


#include <vector>
#include <algorithm>
#include "Tree.h"
#include "../rpn/RpnElemFactory.h"


class RpnTreeFactory {

public:
    Tree *create(std::vector<std::string> expressions) const;
};


#endif //RPNTREE_RPNTREEFACTORY_H
