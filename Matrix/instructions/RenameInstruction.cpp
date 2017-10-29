#include "RenameInstruction.h"

RenameInstruction::RenameInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int RenameInstruction::handle() {
    int index = getIntegerInput();

    if (!indexIsValid(index)) {
        handleInvalidIndex(index);
        return -1;
    }

    std::string name;
    std::cin >> name;

    (*matrixes)[index]->rename(name);
}
