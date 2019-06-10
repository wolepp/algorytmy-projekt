#include "PrzydzialZasobow.hpp"
#include "Random.hpp"

#include <iostream>
#include <iomanip>

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
    for (const auto &przydzial: m_przydzial) {
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
        int losowyIndex = Random::losujInt(0, zasoby.size()-1);
        przydzialZasobow.przydzielZasobZadaniu(zasoby[losowyIndex], zadanie);
    }
    return przydzialZasobow;
}

int PrzydzialZasobow::getWartoscFunkcjiDopasowania() const {
    return wartoscFunkcjiDopasowania;
}

void PrzydzialZasobow::setWartoscFunkcjiDopasowania(int wartosc) {
    PrzydzialZasobow::wartoscFunkcjiDopasowania = wartosc;
}

std::ostream& operator<<(std::ostream& stream, const PrzydzialZasobow& przydzial) {
    stream << std::setw(7) << "zadanie" << std::setw(8) << "zasób" << std::endl;
    for (const auto& wpis: przydzial.m_przydzial) {
        stream << std::setw(7) << wpis.first << std::setw(7) << wpis.second << std::endl;
    }

    return stream;
}
