
#include "RandomRpnElemCreator.h"


RpnElem *RandomRpnElemCreator::randomElem(const RpnElem *type) {
    switch (type->getType()) {
        case RpnElem::Type::OPERATOR: {
            auto rpnOperator = (RpnOperator *) type;
            return RpnElemFactory().create(randomOperator(rpnOperator->getNumberOfChildren()));
        }
        default:
            return createVarOrConst();
    }
}

RpnOperator *RandomRpnElemCreator::randomOperator() {
    return (RpnOperator*) RpnElemFactory().create(randomOperator(-1));
}

RpnElem *RandomRpnElemCreator::createVarOrConst() {
    bool createVariable = rand() % 2;

    return createVariable
           ? RpnElemFactory().create(randomVariable())
           : RpnElemFactory().create(randomNumber());
}

const std::string RandomRpnElemCreator::randomOperator(int numberOfChildren) {
    std::map<std::string, int> operators;
    for (const auto &it : OPERATORS_TO_CHILDREN) {
        if (numberOfChildren == -1 || it.second == numberOfChildren)
            operators.insert({it.first, it.second});
    }
    int elem = rand() % operators.size();

    for (auto it = operators.begin(); it != operators.end(); ++it, elem--) {
        if (elem <= 0)
            return it->first;
    }
    throw "Nie powinno sie zdarzyć nigdy";
}

const std::string RandomRpnElemCreator::randomVariable() {
    return (rand() % 2 == 0) ? "x" : "y";
}

const std::string RandomRpnElemCreator::randomNumber() {
    int numberRange = rand() % 10;

    if (numberRange < 4)
        return std::to_string(10 - (rand() % 20));
    if (numberRange < 7)
        return std::to_string(100 - (rand() % 200));
    else if (numberRange < 9)
        return std::to_string(1000 - (rand() % 2000));
    else return std::to_string(RAND_MAX / 2 - rand());
}
