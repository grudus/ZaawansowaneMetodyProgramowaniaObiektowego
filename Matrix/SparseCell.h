#ifndef MATRIX_SPARSECELL_H
#define MATRIX_SPARSECELL_H

#include <vector>
#include "SpareMatrix.h"

class SparseCell {
    friend class SpareMatrix;

public:
    explicit SparseCell(int dimensions, int *coordinates, int value);

    ~SparseCell();

private:
    int *coordinates;
    int dimensions;
    int value;
};


#endif //MATRIX_SPARSECELL_H
