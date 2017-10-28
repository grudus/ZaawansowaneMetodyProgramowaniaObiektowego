//
// Created by grudus on 10/26/17.
//

#include "DefInstruction.h"

DefInstruction::DefInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int DefInstruction::handle() {
    int matrixIndex = getIntegerInput();
    SpareMatrix *matrix = (*matrixes)[matrixIndex];
    int dimensions = matrix->getNumberOfDimensions();
    int coordinates[dimensions];

    for (int i = 0; i < dimensions; i++)
        coordinates[i] = getIntegerInput();
    int value = getIntegerInput();

    matrix->setValue(coordinates, value);
}
