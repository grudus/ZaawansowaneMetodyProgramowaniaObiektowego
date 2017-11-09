#ifndef MATRIX_REVERSEINSTRUCTION_H
#define MATRIX_REVERSEINSTRUCTION_H


#include "Instruction.h"

class ReverseInstruction : public Instruction {
public:
    ReverseInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;
};


#endif //MATRIX_REVERSEINSTRUCTION_H
