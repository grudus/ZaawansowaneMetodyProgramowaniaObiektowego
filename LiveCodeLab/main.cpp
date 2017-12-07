#include <iostream>
#include "CiCanCopy.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    CiCanCopy arg0, arg1, concat;
    arg0 = "ala";
    arg1 = "ma kota";
    concat = arg0 + arg1;

    arg0.print();
    arg1.print();
    concat.print();


    return 0;
}