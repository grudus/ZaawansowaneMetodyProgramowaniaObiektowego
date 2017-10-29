//
// Created by grudus on 10/25/17.
//

#ifndef MATRIX_INSTRUCTION_H
#define MATRIX_INSTRUCTION_H


#include <vector>
#include <regex>
#include "../SpareMatrix.h"

class Instruction {
public:
    explicit Instruction(std::vector<SpareMatrix *> *matrixes) {
        this->matrixes = matrixes;
    }

    virtual ~Instruction() {}

    virtual int handle() = 0;

protected:

    bool indexIsValid(int index) {
        return index >= 0 && index < (*matrixes).size();
    }
    void handleInvalidIndex(int index) {
        std::cerr << "Invalid index [" << index << "]" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int getIntegerInput() {
        std::string input;
        bool isNumeric;
        do {
            std::cin >> input;
            isNumeric = isNumber(input);
            if (!isNumeric)
                std::cout << "Please enter valid numeric input" << std::endl;
        } while (!isNumeric);
        return std::stoi(input);
    }

    bool isNumber(const std::string &x) {
        std::regex e("^-?\\d+");
        return std::regex_match(x, e);
    }


    std::vector<SpareMatrix *> *matrixes;

};


#endif //MATRIX_INSTRUCTION_H
