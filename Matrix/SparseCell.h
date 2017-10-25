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
    static const double RESIZE_SCALE = 1.5;
    int *offsets;
    int *values;
    int tableSize = DEFAULT_TABLE_SIZE;
    int vectorSize;
    int defaultValue;

    void initValueVectors();

    int getValue(int index);

    void setValue(int index, int value);

    void addDefaultValue(int index);

    void addNotDefaultValue(int index, int value);

    int findFreeIndex();

    void resizeTables();
};


#endif //MATRIX_SPARSECELL_H
