#include "Drzewo.hpp"
#include "Random.hpp"

// funkcjaGenu to wskaźnik na metodę klasy Graf, której parametrem jest referencja do PrzydzialZasobow
typedef void (Graf::*funkcjaGenu)(PrzydzialZasobow&) const;

funkcjaGenu losowyGen() {
    switch (Random::losujInt(0, 3)) {
        case 0:
            return &Graf::najtanszaNajdrozszaSciezka;
        case 1:
            return &Graf::najszybszaSciezkaKrytyczna;
        case 2:
            return &Graf::najmniejszeTK;
        case 3:
            return &Graf::najmniejObciazonyZasob;
    }
    return nullptr;
}

Drzewo::Drzewo(const Drzewo& drzewo) : m_embrion{drzewo.m_embrion} {
    m_root = new Node(*drzewo.m_root);
}

Drzewo::~Drzewo() {
    delete m_root;
}

void Drzewo::ustawEmbrion(PrzydzialZasobow p) {
    m_embrion = p;
}

Drzewo Drzewo::losowyGenotyp() {
    return losowyGenotyp(10);
}

Drzewo Drzewo::losowyGenotyp(int liczbaWezlow) {
    Drzewo d;
    d.m_root = new Node(0);
    for (int i = 0; i < liczbaWezlow; i++) {
        Node *tmp = d.m_root->znajdzWezel(Random::losujInt(0, i));
        tmp->dodajDziecko(i+1);
        tmp->m_gen = losowyGen();
    }
    return d;
}

void DFS(PrzydzialZasobow &przydzial, Node* wezel, const Graf &graf) {
    if (wezel->m_gen != nullptr) {
        WYWOLAJ_METODE(graf, wezel->m_gen)(przydzial);
    }
    for (Node* dziecko: wezel->dzieci()) {
        DFS(przydzial, dziecko, graf);
    }
}

PrzydzialZasobow Drzewo::fenotyp(const Graf &graf) {
    PrzydzialZasobow fenotyp = m_embrion;
    DFS(m_embrion, m_root, graf);
    return fenotyp;
}

Node *Drzewo::znajdzWezel(int id) {
    if (m_root != nullptr) {
        return m_root->znajdzWezel(id);
    }
    return nullptr;
}

int Drzewo::size() {
    if (m_root != nullptr) {
        return m_root->rozmiarPoddrzewa();
    }
    return 0;
}

void Drzewo::operatorMutacji() {
    auto mutowanyWezel = znajdzWezel(Random::losujInt(1, size()-1));
    funkcjaGenu obecnyGen = mutowanyWezel->m_gen;
    funkcjaGenu nowyGen = losowyGen();
    while (nowyGen == obecnyGen) {
        nowyGen = losowyGen();
    }
    mutowanyWezel->m_gen = nowyGen;
}
