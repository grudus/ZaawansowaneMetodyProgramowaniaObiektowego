#include <iostream>
#include "tree/Tree.h"
#include "tree/RpnTreeFactory.h"
#include "interface/CommandLineInterface.h"
#include "tree/RpnTreeSolver.h"

int main() {

    std::string instruction;
    Tree *tree = nullptr;

    CommandLineInterface().showMenu();

    while (instruction != "exit") {
        std::cin >> instruction;

        if (instruction == "enter") {
            std::string formula;
            getline(std::cin, formula);
            ltrim(formula);
            tree = RpnTreeFactory().create(split(formula, ' '));
        } else if (instruction == "print") {
            std::cout << tree->prefixToString() << std::endl;
        } else if (instruction == "vars") {
            auto set = tree->findVariables();
            for (const auto &var : set) std::cout << var << " ";
            std::cout << std::endl;
        } else if (instruction == "comp") {
            std::string line;
            getline(std::cin, line);
            ltrim(line);
            auto userData = split(line, ' ');
            auto variables = tree->findVariables();
            std::map<std::string, double> environment;
            std::set<std::string>::iterator it;
            int i = 0;
            for (auto var: variables) {
                std::string &str = userData[i++];
                environment.insert({var, std::stoi(str)});
            }


            std::cout << RpnTreeSolver::solve(tree, environment)->getValue() << std::endl;
        }
    }


    delete tree;
    return 0;
}