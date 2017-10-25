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

    SpareMatrix(const std::string &name, int numberOfDimensions, const int *dimensions, int defaultValue);


    std::string getName() const;
    void printSizes() const;

    int getValue(int row, int column);

    ~SpareMatrix();

private:
    void printCreation();

    static const std::string DEFAULT_NAME;
    std::string name;
    SparseCell **cells;
    int numberOfDimensions;

    void initCells(int size);

    int setValue(int row, int column, int value);
};


#endif //MATRIX_SPAREMATRIX_H
