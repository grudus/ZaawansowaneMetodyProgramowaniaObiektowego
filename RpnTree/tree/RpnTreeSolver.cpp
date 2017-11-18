#include "RpnTreeSolver.h"

double RpnTreeSolver::solve(Tree *tree, std::map<std::string, double> variables) {
    return solve(tree->getRoot(), std::move(variables));
}

double RpnTreeSolver::solve(Node *node, std::map<std::string, double> variables) {
    auto elem = node->getElem();

    switch (elem->getType()) {
        case RpnElem::Type::CONSTANT:
            return ((RpnNumber *) elem)->getNumber();
        case RpnElem::Type::VARIABLE:
            return variables[elem->toString()];
        case RpnElem::Type::OPERATOR:
            return calculate(node, variables, elem);

    }
}

double RpnTreeSolver::calculate(Node *node, const std::map<std::string, double> &variables, const RpnElem *elem) {
    const auto &children = node->getChildren();

    if (elem->toString() == "+")
        return solve(children[0], variables) + solve(children[1], variables);
    if (elem->toString() == "-")
        return solve(children[0], variables) - solve(children[1], variables);
    if (elem->toString() == "*")
        return solve(children[0], variables) * solve(children[1], variables);
    if (elem->toString() == "/")
        return solve(children[0], variables) / solve(children[1], variables);
    if (elem->toString() == "sin")
        return sin(solve(children[0], variables));
    if (elem->toString() == "cos")
        return cos(solve(children[0], variables));
}
