#ifndef GENERICPROGRAMMING_GENERICTREE_H
#define GENERICPROGRAMMING_GENERICTREE_H


#include "../tree/Tree.h"
#include <cstdlib>
#include <ctime>

class GenericTree: public Tree {

public:
    GenericTree();

    GenericTree(Node *root);
    GenericTree(const Tree &tree);

    GenericTree mutate();

    void changeLeafToLeaf(Node *node);

    void setRoot(Node *root);

    void changeLeafOrNodeToNode(Node **pNode);

    std::pair<GenericTree, GenericTree> cross(const GenericTree& other);
};


#endif //GENERICPROGRAMMING_GENERICTREE_H
