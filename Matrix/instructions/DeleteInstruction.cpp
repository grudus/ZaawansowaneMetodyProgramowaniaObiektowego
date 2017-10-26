//
// Created by grudus on 10/25/17.
//

#include "DeleteInstruction.h"

DeleteInstruction::DeleteInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int DeleteInstruction::handle() {
    int index = getIntegerInput();

    SpareMatrix *matrix = (*matrixes)[index];
    delete matrix;
    matrixes->erase(matrixes->begin() + index);


    return 0;
}


