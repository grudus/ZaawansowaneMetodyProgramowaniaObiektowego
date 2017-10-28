#ifndef MATRIX_PRINTINSTRUCTION_H
#define MATRIX_PRINTINSTRUCTION_H


#include "Instruction.h"

class PrintInstruction : public Instruction {
public:
    PrintInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle();
};


#endif //MATRIX_PRINTINSTRUCTION_H
