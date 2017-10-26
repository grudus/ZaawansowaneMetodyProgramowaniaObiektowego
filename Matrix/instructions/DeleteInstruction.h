//
// Created by grudus on 10/25/17.
//

#ifndef MATRIX_DELETEINSTRUCTION_H
#define MATRIX_DELETEINSTRUCTION_H


#include "Instruction.h"

class DeleteInstruction : public Instruction {
public:
    DeleteInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle();
};


#endif //MATRIX_DELETEINSTRUCTION_H
