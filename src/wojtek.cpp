#include <iostream>
#include "Graf.hpp"
#include "PrzydzialZasobow.hpp"
#include "Wczytywanie.hpp"
#include "Drzewo.hpp"

int main() {
    using namespace std;

    std::ifstream plik{"../graf10"};
    Graf g = Wczytywanie::wczytaj(plik);
    auto przydzial = PrzydzialZasobow::losowyPrzydzial(g.numeryWierzcholkow(), g.iloscZasobow);

    return 0;
}
