#include <iostream>
#include <cmath>
#include "rpn/RpnElemFactory.h"
#include "tree/RpnTreeFactory.h"
#include "generic-tree/GenericTree.h"
#include "tree/RpnTreeSolver.h"
#include "generic-tree/RandomRpnElemCreator.h"
#include "FunctionXY.h"
#include "FunctionFileReader.h"
#include <chrono>


std::vector<GenericTree *> *
makeSelection(const std::vector<GenericTree *> &vector, const std::vector<double> &przystosowanie, int Np) {
    auto resultVector = new std::vector<GenericTree *>();

    for (int i = 0; i < Np; i++) {
        int index1 = abs((rand() * Np) % Np);
        int index2 = abs((rand() * Np) % Np);

        auto betterTree = przystosowanie[index1] < przystosowanie[index2]
                          ? vector[index1] : vector[index2];
        resultVector->push_back(betterTree);
    }
    return resultVector;
}

std::vector<double>
findPrzystosowanie(std::vector<GenericTree *> vector, std::vector<FunctionXY *> functions, const int i) {
    std::vector<double> resultsPerTree;
    for (GenericTree *tree : vector) {

        double estimate = 0;
        for (int i = 0; i < functions.size(); i++) {
            double treeResult = RpnTreeSolver::solve(tree, functions[i]->getEnv())->getValue();
            double przystosowanie = pow(functions[i]->result - treeResult, 2);
            estimate += przystosowanie;
        }
        resultsPerTree.push_back(estimate);
    }
    return resultsPerTree;
}

GenericTree *createRandomTree() {
    auto creator = RandomRpnElemCreator();
    auto anOperator = creator.randomOperator();
    Node *node = new Node(anOperator);
    for (int i = 0; i < anOperator->getNumberOfChildren(); i++) {
        auto child = new Node(creator.createVarOrConst());
        node->addChild(child);
    }
    return new GenericTree(node);
}

std::vector<GenericTree *> initialize(int Np) {
    std::vector<GenericTree *> trees;
    for (int i = 0; i < Np; i++) {
        auto tree = createRandomTree();
        trees.push_back(tree);
    }
    return trees;
}

int main() {
    std::cout << "Liczenie..." << std::endl;
    srand(time(nullptr));


    auto path = "/home/grudus/CLionProjects/ZaawansowaneMetodyProgramowaniaObiektowego/GenericProgramming/resources/ZMPO_lista_4_03_sin_x.txt";
    auto functions = FunctionFileReader(path).read();

    const int Np = 300;

    std::vector<GenericTree *> population = initialize(Np);

    std::vector<double> przystosowanie = findPrzystosowanie(population, functions, Np);

    int i = 0;
    const int Ni = 150;
    const double Pk = 0.5;
    const double Pm = 0.6;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    while (i < Ni) {
        population = *makeSelection(population, przystosowanie, Np);
        int populationSize = population.size();

        if (rand() < Pk) {
            int index1 = (abs(rand()) * populationSize) % populationSize;
            int index2 = (abs(rand()) * populationSize) % populationSize;

            auto treePair = population[index1]->cross(*population[index2]);

            population.push_back(&treePair.first);
            population.push_back(&treePair.second);

            population.erase(population.begin() + index1);
            population.erase(population.begin() + index2);
        }

        if (rand() < Pm) {
            int index = (abs(rand()) * populationSize) % populationSize;

            GenericTree tree = population[index]->mutate();
            population.push_back(&tree);
        }

        przystosowanie = findPrzystosowanie(population, functions, Np);

        i++;
    }


    double smallestPrzystosowanie = (double) RAND_MAX;
    int indexOfTheSmallest = population.size();
    for (int i = 0; i < population.size(); i++) {
        if (przystosowanie[i] < smallestPrzystosowanie) {
            indexOfTheSmallest = i;
            smallestPrzystosowanie = przystosowanie[i];
        }
    }

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

    std::cout << "Znaleziono najlepsze drzewo w " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000 << " milisekund" << std::endl;

    GenericTree *bestTree = population[indexOfTheSmallest];
    bestTree->printPrefixed();


    return 0;
}