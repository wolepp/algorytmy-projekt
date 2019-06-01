#ifndef PRZYDZIAL_ZASOBOW_HPP
#define PRZYDZIAL_ZASOBOW_HPP

#include <map>
#include <vector>

class PrzydzialZasobow {
private:
    std::map<int, int> m_przydzial;

public:
    void przydzielZasobZadaniu(int zasob, int zadanie);
    int zasobZadania(int zadanie) const;
    std::vector<int> zadaniaZasobu(int zasob) const;

    static PrzydzialZasobow losowyPrzydzial(const std::vector<int>& zadania, const std::vector<int>& zasoby);
    static PrzydzialZasobow losowyPrzydzial(int iloscZadan, int iloscZasobow);
    static PrzydzialZasobow losowyPrzydzial(const std::vector<int>& zadania, int iloscZasobow);
    static PrzydzialZasobow losowyPrzydzial(int iloscZadan, const std::vector<int>& zasoby);

};

#endif /* ifndef PRZYDZIAL_ZASOBOW_HPP */
