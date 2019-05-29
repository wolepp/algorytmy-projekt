#include <vector>
#include <map>
#include "PrzydzialZasobow.hpp"

struct Info {
    std::vector<int> times;
    std::vector<int> cost;
    std::vector<int> dzieci;
};

class Graf {
private:
    std::map<int, Info> m_wierzcholki;

    void znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &);
    std::vector<int> sciezkaKrytyczna(const PrzydzialZasobow &przydzial);
    std::vector<int> sciezkaNajdrozsza(const PrzydzialZasobow &przydzial);
    std::vector<std::vector<int>> wszystkieSciezki();

public:
    void najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial); //gen1
    void najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial); //gen2
    void najmniejszeTK(PrzydzialZasobow &przydzial); //gen3
    void najmniejObciazonyZasob(PrzydzialZasobow &przydzial); //gen4
};
