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

    auto root = tree->getRoot();

    Node dupa(nullptr);

    dupa = *root;

    delete root;

    std::cout << Tree(&dupa).prefixToString() << std::endl;

    return 0;
}