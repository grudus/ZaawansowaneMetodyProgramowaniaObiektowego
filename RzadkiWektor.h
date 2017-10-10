#include <string>
#include <algorithm>
#include <iterator>

#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H

#define VECTOR_TYPE int

#define NO_ERROR 0
#define INVALID_SIZE (-1)
#define VECTOR_NOT_CLEAN (-2)
#define VECTOR_TOO_SMALL (-3)

#define _INVALID_SIZE "INVALID SIZE"

static const int DEFAULT_SIZE = 10;
static const double RESIZE_SCALE = 1.5;
static const int OFFSET_EMPTY = -1;
static const std::string LENGTH_TEXT = "len: ";
static const std::string VALUES_TEXT = " values: ";


int init(VECTOR_TYPE*& values, int*& offsets, VECTOR_TYPE defaultValue, int* tableSize);

std::string getValues(const VECTOR_TYPE* values, const int* offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize);

int changeDefaultValues(const int* offsets, int tableSize, int* newValue, int value);

int addValue(VECTOR_TYPE*& values, int*& offsets, int* tableSize, int vectorSize, int position, VECTOR_TYPE newValue);

int clean(VECTOR_TYPE*& values, int*& offsets);

int resize(const VECTOR_TYPE* values, const int* offsets, int *tableSize, int *currentVectorSize, int newVectorSize);
#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
