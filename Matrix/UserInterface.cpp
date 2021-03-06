#include "UserInterface.h"
#include "instructions/AddInstruction.h"
#include "instructions/ListInstruction.h"
#include "instructions/DeleteInstruction.h"
#include "instructions/DeleteAllInstruction.h"
#include "instructions/DefInstruction.h"
#include "instructions/PrintInstruction.h"
#include "instructions/CopyInstruction.h"
#include "instructions/RenameInstruction.h"
#include "instructions/ReverseInstruction.h"
#include "instructions/MultipleInstruction.h"

void UserInterface::showMenu() {
    std::cout << "\n** addmat <dimNum> <dim0size> <dim1size>... <dimNum-1size> <def> <!name!> -\n"
            "wykonanie polecenia dynamicznie tworzy nową matrycę rzadką i dodaje ją do puli (zgodnie z\n"
            "wytycznymi utworzone matryce można przechowywać w wektorze, liście lub tablicy).\n"
            "<dimNum>oznacza liczbę wymiarów nowej matrycy, <dimXsize> oznacza zakres dla danego\n"
            "wymiaru, <def> to wartość, <!name!> to nazwa matrycy rzadkiej, która może, ale nie musi\n"
            "zostać podana. W przypadku braku zdefiniowanej nazwy, obiekt matrycy rzadkiej powinien\n"
            "zostać stworzony z nazwą domyślną (np. „SparseMatrix”).\n"
            "** list – wypisanie na ekran liczby matryc rzadkich przechowywanych obecnie przez program,\n"
            "wraz z ich nazwami w formacie: „<MatNum> matrices:\\n[<off>]: <name> size: [<długości\n"
            "poszczególnych wymiarów>]\\n ”, gdzie MatNum to liczba matryc, off, to offset danej matrycy,\n"
            "długości poszczególnych wymiarów są tak zdefiniowane jak przy wypisywaniu pojedynczej\n"
            "matrycy na ekran, a /n oznacza znak końca linii. Na przykład:\n"
            "2 matrices:\n"
            "[0] – „wektor” size: [58]\n"
            "[1] – „testowa” size: [2, 67, 33]\n"
            "** del <matoff> - skasowanie matrycy przechowywanej na offsecie <matoff>"
            "** delall – skasowanie wszystkich obecnie przechowywanych matryc\n"
            "** def <matoff> <dim0> <dim1>... <dimNum-1> <val> - ustalenie wartości <val> dla\n"
            "matrycy rzadkiej o offsecie <matoff> i koordynatów <dim0> <dim1>... <dimNum-1>\n"
            "** print <matoff> – wykonanie polecenia wypisuje na ekran aktualny stan matrycy rzadkiej o\n"
            "offsecie <matoff>\n"
            "** clone <matoff> - skolonowanie matrycy o offsecie <matoff> i dodanie jej do puli matryc na\n"
            "ostatniej pozycji\n"
            "** rename <matoff> <newName> - zmiany nazwy matrycy rzadkiej o offsecie <matoff>\n"
            "** reverse <matoff> <newValue> - wszystkie defaultowe wartosci zostaja zamienione na <newValue>, wszystkie okreslone\n"
            "wracaja do pozycji defaultowej"
            "** mult <matoff1> <matoff2> - pomnozenie macierzy <matoff1> przez macierz <matoff2> (tylko jesli sa 2 wymiarowe)\n"
            "wynik zostaje zapisany w nowe macierzy"
              << std::endl;

}

void UserInterface::readInstruction(std::vector<SpareMatrix *> *matrixes) {
    std::string instruction;
    std::cin >> instruction;
    std::transform(instruction.begin(), instruction.end(), instruction.begin(), ::tolower);

    if (instruction == "addmat")
        AddInstruction(matrixes).handle();
    else if (instruction == "list")
        ListInstruction(matrixes).handle();
    else if (instruction == "del")
        DeleteInstruction(matrixes).handle();
    else if (instruction == "delall")
        DeleteAllInstruction(matrixes).handle();
    else if (instruction == "def")
        DefInstruction(matrixes).handle();
    else if (instruction == "print")
        PrintInstruction(matrixes).handle();
    else if (instruction == "clone")
        CopyInstruction(matrixes).handle();
    else if (instruction == "rename")
        RenameInstruction(matrixes).handle();
    else if (instruction == "reverse")
        ReverseInstruction(matrixes).handle();
    else if (instruction == "mult")
        MultipleInstruction(matrixes).handle();
    else {
        std::cerr << "Bledna instrukcja: " << instruction << std::endl;
        std::cin.ignore(::std::numeric_limits<long>::max(), '\n');
    }
}
