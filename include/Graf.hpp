#ifndef GRAF_HPP
#define GRAF_HPP

#include <vector>
#include <map>

#include "PrzydzialZasobow.hpp"

struct Dziecko {
    int id;
    int waga;
};

struct Info {
    std::vector<int> times;
    std::vector<int> costs;
    std::vector<Dziecko> dzieci;
};

class Graf {
public:
    std::map<int, Info> m_wierzcholki;
    int iloscZasobow;
    int przepustowosc;

    // funkcja pomocnicza
    void znajdzSciezki(std::vector<int> &sciezka, std::vector<std::vector<int>> &) const;

    /**
     * Gen ustawiający najszybszą implementację ścieżki krytycznej.
     * Dla wszystkich zadań ze ścieżki krytycznej wybierane są zasoby,
     * które wykonują te zadania najszybciej
     * @param przydzial na którym działa gen
     */
    void najszybszaSciezkaKrytyczna(PrzydzialZasobow &przydzial) const; //gen1

    /**
     * Gen ustawiający najmniejszy koszt najdroższej ścieżki.
     * Skutkuje przydziałem zadań z najdroższej ścieżki do najtańszych zasobów.
     * @param przydzial na którym działa gen
     */
    void najtanszaNajdrozszaSciezka(PrzydzialZasobow &przydzial) const; //gen2

    /**
     * Gen "najmniejsze t*k".
     * Wybierane jest zadanie, dla którego iloczyn czasu oraz kosztu wykonania
     * jest największy, następnie zadanie to jest przydzielane do zasobu,
     * na którym ten iloczyn jest najmniejszy
     * @param przydzial na którym działa gen
     */
    void najmniejszeTK(PrzydzialZasobow &przydzial) const; //gen3

    /**
     * Gen "najmniej obciążony".
     * Wybierane jest zadanie z najbardziej obciążonego zasobu (tego, który
     * wykonuje najwięcej zadań), którego czas wykonania jest największy
     * i przydzielane jest do najmniej obciążonego zasobu
     * @param przydzial na którym działa gen
     */
    void najmniejObciazonyZasob(PrzydzialZasobow &przydzial) const; //gen4

    /**
     * Numery wierzchołków ze ścieżki krytycznej.
     * @param przydzial
     * @return std::vector<int> z numerami wierzchołków ze ścieżki krytycznej
     */
    std::vector<int> sciezkaKrytyczna(const PrzydzialZasobow &przydzial) const;

    /**
     * Numery wierzchołków ze ścieżki najdroższej.
     * @param przydzial
     * @return std::vector<int> z numerami wierzchołków ze ścieżki najdroższej
     */
    std::vector<int> sciezkaNajdrozsza(const PrzydzialZasobow &przydzial) const;

    /**
     * Numery wszystkich wierzchołków z grafu.
     * @return wektor z numerami
     */
    std::vector<int> numeryWierzcholkow() const;

    /**
     * Znajduje wszystkie ścieżki w grafie.
     * @return wektor wektorów z numerami wierzchołków na ścieżce
     */
    std::vector<std::vector<int>> wszystkieSciezki() const;

    /**
     * Zwraca czas, który jest potrzebny na wykonanie wszystkich zadań.
     * @param przydzial według którego obliczany jest czas
     * @return czas zadań
     */
    int czasZadanNaSciezceKrytycznej(const PrzydzialZasobow &przydzial) const;

    /**
     * Zwraca koszt wykonania wszystkich zadań.
     * @param przydzial według którego obliczany jest koszt
     * @return
     */
    int kosztWszystkichZadan(const PrzydzialZasobow &przydzial) const;

    /**
     * Zwraca liczbę wierzchołków grafu.
     * @return liczba wierzchołków grafu.
     */
    int rozmiar() const;

private:
    int czasTransmisji(int wierzcholek, const PrzydzialZasobow &przydzial) const;
};

#endif //GRAF_HPP
