#ifndef PRZYDZIAL_ZASOBOW_HPP
#define PRZYDZIAL_ZASOBOW_HPP

#include <map>
#include <vector>
#include <ostream>

class PrzydzialZasobow {
private:
    std::map<int, int> m_przydzial;

public:
    /**
     * Przydziela zasób do zadania
     * @param zasob zasób do przydzielenia
     * @param zadanie zadanie, któremu ma być przydzielony zasób
     */
    void przydzielZasobZadaniu(int zasob, int zadanie);

    /**
     * Zwraca zasób dla podanego zadania
     * @param zadanie
     * @return numer zasobu, który jest przypisany do zadania
     */
    int zasobZadania(int zadanie) const;

    /**
     * Zwraca zadania, do których jest przydzielony zasób.
     * @param zasob numer zasobu, przydzielonego do zadań
     * @return numery zadań, do których przydzielony jest zasob
     */
    std::vector<int> zadaniaZasobu(int zasob) const;

    /**
     * Generuje losowe rozwiązanie.
     * @param zadania wektor numerów zadań
     * @param zasoby wektor numerów zasobów
     * @return losowe rozwiązanie
     */
    static PrzydzialZasobow losowyPrzydzial(const std::vector<int>& zadania, const std::vector<int>& zasoby);

    /**
     * Generuje losowe rozwiązanie.
     * Numery zadań, i zasobów są w przedziale [0, iloscZ.. -1]
     * @param iloscZadan
     * @param iloscZasobow
     * @return
     */
    static PrzydzialZasobow losowyPrzydzial(int iloscZadan, int iloscZasobow);
    static PrzydzialZasobow losowyPrzydzial(const std::vector<int>& zadania, int iloscZasobow);
    static PrzydzialZasobow losowyPrzydzial(int iloscZadan, const std::vector<int>& zasoby);

    friend std::ostream& operator<<(std::ostream& stream, const PrzydzialZasobow& przydzial);

};

#endif /* ifndef PRZYDZIAL_ZASOBOW_HPP */
