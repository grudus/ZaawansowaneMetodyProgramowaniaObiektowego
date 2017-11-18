
#include "tree/Tree.h"
#include "interface/CommandLineInterface.h"

int main() {

    Tree *tree = nullptr;
    CommandLineInterface().showMenu();

    while (CommandLineInterface().readInput(&tree));

    delete tree;
    return 0;
}