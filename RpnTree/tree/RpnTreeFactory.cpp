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
    current->addChild(node);

    if (head->isOperator())
        createTree(tail(vector), node);
    else
        createTree(tail(vector), current);
}
