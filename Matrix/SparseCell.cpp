#include "SparseCell.h"


SparseCell::SparseCell(int dimensions, int *coordinates, int value) {
    this->dimensions = dimensions;
    this->value = value;
    copyCoordinates(coordinates);
}

SparseCell::~SparseCell() {
    delete[] coordinates;
    std::cout << "DELETE SPARSE CCELL" << std::endl;
}

SparseCell::SparseCell(SparseCell *copy) {
    this->dimensions = copy->dimensions;
    this->value = copy->value;
    copyCoordinates(copy);
}

void SparseCell::copyCoordinates(SparseCell *copy) {
    copyCoordinates(copy->coordinates);
}

void SparseCell::copyCoordinates(const int *coordinatesToCopy) {
    this->coordinates = new int[dimensions];
    for (int i = 0; i < dimensions; i++)
        this->coordinates[i] = coordinatesToCopy[i];
}
