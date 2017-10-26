#include <iostream>
#include "SpareMatrix.h"
#include "UserInterface.h"

int main() {
    auto *matrixes = new std::vector<SpareMatrix*>();
    UserInterface interface = UserInterface();

    while (true) {
        interface.showMenu();
        interface.readInstruction(matrixes);
    }


    return 0;
}

