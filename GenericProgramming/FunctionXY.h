
#ifndef GENERICPROGRAMMING_EQUATION_H
#define GENERICPROGRAMMING_EQUATION_H

#include <string>
#include <stdlib.h>
#include "utils/StringUtils.h"

class FunctionXY {
public:

    FunctionXY(std::string string) {
        auto splitted = split(string, "; ");

        x = atof(splitted[0].c_str());
        y = atof(splitted[1].c_str());
        result = atof(splitted[2].c_str());
    }

    double x, y, result;
};


#endif //GENERICPROGRAMMING_EQUATION_H
