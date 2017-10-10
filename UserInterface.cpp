#include "UserInterface.h"
#include "RzadkiWektor.h"


//TODO Validate instructions
int readInput(std::string *function, int *firstVal, int *secondVal) {
    bool validInstruction = false;
    std::string instruction;
    int first, second;

    std::cin >> instruction;

    if (instruction == POSSIBLE_FUNCTIONS[0] || instruction == POSSIBLE_FUNCTIONS[2])
        std::cin >> *firstVal >> *secondVal;
    else if (instruction == POSSIBLE_FUNCTIONS[1])
        std::cin >> *firstVal;

    *function = instruction;

    return NO_ERROR;
}

int showInterface(std::string *function, int *firstVal, int *secondVal) {
    std::cout << MENU_TEXT << std::endl;

    return readInput(function, firstVal, secondVal);
}