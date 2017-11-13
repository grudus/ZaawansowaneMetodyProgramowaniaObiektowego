#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"

class Node {
    friend class Tree;
public:
    explicit Node(const RpnElem &elem): elem(elem), left(nullptr), right(nullptr) {}
private:
    RpnElem elem;
    Node* left;
    Node* right;
};


#endif //RPNTREE_NODE_H
