//
// Created by grudus on 10/28/17.
//

#include "RenameInstruction.h"

RenameInstruction::RenameInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int RenameInstruction::handle() {
    int index = getIntegerInput();
    std::string name;
    std::cin >> name;

    (*matrixes)[index]->rename(name);
}
