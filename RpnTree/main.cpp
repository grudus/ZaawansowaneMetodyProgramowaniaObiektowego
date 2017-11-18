#include <iostream>
#include "tree/Tree.h"
#include "tree/RpnTreeFactory.h"

int main() {
    auto expr = split("+ / 1 2 * + a c 8", ' ');
    auto tree = RpnTreeFactory().create(expr);
    std::map<std::string, double> variables = {
            {"x", M_PI / 2},
            {"a", 2},
            {"b", 3}
    };


    Tree tree2(nullptr);

    tree2 = *tree;

    delete tree;

    std::cout << tree2.prefixToString() << std::endl;

    return 0;
}