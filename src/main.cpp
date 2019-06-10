#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Wczytywanie.hpp"
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "Interfejs.hpp"
#include "Random.hpp"

typedef std::vector<Drzewo*> Rozwiazania;

/**
 * @param c parametr od użytkownika
 * @param t parametr od użytkownika
 * @param przydzialZasobow osobnik
 * @param graf daje czas i koszt potrzebny do obliczeń
 * @return wartość funkcji dopasowania wg wzoru: c*koszt + t*czas
 */
void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf);

/**
 * Operator mutacji.
 * Dokonuje mutacji na osobnikach podanych w parametrze.
 * @param pokolenie wskaźniki do drzew, na których ma nastąpić mutacja
 * @param liczbaRozwiazan liczba rozwiązań do zmutowania
 * @return Rozwiazania - nowa część pokolenia z mutacji
 */
Rozwiazania mutacja(Rozwiazania &pokolenie, int liczbaRozwiazan);

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

    std::ifstream input;
    std::string filename;
    if (argc == 1) {
        std::cout << "Podaj plik z grafem: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }
    input.open(filename);
    Graf graf = Wczytywanie::wczytaj(input);
    input.close();
    Interfejs interfejs;
    Parametry parametry = interfejs.pobierzParametry();


    return 0;
}

void funkcjaDopasowania(int c, int t, PrzydzialZasobow &przydzialZasobow, Graf &graf){

    int f;
    f=(c*graf.kosztWszystkichZadan(przydzialZasobow))+t* graf.czasZadanNaSciezceKrytycznej(przydzialZasobow);

    przydzialZasobow.setWartoscFunkcjiDopasowania(f);
}

Rozwiazania krzyzowanie(Rozwiazania &osobniki, int liczbaRozwiazan) {
    Rozwiazania R;
    // dwa rozwiązania na jeden obieg pętli
    for (int i = 0; i < liczbaRozwiazan/2; i++) {
        // wylosowanie dwóch osobników
        int j = Random::losujInt(0, osobniki.size()-1);
        int k = Random::losujInt(0, osobniki.size()-1);
        // utworzenie ich kopii
        Drzewo* drzewoA {osobniki[j]};
        Drzewo* drzewoB {osobniki[k]};
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
        auto A {osobniki[Random::losujInt(0, osobniki.size()-1)]};
        auto B {osobniki[Random::losujInt(0, osobniki.size()-1)]};
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
        int wartoscFunkcji = drzewo->fenotyp(graf).getWartoscFunkcjiDopasowania();
        wartosciFD.emplace_back(std::make_pair(drzewo, wartoscFunkcji));
    }
    std::sort(wartosciFD.begin(), wartosciFD.end(),
            [](const std::pair<Drzewo*, int> &lhs, const std::pair<Drzewo*, int> &rhs){
        return lhs.second < rhs.second;
    });
    for (int i = 0; i < liczbaRozwiazan; i++) {
        Drzewo *nowe {wartosciFD[i].first};
    }

    return R;
}

Rozwiazania mutacja(Rozwiazania &pokolenie, int liczbaRozwiazan) {
    Rozwiazania R;

    for (int i = 0; i < liczbaRozwiazan; i++) {
        int indeks = Random::losujInt(0, pokolenie.size()-1);
        Drzewo* staryOsobnik = pokolenie[indeks];
        Drzewo* nowyOsobnik {staryOsobnik};
        nowyOsobnik->operatorMutacji();
        R.push_back(nowyOsobnik);
    }

    return R;
}


