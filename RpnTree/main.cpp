#include <iostream>
#include "utils/ErrorableValue.h"
#include "tree/Tree.h"
#include "rpn/RpnOperator.h"
#include "rpn/RpnNumber.h"
#include "rpn/RpnVariable.h"

int main() {

    auto a = new Node(new RpnVariable("a"));
    auto b = new Node(new RpnVariable("b"));
    auto plus = new Node(new RpnOperator("+"));
    plus->setLeft(a);
    plus->setRight(b);

    auto eight = new Node(new RpnNumber(8));
    auto multR = new Node(new RpnOperator("*"));
    multR->setRight(eight);
    multR->setLeft(plus);


    auto x = new Node(new RpnVariable("x"));
    auto sin = new Node(new RpnOperator("sin"));
    sin->setRight(x);

    auto five = new Node(new RpnNumber(5));
    auto multL = new Node(new RpnOperator("*"));
    multL->setRight(sin);
    multL->setLeft(five);

    auto root = new Node(new RpnOperator("+"));

    root->setLeft(multL);
    root->setRight(multR);


    auto tree = new Tree(root);

    std::cout << "prefixed: " << std::endl;
    std::cout << tree->prefixToString() << std::endl;

    
    return 0;
}