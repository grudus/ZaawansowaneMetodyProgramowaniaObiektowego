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

SparseCell::SparseCell(SparseCell *copy) {
    this->dimensions = copy->dimensions;
    this->value = copy->value;
    copyCoordinates(copy);
}

void SparseCell::copyCoordinates(SparseCell *copy) {
    coordinates = new int[dimensions];
    for (int i = 0; i < dimensions; i++)
        coordinates[i] = copy->coordinates[i];
}
