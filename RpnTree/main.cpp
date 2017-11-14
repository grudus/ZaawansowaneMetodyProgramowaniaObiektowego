#include <iostream>
#include "tree/Tree.h"
#include "rpn/RpnOperator.h"
#include "rpn/RpnNumber.h"
#include "rpn/RpnVariable.h"
#include "tree/RpnTreeFactory.h"

int main() {
//
    auto a = new Node(new RpnVariable("a"));
    auto b = new Node(new RpnVariable("b"));
    auto plus = new Node(new RpnOperator("+"));
    plus->addChildren(a);
    plus->addChildren(b);

    auto eight = new Node(new RpnNumber(8));
    auto multR = new Node(new RpnOperator("*"));
    multR->addChildren(plus);
    multR->addChildren(eight);


    auto x = new Node(new RpnVariable("x"));
    auto sin = new Node(new RpnOperator("sin"));
    sin->addChildren(x);

    auto five = new Node(new RpnNumber(5));
    auto multL = new Node(new RpnOperator("*"));
    multL->addChildren(five);
    multL->addChildren(sin);

    auto root = new Node(new RpnOperator("+"));

    root->addChildren(multL);
    root->addChildren(multR);
//

    auto expr = split("+ * 5 sin x * + a b 8", ' ');
    auto tree = RpnTreeFactory().create(expr);


    std::cout << (new Tree(root))->prefixToString() << std::endl;

    return 0;
}