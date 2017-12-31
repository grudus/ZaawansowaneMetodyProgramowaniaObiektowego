#ifndef RPNTREE_NODE_H
#define RPNTREE_NODE_H

#include "../rpn/RpnElem.h"
#include "../rpn/RpnElemFactory.h"
#include <vector>

class Node {
    friend class Tree;

public:
    explicit Node(RpnElem *elem) : elem(elem), parent(nullptr) {}

    const RpnElem *getElem() const;

    void setElem(RpnElem *elem);

    void addChild(Node *child);

    std::vector<Node *> getChildren() const;

    Node *getParent() const;

    int getChildrenNodesSize() const;

    Node(const Node &node);

    Node &operator=(const Node &node);

    ~Node();

private:
    RpnElem *elem;
    std::vector<Node *> children;
    Node *parent;
};


#endif //RPNTREE_NODE_H
