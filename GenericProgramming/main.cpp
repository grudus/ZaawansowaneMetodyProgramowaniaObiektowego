#include <iostream>
#include "rpn/RpnElemFactory.h"
#include "tree/RpnTreeFactory.h"
#include "generic-tree/GenericTree.h"
#include "tree/RpnTreeSolver.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string expression = "* x 2";
    auto vector1 = split(expression, "\\s+");
    auto tree = RpnTreeFactory().create(vector1);

    tree->printPrefixed();


    auto genericTree = GenericTree(tree->getRoot()).mutate();
    std::cout << std::endl << std::endl;
    genericTree.printPrefixed();
    std::cout << "\n";

    std::map<std::string, double> env = {{"x", 1}, {"y", 1}};

    auto result = RpnTreeSolver().solve((Tree*) &genericTree, env);

    std::cout << result->getValue() << std::endl;



    expression = "+ + 3 x - 4 / y 2";
    vector1 = split(expression, "\\s+");
    auto tree2 = GenericTree(RpnTreeFactory().create(vector1)->getRoot());

    expression = "* / + 2 1 x * 1 y";
    vector1 = split(expression, "\\s+");
    auto tree1 = GenericTree(RpnTreeFactory().create(vector1)->getRoot());

    tree1.printPrefixed();
    tree2.printPrefixed();

    auto crossed = tree1.cross(tree2);

    crossed.first.printPrefixed();
    crossed.second.printPrefixed();

    return 0;
}