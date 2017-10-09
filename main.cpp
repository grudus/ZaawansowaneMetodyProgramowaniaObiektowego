#include <iostream>
#include "RzadkiWektor.h"


int main() {
    std::cout << "Hello, we will start using vectors!" << std::endl;

    int* offsets;
    int* values;
    int tableSize;
    int vectorSize = 20;
    int defaultValue = 0;


    init(values, offsets, defaultValue, &tableSize);

    offsets[0] = 10;
    offsets[1] = 15;
    offsets[2] = 17;
    values[0] = 222;
    values[1] = -13;
    values[2] = 15;

    std::string vall = getValues(values, offsets, defaultValue, vectorSize, tableSize);

    std::cout <<  vall << std::endl;

    return 0;
}