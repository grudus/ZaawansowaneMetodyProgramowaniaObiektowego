#ifndef MATRIX_SPARSECELL_H
#define MATRIX_SPARSECELL_H

#include <vector>
#include "SpareMatrix.h"

class SparseCell {
    friend class SpareMatrix;

public:
    explicit SparseCell();
    explicit SparseCell(int vectorSize, int defaultValue);


private:
    static const int DEFAULT_TABLE_SIZE = 10;
    static const int NO_OFFSET = -1;
    std::vector<int> offsets;
    std::vector<int> values;
    int tableSize = DEFAULT_TABLE_SIZE;
    int vectorSize;
    int defaultValue;

    void initValueVectors();
};


#endif //MATRIX_SPARSECELL_H
