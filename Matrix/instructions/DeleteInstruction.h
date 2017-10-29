#ifndef MATRIX_DELETEINSTRUCTION_H
#define MATRIX_DELETEINSTRUCTION_H


#include "Instruction.h"

class DeleteInstruction : public Instruction {
public:
    DeleteInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle();
};


#endif //MATRIX_DELETEINSTRUCTION_H
