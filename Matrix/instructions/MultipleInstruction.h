#ifndef MATRIX_MULTIPLEINSTRUCTION_H
#define MATRIX_MULTIPLEINSTRUCTION_H


#include "Instruction.h"

class MultipleInstruction : Instruction {
public:
    MultipleInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;

private:

    void multipleMatrixes(int index, int secondIndex, const int *sizes1, const int *sizes2) const;
};


#endif //MATRIX_MULTIPLEINSTRUCTION_H
