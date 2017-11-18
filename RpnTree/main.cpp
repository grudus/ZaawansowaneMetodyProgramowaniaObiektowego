#include <iostream>
#include "tree/Tree.h"
#include "rpn/RpnVariable.h"
#include "tree/RpnTreeFactory.h"
#include "tree/RpnTreeSolver.h"

int main() {
    auto expr = split("+ / 1 2 * + a c 8", ' ');
    auto tree = RpnTreeFactory().create(expr);
    std::map<std::string, double> variables = {
            {"x", M_PI / 2},
            {"a", 2},
            {"b", 3}
    };


    std::cout << tree->prefixToString() << std::endl;

    Errorable<double> *pErrorable = RpnTreeSolver().solve(tree, variables);
    if (pErrorable->isError())
        std::cerr << "ERROR OCCURED: " << pErrorable->getErrorCode() << std::endl;
    else
        std::cout << pErrorable->getValue() << std::endl;

    return 0;
}