#include "RpnTreeFactory.h"

Tree *RpnTreeFactory::create(std::vector<std::string> expressions) const {
    std::vector<RpnElem *> elems;

    std::transform(expressions.begin(), expressions.end(), std::back_inserter(elems),
                   [](std::string elem) -> RpnElem * { return RpnElemFactory().create(elem); });


    auto root = new Node(elems.front());
    createTree(tail(elems), root);
    return new Tree(root);
}

void RpnTreeFactory::createTree(std::vector<RpnElem *> vector, Node *current) const {
    if (vector.empty())
        return;

    auto head = vector.front();
    auto node = new Node(head);

    if (head->isOperator())
        addNewOperator(vector, current, node);
    else
        addVariableOrConstant(vector, current, node);

}

void RpnTreeFactory::addVariableOrConstant(const std::vector<RpnElem *> &vector, Node *current, Node *node) const {
    current->addChild(node);
    if (hasEnoughChildren(current))
        createTree(tail(vector), current->getParent());
    else
        createTree(tail(vector), current);
}

void RpnTreeFactory::addNewOperator(const std::vector<RpnElem *> &vector, Node *current, Node *node) const {
    if (hasEnoughChildren(current))
        createTree(vector, current->getParent());
    else {
        current->addChild(node);
        createTree(tail(vector), node);
    }
}

bool RpnTreeFactory::hasEnoughChildren(Node *pNode) const {
    auto elem = pNode->getElem();
    return elem->isOperator()
           && ((RpnOperator *) elem)->getNumberOfChildren() == pNode->getChildrenNodesSize();
}
