#include <iostream>

#include "Interfejs.hpp"

Parametry pobierzWszystkieParametry() {
    Parametry parametry;

    std::cout << "Podaj parametr alfa";
    std::cin >> parametry.alfa;
    //itd.

    return parametry;
}

void wyswietlParametry(const Parametry &parametry) {
    //tutaj wypisuje po linijkach
}

char poprawParametry(Parametry &parametry) {
    char ch = 'x';
    std::cout << "Czy poprawić któryś z parametrów? t/N";
    std::cin >> ch;
    if (ch == 't') {
        std::cout << "Podaj parametr do poprawy: ";
        std::cin >> ch;
        return 'q';
    }
    return 'x';
}

void poprawParametr(Parametry &parametry, char parametr) {
    switch (parametr) {
        case 'a': //alfa
            std::cout << "alfa = ";
            std::cin >> parametry.alfa;
            break;
        //itd.
    }
}

Parametry Interfejs::pobierzParametry() {
    m_parametry = pobierzWszystkieParametry();
    wyswietlParametry(m_parametry);
    char ch = 'x';
    ch = poprawParametry(m_parametry);
    while (ch != 'q') {
        ch = poprawParametry(m_parametry);
    }
    return m_parametry;
}
