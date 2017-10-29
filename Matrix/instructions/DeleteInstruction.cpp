#include "DeleteInstruction.h"

DeleteInstruction::DeleteInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int DeleteInstruction::handle() {
    int index = getIntegerInput();

    if (!indexIsValid(index)) {
        handleInvalidIndex(index);
        return -1;
    }

    SpareMatrix *matrix = (*matrixes)[index];
    delete matrix;
    matrixes->erase(matrixes->begin() + index);


    return 0;
}


