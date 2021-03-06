#include "SpareMatrix.h"

const std::string SpareMatrix::DEFAULT_NAME = "no_name";
const int SpareMatrix::DEFAULT_CELLS_TABLE_SIZE = 15;
const double SpareMatrix::CELLS_TABLE_SCALE = 1.5;

SpareMatrix::SpareMatrix() {
    this->name = DEFAULT_NAME;
    initCells();
    printCreation();
}

SpareMatrix::SpareMatrix(const std::string &name) {
    this->name = name;
    initCells();
    printCreation();
}

SpareMatrix::SpareMatrix(const SpareMatrix &copy) {
    this->name = copy.getName() + "_copy";
    this->numberOfDimensions = copy.numberOfDimensions;
    this->defaultValue = copy.defaultValue;
    copyCells(copy);
    copyDimensionSizes(copy);
    printCreation();
}

void SpareMatrix::copyDimensionSizes(const SpareMatrix &copy) {
    dimensionSizes = new int[copy.numberOfDimensions];
    for (int i = 0; i < numberOfDimensions; i++)
        dimensionSizes[i] = copy.dimensionSizes[i];
}

void SpareMatrix::copyCells(const SpareMatrix &copy) {
    cellsTableSize = copy.cellsTableSize;
    cells = new SparseCell *[copy.cellsTableSize];
    for (int i = 0; i < cellsTableSize; i++) {
        auto copyCell = copy.cells[i];
        cells[i] = copyCell == nullptr ? nullptr : new SparseCell(copyCell);
    }
}

SpareMatrix::SpareMatrix(const std::string &name, int numberOfDimensions, int *dimensions, int defaultValue) {
    if (name.empty())
        this->name = DEFAULT_NAME;
    else
        this->name = name;
    this->numberOfDimensions = numberOfDimensions;
    this->dimensionSizes = dimensions;
    this->defaultValue = defaultValue;
    initCells();
    printCreation();
}

SpareMatrix::~SpareMatrix() {
    for (int i = 0; i < cellsTableSize; i++)
        delete cells[i];
    delete[] cells;
    delete[] dimensionSizes;
    std::cout << "Destroy [" << name << "]" << std::endl;
}

void SpareMatrix::printCreation() {
    std::cout << "Create [" << this->name << "]" << std::endl;
}

std::string SpareMatrix::getName() const {
    return this->name;
}

void SpareMatrix::initCells() {
    cellsTableSize = DEFAULT_CELLS_TABLE_SIZE;
    cells = new SparseCell *[cellsTableSize];
    for (int i = 0; i < cellsTableSize; i++)
        cells[i] = nullptr;
}

std::string SpareMatrix::getDimensionsString() const {
    std::string string = "[";
    for (int i = 0; i < numberOfDimensions; i++) {
        string += std::to_string(dimensionSizes[i]);
        if (i < numberOfDimensions - 1)
            string += ", ";
    }
    string += "]";
    return string;
}

void SpareMatrix::setValue(int *coordinates, int value) {
    int index = findIndexOfCellWithCoordinates(coordinates);
    if (index == cellsTableSize)
        resizeTable();
    cells[index] = new SparseCell(numberOfDimensions, coordinates, value);
}

int SpareMatrix::getValue(const int *coordinates) const {
    int index = findIndexOfCellWithCoordinates(coordinates);
    if (index == cellsTableSize || cells[index] == nullptr)
        return defaultValue;
    return cells[index]->value;
}

int SpareMatrix::findIndexOfCellWithCoordinates(const int *coordinates) const {
    int indexOfOldValue = getIndexIfValueExists(coordinates);

    if (indexOfOldValue >= 0) {
        return indexOfOldValue;
    }

    int freeIndex = cellsTableSize;
    for (int i = 0; i < freeIndex; i++)
        if (cells[i] == nullptr)
            freeIndex = i;

    return freeIndex;
}

int SpareMatrix::getIndexIfValueExists(const int *coordinates) const {
    int index = -1;
    for (int i = 0; i < cellsTableSize && index == -1; i++) {
        SparseCell *cell = cells[i];
        if (cell != nullptr) {
            bool coordinatesAreTheSame = true;
            for (int j = 0; j < cell->dimensions && coordinatesAreTheSame; j++) {
                if (coordinates[j] != cell->coordinates[j])
                    coordinatesAreTheSame = false;
            }
            if (coordinatesAreTheSame)
                index = i;
        }
    }
    return index;
}

void SpareMatrix::resizeTable() {
    int newSize = (int) (cellsTableSize * CELLS_TABLE_SCALE);
    SparseCell **newCells = new SparseCell *[newSize];

    for (int i = 0; i < newSize; i++) {
        if (i < cellsTableSize)
            newCells[i] = cells[i];
        else
            newCells[i] = nullptr;
    }

    delete[] this->cells;
    this->cellsTableSize = newSize;
    this->cells = newCells;
}

int SpareMatrix::getNumberOfDimensions() const {
    return this->numberOfDimensions;
}

std::string SpareMatrix::toString() const {
    std::string string = "size: ";
    string += getDimensionsString();
    string += " values: ";
    string += getValuesString();


    return string;
}

std::string SpareMatrix::getValuesString() const {
    int currentIndexes[numberOfDimensions];
    std::string string;
    for (int i = 0; i < numberOfDimensions; i++) currentIndexes[i] = 0;

    int index = numberOfDimensions - 1;
    while (currentIndexes[0] < dimensionSizes[0]) {
        string += coordinatesToString(currentIndexes);
        string += ":";
        string += std::to_string(getValue(currentIndexes));
        string += "; ";
        currentIndexes[index]++;
        changeBackwardValuesIfNeeded(currentIndexes, index);
    }

    return string;
}

void SpareMatrix::reverse(int value) {
    int currentIndexes[numberOfDimensions];
    for (int i = 0; i < numberOfDimensions; i++) currentIndexes[i] = 0;
    int index = numberOfDimensions - 1;

    while (currentIndexes[0] < dimensionSizes[0]) {
        if (isDefaultValue(currentIndexes))
            setValue(currentIndexes, value);
        else
            setValue(currentIndexes, defaultValue);

        currentIndexes[index]++;
        changeBackwardValuesIfNeeded(currentIndexes, index);
    }
}

std::string SpareMatrix::coordinatesToString(int *coordinates) const {
    std::string string = "[";
    for (int i = 0; i < numberOfDimensions; i++) {
        string += std::to_string(coordinates[i]);
        if (i < numberOfDimensions - 1)
            string += ", ";
    }
    string += "]";
    return string;
}

void SpareMatrix::changeBackwardValuesIfNeeded(int *coordinates, int index) const {
    if (index != 0 && coordinates[index] == dimensionSizes[index]) {
        coordinates[index] = 0;
        coordinates[index - 1]++;
        changeBackwardValuesIfNeeded(coordinates, index - 1);
    }
}

void SpareMatrix::rename(std::string name) {
    this->name = name;
}

int *SpareMatrix::getDimensionsSizes() const {
    return dimensionSizes;
}

bool SpareMatrix::isDefaultValue(const int *coordinates) const {
    return getValue(coordinates) == SpareMatrix::defaultValue;
}
