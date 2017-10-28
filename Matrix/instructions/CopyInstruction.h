
#ifndef MATRIX_COPYINSTRUCTION_H
#define MATRIX_COPYINSTRUCTION_H


#include "Instruction.h"

class CopyInstruction : public Instruction {
public:
    CopyInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;

};


#endif //MATRIX_COPYINSTRUCTION_H
