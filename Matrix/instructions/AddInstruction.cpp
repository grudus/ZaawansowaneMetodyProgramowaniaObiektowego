//
// Created by grudus on 10/25/17.
//

#include "AddInstruction.h"

AddInstruction::AddInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int AddInstruction::handle() {

    int size = getIntegerInput();
    int *sizes = new int[size];
    for (int i = 0; i < size; i++)
        sizes[i] = getIntegerInput();

    std::string name;
    int defaultValue = getIntegerInput();

    std::cin >> name;

    matrixes->push_back(new SpareMatrix(name, size, sizes, defaultValue));

    return 0;
}
