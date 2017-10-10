#include <iostream>
#include "RzadkiWektor.h"


int main() {
    std::cout << "Hello, we will start using vectors!" << std::endl;

    int *offsets;
    int *values;
    int tableSize;
    int vectorSize = 20;
    int defaultValue = 0;


    init(values, offsets, defaultValue, &tableSize);

    addValue(values, offsets, &tableSize, vectorSize, 3, 12);
    addValue(values, offsets, &tableSize, vectorSize, 7, 555);
    addValue(values, offsets, &tableSize, vectorSize, 11, -114);
    addValue(values, offsets, &tableSize, vectorSize, 1, 666);



    std::string vall = getValues(values, offsets, defaultValue, vectorSize, tableSize);
    std::cout << vall << std::endl;

    return 0;
}