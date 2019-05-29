#include "Graf.hpp"

std::vector<int> Graf::sciezkaKrytyczna(const PrzydzialZasobow &przydzial) {
    //Wojtek?
}

std::vector<int> Graf::sciezkaNajdrozsza(const PrzydzialZasobow &przydzial) {
    //Wojtek?
}

void Graf::znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &sciezki) {
    for (int dziecko: m_wierzcholki[sciezka.back()].dzieci) {
        sciezka.push_back(dziecko);
        znajdzSciezki(sciezka, sciezki);
    }
    if (m_wierzcholki[sciezka.back()].dzieci.empty()) {
        sciezki.push_back(sciezka);
    }
    sciezka.pop_back();
}

std::vector<std::vector<int>> Graf::wszystkieSciezki() {
    std::vector<int> sciezka;
    sciezka.push_back(m_wierzcholki.begin()->first);
    std::vector<std::vector<int>> sciezki;
    znajdzSciezki(sciezka, sciezki);
    return sciezki;
}

void Graf::najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial) {
    //Ola
}

void Graf::najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial) {
    //Ola

}

void Graf::najmniejszeTK(PrzydzialZasobow &przydzial) {
    //Ola

}

void Graf::najmniejObciazonyZasob(PrzydzialZasobow &przydzial) {
    //Ola

}
