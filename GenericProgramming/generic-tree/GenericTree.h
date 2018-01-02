#ifndef GENERICPROGRAMMING_GENERICTREE_H
#define GENERICPROGRAMMING_GENERICTREE_H


#include "../tree/Tree.h"
#include <cstdlib>
#include <ctime>

class GenericTree: public Tree {

public:
    GenericTree(Node *root);
    GenericTree(const Tree &tree);

    GenericTree mutate();

    void changeLeafToLeaf(Node *node);

    void setRoot(Node *root);

    void changeLeafToNode(Node **pNode);
};


#endif //GENERICPROGRAMMING_GENERICTREE_H
