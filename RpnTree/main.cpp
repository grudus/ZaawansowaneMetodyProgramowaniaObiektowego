#include <iostream>
#include "tree/Tree.h"
#include "rpn/RpnVariable.h"
#include "tree/RpnTreeFactory.h"
#include "tree/RpnTreeSolver.h"

int main() {
    auto expr = split("+ * 5 sin x * + a b 8", ' ');
    auto tree = RpnTreeFactory().create(expr);
    std::map<std::string, double> variables = {
            {"x", M_PI / 2},
            {"a", 2},
            {"b", 3}
    };


    std::cout << tree->prefixToString() << std::endl;

    std::cout << (RpnTreeSolver().solve(tree, variables)) << std::endl;

    return 0;
}