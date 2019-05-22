#include "PrzydzialZasobow.hpp"

void PrzydzialZasobow::przydzielZasobZadaniu
  (int zadanie, int zasob) 
{
  m_przydzial[zadanie] = zasob;
}

int PrzydzialZasobow::zasobZadania(int zadanie)
{
  auto it = m_przydzial.find(zadanie);
  if (it == m_przydzial.end())
  {
    return -1;
  }
  return it->second;
}

std::vector<int> PrzydzialZasobow::zadaniaZasobu(int zasob)
{
  std::vector<int> v;
  for (auto przydzial: m_przydzial)
  {
    if (przydzial.second == zasob)
    {
      v.push_back(przydzial.first);
    }
  }

  return v;
}
