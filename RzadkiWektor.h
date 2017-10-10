#include <string>
#include <algorithm>
#include <iterator>

#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H

#define NO_ERROR 0
#define INVALID_SIZE (-1)
#define VECTOR_NOT_CLEAN (-2)
#define VECTOR_TOO_SMALL (-3)


#define _INVALID_SIZE "INVALID SIZE"

const int DEFAULT_SIZE = 10;
const double RESIZE_SCALE = 1.5;
const int OFFSET_EMPTY = -1;

#define VECTOR_TYPE int

int init(VECTOR_TYPE*& values, int*& offsets, VECTOR_TYPE defaultValue, int* tableSize);
std::string getValues(const VECTOR_TYPE* values, const int* offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize);
int changeDefaultValues(const int* offsets, int tableSize, int* newValue, int value);

int addValue(VECTOR_TYPE*& values, int*& offsets, int* tableSize, int vectorSize, int position, VECTOR_TYPE newValue);


#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
