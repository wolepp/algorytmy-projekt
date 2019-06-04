#ifndef DRZEWO_HPP
#define DRZEWO_HPP

// makro do wywołania metody danego obiektu
#define WYWOLAJ_METODE(object, funcPtr) ((object).*(funcPtr))

#include "PrzydzialZasobow.hpp"
#include "Graf.hpp"
#include "Node.hpp"

#include <vector>

class Drzewo {
private:
    Node* m_root = nullptr;
    PrzydzialZasobow m_embrion;

public:
    Drzewo() = default;
    explicit Drzewo(PrzydzialZasobow &p) : m_embrion{p} {};
    Drzewo(const Drzewo& d);

    /**
     * Przypisuje embrion na zadany przydzialZasobow
     * @param przydzialZasobow rozwiązanie do przypisania
     */
    void ustawEmbrion(PrzydzialZasobow przydzialZasobow);

    /**
     * Zwraca fenotyp (rozwiązanie) danego drzewa.
     * @param graf graf na którym dane drzewo ustala rozwiązanie
     * @return PrzydzialZasobow będący rozwiązaniem
     */
    PrzydzialZasobow fenotyp(const Graf &graf);

    static Drzewo losowyGenotyp(); // liczbaWezlow = 10
    /**
     * Zwraca Drzewo zbudowane w sposób losowy.
     * W korzeniu drzewa jest embrion, również wygenerowany w sposób losowy
     * We wszystkich węzłach (wyłączając korzeń) znajduje się decyzja (gen, funkcja) zmieniająca
     * rozwiązanie.
     * @param liczbaWezlow określa liczbę węzłów budującą dane drzewo
     * @return losowe Drzewo o zadanej liczbie węzłów
     */
    static Drzewo losowyGenotyp(int liczbaWezlow);
};


#endif //DRZEWO_HPP
