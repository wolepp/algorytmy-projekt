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

    void znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &);

    //funkcje genów
    void najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial); //gen1
    void najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial); //gen2
    void najmniejszeTK(PrzydzialZasobow &przydzial); //gen3
    void najmniejObciazonyZasob(PrzydzialZasobow &przydzial); //gen4

    std::vector<int> sciezkaKrytyczna(const PrzydzialZasobow &przydzial);
    std::vector<int> sciezkaNajdrozsza(const PrzydzialZasobow &przydzial);
    std::vector<int> numeryWierzcholkow();
    std::vector<std::vector<int>> wszystkieSciezki();
    int czasWszytskichZadan(const PrzydzialZasobow &przydziall);
    int kosztWszystkichZadan(const PrzydzialZasobow &przydzial);
};

#endif //GRAF_HPP
