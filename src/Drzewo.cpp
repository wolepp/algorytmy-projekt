#include "Drzewo.hpp"

#include <random>

typedef void (Graf::*funkcjaGenu)(PrzydzialZasobow&);

// random number generator from Stroustrup:
// http://www.stroustrup.com/C++11FAQ.html#std-random
int rand_int(int min, int max) {
    static std::random_device re {};
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid {};
    return uid(re, Dist::param_type{min, max});
}

funkcjaGenu losowyGen() {
    switch (rand_int(0, 3)) {
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
        Node *tmp = d.m_root->znajdzWezel(rand_int(0, i));
        tmp->dodajDziecko(i+1);
        tmp->m_gen = losowyGen();
    }
    return d;
}
