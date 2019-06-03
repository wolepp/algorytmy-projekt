#ifndef GRAF_HPP
#define GRAF_HPP

#include <vector>
#include <map>

#include "PrzydzialZasobow.hpp"

struct Info {
    std::vector<int> times;
    std::vector<int> costs;
    std::vector<int> dzieci;
};

class Graf {
public:
    std::map<int, Info> m_wierzcholki;
    int iloscZasobow;

    void znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &) const;

    //funkcje genów
    void najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial) const; //gen1
    void najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial) const; //gen2
    void najmniejszeTK(PrzydzialZasobow &przydzial) const; //gen3
    void najmniejObciazonyZasob(PrzydzialZasobow &przydzial) const; //gen4

    std::vector<int> sciezkaKrytyczna(const PrzydzialZasobow &przydzial) const;
    std::vector<int> sciezkaNajdrozsza(const PrzydzialZasobow &przydzial) const;
    std::vector<int> numeryWierzcholkow() const;
    std::vector<std::vector<int>> wszystkieSciezki() const;
    int czasWszytskichZadan(const PrzydzialZasobow &przydzial) const;
    int kosztWszystkichZadan(const PrzydzialZasobow &przydzial) const;
};

#endif //GRAF_HPP
