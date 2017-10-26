#include "SparseCell.h"


const int SparseCell::DEFAULT_TABLE_SIZE = 10;
const int SparseCell::NO_OFFSET = -1;
const double SparseCell::RESIZE_SCALE = 1.5;


SparseCell::SparseCell() {
    vectorSize = DEFAULT_TABLE_SIZE;
    initValueVectors();
}


SparseCell::SparseCell(int vectorSize, int defaultValue) {
    this->vectorSize = vectorSize;
    this->defaultValue = defaultValue;
    initValueVectors();
}

void SparseCell::initValueVectors() {
    tableSize = DEFAULT_TABLE_SIZE;
    offsets = new int[tableSize];
    values = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
        offsets[i] = NO_OFFSET;
}

int SparseCell::getValue(int index) {
    for (int i = 0; i < tableSize; i++)
        if (offsets[i] == index)
            return values[i];
    return defaultValue;
}

void SparseCell::setValue(int index, int value) {
    if (value == defaultValue)
        addDefaultValue(index);
    else
        addNotDefaultValue(index, value);
}

void SparseCell::addDefaultValue(int index) {
    bool defaultValueAtPosition = true;
    for (int i = 0; i < tableSize && defaultValueAtPosition; i++)
        if (offsets[i] == index) {
            offsets[i] = this->NO_OFFSET;
            defaultValueAtPosition = false;
        }
}

void SparseCell::addNotDefaultValue(int position, int value) {
    int index = findFreeIndex();
    if (index == tableSize)
        resizeTables();

    offsets[index] = position;
    values[index] = value;
}

int SparseCell::findFreeIndex() {
    int index = tableSize;
    for (int i = 0; i < tableSize && index == tableSize; i++) {
        if (offsets[i] == NO_OFFSET) index = i;
    }
    return index;
}

void SparseCell::resizeTables() {
    int newSize = (int) (tableSize * RESIZE_SCALE);
    int *newOffsets = new int[newSize];
    int *newValues = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        if (i < tableSize) {
            newValues[i] = values[i];
            newOffsets[i] = offsets[i];
        } else
            newOffsets[i] = NO_OFFSET;
    }

    delete[] values;
    delete[] offsets;

    values = newValues;
    offsets = newOffsets;
    tableSize = newSize;
}
