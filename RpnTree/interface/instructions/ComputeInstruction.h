#ifndef RPNTREE_COMPUTEINSTRUCTION_H
#define RPNTREE_COMPUTEINSTRUCTION_H

#include <iostream>
#include <set>
#include <map>

#include "../../tree/Tree.h"
#include "../../tree/RpnTreeSolver.h"

std::vector<std::string> readUserComputeInput();

void handleComputeInstruction(Tree *tree) {
    if (tree == nullptr) {
        std::cerr << "You have to initialize tree first!" << std::endl;
        return;
    }

    std::vector<std::string> userData = readUserComputeInput();
    std::set<std::string> variables = tree->findVariables();
    std::map<std::string, double> environment;
    std::set<std::string>::iterator it;

    if (userData.size() > variables.size()) {
        std::cout << "You entered too many arguments! The last " << userData.size() - variables.size()
                  << " will be omitted" << std::endl;
    } else if (userData.size() < variables.size()) {
        unsigned long delta = variables.size() - userData.size();
        std::cout << "You entered not enough arguments! " << delta
                  << " variables will be set to default [1]" << std::endl;
        for (unsigned long i = 0; i < delta; i++)
            userData.push_back("1");
    }

    int i = 0;
    for (auto var: variables) {
        std::string &str = userData[i++];
        environment.insert({var, std::stod(str)});
    }

    Errorable<double> *errorableValue = RpnTreeSolver::solve(tree, environment);
    if (errorableValue->isError())
        std::cerr << "An error occurred while computing result [" << errorableValue->getErrorCode() << "]" << std::endl;
    else
        std::cout << "Result: " << errorableValue->getValue() << std::endl;
}

std::vector<std::string> readUserComputeInput() {
    std::string line;
    getline(std::cin, line);
    ltrim(line);
    return line.empty() ? std::vector<std::string>() : split(line, "\\s+");
}

#endif //RPNTREE_COMPUTEINSTRUCTION_H
