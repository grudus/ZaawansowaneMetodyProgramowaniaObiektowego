#ifndef MATRIX_INSTRUCTION_H
#define MATRIX_INSTRUCTION_H


#include <vector>
#include <regex>
#include "../SpareMatrix.h"

class Instruction {
public:
    explicit Instruction(std::vector<SpareMatrix *> *matrixes);
    virtual ~Instruction() {}
    virtual int handle() = 0;

protected:
    bool indexIsValid(int index) const;
    void handleInvalidIndex(int index) const;
    int getIntegerInput() const;

    std::vector<SpareMatrix *> *matrixes;

private:
    bool isNumber(const std::string &x) const;
};


#endif //MATRIX_INSTRUCTION_H
