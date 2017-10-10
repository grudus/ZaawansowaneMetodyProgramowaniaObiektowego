#include "RzadkiWektor.h"

void resizeTablesIfNeeded(const int *pInt, const int *offsets, int *size);

int findFreeOffsetIndex(int *&pInt);

int init(VECTOR_TYPE *&values, int *&offsets, VECTOR_TYPE defaultValue, int *tableSize) {
    *tableSize = DEFAULT_SIZE;
    values = new int[*tableSize];
    offsets = new int[*tableSize];

    for (int i = 0; i < DEFAULT_SIZE; i++) {
        values[i] = defaultValue;
        offsets[i] = OFFSET_EMPTY;
    }

    return NO_ERROR;
}

std::string
getValues(const VECTOR_TYPE *values, const int *offsets, VECTOR_TYPE defaultValue, int vectorSize, int tableSize) {
    if (vectorSize < 0 || tableSize < 0)
        return _INVALID_SIZE;

    std::string string = LENGTH_TEXT + std::to_string(vectorSize) + VALUES_TEXT;

    VECTOR_TYPE *valuesArray = new VECTOR_TYPE[vectorSize];
    std::fill_n(valuesArray, vectorSize, defaultValue);
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] != OFFSET_EMPTY)
            valuesArray[offsets[i]] = values[i];

    for (int i = 0; i < vectorSize; i++)
        string += std::to_string(valuesArray[i]) + (i == vectorSize - 1 ? " " : ", ");

    delete[] valuesArray;
    return string;
}

int changeDefaultValues(const int *offsets, int tableSize, int *newValue, int value) {
    bool vectorClean = true;
    for (int i = 0; i < tableSize; i++)
        vectorClean = vectorClean && offsets[i] == OFFSET_EMPTY;

    if (vectorClean) *newValue = value;
    return vectorClean ? NO_ERROR : VECTOR_NOT_CLEAN;
}


void resizeTables(int *&values, int *&offsets, int *tableSize) {
    int newSize = (int) (*tableSize * RESIZE_SCALE);
    VECTOR_TYPE *newValues = new VECTOR_TYPE[newSize];
    int *newOffsets = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        if (i < *tableSize) {
            newValues[i] = values[i];
            newOffsets[i] = offsets[i];
        } else {
            newValues[i] = 0;
            newOffsets[i] = OFFSET_EMPTY;
        }
    }

    values = newValues;
    offsets = newOffsets;
    *tableSize = newSize;
}

int findFreeIndex(const int *offsets, int tableSize) {
    int index = tableSize;
    for (int i = 0; i < tableSize && index == tableSize; i++) {
        if (offsets[i] == OFFSET_EMPTY) index = i;
    }
    return index;
}


int addValue(VECTOR_TYPE *&values, int *&offsets, int *tableSize, int vectorSize, int position,
             VECTOR_TYPE newValue) {
    if (vectorSize < 0 || *tableSize < 0)
        return INVALID_SIZE;

    if (position >= vectorSize)
        return VECTOR_TOO_SMALL;

    int index = findFreeIndex(offsets, *tableSize);
    if (index == *tableSize)
        resizeTables(values, offsets, tableSize);

    offsets[index] = position;
    values[index] = newValue;

    return NO_ERROR;
}


//TODO implement
int resize(const VECTOR_TYPE *values, const int *offsets, int *tableSize, int *currentVectorSize, int newVectorSize) {
    *currentVectorSize = newVectorSize;
    return NO_ERROR;
}

int clean(VECTOR_TYPE *&values, int *&offsets) {
    if (values != nullptr) {
        delete[] values;
        values = nullptr;
    }
    if (offsets != nullptr) {
        delete[] offsets;
        offsets = nullptr;
    }
}