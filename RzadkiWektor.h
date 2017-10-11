#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H

#include <string>
#include <algorithm>
#include <iterator>

#define VECTOR_TYPE int

#define NO_ERROR 0
#define NEGATIVE_NUMBER (-1)
#define VECTOR_NOT_CLEAN (-2)
#define VECTOR_TOO_SMALL (-3)
#define INDEX_OUT_OF_BOUNDS (-4)

#define _INVALID_SIZE "INVALID SIZE"

static const int DEFAULT_SIZE = 10;
static const double RESIZE_SCALE = 1.5;
static const int OFFSET_EMPTY = -1;
static const std::string LENGTH_TEXT = "len: ";
static const std::string VALUES_TEXT = " values: ";


int init(VECTOR_TYPE*& values, int*& offsets, int* tableSize);

std::string getValues(const VECTOR_TYPE* values, const int* offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize);

int changeDefaultValues(const int* offsets, int tableSize, int* newValue, int value);

int addValue(VECTOR_TYPE*& values, int*& offsets, int* tableSize, int vectorSize, int position, VECTOR_TYPE defaultValue, VECTOR_TYPE newValue);

int clean(VECTOR_TYPE*& values, int*& offsets);

int resize(int* offsets, int tableSize, int *currentVectorSize, int newVectorSize);

VECTOR_TYPE readValue(const VECTOR_TYPE* values, const int* offsets, int tableSize, int vectorSize, VECTOR_TYPE defaultValue, int position);

#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_RZADKIWEKTOR_H
