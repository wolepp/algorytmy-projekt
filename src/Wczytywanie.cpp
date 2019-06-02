//
// Created by wojtek on 01.06.19.
//

#include "Wczytywanie.hpp"

Graf Wczytywanie::wczytaj(std::ifstream &myfile) {
    {
        Graf G;
        Info informacja;
        while (!myfile.eof()) {
            std::string pierwsze;
            int liczba_zadan;
            int zasoby;
            myfile >> pierwsze;
            if (pierwsze == "@tasks") {
                myfile >> liczba_zadan;

                 for (int i = 0; i < liczba_zadan; i++) {
                    char T;
                    int root, size;
                    myfile >> T >> root >> size;
                    G.wierzcholki.insert(std::pair<int, Info>(root, informacja));
                    for (int j = 0; j < size; j++) {
                        int t, x;
                        char y;

                        myfile >> t >> y >> x >> y;
                        G.wierzcholki.find(i)->second.dzieci.push_back(t);
                    }
                }
            } else if (pierwsze == "@proc") {
                myfile >> zasoby;
                G.iloscZasobow = zasoby;

            } else if (pierwsze == "@times") {
                int x;
                for (int i = 0; i < liczba_zadan; i++) {
                    for (int j = 0; j < zasoby; j++) {
                        myfile >> x;
                        G.m_wierzcholki.find(i)->second.times.push_back(x);
                    }
                }

            } else if (pierwsze == "@costs") {
                int x, y, z, a;
                for (int i = 0; i < liczba_zadan; i++) {
                    for (int j = 0; j < zasoby; j++) {
                        myfile >> x;
                        G.m_wierzcholki.find(i)->second.costs.push_back(x);
                    }
                }
            }
        }
        return G;
    }
}
