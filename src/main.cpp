#include <iostream>
#include <fstream>
#include <string>

#include "Graf.hpp"
#include "Wczytywanie.hpp"

int main(int argc, char *argv[]) {

    std::ifstream input;
    std::string filename;
    if (argc == 1) {
        std::cout << "Podaj plik z grafem: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }
    input.open(filename);
    Graf graf = Wczytywanie::wczytaj(input);
    input.close();

    std::cout << "EEO";

    // pobierz parametry
    // ogólnie w jakiejś pętli wyświetlanie i akceptowanie


    return 0;
}
