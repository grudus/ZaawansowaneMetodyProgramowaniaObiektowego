#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"
#include <vector>

class Node {
    friend class Tree;

public:
    explicit Node(RpnElem *elem) : elem(elem) {}

    const RpnElem *getElem() const {
        return elem;
    }

    void setElem(RpnElem *elem) {
        Node::elem = elem;
    }

    void addChild(Node *child) {
        children.push_back(child);
    }

    std::vector<Node *> getChildren() {
        return children;
    }


    ~Node() {
        delete elem;
        for (auto node : children)
            delete node;
        children.clear();
    }

private:
    RpnElem *elem;
    std::vector<Node *> children;
};


#endif //RPNTREE_NODE_H
