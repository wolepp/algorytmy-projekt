#ifndef DRZEWO_HPP
#define DRZEWO_HPP

// makro do wywołania metody danego obiektu
#define WYWOLAJ_METODE(object, funcPtr) ((object).*(funcPtr))

#include "PrzydzialZasobow.hpp"
#include "Graf.hpp"
#include "Node.hpp"

#include <vector>

struct P_geny {
    double g1;
    double g2;
    double g3;
    double g4;
};

class Drzewo {
private:
    Node* m_root = nullptr;
    PrzydzialZasobow m_embrion;

public:
    double wartoscFunkcjiDopasowania = 0;

    Drzewo() = default;
    explicit Drzewo(PrzydzialZasobow &p) : m_embrion{p} {};
    Drzewo(const Drzewo& d);
    ~Drzewo();

    /**
     * Przypisuje embrion na zadany przydzialZasobow
     * @param przydzialZasobow rozwiązanie do przypisania
     */
    void ustawEmbrion(PrzydzialZasobow przydzialZasobow);

    /**
     * Wyszukuje w drzewie węzeł o podanym id.
     * @param id identyfikator szukanego węzła
     * @return wskaźnik na znaleziony węzeł
     */
    Node* znajdzWezel(int id);

    /**
     * Oblicza liczbę węzłów drzewa.
     * @return liczba węzłów drzewa.
     */
    int size();

    /**
     * Zwraca fenotyp (rozwiązanie) danego drzewa.
     * @param graf graf na którym dane drzewo ustala rozwiązanie
     * @return PrzydzialZasobow będący rozwiązaniem
     */
    PrzydzialZasobow fenotyp(const Graf &graf);

    /**
     * Zmienia w losowym węźle gen na inny losowo wybrany.
     */
    void operatorMutacji(P_geny prawdopodobienstwa);

    /**
     * Zwraca Drzewo zbudowane w sposób losowy.
     * W korzeniu drzewa jest embrion, również wygenerowany w sposób losowy
     * We wszystkich węzłach (wyłączając korzeń) znajduje się decyzja (gen, funkcja) zmieniająca
     * rozwiązanie.
     * @param liczbaWezlow określa liczbę węzłów budującą dane drzewo
     * @return losowe Drzewo o zadanej liczbie węzłów
     */
    static Drzewo losowyGenotyp(int liczbaWezlow, P_geny prawdopodobienstwa, const Graf &graf);
};


#endif //DRZEWO_HPP
