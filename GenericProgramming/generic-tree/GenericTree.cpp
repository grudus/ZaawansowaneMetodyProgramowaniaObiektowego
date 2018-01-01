
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
    int index = /*rand() % 7;*/ 0;

    auto mutation = mutateTypes[index];
    auto root = tree.getRoot();

    switch (index) {
        case 0: tree.changeLeafToLeaf(root);
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
//    delete Tree::root;
    Tree::root = root;
}


