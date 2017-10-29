#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H

#include <iostream>
#include <string>
#include <regex>

static const char* MVEC_INSTRUCTION = "mvec";
static const char* LEN_INSTRUCTION = "len";
static const char* DEF_INSTRUCTION = "def";
static const char* PRINT_INSTRUCTION = "print";
static const char* DEL_INSTRUCTION = "del";
static const char* READ_INSTRUCTION = "read";
static const char* RESET_INSTRUCTION = "reset";
static const char* QUIT_INSTRUCTION = "quit";


static const char* MENU_TEXT = "\nWITAM W PROGRAMIE DO WEKTORA RZADKIEGO!\n\n"
        "* mvec <len> <def> - wykonanie polecenia usuwa istniejący wektor rzadki (jeśli jakiś istnieje)\n"
        "i tworzy nowy wektor, o długości <len> i wartości domyślnej wektora rzadkiego <def>\n"
        "* len <len> - zmiana długości wektora rzadkiego. Jeśli zostaje zmniejszona to, to te pozycje,\n"
        "które inne niż domyślna, a nie mieszczą się w nowym zakresie powinny zostać usunięte z\n"
        "tablicy wartości i tablicy offsetów.\n"
        "* def <off> <val> - ustalenie wartości <val> dla offsetu <off> wektora rzadkiego\n"
        "* print – wykonanie polecenia wypisuje na ekran aktualny stan wektora rzadkiego\n"
        "* del – usuwa wszystkie dynamicznie alokowane zmienne dla wektor rzadkiego, jeśli wektor\n"
        "obecnie istnieje.\n"
        "* reset <val> - zmienia wartosc wektora domyslnego"
        "* quit - end program";

int showInterface(std::string* function, int* firstVal, int* secondVal);
int readInput(std::string* function, int* firstVal, int* secondVal);

#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H
