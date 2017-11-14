
#ifndef RPNTREE_RPNTREEFACTORY_H
#define RPNTREE_RPNTREEFACTORY_H


#include <vector>
#include <algorithm>
#include "Tree.h"
#include "../rpn/RpnElemFactory.h"
#include "../utils/VectorUtils.h"

class RpnTreeFactory {

public:
    Tree *create(std::vector<std::string> expressions) const;

    void createTree(std::vector<RpnElem *> vector, Node *current) const;
};


#endif //RPNTREE_RPNTREEFACTORY_H
