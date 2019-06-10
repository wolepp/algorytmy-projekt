//
// Created by wojtek on 02.06.19.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

#include "Graf.hpp"

typedef void (Graf::*funkcjaGenu)(PrzydzialZasobow&) const;

class Node {
public:
    funkcjaGenu m_gen = nullptr;    //wskaźnik na metodę

    Node() = default;
    explicit Node(int);
    Node(const Node &node);
    ~Node();

    /**
     * Znajduje węzeł o podanym id.
     * @param id
     * @return wskaźnik na znaleziony węzeł. nullptr jeśli węzeł nie istnieje
     */
    Node* znajdzWezel(int id);

    /**
     * Znajduje rodzica węzła o podanym id.
     * @param id
     * @return wskaźnik na znaleziony węzeł. nullptr jeśli węzeł nie istnieje
     */
    Node* rodzicWezla(int id);

    /**
     * Dodaje potomka do węzła, na którym metoda jest wywołana.
     * @param id identyfikator potomka do dodania
     * @return wskaźnik na utworzonego potomka
     */
    Node* dodajDziecko(int id);

    /**
     * Zwraca wskaźniki do wszystkich dzieci węzła, na którym metoda jest wywołana.
     * @return
     */
    std::vector<Node*> dzieci();

    /**
     * Zwraca identyfikator węzła, na którym metoda jest wywołana.
     * @return
     */
    int id();

    int rozmiarPoddrzewa();

private:
    int m_id;
    std::vector<Node*> m_dzieci;

    void kopiujDzieci(const Node &node);
};


#endif // NODE_HPP
