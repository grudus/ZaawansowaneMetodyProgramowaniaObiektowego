//
// Created by grudus on 10/25/17.
//

#include "ListInstruction.h"

ListInstruction::ListInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int ListInstruction::handle() {
    std::cout << matrixes->size() << " matrices:" << std::endl;
    for (int i = 0; i < matrixes->size(); i++) {
        std::cout << "[" << i << "] \"";
        std::cout << (*matrixes)[i]->getName() << "\" size: ";
        std::cout << (*matrixes)[i]->getDimensionsString() << std::endl;
    }

    return 0;
}


