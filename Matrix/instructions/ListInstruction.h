#ifndef MATRIX_LISTINSTRUCTION_H
#define MATRIX_LISTINSTRUCTION_H


#include "Instruction.h"

class ListInstruction : public Instruction {
public:
    explicit ListInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;
};


#endif //MATRIX_LISTINSTRUCTION_H
