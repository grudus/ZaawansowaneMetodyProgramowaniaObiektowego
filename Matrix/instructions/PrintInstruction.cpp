//
// Created by grudus on 10/28/17.
//

#include "PrintInstruction.h"

PrintInstruction::PrintInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int PrintInstruction::handle() {
    int index = getIntegerInput();

    std::cout << (*matrixes)[index]->toString() << std::endl;
}
