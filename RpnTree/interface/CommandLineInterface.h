#ifndef RPNTREE_COMMANDLINEINTERFACE_H
#define RPNTREE_COMMANDLINEINTERFACE_H


#include "../tree/Tree.h"

class CommandLineInterface {
public:
    void showMenu();

    bool readInput(Tree **tree);
};


#endif //RPNTREE_COMMANDLINEINTERFACE_H
