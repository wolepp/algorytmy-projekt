#include <iostream>
#include <fstream>
#include <string>

#include "Graf.hpp"
#include "Wczytywanie.hpp"

/**
 * @param c parametr od użytkownika
 * @param t parametr od użytkownika
 * @param przydzialZasobow osobnik
 * @param graf daje czas i koszt potrzebny do obliczeń
 * @return wartość funkcji dopasowania wg wzoru: c*koszt + t*czas
 */
void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf);

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

    std::cout << "EEO";


    return 0;
}

void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf){

    int f;
    f=(c*graf.kosztWszystkichZadan(przydzialZasobow))+t*graf.czasWszytskichZadan(przydzialZasobow);

    przydzialZasobow.setWartoscFunkcjiDopasowania(f);
}