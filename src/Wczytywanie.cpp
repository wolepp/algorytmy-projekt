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
                    G.m_wierzcholki.insert(std::pair<int, Info>(root, informacja));
                    for (int j = 0; j < size; j++) {
                        int t, x;
                        char y;
                        Dziecko dziecko;
                        myfile >> t >> y >> x >> y;
                        dziecko.id = t;
                        dziecko.waga = x;
                        G.m_wierzcholki.find(i)->second.dzieci.push_back(dziecko);
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

            } else if (pierwsze == "@cost") {
                int x, y, z, a;
                for (int i = 0; i < liczba_zadan; i++) {
                    for (int j = 0; j < zasoby; j++) {
                        myfile >> x;
                        G.m_wierzcholki.find(i)->second.costs.push_back(x);
                    }
                }
            } else if (pierwsze == "@comm") {
                int x;
                std::string tmp;
                myfile >> x >> tmp >> x >> G.przepustowosc;
            }
        }
        return G;
    }
}
