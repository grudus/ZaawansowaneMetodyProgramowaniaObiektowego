#ifndef RPNTREE_JOININSTRUCTION_H
#define RPNTREE_JOININSTRUCTION_H

#include "../../tree/Tree.h"
#include "EnterInstruction.h"

void handleJoinInstruction(Tree **tree) {
    if (tree == nullptr || *tree == nullptr) {
        std::cerr << "You have to initialize tree first!" << std::endl;
        return;
    }

    Tree *newTree;
    handleEnterInstruction(&newTree);

    **tree = **tree + *newTree;
}

#endif //RPNTREE_JOININSTRUCTION_H
