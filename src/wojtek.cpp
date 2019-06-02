#include <iostream>
#include "Graf.hpp"
#include "PrzydzialZasobow.hpp"
#include "Wczytywanie.hpp"

int main() {
    using namespace std;

    std::ifstream plik{"../graf10"};
    Graf g = Wczytywanie::wczytaj(plik);

    auto numery = g.numeryWierzcholkow();
    auto przydzial = PrzydzialZasobow::losowyPrzydzial(numery, g.iloscZasobow);
    auto sk = g.sciezkaKrytyczna(przydzial);

    for (auto x : numery) {
        cout << x << " " << przydzial.zasobZadania(x) << "\n";
    }

    for (int wierzcholek: g.sciezkaNajdrozsza(przydzial)) {
        cout << wierzcholek << " ";
    }


    return 0;
}
