#ifndef RPNTREE_RPNOPERATOR_H
#define RPNTREE_RPNOPERATOR_H

#include <string>
#include "RpnElem.h"

class RpnOperator : public RpnElem {
public:
    explicit RpnOperator(std::string _operator);
    bool isOperator() override;
    std::string getOperator();

private:
    const std::string oper;
};


#endif //RPNTREE_RPNOPERATOR_H
