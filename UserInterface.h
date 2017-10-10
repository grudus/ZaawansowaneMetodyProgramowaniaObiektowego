#ifndef ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H
#define ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H

#include <iostream>
#include <string>

static const std::string POSSIBLE_FUNCTIONS[5] = {"mvec", "len", "def", "print", "del"};
static const char* MENU_TEXT = "\nWITAM W PROGRAMIE DO WEKTORA RZADKIEGO!\n\n"
        "1) mvec <len> <def> - wykonanie polecenia usuwa istniejący wektor rzadki (jeśli jakiś istnieje)\n"
        "i tworzy nowy wektor, o długości <len> i wartości domyślnej wektora rzadkiego <def>\n"
        "2) len <len> - zmiana długości wektora rzadkiego. Jeśli zostaje zmniejszona to, to te pozycje,\n"
        "które inne niż domyślna, a nie mieszczą się w nowym zakresie powinny zostać usunięte z\n"
        "tablicy wartości i tablicy offsetów.\n"
        "3) def <off> <val> - ustalenie wartości <val> dla offsetu <off> wektora rzadkiego\n"
        "4) print – wykonanie polecenia wypisuje na ekran aktualny stan wektora rzadkiego\n"
        "5) del – usuwa wszystkie dynamicznie alokowane zmienne dla wektor rzadkiego, jeśli wektor\n"
        "obecnie istnieje.\n";

int showInterface(std::string* function, int* firstVal, int* secondVal);
int readInput(std::string* function, int* firstVal, int* secondVal);

#endif //ZAAWANSOWANEMETODYPROGRAMOWANIAOBIEKTOWEGO_USERINTERFACE_H
