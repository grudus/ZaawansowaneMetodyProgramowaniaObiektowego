#ifndef GENERICPROGRAMMING_RANDOMRPNELEMCREATOR_H
#define GENERICPROGRAMMING_RANDOMRPNELEMCREATOR_H


#include "../rpn/RpnElem.h"
#include "../rpn/RpnElemFactory.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "../rpn/operators.h"

class RandomRpnElemCreator {

public:
    RandomRpnElemCreator() {
        srand(time(nullptr));
    }

    RpnElem *randomElem(const RpnElem *type);
    RpnOperator * randomOperator();

    RpnElem *createVarOrConst();

private:
    const std::string randomOperator(int numberOfChildren);

    const std::string randomVariable();

    const std::string randomNumber();
};


#endif //GENERICPROGRAMMING_RANDOMRPNELEMCREATOR_H
