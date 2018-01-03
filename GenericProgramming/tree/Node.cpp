#include <iostream>
#include "Node.h"


const RpnElem *Node::getElem() const {
    return elem;
}

void Node::setElem(RpnElem *elem) {
    Node::elem = elem;
}

void Node::addChild(Node *child) {
    children.push_back(child);
    child->parent = this;
}

std::vector<Node *> Node::getChildren() const {
    return children;

}

Node *Node::getParent() const {
    return parent;
}

int Node::getChildrenNodesSize() const {
    return static_cast<int>(children.size());
}

Node::Node(const Node &node) {
    if (&node != nullptr) {
        this->elem = RpnElemFactory().create(node.elem->toString());
        for (auto child: node.children) {
            this->children.push_back(new Node(*child));
        }
        this->parent = node.parent;
    }
}

Node &Node::operator=(const Node &node) {
    parent = new Node(*node.parent);
    for (auto child : node.children)
        children.push_back(new Node(*child));
    elem = RpnElemFactory().create(node.elem->toString());
    return *this;

}

Node::~Node() {
    delete elem;
    for (auto node : children)
        delete node;
    children.clear();
}

void Node::removeFirstChild() {
    children.erase(children.begin());
}

void Node::removeLastChild() {
    children.pop_back();
}
