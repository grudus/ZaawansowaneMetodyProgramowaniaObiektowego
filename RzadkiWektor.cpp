#include "RzadkiWektor.h"

void init(VECTOR_TYPE*& values, int*& offsets, VECTOR_TYPE defaultValue, int* tableSize) {
    *tableSize = DEFAULT_SIZE;
    values = new int [*tableSize];
    offsets = new int [*tableSize];

    for (int i = 0; i < DEFAULT_SIZE; i++) {
        values[i] = defaultValue;
        offsets[i] = 0;
    }
}

std::string getValues(VECTOR_TYPE* values, int* offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize) {
    std::string string = "len: " + std::to_string(vectorSize) + " values: ";

    int currentOffsetIndex = 0;

    for (int i = 0; i < vectorSize; i++) {

        if (currentOffsetIndex < tableSize && offsets[currentOffsetIndex] != 0 && offsets[currentOffsetIndex] == i) {
            string += std::to_string(values[currentOffsetIndex]);
            ++currentOffsetIndex;
        }
        else
            string += std::to_string(defaultValue);

        if (i < vectorSize - 1) string += ", ";
    }

    return string;
}


