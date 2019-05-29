#include "Graf.hpp"

std::vector<int> znajdzMaxSciezke(const std::vector<std::vector<int>> &sciezki, std::map<int, int> wagi)
{
    int maxWaga = 0;
    std::vector<int> maxSciezka;
    for (auto &sciezka: sciezki) {
        int wagaSciezki = 0;
        for (int wierzcholek: sciezka) {
            wagaSciezki += wagi[wierzcholek];
        }
        if (wagaSciezki > maxWaga) {
            maxWaga = wagaSciezki;
            maxSciezka = sciezka;
        }
    }
    return maxSciezka;
}

std::vector<int> Graf::sciezkaKrytyczna(const PrzydzialZasobow &przydzial) {
    std::map<int, int> czasy;
    for (auto &wierzcholek: m_wierzcholki) {
        int numerWierzcholka = wierzcholek.first;
        int zasob = przydzial.zasobZadania(numerWierzcholka);
        int czas = wierzcholek.second.times[zasob];
        czasy[numerWierzcholka] = czas;
    }
    return znajdzMaxSciezke(wszystkieSciezki(), czasy);
}

std::vector<int> Graf::sciezkaNajdrozsza(const PrzydzialZasobow &przydzial) {
    std::map<int, int> koszty;
    for (auto &wierzcholek: m_wierzcholki) {
        int numerWierzcholka = wierzcholek.first;
        int zasob = przydzial.zasobZadania(numerWierzcholka);
        int koszt = wierzcholek.second.cost[zasob];
        koszty[numerWierzcholka] = koszt;
    }
    return znajdzMaxSciezke(wszystkieSciezki(), koszty);
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
