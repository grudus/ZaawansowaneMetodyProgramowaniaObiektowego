#include "DeleteAllInstruction.h"

DeleteAllInstruction::DeleteAllInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int DeleteAllInstruction::handle() {
    for (auto matrix: *matrixes)
        delete matrix;
    matrixes->clear();
    return 0;
}
