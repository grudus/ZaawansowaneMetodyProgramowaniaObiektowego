#include "UserInterface.h"
#include "RzadkiWektor.h"


//TODO Validate instructions
int readInput(std::string *function, int *firstVal, int *secondVal) {
    bool validInstruction = false;
    std::string instruction;
    int first, second;

    std::cin >> instruction;

    if (instruction == MVEC_INSTRUCTION || instruction == DEF_INSTRUCTION)
        std::cin >> *firstVal >> *secondVal;
    else if (instruction == LEN_INSTRUCTION)
        std::cin >> *firstVal;

    *function = instruction;

    return NO_ERROR;
}

int showInterface(std::string *function, int *firstVal, int *secondVal) {
    std::cout << MENU_TEXT << std::endl;

    return readInput(function, firstVal, secondVal);
}