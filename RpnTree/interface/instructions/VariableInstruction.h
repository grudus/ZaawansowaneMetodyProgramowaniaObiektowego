#ifndef RPNTREE_VARIABLEINSTRUCTION_H
#define RPNTREE_VARIABLEINSTRUCTION_H

#include <iostream>
#include "../../tree/Tree.h"

void handleVariableInstruction(Tree *tree) {
    if (tree == nullptr) {
        std::cerr << "You have to initialize tree first!" << std::endl;
        return;
    }
    std::set<std::string> set = tree->findVariables();

    if (set.empty())
        std::cout << "Cannot find any variable" << std::endl;
    else
        for (const auto &var : set) std::cout << var << " ";
    std::cout << std::endl;
}

#endif //RPNTREE_VARIABLEINSTRUCTION_H
