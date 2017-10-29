#include "DefInstruction.h"

DefInstruction::DefInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int DefInstruction::handle() {
    int matrixIndex = getIntegerInput();

    if (!indexIsValid(matrixIndex)) {
        handleInvalidIndex(matrixIndex);
        return -1;
    }

    SpareMatrix *matrix = (*matrixes)[matrixIndex];
    int dimensions = matrix->getNumberOfDimensions();
    int *coordinates = new int[dimensions];

    for (int i = 0; i < dimensions; i++)
        coordinates[i] = getIntegerInput();
    int value = getIntegerInput();

    if (invalidCoordinates(coordinates, matrix)) {
        std::cerr << "Invalid coordinates" << std::endl;
        delete[] coordinates;
        return -1;
    }

    matrix->setValue(coordinates, value);
}

bool DefInstruction::invalidCoordinates(const int *coordinates, SpareMatrix *matrix) {
    bool valid = true;
    for (int i = 0; i < matrix->getNumberOfDimensions(); i++)
        valid = valid && coordinates[i] < matrix->getDimensionsSizes()[i];
    return !valid;
}
