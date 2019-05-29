//
// Created by gosia on 29.05.19.
//

#ifndef WCZYTYWANIE_HPP
#define WCZYTYWANIE_HPP

#include "Graf.hpp"

class Wczytywanie{
    Graf wczytaj(Graf G);
};
Graf Wczytywanie::wczytaj(Graf G) {
    {
        Info informacja;
        std::ifstream myfile{"graph10.txt"};
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
                        informacja.dzieci.push_back(t);
                    }
                }
            } else if (pierwsze == "@proc") {
                myfile >> zasoby;

            } else if (pierwsze == "@times") {
                int x;
                for (int i = 0; i < liczba_zadan; i++) {
                    for (int j = 0; j < zasoby; j++) {
                        myfile >> x;
                        G.wierzcholki.find(i)->second.times.push_back(x);
                    }
                }

            } else if (pierwsze == "@cost") {
                int x, y, z, a;
                for (int i = 0; i < liczba_zadan; i++) {
                    for (int j = 0; j < zasoby; j++) {
                        myfile >> x;
                        G.wierzcholki.find(i)->second.costs.push_back(x);
                    }
                }
            }
        }

    }
    return G;
}

#endif //KOSZTY_WCZYTYWANIE_HPP
