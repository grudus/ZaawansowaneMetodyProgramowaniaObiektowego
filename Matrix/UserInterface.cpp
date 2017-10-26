//
// Created by grudus on 10/14/17.
//
#include "UserInterface.h"
#include "instructions/AddInstruction.h"
#include "instructions/ListInstruction.h"
#include "instructions/DeleteInstruction.h"
#include "instructions/DeleteAllInstruction.h"

void UserInterface::showMenu() {
    std::cout << "\naddmat <dimNum> <dim0size> <dim1size>... <dimNum-1size> <def> <!name!> -\n"
            "wykonanie polecenia dynamicznie tworzy nową matrycę rzadką i dodaje ją do puli (zgodnie z\n"
            "wytycznymi utworzone matryce można przechowywać w wektorze, liście lub tablicy).\n"
            "<dimNum>oznacza liczbę wymiarów nowej matrycy, <dimXsize> oznacza zakres dla danego\n"
            "wymiaru, <def> to wartość, <!name!> to nazwa matrycy rzadkiej, która może, ale nie musi\n"
            "zostać podana. W przypadku braku zdefiniowanej nazwy, obiekt matrycy rzadkiej powinien\n"
            "zostać stworzony z nazwą domyślną (np. „SparseMatrix”).\n"
            "list – wypisanie na ekran liczby matryc rzadkich przechowywanych obecnie przez program,\n"
            "wraz z ich nazwami w formacie: „<MatNum> matrices:\\n[<off>]: <name> size: [<długości\n"
            "poszczególnych wymiarów>]\\n ”, gdzie MatNum to liczba matryc, off, to offset danej matrycy,\n"
            "długości poszczególnych wymiarów są tak zdefiniowane jak przy wypisywaniu pojedynczej\n"
            "matrycy na ekran, a /n oznacza znak końca linii. Na przykład:\n"
            "2 matrices:\n"
            "[0] – „wektor” size: [58]\n"
            "[1] – „testowa” size: [2, 67, 33]\n"
            "del <matoff> - skasowanie matrycy przechowywanej na offsecie <matoff>"
            "delall – skasowanie wszystkich obecnie przechowywanych matryc\n"
            "def <matoff> <dim0> <dim1>... <dimNum-1> <val> - ustalenie wartości <val> dla\n"
            "matrycy rzadkiej o offsecie <matoff> i koordynatów <dim0> <dim1>... <dimNum-1>\n"
            "print <matoff> – wykonanie polecenia wypisuje na ekran aktualny stan matrycy rzadkiej o\n"
            "offsecie <matoff>\n"
            "clone <matoff> - skolonowanie matrycy o offsecie <matoff> i dodanie jej do puli matryc na\n"
            "ostatniej pozycji\n"
            "rename <matoff> <newName> - zmiany nazwy matrycy rzadkiej o offsecie <matoff>\n" << std::endl;

}

void UserInterface::readInstruction(std::vector<SpareMatrix *> *matrixes) {
    std::string instruction;
    std::cin >> instruction;

    if (instruction == "addmat")
        AddInstruction(matrixes).handle();
    else if (instruction == "list")
        ListInstruction(matrixes).handle();
    else if (instruction == "del")
        DeleteInstruction(matrixes).handle();
    else if (instruction == "delall")
        DeleteAllInstruction(matrixes).handle();


}
