#include <iostream>
#include "tree/Tree.h"
#include "rpn/RpnVariable.h"
#include "tree/RpnTreeFactory.h"

int main() {
    auto expr = split("+ * 5 sin x * + a b 8", ' ');
    auto tree = RpnTreeFactory().create(expr);


    std::cout << tree->prefixToString() << std::endl;

    return 0;
}