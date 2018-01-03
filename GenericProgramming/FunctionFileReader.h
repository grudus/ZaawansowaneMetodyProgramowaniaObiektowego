
#ifndef GENERICPROGRAMMING_FUNCTIONFILEREADER_H
#define GENERICPROGRAMMING_FUNCTIONFILEREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "FunctionXY.h"

class FunctionFileReader {
public:
    explicit FunctionFileReader(std::string filename) : filename(filename) {}

    std::vector<FunctionXY*> read() {
        std::vector<FunctionXY*> functions;
        std::ifstream inFile;

        inFile.open(filename);

        if(!inFile) {
            std::cerr << "Nie ma pliku " << filename << std::endl;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            FunctionXY* func = new FunctionXY(line);
            functions.push_back(func);
        }

        inFile.close();


        return functions;
    }


private:
    const std::string filename;
};


#endif //GENERICPROGRAMMING_FUNCTIONFILEREADER_H
