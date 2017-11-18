#ifndef RPNTREE_TREE_H
#define RPNTREE_TREE_H

#include <string>
#include "Node.h"

class Tree {
public:
    explicit Tree(Node *root);

    Tree(const Tree &tree);

    std::string prefixToString();

    void printInOrder();

    Node *getRoot() const;

    Tree &operator=(const Tree &tree);

    Tree operator+(const Tree &tree);


private:
    Node *root;

    std::string prefix(std::string actual, Node *node);

    void printInOrder(Node *pNode);

    Node *findLastChild(Node *pNode);
};


#endif //RPNTREE_TREE_H
