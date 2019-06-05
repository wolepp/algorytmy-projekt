#include <math.h>
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

std::vector<int> Graf::sciezkaKrytyczna(const PrzydzialZasobow &przydzial) const {
    std::map<int, int> czasy;
    for (auto &wierzcholek: m_wierzcholki) {
        int numerWierzcholka = wierzcholek.first;
        int zasob = przydzial.zasobZadania(numerWierzcholka);
        int czas = wierzcholek.second.times[zasob];
        czasy[numerWierzcholka] = czas;
    }
    return znajdzMaxSciezke(wszystkieSciezki(), czasy);
}

std::vector<int> Graf::sciezkaNajdrozsza(const PrzydzialZasobow &przydzial) const {
    std::map<int, int> koszty;
    for (auto &wierzcholek: m_wierzcholki) {
        int numerWierzcholka = wierzcholek.first;
        int zasob = przydzial.zasobZadania(numerWierzcholka);
        int koszt = wierzcholek.second.costs[zasob];
        koszty[numerWierzcholka] = koszt;
    }
    return znajdzMaxSciezke(wszystkieSciezki(), koszty);
}

void Graf::znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &sciezki) const {
    for (Dziecko dziecko: m_wierzcholki.at(sciezka.back()).dzieci) {
        sciezka.push_back(dziecko.id);
        znajdzSciezki(sciezka, sciezki);
    }
    if (m_wierzcholki.at(sciezka.back()).dzieci.empty()) {
        sciezki.push_back(sciezka);
    }
    sciezka.pop_back();
}

std::vector<std::vector<int>> Graf::wszystkieSciezki() const {
    std::vector<int> sciezka;
    sciezka.push_back(m_wierzcholki.begin()->first);
    std::vector<std::vector<int>> sciezki;
    znajdzSciezki(sciezka, sciezki);
    return sciezki;
}

void Graf::najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial) const {
    for(auto i: sciezkaKrytyczna(przydzial)){
        int zasob = przydzial.zasobZadania(i);
        int minimalnyCzas = m_wierzcholki.at(i).times[zasob];
        int temp = 0;
        for(int j = 0; j < m_wierzcholki.at(i).times.size(); j++){
            temp = m_wierzcholki.at(i).times[j];
            if(temp < minimalnyCzas){
                minimalnyCzas = temp;
                przydzial.przydzielZasobZadaniu(j, i);
            }
        }
    }
}

void Graf::najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial) const {
    for(auto i: sciezkaNajdrozsza(przydzial)){
        int zasob = przydzial.zasobZadania(i);
        int minimalnyKoszt = m_wierzcholki.at(i).costs[zasob];
        int temp = 0;
        for(int j = 0; j < m_wierzcholki.at(i).costs.size(); j++){
            temp = m_wierzcholki.at(i).costs[j];
            if(temp < minimalnyKoszt){
                minimalnyKoszt = temp;
                przydzial.przydzielZasobZadaniu(j, i);
            }
        }
    }
}

void Graf::najmniejszeTK(PrzydzialZasobow &przydzial) const {
    int iloczynTK = 0;
    int wierzcholekMaxTK = 0;
    for(const auto &i: m_wierzcholki){
        int zasob = przydzial.zasobZadania(i.first);
        int temp = m_wierzcholki.at(i.first).times[zasob] * m_wierzcholki.at(i.first).costs[zasob];
        if(temp > iloczynTK){
            iloczynTK = temp;
            wierzcholekMaxTK = i.first;
        }
    }
    int minIloczynTK = iloczynTK;
    for(int i = 0; i < m_wierzcholki.at(wierzcholekMaxTK).times.size(); i++){
        int temp = m_wierzcholki.at(wierzcholekMaxTK).times[i] * m_wierzcholki.at(wierzcholekMaxTK).costs[i];
        if(temp < minIloczynTK){
            minIloczynTK = temp;
            przydzial.przydzielZasobZadaniu(i, wierzcholekMaxTK);
        }
    }
}

void Graf::najmniejObciazonyZasob(PrzydzialZasobow &przydzial) const {
    int najwiecejZadan = 0;
    int najmniejZadan = m_wierzcholki.size();
    int najbardziejObciazony = 0;
    int najmniejObciazony = 0;
    for(int i = 0; i < m_wierzcholki.at(sciezkaNajdrozsza(przydzial).front()).times.size(); i++){
        int temp = przydzial.zadaniaZasobu(i).size();
        if(temp > najwiecejZadan){
            najwiecejZadan = temp;
            najbardziejObciazony = i;
        }
        if(temp < najmniejZadan){
            najmniejZadan = temp;
            najmniejObciazony = i;
        }
    }
    int czasNajdluzszegoZadanie = 0;
    int najdluzszeZadanie = 0;
    for(auto i: przydzial.zadaniaZasobu(najbardziejObciazony)){
        int temp = m_wierzcholki.at(i).costs[najbardziejObciazony];
        if(temp > czasNajdluzszegoZadanie){
            czasNajdluzszegoZadanie = temp;
            najdluzszeZadanie = i;
        }
    }
    przydzial.przydzielZasobZadaniu(najmniejObciazony, najdluzszeZadanie);
}

std::vector<int> Graf::numeryWierzcholkow() const {
    std::vector<int> v(m_wierzcholki.size());
    int i {0};
    for (const auto &wierzcholek: m_wierzcholki) {
        v[i++] = wierzcholek.first;
    }
    return v;
}

int wzorTC(int waga, int przepustowosc){
    double tC = double (waga) / double (przepustowosc);
    return ceil(tC);
}

int Graf::czasTransmisji(int wierzcholek, const PrzydzialZasobow &przydzial) const{
    int temp = 0;
    int calkowityCzasTransmisji = 0;
    for (Dziecko i: m_wierzcholki.at(wierzcholek).dzieci) {
        temp = czasTransmisji(i.id, przydzial);
        if (przydzial.zasobZadania(wierzcholek) != przydzial.zasobZadania(i.id)) {
            calkowityCzasTransmisji += wzorTC(i.waga, przepustowosc);
        }
        calkowityCzasTransmisji += temp;
    }
    return calkowityCzasTransmisji;
}

int Graf::czasWszytskichZadan(const PrzydzialZasobow &przydzial) const {
    int calkowityCzas = 0;
    for(int i: sciezkaKrytyczna(przydzial)){
        int temp = przydzial.zasobZadania(i);
        calkowityCzas += m_wierzcholki.at(i).times.at(temp);
    }
    calkowityCzas += czasTransmisji(m_wierzcholki.begin()->first, przydzial);
    return calkowityCzas;
}

int Graf::kosztWszystkichZadan(const PrzydzialZasobow &przydzial) const {
    int calkowityKoszt = 0;
    for(auto i: m_wierzcholki){
        int temp = przydzial.zasobZadania(i.first);
        calkowityKoszt += i.second.costs[temp];
    }
    return calkowityKoszt;
}

int Graf::rozmiar() const {
    return m_wierzcholki.size();
}
