#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"
#include "../rpn/RpnElemFactory.h"
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

    Node(const Node &node) {
        if (&node != nullptr) {
            this->elem = RpnElemFactory().create(node.elem->toString());
            for (auto child: node.children) {
                this->children.push_back(new Node(*child));
            }
            this->parent = node.parent;
        }
    }

    Node &operator=(const Node &node) {
        parent = new Node(*node.parent);
        for (auto child : node.children)
            children.push_back(new Node(*child));
        elem = RpnElemFactory().create(node.elem->toString());
        return *this;
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
