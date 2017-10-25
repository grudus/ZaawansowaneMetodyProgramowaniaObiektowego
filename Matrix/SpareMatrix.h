#ifndef MATRIX_SPAREMATRIX_H
#define MATRIX_SPAREMATRIX_H

#include <string>
#include <iostream>
#include "SparseCell.h"


class SpareMatrix {
public:
    SpareMatrix();
    explicit SpareMatrix(const std::string &name);
    SpareMatrix(const SpareMatrix &copy);

    std::string getName() const;

    ~SpareMatrix();

private:
    void printCreation();

    static const std::string DEFAULT_NAME;
    std::string name;

};


#endif //MATRIX_SPAREMATRIX_H
