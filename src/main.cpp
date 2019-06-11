#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

#include "Wczytywanie.hpp"
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "Interfejs.hpp"
#include "Random.hpp"

typedef std::vector<Drzewo*> Rozwiazania;

/**
 * @param c parametr od użytkownika
 * @param t parametr od użytkownika
 * @param drzewo osobnik
 * @param graf daje czas i koszt potrzebny do obliczeń
 * @return wartość funkcji dopasowania wg wzoru: c*koszt + t*czas
 */
double funkcjaDopasowania(double c, double t, Drzewo &drzewo, Graf &graf);

/**
 * Operator mutacji.
 * Dokonuje mutacji na osobnikach podanych w parametrze.
 * @param pokolenie wskaźniki do drzew, na których ma nastąpić mutacja
 * @param liczbaRozwiazan liczba rozwiązań do zmutowania
 * @return Rozwiazania - nowa część pokolenia z mutacji
 */
Rozwiazania mutacja(Rozwiazania &pokolenie, int liczbaRozwiazan, P_geny prawdopodobienstwaGenow);

/**
 * Operator selekcji.
 * Rozwiązania są przechowywane na liście rankingowej. Z niej wybierane
 * są osobniki.
 * @param pokolenie
 * @param liczbaRozwiazan liczba rozwiązań do selekcji
 * @return Rozwiazania - nowa część pokolenia z selekcji
 */
Rozwiazania selekcja(Rozwiazania &pokolenie, int liczbaRozwiazan, Graf &graf);

/**
 * Operator krzyżowania.
 * Krzyżuje drzewa spośród wybranych.
 * @param osobniki
 * @param liczbaRozwiazan liczba osobników, które mają wyjść z krzyżowania
 * @return Rozwiazania - nowa część pokolenia z krzyżowania
 */
Rozwiazania krzyzowanie(Rozwiazania &osobniki, int liczbaRozwiazan);

