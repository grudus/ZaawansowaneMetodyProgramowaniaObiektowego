#ifndef MATRIX_ADDINSTRUCTION_H
#define MATRIX_ADDINSTRUCTION_H


#include "Instruction.h"

class AddInstruction : public Instruction {
public:
    explicit AddInstruction(std::vector<SpareMatrix *> *matrixes);

    int handle() override;

private:
    inline void ltrim(std::string &s);

};


#endif //MATRIX_ADDINSTRUCTION_H
