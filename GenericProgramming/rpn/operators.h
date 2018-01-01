
#ifndef GENERICPROGRAMMING_OPERATORS_H
#define GENERICPROGRAMMING_OPERATORS_H

#include <string>
#include <map>

const std::map<std::string, int> OPERATORS_TO_CHILDREN = {
        {"$",   3},
        {"+",   2},
        {"-",   2},
        {"*",   2},
        {"/",   2},
        {"sin", 1},
        {"cos", 1}
};

#endif //GENERICPROGRAMMING_OPERATORS_H
