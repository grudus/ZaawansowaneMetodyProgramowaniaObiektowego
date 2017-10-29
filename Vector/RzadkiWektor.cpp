#include "RzadkiWektor.h"


int findFreeIndex(const int *offsets, int tableSize);

void removeOffsetsAboveVectorSize(int *offsets, int tableSize, int newVectorSize);

void addNotDefaultValue(int *&values, int *&offsets, int *tableSize, int position, int newValue);

void addDefaultValue(int *&offsets, int tableSize, int position);

int init(int *& values, int *&offsets, int *tableSize) {
    *tableSize = DEFAULT_SIZE;
    values = new int[*tableSize];
    offsets = new int[*tableSize];

    for (int i = 0; i < DEFAULT_SIZE; i++)
        offsets[i] = OFFSET_EMPTY;

    return NO_ERROR;
}

std::string
getValues(const int *values, const int *offsets, int defaultValue, int vectorSize, int tableSize) {
    if (vectorSize < 0 || tableSize < 0)
        return _INVALID_SIZE;

    std::string string = LENGTH_TEXT + std::to_string(vectorSize) + VALUES_TEXT;

    int *valuesArray = new int[vectorSize];
    std::fill_n(valuesArray, vectorSize, defaultValue);
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] != OFFSET_EMPTY)
            valuesArray[vectorSize - 1 - offsets[i]] = values[i];

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
    int *newValues = new int[newSize];
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

int
addValue(int *&values, int *&offsets, int *tableSize, int vectorSize, int position, int defaultValue,
         int newValue) {
    if (vectorSize < 0 || *tableSize < 0 || position < 0)
        return NEGATIVE_NUMBER;

    if (position >= vectorSize)
        return VECTOR_TOO_SMALL;

    if (newValue == defaultValue)
        addDefaultValue(offsets, *tableSize, position);
    else
        addNotDefaultValue(values, offsets, tableSize, position, newValue);

    return NO_ERROR;
}

void addDefaultValue(int *&offsets, int tableSize, int position) {
    bool defaultValueAtPosition = true;
    for (int i = 0; i < tableSize && defaultValueAtPosition; i++)
        if (offsets[i] == position) {
            offsets[i] = OFFSET_EMPTY;
            defaultValueAtPosition = false;
        }

}

void addNotDefaultValue(int *&values, int *&offsets, int *tableSize, int position, int newValue) {
    int index = findFreeIndex(offsets, *tableSize);
    if (index == *tableSize)
        resizeTables(values, offsets, tableSize);

    offsets[index] = position;
    values[index] = newValue;
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

int clean(int *&values, int *&offsets) {
    if (values != nullptr) {
        delete[] values;
        values = nullptr;
    }
    if (offsets != nullptr) {
        delete[] offsets;
        offsets = nullptr;
    }
}

int
readValue(const int *values, const int *offsets, int tableSize, int vectorSize, int defaultValue,
          int position) {
    if (position >= vectorSize)
        return INDEX_OUT_OF_BOUNDS;
    if (position < 0)
        return NEGATIVE_NUMBER;

    int value = defaultValue;
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] == position)
            value = values[i];

    return value;
}
