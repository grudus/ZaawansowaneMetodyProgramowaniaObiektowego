#include <iostream>
#include "RzadkiWektor.h"
#include "UserInterface.h"


bool isVectorValid(int *offsets, int *values) {
    bool valid = offsets != nullptr && values != nullptr;
    if (!valid)
        std::cout << "You should initialize vector first (with mvec)!\n";
    return valid;
}

int main() {
    std::cout << "Hello, we will start using vectors!" << std::endl;

    int *offsets = nullptr;
    int *values = nullptr;
    int tableSize = 0;
    int vectorSize = 20;
    int defaultValue = 0;


    std::string userInstruction;
    int arg1, arg2;

    while (userInstruction != QUIT_INSTRUCTION) {

        showInterface(&userInstruction, &arg1, &arg2);


        if (userInstruction == MVEC_INSTRUCTION) {
            clean(values, offsets);
            init(values, offsets, arg2, &tableSize);
            resize(offsets, tableSize, &vectorSize, arg1);
            changeDefaultValues(offsets, tableSize, &defaultValue, arg2);
        } else if (userInstruction == LEN_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                resize(offsets, tableSize, &vectorSize, arg1);
        } else if (userInstruction == DEF_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                addValue(values, offsets, &tableSize, vectorSize, arg1, arg2);
        } else if (userInstruction == PRINT_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                std::cout << getValues(values, offsets, defaultValue, vectorSize, tableSize) << std::endl;
        } else if (userInstruction == DEL_INSTRUCTION) {
            clean(values, offsets);
        }


    }
    return 0;
}
