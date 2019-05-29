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
};

#endif /* ifndef PRZYDZIAL_ZASOBOW_HPP */
