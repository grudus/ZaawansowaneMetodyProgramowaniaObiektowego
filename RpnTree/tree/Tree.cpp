
#include <iostream>
#include "Tree.h"

Tree::Tree(Node *root) {
    this->root = root;
}

std::string Tree::prefixToString() {
    return prefix("", root);
}

std::string Tree::prefix(std::string actual, Node *node) {
    if (node == nullptr)
        return actual;
    
    auto elem = node->getElem();
    actual += (*elem).toString() + " ";

    for (auto child : node->getChildren())
        actual = prefix(actual, child);

    return actual;
}
