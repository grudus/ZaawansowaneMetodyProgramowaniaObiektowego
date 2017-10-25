#include "SparseCell.h"

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
    offsets = std::vector<int>(static_cast<unsigned long>(tableSize));
    values = std::vector<int>(static_cast<unsigned long>(tableSize));
}