int main(int argc, char *argv[]) {

    // otworzenie pliku i wczytanie grafu
    std::ifstream input;
    std::string filename;
    if (argc == 1) {
        std::cout << "Podaj plik z grafem: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }
    input.open(filename);
    if (!input.good()) {
        std::cout << "Błąd pliku";
        return -1;
    }
    Graf graf = Wczytywanie::wczytaj(input);
    input.close();

    // pobranie parametrów od użytkownika
    Parametry parametry = Interfejs::pobierzParametry();
    const int PI = static_cast<int>(parametry.alfa * graf.rozmiar() * graf.iloscZasobow);
    const int FI = static_cast<int>(parametry.beta * PI);
    const int PSI = static_cast<int>(parametry.gamma * PI);
    const int OMEGA = static_cast<int>(parametry.delta * PI);
    P_geny prawdGenow {parametry.P_gen1, parametry.P_gen2,
                                    parametry.P_gen3, parametry.P_gen4};

    // generowanie pokolenia początkowego
    Rozwiazania pokoleniePoczatkowe;
    for (int i = 0; i < PI; i++) {
        // generuje drzewo o ilości węzłów między 5 a 15
        Drzewo* drzewo = new Drzewo(Drzewo::losowyGenotyp(
                Random::losujInt(5, 15),
                prawdGenow, graf));
        pokoleniePoczatkowe.push_back(drzewo);
    }

    double minimumFD = INT_MAX;
    int pokoleniaBezLepszego = 0;
    int iloscPokolen = 0;
    PrzydzialZasobow najlepszy;
    while (pokoleniaBezLepszego < parametry.epsilon) {

        for (auto rozwiazanie: pokoleniePoczatkowe) {
            funkcjaDopasowania(parametry.c, parametry.t, *rozwiazanie, graf);
        }

        // generowanie rozwiązań
        Rozwiazania zSelekcji = selekcja(pokoleniePoczatkowe, FI, graf);
        Rozwiazania zKrzyzowania = krzyzowanie(pokoleniePoczatkowe, PSI);
        Rozwiazania zMutacji = mutacja(pokoleniePoczatkowe, OMEGA, prawdGenow);

        // zapisywanie
        Rozwiazania nowePokolenie = zSelekcji;
        nowePokolenie.insert(nowePokolenie.end(), zKrzyzowania.begin(), zKrzyzowania.end());
        nowePokolenie.insert(nowePokolenie.end(), zMutacji.begin(), zMutacji.end());

        // szukanie najlepszego rozwiązania
        bool istniejeLepszy = false;
        for (auto rozwiazanie: nowePokolenie) {
            double fd = funkcjaDopasowania(parametry.c, parametry.t, *rozwiazanie, graf);
            if (fd < minimumFD) {
                minimumFD = fd;
                najlepszy = rozwiazanie->fenotyp(graf);
                istniejeLepszy = true;
            }
        }
        if (istniejeLepszy) {
            pokoleniaBezLepszego = 0;
        } else {
            pokoleniaBezLepszego++;
        }

        // usuwanie starych rozwiązań
        for (auto it = pokoleniePoczatkowe.begin(); it != pokoleniePoczatkowe.end();){
            delete *it;
            it = pokoleniePoczatkowe.erase(it);
        }

        // przeniesienie nowego pokolenia jako starego
        pokoleniePoczatkowe.insert(pokoleniePoczatkowe.end(), nowePokolenie.begin(), nowePokolenie.end());
        iloscPokolen++;
    }

    // wypisanie najlepszego przydziału zasobów
    std::cout << "Znaleziono w " << iloscPokolen-parametry.epsilon << " pokoleniu\n";
    std::cout << "Wartość funkcji dopasowania: " << minimumFD << std::endl;
    std::cout << najlepszy;

    return 0;
}

double funkcjaDopasowania(double c, double t, Drzewo &drzewo, Graf &graf) {
    auto fenotyp = drzewo.fenotyp(graf);
    double f = (c*graf.kosztWszystkichZadan(fenotyp) + t*graf.czasZadanNaSciezceKrytycznej(fenotyp));
    drzewo.wartoscFunkcjiDopasowania = f;
    return f;
}

Rozwiazania krzyzowanie(Rozwiazania &osobniki, int liczbaRozwiazan) {
    Rozwiazania R;
    // dwa rozwiązania na jeden obieg pętli
    for (int i = 0; i < liczbaRozwiazan/2; i++) {
        // wylosowanie dwóch osobników
        int j = Random::losujInt(0, osobniki.size()-1);
        int k = Random::losujInt(0, osobniki.size()-1);
        // utworzenie ich kopii
        auto* drzewoA = new Drzewo {*osobniki[j]};
        auto* drzewoB = new Drzewo {*osobniki[k]};
        // wylosowanie punktów w których drzewa się skrzyżują
        int losowyWezelA = Random::losujInt(1, drzewoA->size()-1);
        int losowyWezelB = Random::losujInt(1, drzewoB->size()-1);
        auto pktKrzyzowaniaA = drzewoA->znajdzWezel(losowyWezelA);
        auto pktKrzyzowaniaB = drzewoB->znajdzWezel(losowyWezelB);
        //skrzyżowanie
        std::swap(pktKrzyzowaniaA, pktKrzyzowaniaB);
        R.push_back(drzewoA);
        R.push_back(drzewoB);
    }
    // jeśli jest nieparzyście do dodaj jeszcze jedno
    if (liczbaRozwiazan % 2 != 0) {
        auto* A = new Drzewo {*osobniki[Random::losujInt(0, osobniki.size()-1)]};
        auto* B = new Drzewo {*osobniki[Random::losujInt(0, osobniki.size()-1)]};
        auto pktA = A->znajdzWezel(Random::losujInt(1, A->size()-1));
        auto pktB = B->znajdzWezel(Random::losujInt(1, B->size()-1));
        std::swap(pktA, pktB);
        R.push_back(A);
    }
    return R;
}

Rozwiazania selekcja(Rozwiazania &pokolenie, int liczbaRozwiazan, Graf &graf) {
    Rozwiazania R;
    std::vector<std::pair<Drzewo*, int>> wartosciFD;
    for (Drzewo* drzewo: pokolenie) {
        int wartoscFunkcji = drzewo->wartoscFunkcjiDopasowania;
        wartosciFD.emplace_back(std::make_pair(drzewo, wartoscFunkcji));
    }
    std::sort(wartosciFD.begin(), wartosciFD.end(),
            [](const std::pair<Drzewo*, int> &lhs, const std::pair<Drzewo*, int> &rhs){
        return lhs.second < rhs.second;
    });
    for (int i = 0; i < liczbaRozwiazan; i++) {
        auto *nowe = new Drzewo(*wartosciFD[i].first);
        R.push_back(nowe);
    }

    return R;
}

Rozwiazania mutacja(Rozwiazania &pokolenie, int liczbaRozwiazan, P_geny prawdopodobienstwaGenow) {
    Rozwiazania R;

    for (int i = 0; i < liczbaRozwiazan; i++) {
        int indeks = Random::losujInt(0, pokolenie.size()-1);
        Drzewo* staryOsobnik = pokolenie[indeks];
        auto* nowyOsobnik = new Drzewo(*staryOsobnik);
        nowyOsobnik->operatorMutacji(prawdopodobienstwaGenow);
        R.push_back(nowyOsobnik);
    }

    return R;
}


