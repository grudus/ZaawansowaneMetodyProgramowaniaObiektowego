#include <iostream>
#include "rpn/RpnElemFactory.h"
#include "tree/RpnTreeFactory.h"
#include "generic-tree/GenericTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string expression = "* - x 2 + y 4";
    auto vector1 = split(expression, "\\s+");
    auto tree = RpnTreeFactory().create(vector1);

    tree->printInOrder();


    auto genericTree = GenericTree(tree->getRoot()).mutate();
    std::cout << std::endl << std::endl;
    genericTree.printInOrder();

    return 0;
}