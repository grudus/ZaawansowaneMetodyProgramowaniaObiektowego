#ifndef RPNTREE_RPNELEM_H
#define RPNTREE_RPNELEM_H

#include <string>

class RpnElem {
public:
    virtual ~RpnElem() = default;;

    virtual bool isOperator() const = 0;
    virtual std::string toString() const = 0;
};


#endif //RPNTREE_RPNELEM_H
