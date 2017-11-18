
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

    bool hasEnoughChildren(Node *pNode) const;

    void addNewOperator(const std::vector<RpnElem *> &vector, Node *current, Node *node) const;

    void addVariableOrConstant(const std::vector<RpnElem *> &vector, Node *current, Node *node) const;
};


#endif //RPNTREE_RPNTREEFACTORY_H
