#include <iostream>
#include "utils/ErrorableValue.h"

int main() {
    auto maybeError = ErrorableValue<std::string>::fromValue("heheszki");

    std::cout << "Hello, World!" << std::endl;
    std::cout << maybeError->getValue() << std::endl;

    return 0;
}