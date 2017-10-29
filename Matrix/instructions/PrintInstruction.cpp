#include "PrintInstruction.h"

PrintInstruction::PrintInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int PrintInstruction::handle() {
    int index = getIntegerInput();

    if (!indexIsValid(index)) {
        handleInvalidIndex(index);
        return -1;
    }

    std::cout << (*matrixes)[index]->toString() << std::endl;
}
