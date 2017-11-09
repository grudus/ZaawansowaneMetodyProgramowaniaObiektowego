#include "ReverseInstruction.h"

ReverseInstruction::ReverseInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int ReverseInstruction::handle() {
    int index = getIntegerInput();
    if (!indexIsValid(index)) {
        handleInvalidIndex(index);
        return -1;
    }

    int value = getIntegerInput();

    (*matrixes)[index]->reverse(value);
}
