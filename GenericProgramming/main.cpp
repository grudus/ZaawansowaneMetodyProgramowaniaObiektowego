#include <iostream>
#include "rpn/RpnElemFactory.h"
#include "tree/RpnTreeFactory.h"
#include "generic-tree/GenericTree.h"
#include "tree/RpnTreeSolver.h"
#include "generic-tree/RandomRpnElemCreator.h"
#include "FunctionXY.h"
#include "FunctionFileReader.h"


GenericTree *createRandomTree() {
    auto creator = RandomRpnElemCreator();
    auto anOperator = creator.randomOperator();
    Node* node = new Node(anOperator);
    for (int i = 0; i < anOperator->getNumberOfChildren(); i++) {
        auto child = new Node(creator.createVarOrConst());
        node->addChild(child);
    }
    return new GenericTree(node);
}

std::vector<GenericTree*> initialize(int Np) {
    std::vector<GenericTree*> trees;
    for (int i = 0; i < Np; i++) {
        auto tree = createRandomTree();
        trees.push_back(tree);
    }
    return trees;
}

int main() {
    srand(time(nullptr));
    std::cout << "Hello, World!" << std::endl;


    auto path = "/home/grudus/CLionProjects/ZaawansowaneMetodyProgramowaniaObiektowego/GenericProgramming/resources/ZMPO_lista_4_02_3_punkty.txt";
    auto dupa =    FunctionFileReader(path).read();


//    const int Np = 200;
//
//    std::vector<GenericTree*> population = initialize(Np);
//
//    for (auto aTree: population)
//        aTree->printPrefixed();



    return 0;
}