#include "Drzewo.hpp"
#include "Random.hpp"

// funkcjaGenu to wskaźnik na metodę klasy Graf, której parametrem jest referencja do PrzydzialZasobow
typedef void (Graf::*funkcjaGenu)(PrzydzialZasobow&) const;

funkcjaGenu losowyGen(P_geny pG) {
    double rand = Random::losujDouble(0, 1);
    if (rand < pG.g1) {
        return &Graf::najtanszaNajdrozszaSciezka;
    } else if (rand < pG.g1 + pG.g2) {
        return &Graf::najszybszaSciezkaKrytyczna;
    } else if (rand < pG.g1 + pG.g2 + pG.g3) {
        return &Graf::najmniejszeTK;
    } else {
        return &Graf::najmniejObciazonyZasob;
    }
}

Drzewo::Drzewo(const Drzewo& drzewo) : m_embrion{drzewo.m_embrion}, m_root{new Node(*drzewo.m_root)} {}

Drzewo::~Drzewo() {
    delete m_root;
}

void Drzewo::ustawEmbrion(PrzydzialZasobow p) {
    m_embrion = p;
}

Drzewo Drzewo::losowyGenotyp(P_geny prawdopodobienstwo) {
    return losowyGenotyp(10, prawdopodobienstwo);
}

Drzewo Drzewo::losowyGenotyp(int liczbaWezlow, P_geny prawdopodobienstwa) {
    Drzewo d;
    d.m_root = new Node(0);
    for (int i = 0; i < liczbaWezlow; i++) {
        Node *tmp = d.m_root->znajdzWezel(Random::losujInt(0, i));
        Node* dziecko = tmp->dodajDziecko(i+1);
        dziecko->m_gen = losowyGen(prawdopodobienstwa);
    }
    //TODO: wygenerować embrion xD
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

void Drzewo::operatorMutacji(P_geny prawdopodobienstwa) {
    auto mutowanyWezel = znajdzWezel(Random::losujInt(1, size()-1));
    funkcjaGenu obecnyGen = mutowanyWezel->m_gen;
    funkcjaGenu nowyGen = losowyGen(prawdopodobienstwa);
    while (nowyGen == obecnyGen) {
        nowyGen = losowyGen(prawdopodobienstwa);
    }
    mutowanyWezel->m_gen = nowyGen;
}
