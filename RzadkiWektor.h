#include <string>

#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H

#define INVALID_SIZE (-1)
#define VECTOR_NOT_CLEAN (-2)
#define OK 0

const int DEFAULT_SIZE = 10;

#define VECTOR_TYPE int

void init(VECTOR_TYPE*& values, int*& offsets, VECTOR_TYPE defaultValue, int* tableSize);

std::string getValues(VECTOR_TYPE* values, int* offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize);

#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
