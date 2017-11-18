
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

Node *Tree::getRoot() const {
    return root;
}

Tree &Tree::operator=(const Tree &tree) {
    this->root = new Node(*tree.root);
    return *this;
}

Tree::Tree(const Tree &tree) {
    this->root = new Node(*tree.root);
}

void Tree::printInOrder() {
    printInOrder(root);
}

void Tree::printInOrder(Node *pNode) {
    if (!pNode)
        return;
    if (!pNode->children.empty())
        printInOrder(pNode->children[0]);

    std::cout << pNode->elem->toString() << " ";

    if (pNode->children.size() > 1)
        printInOrder(pNode->children[1]);
}

Tree Tree::operator+(const Tree &tree) {
    auto newTree = *this;

    Node *leaf = findLastChild(newTree.root);

    *leaf = *tree.root;

    return newTree;
}

Node *Tree::findLastChild(Node *pNode) {
    if (pNode->children.empty())
        return pNode;
    return findLastChild(pNode->children[0]);
}
