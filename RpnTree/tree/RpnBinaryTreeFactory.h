
#ifndef RPNTREE_RPNBINARYTREEFACTORY_H
#define RPNTREE_RPNBINARYTREEFACTORY_H


#include <vector>
#include "Tree.h"

class RpnBinaryTreeFactory {

public:
    Tree *create(std::vector<std::string> expressions) const;
};


#endif //RPNTREE_RPNBINARYTREEFACTORY_H
