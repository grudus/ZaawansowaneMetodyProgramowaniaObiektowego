//
// Created by grudus on 10/25/17.
//

#ifndef MATRIX_ADDINSTRUCTION_H
#define MATRIX_ADDINSTRUCTION_H


#include "Instruction.h"

class AddInstruction : public Instruction {
public:
    explicit AddInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;

};


#endif //MATRIX_ADDINSTRUCTION_H
