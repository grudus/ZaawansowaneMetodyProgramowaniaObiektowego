#include <iostream>
#include "tree/Tree.h"
#include "tree/RpnTreeFactory.h"

int main() {
    auto expr = split("+ * 5 sin x * + a b 8", ' ');
    auto tree = RpnTreeFactory().create(expr);
    std::map<std::string, double> variables = {
            {"x", M_PI / 2},
            {"a", 2},
            {"b", 3}
    };


    auto tree2 = RpnTreeFactory().create(split("+ 1 2", ' '));

    auto tree3 = *tree + *tree2;

    std::cout << tree->prefixToString() << std::endl;
    std::cout << tree2->prefixToString() << std::endl;
    std::cout << tree3.prefixToString() << std::endl;

    tree3.printInOrder();

    return 0;
}