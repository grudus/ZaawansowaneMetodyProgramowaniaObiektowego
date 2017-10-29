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

    getline(std::cin, name);
    ltrim(name);

    matrixes->push_back(new SpareMatrix(name, size, sizes, defaultValue));

    return 0;
}

inline void AddInstruction::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
