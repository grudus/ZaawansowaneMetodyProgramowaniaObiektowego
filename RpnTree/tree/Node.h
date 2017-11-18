#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"
#include <vector>

class Node {
    friend class Tree;

public:
    explicit Node(RpnElem *elem) : elem(elem) {
        parent = nullptr;
    }

    const RpnElem *getElem() const {
        return elem;
    }

    void setElem(RpnElem *elem) {
        Node::elem = elem;
    }

    void addChild(Node *child) {
        children.push_back(child);
        child->parent = this;
    }

    std::vector<Node *> getChildren() {
        return children;
    }

    Node *getParent() {
        return parent;
    }

    int getChildrenNodesSize() {
        return static_cast<int>(children.size());
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
    Node *parent;
};


#endif //RPNTREE_NODE_H
