#include "RzadkiWektor.h"


int findFreeIndex(const int *offsets, int tableSize);

void removeOffsetsAboveVectorSize(int *offsets, int tableSize, int newVectorSize);

int init(VECTOR_TYPE *&values, int *&offsets, int *tableSize) {
    *tableSize = DEFAULT_SIZE;
    values = new int[*tableSize];
    offsets = new int[*tableSize];

    for (int i = 0; i < DEFAULT_SIZE; i++)
        offsets[i] = OFFSET_EMPTY;

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
    for (int i = 0; i < tableSize && vectorClean; i++)
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
        } else
            newOffsets[i] = OFFSET_EMPTY;
    }

    values = newValues;
    offsets = newOffsets;
    *tableSize = newSize;
}

int addValue(VECTOR_TYPE *&values, int *&offsets, int *tableSize, int vectorSize, int position, VECTOR_TYPE defaultValue,
             VECTOR_TYPE newValue) {
    if (vectorSize < 0 || *tableSize < 0 || position < 0)
        return NEGATIVE_NUMBER;

    if (position >= vectorSize)
        return VECTOR_TOO_SMALL;

    int index = findFreeIndex(offsets, *tableSize);
    if (index == *tableSize)
        resizeTables(values, offsets, tableSize);

    offsets[index] = newValue == defaultValue ? OFFSET_EMPTY : position;
    values[index] = newValue;

    return NO_ERROR;
}


int findFreeIndex(const int *offsets, int tableSize) {
    int index = tableSize;
    for (int i = 0; i < tableSize && index == tableSize; i++) {
        if (offsets[i] == OFFSET_EMPTY) index = i;
    }
    return index;
}


int resize(int *offsets, int tableSize, int *currentVectorSize, int newVectorSize) {
    if (newVectorSize < 0)
        return NEGATIVE_NUMBER;

    if (newVectorSize < *currentVectorSize)
        removeOffsetsAboveVectorSize(offsets, tableSize, newVectorSize);


    *currentVectorSize = newVectorSize;
    return NO_ERROR;
}

void removeOffsetsAboveVectorSize(int *offsets, int tableSize, int newVectorSize) {
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] >= newVectorSize)
            offsets[i] = OFFSET_EMPTY;
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

VECTOR_TYPE readValue(const VECTOR_TYPE* values, const int* offsets, int tableSize, int vectorSize, VECTOR_TYPE defaultValue, int position) {
    if (position >= vectorSize)
        return INDEX_OUT_OF_BOUNDS;
    if (position < 0)
        return NEGATIVE_NUMBER;

    VECTOR_TYPE value = defaultValue;
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] == position)
            value = values[i];

    return value;
}
