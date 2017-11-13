#include <iostream>
#include <string>
#include "utils/ErrorableValue.h"
#include "tree/Tree.h"
#include "rpn/RpnOperator.h"
#include "rpn/RpnNumber.h"
#include "rpn/RpnVariable.h"
#include "tree/RpnBinaryTreeFactory.h"
#include "utils/StringUtils.h"

int main() {
//
//    auto a = new Node(new RpnVariable("a"));
//    auto b = new Node(new RpnVariable("b"));
//    auto plus = new Node(new RpnOperator("+"));
//    plus->setLeft(a);
//    plus->setRight(b);
//
//    auto eight = new Node(new RpnNumber(8));
//    auto multR = new Node(new RpnOperator("*"));
//    multR->setRight(eight);
//    multR->setLeft(plus);
//
//
//    auto x = new Node(new RpnVariable("x"));
//    auto sin = new Node(new RpnOperator("sin"));
//    sin->setRight(x);
//
//    auto five = new Node(new RpnNumber(5));
//    auto multL = new Node(new RpnOperator("*"));
//    multL->setRight(sin);
//    multL->setLeft(five);
//
//    auto root = new Node(new RpnOperator("+"));
//
//    root->setLeft(multL);
//    root->setRight(multR);
//

    auto expr = split("+ * 5 sin x * + a b 8", ' ');
    auto tree = RpnBinaryTreeFactory().create(expr);


    std::cout << "end" << std::endl;

    return 0;
}