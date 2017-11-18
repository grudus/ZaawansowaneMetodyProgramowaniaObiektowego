#include "RpnTreeSolver.h"

Errorable<double> *RpnTreeSolver::solve(Tree *tree, std::map<std::string, double> variables) {
    return solve(tree->getRoot(), std::move(variables));
}

Errorable<double> *RpnTreeSolver::solve(Node *node, std::map<std::string, double> variables) {
    auto elem = node->getElem();

    switch (elem->getType()) {
        case RpnElem::Type::CONSTANT: {
            double value = ((RpnNumber *) elem)->getNumber();
            return Errorable<double>::ok(value);
        }

        case RpnElem::Type::VARIABLE: {
            auto found = variables.find(elem->toString());
            return found == variables.end() ? Errorable<double>::fromError(VARIABLE_NOT_EXISTS)
                                            : Errorable<double>::ok(found->second);
        }
        case RpnElem::Type::OPERATOR:
            return calculate(node, variables, elem);

    }
}

Errorable<double> *
RpnTreeSolver::calculate(Node *node, const std::map<std::string, double> &variables, const RpnElem *elem) {
    const auto &children = node->getChildren();

    Errorable<double> *_value1 = solve(children[0], variables);
    if (_value1->isError())
        return _value1;
    double value1 = _value1->getValue();

    if (children.size() == 1) {
        if (elem->toString() == "sin")
            return Errorable<double>::ok(sin(value1));
        if (elem->toString() == "cos")
            return Errorable<double>::ok(cos(value1));
    }

    Errorable<double> *_value2 = solve(children[1], variables);
    if (_value2->isError())
        return _value2;
    double value2 = _value2->getValue();


    if (elem->toString() == "+")
        return Errorable<double>::ok(value1 + value2);
    if (elem->toString() == "-")
        return Errorable<double>::ok(value1 - value2);
    if (elem->toString() == "*")
        return Errorable<double>::ok(value1 * value2);
    if (elem->toString() == "/") {
        if (value2 == 0)
            return Errorable<double>::fromError(DIVISION_BY_ZERO);
        return Errorable<double>::ok(value1 / value2);
    }
}
