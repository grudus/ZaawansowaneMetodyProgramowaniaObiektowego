
#include "GenericTree.h"
#include "RandomRpnElemCreator.h"

GenericTree::GenericTree(Node *root) : Tree(root) {
    srand(time(nullptr));
}

GenericTree::GenericTree(const Tree &tree) : Tree(tree) {
    srand(time(nullptr));
}

GenericTree GenericTree::mutate() {
    GenericTree tree = GenericTree(*this);

    std::string mutateTypes[] = {"leafToLeaf", "leafToNode", "nodeToLeaf", "nodeToNode", "switchLeafAndNode", "switchLeafAndLeaf", "switchNodeAndNode"};
    int index = rand() % 2;

    auto mutation = mutateTypes[index];
    auto root = tree.getRoot();

    switch (index) {
        case 0: tree.changeLeafToLeaf(root);
        case 1:
            tree.changeLeafOrNodeToNode(&root);
        case 2: tree.changeNodeToLeaf(&root);
    }

    tree.setRoot(root);
    return tree;
}

void GenericTree::changeLeafToLeaf(Node *node) {
    bool useCurrentNode = (node)->getChildrenNodesSize() == 0 || rand() % 2;

    if (!useCurrentNode) {
        int index = rand() % (node->getChildrenNodesSize());
        auto child = node->getChildren()[index];
        changeLeafToLeaf(child);
        return;
    }

    RpnElem *elem = RandomRpnElemCreator().randomElem(node->getElem());
    node->setElem(elem);
}

void GenericTree::setRoot(Node *root) {
    Tree::root = root;
}

void GenericTree::changeLeafOrNodeToNode(Node **pNode) {
    Node* currentNode = *pNode;
    bool shouldGoToChildNode = rand() % 3 != 0;

    int numberOfChildren = currentNode->getChildrenNodesSize();
    if (numberOfChildren > 0 && shouldGoToChildNode) {
        int index = rand() % numberOfChildren;
        Node* child = currentNode->getChildren()[index];
        changeLeafOrNodeToNode(&child);
    }
    else {
        RpnOperator *anOperator = RandomRpnElemCreator().randomOperator();
        auto newNode = new Node(anOperator);
        auto creator = RandomRpnElemCreator();
        for (int i = 0; i < anOperator->getNumberOfChildren(); i++) {
            RpnElem *pElem = creator.createVarOrConst();
            auto * child = new Node(pElem);
            newNode->addChild(child);
        }
        delete currentNode;
        **pNode = *newNode;

    }
}

void GenericTree::changeNodeToLeaf(Node **pNode) {

}


