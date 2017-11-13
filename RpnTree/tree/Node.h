#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"

class Node {
//    friend class Tree;
public:
    explicit Node(RpnElem *elem) : elem(elem), left(nullptr), right(nullptr) {}

    const RpnElem *getElem() const {
        return elem;
    }

    void setElem(RpnElem *elem) {
        Node::elem = elem;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }


private:
    RpnElem *elem;
    Node *left;
    Node *right;
};


#endif //RPNTREE_NODE_H
