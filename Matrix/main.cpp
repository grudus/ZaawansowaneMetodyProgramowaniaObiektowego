#include <iostream>
#include "SpareMatrix.h"
#include <vector>

SpareMatrix* createMatrix(int numberOfDimensions, const int* dimensions, int defaultValue, const std::string &name);

void printMatrixes(std::vector<SpareMatrix*> matrixes);

int main() {
    auto *matrixes = new std::vector<SpareMatrix*>();

    SpareMatrix* matrix = createMatrix(3, new int[3] {20,30,40}, 1, "Pierwsza");

    matrixes->push_back(matrix);

    printMatrixes(*matrixes);

    delete matrix;


    return 0;
}

SpareMatrix *createMatrix(int numberOfDimensions, const int *dimensions, int defaultValue, const std::string &name) {
    return new SpareMatrix(name, numberOfDimensions, dimensions, defaultValue);
}

void printMatrixes(std::vector<SpareMatrix *> matrixes) {
    std::cout << matrixes.size() << " matrices:" << std::endl;
    for (int i = 0; i < matrixes.size(); i++) {
        std::cout << "[" << i << "] \"";
        std::cout << matrixes[i]->getName() << "\" size: ";
        matrixes[i]->printSizes();
    }
}
