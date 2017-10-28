#ifndef MATRIX_RENAMEINSTRUCTION_H
#define MATRIX_RENAMEINSTRUCTION_H


#include "Instruction.h"

class RenameInstruction: public Instruction {
public:
    RenameInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;
};


#endif //MATRIX_RENAMEINSTRUCTION_H
