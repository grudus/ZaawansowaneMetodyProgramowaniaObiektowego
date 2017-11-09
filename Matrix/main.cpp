#include <iostream>
#include "SpareMatrix.h"
#include "UserInterface.h"

int main() {
    auto *matrixes = new std::vector<SpareMatrix *>();
    UserInterface interface = UserInterface();

    interface.showMenu();
    while (true) {
        interface.readInstruction(matrixes);
    }

    return 0;
}

