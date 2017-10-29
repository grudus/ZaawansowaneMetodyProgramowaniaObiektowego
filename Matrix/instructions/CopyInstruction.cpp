//
// Created by grudus on 10/28/17.
//

#include "CopyInstruction.h"

CopyInstruction::CopyInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int CopyInstruction::handle() {
    int index = getIntegerInput();

    if (!indexIsValid(index)) {
        handleInvalidIndex(index);
        return -1;
    }

    SpareMatrix *matrix = (*matrixes)[index];

    SpareMatrix *copy = new SpareMatrix(*matrix);

    matrixes->push_back(copy);

    return 0;
}
