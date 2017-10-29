//
// Created by grudus on 10/26/17.
//

#ifndef MATRIX_DEFINSTRUCTION_H
#define MATRIX_DEFINSTRUCTION_H


#include "Instruction.h"

class DefInstruction : public Instruction {
public:
    explicit DefInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;

    bool invalidCoordinates(const int *coordinates, SpareMatrix *matrix);
};


#endif //MATRIX_DEFINSTRUCTION_H
