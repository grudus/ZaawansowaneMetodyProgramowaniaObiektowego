#ifndef RPNTREE_RPNELEM_H
#define RPNTREE_RPNELEM_H


class RpnElem {
public:
    virtual ~RpnElem() = default;;

    virtual bool isOperator() = 0;
};


#endif //RPNTREE_RPNELEM_H
