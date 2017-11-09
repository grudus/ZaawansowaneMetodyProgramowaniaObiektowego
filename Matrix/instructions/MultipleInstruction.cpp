#include "MultipleInstruction.h"

MultipleInstruction::MultipleInstruction(std::vector<SpareMatrix *> *matrixes) : Instruction(matrixes) {}

int MultipleInstruction::handle() {
    int firstIndex = getIntegerInput();
    int secondIndex = getIntegerInput();
    if (!(indexIsValid(firstIndex) && indexIsValid(secondIndex))) {
        handleInvalidIndex(firstIndex > secondIndex ? secondIndex : firstIndex);
        return -1;
    }

    int numberOfDimensions1 = (*matrixes)[firstIndex]->getNumberOfDimensions();
    int numberOfDimensions2 = (*matrixes)[secondIndex]->getNumberOfDimensions();

    if (numberOfDimensions1 != 2 || numberOfDimensions2 != 2) {
        handleInvalidInput("Invalid number of dimensions! Must be 2, but was: "
                           + std::to_string(numberOfDimensions1) + ", " + std::to_string(numberOfDimensions2));
        return -1;
    }

    auto sizes1 = (*matrixes)[firstIndex]->getDimensionsSizes();
    auto sizes2 = (*matrixes)[secondIndex]->getDimensionsSizes();

    if (sizes1[1] != sizes2[0]) {
        handleInvalidInput("First matrix has to be as big as the second one!");
        return -1;
    }

    multipleMatrixes(firstIndex, secondIndex, sizes1, sizes2);
    return 0;
}

void MultipleInstruction::multipleMatrixes(int index, int secondIndex, const int *sizes1, const int *sizes2) const {
    auto matrix1 = (*matrixes)[index];
    auto matrix2 = (*matrixes)[secondIndex];

    int r1 = sizes1[0];
    int c1 = sizes1[1];
    int c2 = sizes2[1];

    auto multipledMatrix = new SpareMatrix(matrix1->getName() + " x " + matrix2->getName(), 2, new int[2]{r1, c2}, 0);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int coordinates[] = {i, j};
            for (int k = 0; k < c1; k++) {
                int *cord1 = new int[2]{i, k};
                int *cord2 = new int[2]{k, j};
                int val1 = matrix1->getValue(cord1);
                int val2 = matrix2->getValue(cord2);

                multipledMatrix->setValue(coordinates, multipledMatrix->getValue(coordinates) + val1 * val2);

                delete[] cord1;
                delete[] cord2;
            }
        }
    }

    matrixes->push_back(multipledMatrix);
}
