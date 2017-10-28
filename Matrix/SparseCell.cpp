#include "SparseCell.h"


SparseCell::SparseCell(int dimensions, int *coordinates, int value) {
    this->dimensions = dimensions;
    this->coordinates = coordinates;
    this->value = value;
}

SparseCell::~SparseCell() {
    std::cout << "DELETE SPARSE CCELL" << std::endl;
    delete[] coordinates;
}
