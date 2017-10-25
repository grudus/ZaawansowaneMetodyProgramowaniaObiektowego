#include <iostream>
#include "SpareMatrix.h"
#include <vector>
int main() {
    std::string name = "Fajna moja taka matryca";

    auto *matrix = new SpareMatrix(name);

    matrix->getName();

    delete matrix;

    return 0;
}