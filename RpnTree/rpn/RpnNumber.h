#ifndef RPNTREE_RPNNUMBER_H
#define RPNTREE_RPNNUMBER_H


#include "RpnElem.h"

class RpnNumber : public RpnElem {
public:
    explicit RpnNumber(int number);
    bool isOperator() override;
    int getNumber() const;

    std::string toString() const override;

private:
    const int number;

};


#endif //RPNTREE_RPNNUMBER_H
