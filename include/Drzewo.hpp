#ifndef DRZEWO_HPP
#define DRZEWO_HPP

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

    void ustawEmbrion(PrzydzialZasobow);

    static Drzewo losowyGenotyp(); // liczbaWezlow = 10
    static Drzewo losowyGenotyp(int liczbaWezlow);
};


#endif //DRZEWO_HPP
