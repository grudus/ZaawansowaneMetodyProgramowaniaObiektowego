#ifndef RPNTREE_RPNTREESOLVER_H
#define RPNTREE_RPNTREESOLVER_H


#include <map>
#include <cmath>
#include <utility>
#include "../rpn/RpnNumber.h"
#include "../utils/Errorable.h"
#include "Tree.h"

class RpnTreeSolver {
public:

    static Errorable<double> *solve(Tree *tree, std::map<std::string, double> variables);

private:

    static Errorable<double> *solve(Node *node, std::map<std::string, double> variables);

    static Errorable<double> *
    calculate(Node *node, const std::map<std::string, double> &variables, const RpnElem *elem);
};


#endif //RPNTREE_RPNTREESOLVER_H
