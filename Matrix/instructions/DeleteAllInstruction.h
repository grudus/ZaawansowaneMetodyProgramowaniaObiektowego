#ifndef MATRIX_DELETEALLINSTRUCTION_H
#define MATRIX_DELETEALLINSTRUCTION_H


#include "Instruction.h"

class DeleteAllInstruction : public Instruction {
public:
    DeleteAllInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle();
};


#endif //MATRIX_DELETEALLINSTRUCTION_H
