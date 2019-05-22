#ifndef PRZYDZIAL_ZASOBOW_HPP
#define PRZYDZIAL_ZASOBOW_HPP

#include <map>
#include <vector>

class PrzydzialZasobow
{
  private:
    std::map<int, int> m_przydzial;

  public:
    void przydzielZasobZadaniu(int zadanie, int zasob);
    int zasobZadania(int zadanie);
    std::vector<int> zadaniaZasobu(int zasob);
};

#endif /* ifndef PRZYDZIAL_ZASOBOW_HPP */
