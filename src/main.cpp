#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Wczytywanie.hpp"
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "Interfejs.hpp"
#include "Random.hpp"

typedef std::vector<Drzewo*> Rozwiazania;

/**
 * @param c parametr od użytkownika
 * @param t parametr od użytkownika
 * @param przydzialZasobow osobnik
 * @param graf daje czas i koszt potrzebny do obliczeń
 * @return wartość funkcji dopasowania wg wzoru: c*koszt + t*czas
 */
void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf);

/**
 * Operator mutacji.
 * Dokonuje mutacji na osobnikach podanych w parametrze.
 * @param pokolenie wskaźniki do drzew, na których ma nastąpić mutacja
 * @param liczba liczba rozwiązań do zmutowania
 * @return Rozwiazania - nowa część pokolenia z mutacji
 */
 //TODO: Radosław
Rozwiazania mutacja(Rozwiazania &pokolenie, int liczba);

/**
 * Operator selekcji.
 * Rozwiązania są przechowywane na liście rankingowej. Z niej wybierane
 * są osobniki.
 * @param pokolenie
 * @param liczba liczba rozwiązań do selekcji
 * @return Rozwiazania - nowa część pokolenia z selekcji
 */
 // Osobniki nie z góry lecąc, tam jest jakiś wzór na wybór z prawdopodobieństwem
 //TODO: Radosław
Rozwiazania selekcja(Rozwiazania &pokolenie, int liczba);

/**
 * Operator krzyżowania.
 * Krzyżuje drzewa spośród wybranych.
 * @param osobniki
 * @param liczba liczba osobników, które mają wyjść z krzyżowania
 * @return Rozwiazania - nowa część pokolenia z krzyżowania
 */
Rozwiazania krzyzowanie(Rozwiazania &osobniki, int liczba);

int main(int argc, char *argv[]) {

    std::ifstream input;
    std::string filename;
    if (argc == 1) {
        std::cout << "Podaj plik z grafem: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }
    input.open(filename);
    Graf graf = Wczytywanie::wczytaj(input);
    input.close();
    Interfejs interfejs;
    Parametry parametry = interfejs.pobierzParametry();


    return 0;
}

void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf){

    int f;
    f=(c*graf.kosztWszystkichZadan(przydzialZasobow))+t*graf.czasWszytskichZadan(przydzialZasobow);

    przydzialZasobow.setWartoscFunkcjiDopasowania(f);
}

Rozwiazania krzyzowanie(Rozwiazania &osobniki, int liczba) {
    Rozwiazania noweRozwiazania;
    
    
    return noweRozwiazania;
}

Rozwiazania selekcja(Rozwiazania &pokolenie, int liczba) {

    return Rozwiazania();
}

Rozwiazania mutacja(Rozwiazania &pokolenie, int liczba) {
    Rozwiazania R = pokolenie;

    for(int i=0; i<pokolenie.size(); i++){
        R[i]->operatorMutacji();
    }

    return R;
}


