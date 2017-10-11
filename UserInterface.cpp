#include "UserInterface.h"
#include "RzadkiWektor.h"

int getIntegerInput() ;

int readInput(std::string *function, int *firstVal, int *secondVal) {
    bool validInstruction = false;
    std::string instruction;

    while (!validInstruction) {
        std::cin >> instruction;
        validInstruction = true;

        if (instruction == MVEC_INSTRUCTION || instruction == DEF_INSTRUCTION) {
            *firstVal = getIntegerInput();
            *secondVal = getIntegerInput();
            *function = instruction;
        } else if (instruction == LEN_INSTRUCTION || instruction == RESET_INSTRUCTION || instruction == READ_INSTRUCTION) {
            *firstVal = getIntegerInput();
            *function = instruction;
        } else if (instruction == PRINT_INSTRUCTION || instruction == DEL_INSTRUCTION || instruction == QUIT_INSTRUCTION)
            *function = instruction;
        else {
            std::cerr << "Couldn't find instruction {" << instruction << "}\n" << std::endl;
            validInstruction = false;
        }
    }

    return NO_ERROR;
}

int showInterface(std::string *function, int *firstVal, int *secondVal) {
    std::cout << MENU_TEXT << std::endl;

    return readInput(function, firstVal, secondVal);
}


bool isNumber(const std::string &x) {
    std::regex e("^-?\\d+");
    return std::regex_match(x, e);
}

int getIntegerInput() {
    std::string input;
    bool isNumeric;
    do {
        std::cin >> input;
        isNumeric = isNumber(input);
        if (!isNumeric)
            std::cout << "Please enter valid numeric input" << std::endl;
    } while (!isNumeric);
    return std::stoi(input);
}
