#ifndef WCZYTYWANIE_HPP
#define WCZYTYWANIE_HPP

#include <fstream>

#include "Graf.hpp"

class Wczytywanie {
public:
    /**
     * Wczytuje graf z podanego strumienia plikowego
     * @param input
     * @return
     */
    static Graf wczytaj(std::ifstream &input);
};

#endif //KOSZTY_WCZYTYWANIE_HPP
