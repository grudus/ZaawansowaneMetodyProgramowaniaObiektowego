
#ifndef RPNTREE_PRINTINSTRUCTION_H
#define RPNTREE_PRINTINSTRUCTION_H

#include <iostream>
#include "../../tree/Tree.h"

void handlePrintInstruction(Tree *tree) {
    if (tree == nullptr) {
        std::cerr << "You have to initialize tree first!" << std::endl;
        return;
    }
    std::cout << tree->prefixToString() << std::endl;
}

#endif //RPNTREE_PRINTINSTRUCTION_H
