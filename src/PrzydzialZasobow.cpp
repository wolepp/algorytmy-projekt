#include "PrzydzialZasobow.hpp"

#include <random>

// random number generator from Stroustrup:
// http://www.stroustrup.com/C++11FAQ.html#std-random
int rand_int(int min, int max) {
    static std::default_random_engine re {};
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid {};
    return uid(re, Dist::param_type{min, max});
}

void PrzydzialZasobow::przydzielZasobZadaniu(int zasob, int zadanie) {
    m_przydzial[zadanie] = zasob;
}

int PrzydzialZasobow::zasobZadania(int zadanie) const {
    auto it = m_przydzial.find(zadanie);
    if (it == m_przydzial.end()) {
        return -1;
    }
    return it->second;
}

std::vector<int> PrzydzialZasobow::zadaniaZasobu(int zasob) const {
    std::vector<int> v;
    for (auto przydzial: m_przydzial) {
        if (przydzial.second == zasob) {
            v.push_back(przydzial.first);
        }
    }

    return v;
}

PrzydzialZasobow PrzydzialZasobow::losowyPrzydzial(int iloscZadan, int iloscZasobow) {
    std::vector<int> zadania(iloscZadan);
    for (int i = 0; i < iloscZadan; i++) {
        zadania[i] = i;
    }
    return losowyPrzydzial(zadania, iloscZasobow);
}

PrzydzialZasobow PrzydzialZasobow::losowyPrzydzial(const std::vector<int>& zadania, int iloscZasobow) {
    std::vector<int> zasoby(iloscZasobow);
    for (int i = 0; i < iloscZasobow; i++) {
        zasoby[i] = i;
    }
    return losowyPrzydzial(zadania, zasoby);
}

PrzydzialZasobow PrzydzialZasobow::losowyPrzydzial(int iloscZadan, const std::vector<int>& zasoby) {
    std::vector<int> zadania(iloscZadan);
    for (int i = 0; i < iloscZadan; i++) {
        zadania[i] = i;
    }
    return losowyPrzydzial(zadania, zasoby);
}

PrzydzialZasobow PrzydzialZasobow::losowyPrzydzial(const std::vector<int>& zadania, const std::vector<int>& zasoby) {
    PrzydzialZasobow przydzialZasobow;
    for (int zadanie: zadania) {
        int losowyIndex = rand_int(0, zasoby.size()-1);
        przydzialZasobow.przydzielZasobZadaniu(zasoby[losowyIndex], zadanie);
    }
    return przydzialZasobow;
}
