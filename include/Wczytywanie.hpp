//
// Created by gosia on 29.05.19.
//

#ifndef WCZYTYWANIE_HPP
#define WCZYTYWANIE_HPP

#include <fstream>

#include "Graf.hpp"

class Wczytywanie {
public:
    static Graf wczytaj(std::ifstream &input);
};

#endif //KOSZTY_WCZYTYWANIE_HPP
