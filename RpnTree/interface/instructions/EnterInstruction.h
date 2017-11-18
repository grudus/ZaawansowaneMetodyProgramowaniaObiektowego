#ifndef RPNTREE_ENTERINSTRUCTION_H
#define RPNTREE_ENTERINSTRUCTION_H

#include <iostream>
#include "../../tree/Tree.h"
#include "../../tree/RpnTreeFactory.h"
#include "../../utils/StringUtils.h"

void handleEnterInstruction(Tree **tree) {
    std::string formula;
    getline(std::cin, formula);
    ltrim(formula);
    const std::vector<std::string> &expressions = split(formula, "\\s+");
    *tree = RpnTreeFactory().create(expressions);

    (*tree)->repair();
    auto prefix = (*tree)->prefixToString();

    if (split(prefix, "\\s+") != expressions) {
        std::cerr << "You entered invalid expression! It will be fixed to: " << std::endl;
        std::cout << prefix << std::endl;
    }
}


#endif //RPNTREE_ENTERINSTRUCTION_H
