#ifndef MATRIX_USERINTERFACE_H
#define MATRIX_USERINTERFACE_H

#include <iostream>
#include "SpareMatrix.h"


class UserInterface {
public:
    void showMenu();

    void readInstruction(std::vector<SpareMatrix *> *matrixes);
private:

};


#endif //MATRIX_USERINTERFACE_H
