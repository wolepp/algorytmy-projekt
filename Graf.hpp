#include <vector>
#include <map>
#include "PrzydzialZasobow.hpp"

struct Info
{
  std::vector<int> times;
  std::vector<int> cost;
  std::vector<int> dzieci;
};

class Graf
{
  private:
    std::map<int, Info> m_wierzcholki;

  public:
    void krytycznaSciezka(PrzydzialZasobow &przydzial); //gen1
    void najdrozszaSciezka(PrzydzialZasobow &przydzial); //gen2
    void najdrozszeTK(PrzydzialZasobow &przydzial); //gen3
    void najmniejObciazony(PrzydzialZasobow &przydzial); //gen4
};
