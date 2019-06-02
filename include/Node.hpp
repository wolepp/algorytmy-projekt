//
// Created by wojtek on 02.06.19.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

#include "Graf.hpp"

typedef void (Graf::*funkcjaGenu)(PrzydzialZasobow&);

class Node {
public:
    funkcjaGenu m_gen = nullptr;    //wskaźnik na metodę

    Node() = default;
    explicit Node(int);
    Node(const Node &node);

    Node* znajdzWezel(int id);
    Node* rodzicWezla(int id);
    Node* dodajDziecko(int id);
    std::vector<Node*> dzieci();

    int id();

private:
    int m_id;
    std::vector<Node*> m_dzieci;

    void kopiujDzieci(const Node &node);
};


#endif // NODE_HPP
