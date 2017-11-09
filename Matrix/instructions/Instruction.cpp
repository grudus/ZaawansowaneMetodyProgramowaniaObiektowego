#include "Instruction.h"

Instruction::Instruction(std::vector<SpareMatrix *> *matrixes) {
    this->matrixes = matrixes;
}

bool Instruction::indexIsValid(int index) const {
    return index >= 0 && index < (*matrixes).size();
}

void Instruction::handleInvalidIndex(int index) const {
    std::string message = "Invalid index [" + std::to_string(index) + "]";
    handleInvalidInput(message);
}

void Instruction::handleInvalidInput(const std::string &message) const {
    std::cerr << message << std::endl;
    std::cin.ignore(::std::numeric_limits<long>::max(), '\n');
}

int Instruction::getIntegerInput() const {
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

bool Instruction::isNumber(const std::string &x) const {
    std::regex e("^-?\\d+");
    return std::regex_match(x, e);
}
