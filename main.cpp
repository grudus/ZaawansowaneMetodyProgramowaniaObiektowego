#include <iostream>
#include "RzadkiWektor.h"
#include "UserInterface.h"


int main() {
    std::cout << "Hello, we will start using vectors!" << std::endl;

    int *offsets = nullptr;
    int *values = nullptr;
    int tableSize;
    int vectorSize = 20;
    int defaultValue = 0;


    std::string function;
    int arg1, arg2;

    while (function != "quit") {

        showInterface(&function, &arg1, &arg2);


        if (function == POSSIBLE_FUNCTIONS[0]) {
            clean(values, offsets);
            init(values, offsets, arg2, &tableSize);
            resize(values, offsets, &tableSize, &vectorSize, arg1);
            changeDefaultValues(offsets, tableSize, &defaultValue, arg2);
            std::cout << getValues(values, offsets, defaultValue, vectorSize, tableSize) << std::endl;
        } else if (function == POSSIBLE_FUNCTIONS[1]) {
            resize(values, offsets, &tableSize, &vectorSize, arg1);
            std::cout << getValues(values, offsets, defaultValue, vectorSize, tableSize) << std::endl;
        } else if (function == POSSIBLE_FUNCTIONS[2]) {
            addValue(values, offsets, &tableSize, vectorSize, arg1, arg2);
            std::cout << getValues(values, offsets, defaultValue, vectorSize, tableSize) << std::endl;
        }

    }
    return 0;
}
