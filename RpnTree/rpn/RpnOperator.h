#ifndef RPNTREE_RPNOPERATOR_H
#define RPNTREE_RPNOPERATOR_H

#include <string>
#include "RpnElem.h"

class RpnOperator : public RpnElem {
public:
    RpnOperator(std::string _operator, int numberOfChildren);
    explicit RpnOperator(std::string _operator);

    std::string getOperator();

    int getNumberOfChildren() const;
    std::string toString() const override;

    Type getType() const override;

private:
    const std::string oper;
    const int numberOfChildren;
};


#endif //RPNTREE_RPNOPERATOR_H
