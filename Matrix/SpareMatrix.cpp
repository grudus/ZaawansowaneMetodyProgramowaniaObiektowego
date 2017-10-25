#include "SpareMatrix.h"

const std::string SpareMatrix::DEFAULT_NAME = "no_name";


SpareMatrix::SpareMatrix() {
    SpareMatrix::name = DEFAULT_NAME;
    printCreation();
}

SpareMatrix::SpareMatrix(const std::string& name) {
    SpareMatrix::name = name;
    printCreation();
}

SpareMatrix::SpareMatrix(const SpareMatrix &copy) {
    SpareMatrix::name = copy.getName() + "_copy";
    printCreation();
}

SpareMatrix::~SpareMatrix() {
    std::cout << "Destroy [" << name << "]" << std::endl;
    name = nullptr;
}

void SpareMatrix::printCreation() {
    std::cout << "Create [" << SpareMatrix::name << "]" << std::endl;
}

std::string SpareMatrix::getName()const {
    return SpareMatrix::name;
}
