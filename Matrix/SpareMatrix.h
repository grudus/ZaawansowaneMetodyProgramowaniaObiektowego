#ifndef MATRIX_SPAREMATRIX_H
#define MATRIX_SPAREMATRIX_H

#include "SparseCell.h"
#include <string>
#include <iostream>

class SparseCell;


class SpareMatrix {
public:
    SpareMatrix();

    explicit SpareMatrix(const std::string &name);

    SpareMatrix(const SpareMatrix &copy);

    SpareMatrix(const std::string &name, int numberOfDimensions, int *dimensions, int defaultValue);


    std::string getName() const;
    void rename(std::string name);

    std::string getDimensionsString() const;

    void setValue(int *coordinates, int value);

    int getValue(int *coordinates)const;

    int getNumberOfDimensions() const;

    std::string toString() const;

    int* getDimensionsSizes() const;

    ~SpareMatrix();
private:
    static const std::string DEFAULT_NAME;
    static const double CELLS_TABLE_SCALE;
    static const int DEFAULT_CELLS_TABLE_SIZE;

    std::string name;
    int defaultValue;

    int numberOfDimensions;
    int *dimensionSizes;
    int cellsTableSize;
    SparseCell **cells;

    void initCells();

    void printCreation();

    int findIndexOfCellWithCoordinates(int *coordinates) const;

    int getIndexIfValueExists(int *coordinates) const;

    void resizeTable();

    std::string getValuesString() const;

    std::string coordinatesToString(int coordinates[]) const;

    void changeBackwardValuesIfNeeded(int coordinates[], int index) const;

    void copyCells(const SpareMatrix &copy);

    void copyDimensionSizes(const SpareMatrix &copy);
};


#endif //MATRIX_SPAREMATRIX_H
