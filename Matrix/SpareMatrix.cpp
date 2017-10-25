#include "SpareMatrix.h"

const std::string SpareMatrix::DEFAULT_NAME = "no_name";


SpareMatrix::SpareMatrix() {
    SpareMatrix::name = DEFAULT_NAME;
    initCells(0);
    printCreation();
}

SpareMatrix::SpareMatrix(const std::string &name) {
    SpareMatrix::name = name;
    initCells(0);
    printCreation();
}

SpareMatrix::SpareMatrix(const SpareMatrix &copy) {
    SpareMatrix::name = copy.getName() + "_copy";
    initCells(0);
    printCreation();
}

SpareMatrix::SpareMatrix(const std::string &name, int numberOfDimensions, const int* dimensions, int defaultValue) {
    SpareMatrix::name = name;
    this->numberOfDimensions = numberOfDimensions;
    initCells(numberOfDimensions);
    for (int i = 0; i < numberOfDimensions; i++) {
        cells[i] = new SparseCell(dimensions[i], defaultValue);
    }
    printCreation();
}

SpareMatrix::~SpareMatrix() {
    delete[] cells;
    std::cout << "Destroy [" << name << "]" << std::endl;
}

void SpareMatrix::printCreation() {
    std::cout << "Create [" << SpareMatrix::name << "]" << std::endl;
}

std::string SpareMatrix::getName() const {
    return SpareMatrix::name;
}

void SpareMatrix::initCells(int size) { cells = new SparseCell*[size]; }

void SpareMatrix::printSizes() const {
    std::cout << "[";
    for (int i = 0; i < numberOfDimensions; i++) {
        std::cout << cells[i]->vectorSize;
        if (i < numberOfDimensions -1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
