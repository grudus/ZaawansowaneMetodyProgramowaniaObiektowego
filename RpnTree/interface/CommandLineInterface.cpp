
#include <iostream>
#include "CommandLineInterface.h"

void CommandLineInterface::showMenu() {
    std::cout << "*** enter <formula> - wykonanie powoduje próbę stworzenia drzewa na podstawie podanego\n"
            "wyrażenia. Jeżeli wyrażenie nie może zostać wczytane, bo posiada błędy, program ma\n"
            "uzupełnić drzewo tak, żeby drzewo było prawidłowe, wypisać odpowiedni komunikat, oraz\n"
            "poinformować, jaka formuła ostatecznie będzie przetwarzana (należy ją wypisać na ekranie).\n"
            "Naprawa wyrażenia ma nastąpić poprzez jego uzupełnienie. Dokładne wytyczne znajdują się\n"
            "w punkcie 1 na stronie 3.\n"
            "*** vars – wypisuje wszystkie zmienne z aktualnie wprowadzonego drzewa. Każda zmienna jest\n"
            "wypisywana jeden raz, nawet jeśli występuje w drzewie więcej razy.\n"
            "*** print – wypisuje aktualnie wprowadzone drzewo w postaci prefiksowej\n"
            "**** comp <var0> <var1>...<varN> – wyliczenie wartości wprowadzonej formuły, gdzie <var0>\n"
            "<var1>...<varN> to wartości dla kolejnych zmiennych występujących w drzewie. Wartości\n"
            "odpowiadają zmiennym w kolejności w jakiej zmienne są wypisywane przez polecenie vars.\n"
            "Na przykład, jeśli vars wypisało 3 zmienne: a b x, to polecenie „comp 1 2 3” wyliczy wartość\n"
            "drzewa dla a=1, b=2 i x=3. Jeśli liczba podanych wartości <var0> <var1>...<varN> nie\n"
            "będzie odpowiadać liczbie zmiennych w drzewie program ma wypisać odpowiedni\n"
            "komunikat.\n"
            "*** join <formula> - wykonanie powoduje próbę stworzenia drzewa na podstawie podanego\n"
            "wyrażenia. Następnie stworzone drzewo jest doklejane do istniejącego drzewa. Patrz punkt 2\n"
            "na stronie 3. Do wykonania tej komendy należy użyć operatorów „+” i „=”, zgodnie z opisem\n"
            "podanym w wymaganiach dotyczących implementacji." << std::endl;
}
