#include <iostream>
#include "RzadkiWektor.h"
#include "UserInterface.h"


void catchErrors(int status);

bool isVectorValid(const int *offsets, const int *values);

int main() {
    std::cout << "Hello, we will start using vectors!" << std::endl;

    int *offsets = nullptr;
    int *values = nullptr;
    int tableSize = -1;
    int vectorSize = -1;
    int defaultValue = 0;


    std::string userInstruction;
    int arg1, arg2;

    while (userInstruction != QUIT_INSTRUCTION) {
        showInterface(&userInstruction, &arg1, &arg2);


        if (userInstruction == MVEC_INSTRUCTION) {
            clean(values, offsets);
            init(values, offsets, &tableSize);
            catchErrors(resize(offsets, tableSize, &vectorSize, arg1));
            catchErrors(changeDefaultValues(offsets, tableSize, &defaultValue, arg2));
        } else if (userInstruction == LEN_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                catchErrors(resize(offsets, tableSize, &vectorSize, arg1));
        } else if (userInstruction == DEF_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                catchErrors(addValue(values, offsets, &tableSize, vectorSize, arg1, defaultValue, arg2));
        } else if (userInstruction == PRINT_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                std::cout << getValues(values, offsets, defaultValue, vectorSize, tableSize) << std::endl;
        } else if (userInstruction == DEL_INSTRUCTION) {
            clean(values, offsets);
        } else if (userInstruction == RESET_INSTRUCTION) {
            if (isVectorValid(offsets, values))
                catchErrors(changeDefaultValues(offsets, tableSize, &defaultValue, arg1));
        } else if (userInstruction == READ_INSTRUCTION)
            if (isVectorValid(offsets, values))
                std::cout << readValue(values, offsets, tableSize, vectorSize, defaultValue, arg1) << std::endl;

    }
    return 0;
}


bool isVectorValid(const int *offsets, const int *values) {
    bool valid = offsets != nullptr && values != nullptr;
    if (!valid)
        std::cerr << "You should initialize vector first (with mvec)!\n";
    return valid;
}

void catchErrors(int status) {
    switch (status) {
        case NEGATIVE_NUMBER:
            std::cerr << "Cannot pass negative numbers" << std::endl;
            break;
        case VECTOR_NOT_CLEAN:
            std::cerr << "Cannot change default values when vector was touched" << std::endl;
            break;
        case VECTOR_TOO_SMALL:
            std::cerr << "Vector is too small for this value" << std::endl;
            break;
        case NO_ERROR:
            break;
        default:
            std::cerr << "Please reenter data" << std::endl;
    }
}
