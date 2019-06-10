#include <iostream>

#include "Interfejs.hpp"

Parametry pobierzWszystkieParametry() {
    Parametry parametry;

    // alfa
    do {
        std::cout << "Podaj parametr alfa ";
        std::cin >> parametry.alfa;
    } while (parametry.alfa < 1);

    // maksymalny czas wykonania rozwiązania
    do {
        std::cout << "Podaj maksymalny czas wykonania zadania: ";
        std::cin >> parametry.maksymalnyCzas;
    } while (parametry.maksymalnyCzas <= 0);

    // beta, gamma, delta
    do {
        std::cout << "Podaj parametr beta ";
        std::cin >> parametry.beta;
    } while (parametry.beta >= 1 || parametry.beta < 0);
    do {
        std::cout << "Podaj parametr gamma ";
        std::cin >> parametry.gamma;
    } while (parametry.beta + parametry.gamma > 1 || parametry.gamma < 0);
    parametry.delta = 1 - (parametry.beta + parametry.gamma);

    // epsilon
    do {
        std::cout << "Podaj parametr epsilon ";
        std::cin >> parametry.epsilon;
    } while (parametry.epsilon < 1);

    // c, t
    std::cout << "Podaj parametr c ";
    std::cin >> parametry.c;
    std::cout << "Podaj parametr t ";
    std::cin >> parametry.t;

    // prawdopodobieństwa genów
    do {
        std::cout << "Podaj parametr prawdopodobieństwa genu 1 ";
        std::cin >> parametry.P_gen1;
    } while (parametry.P_gen1 > 1 || parametry.P_gen1 < 0);
    do {
        std::cout << "Podaj parametr prawdopodobieństwa genu 2 ";
        std::cin >> parametry.P_gen2;
    } while (parametry.P_gen1 + parametry.P_gen2 > 1 || parametry.P_gen2 < 0);
    do {
        std::cout << "Podaj parametr prawdopodobieństwa genu 3 ";
        std::cin >> parametry.P_gen3;
    } while (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3 > 1
             || parametry.P_gen3 < 0);
    parametry.P_gen4 = 1 - (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3);

    return parametry;
}

void wyswietlParametry(const Parametry &parametry) {
    std::cout << "Parametr alfa:\t" << parametry.alfa << std::endl;
    std::cout << "Parametr beta:\t" << parametry.beta << std::endl;
    std::cout << "Parametr gamma:\t" << parametry.gamma << std::endl;
    std::cout << "Parametr delta:\t" << parametry.delta << std::endl;
    std::cout << "Parametr epsilon:\t" << parametry.epsilon << std::endl;
    std::cout << "Parametr c:\t" << parametry.c << std::endl;
    std::cout << "Parametr t:\t" << parametry.t << std::endl;
    std::cout << "Parametr prawdopodobieństwa genu 1:\t" << parametry.P_gen1 << std::endl;
    std::cout << "Parametr prawdopodobieństwa genu 2:\t" << parametry.P_gen2 << std::endl;
    std::cout << "Parametr prawdopodobieństwa genu 3:\t" << parametry.P_gen3 << std::endl;
    std::cout << "Parametr prawdopodobieństwa genu 4:\t" << parametry.P_gen4 << std::endl;
}

void poprawParametr(Parametry &parametry, char parametr) {
    switch (parametr) {
        case 'a':
        case 'A':
            std::cout << "alfa = ";
            std::cin >> parametry.alfa;
            break;
        case 'b':
        case 'B':
            do {
                std::cout << "beta = ";
                std::cin >> parametry.beta;
            } while (parametry.beta + parametry.gamma + parametry.delta > 1
                     || parametry.beta < 0);
            break;
        case 'g':
        case 'G':
            do {
                std::cout << "gamma = ";
                std::cin >> parametry.gamma;
            } while (parametry.beta + parametry.gamma + parametry.delta > 1
                     || parametry.gamma < 0);
            break;
        case 'd':
        case 'D':
            do {
                std::cout << "delta = ";
                std::cin >> parametry.alfa;
            } while (parametry.beta + parametry.gamma + parametry.delta > 1
                     || parametry.delta < 0);
            break;
        case 'e':
        case 'E':
            do {
                std::cout << "epsilon = ";
                std::cin >> parametry.epsilon;
            } while (parametry.epsilon < 1);
            break;
        case 'c':
        case 'C':
            std::cout << "c = ";
            std::cin >> parametry.c;
            break;
        case 't':
        case 'T':
            std::cout << "t = ";
            std::cin >> parametry.t;
            break;
        case '1':
            do {
                std::cout << "Prawdopodobieństwo genu 1 = ";
                std::cin >> parametry.P_gen1;
            } while (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3 + parametry.P_gen4 > 1
                     || parametry.P_gen1 < 0);
            break;
        case '2':
            do {
                std::cout << "Prawdopodoieństwo genu 2 = ";
                std::cin >> parametry.P_gen2;
            } while (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3 + parametry.P_gen4 > 1
                     || parametry.P_gen2 < 0);
            break;
        case '3':
            do {
                std::cout << "Prawdopodobieństwo genu 3 = ";
                std::cin >> parametry.P_gen3;
            } while (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3 + parametry.P_gen4 > 1
                     || parametry.P_gen3 < 0);
            break;
        case '4':
            do {
                std::cout << "Prawdopodobieństwo genu 4 = ";
                std::cin >> parametry.P_gen4;
            } while (parametry.P_gen1 + parametry.P_gen2 + parametry.P_gen3 + parametry.P_gen4 > 1
                     || parametry.P_gen4 < 0);
            break;
        case 'm':
        case 'M':
            do {
                std::cout << "Maksymalny czas wykonania rozwiazania: ";
                std::cin >> parametry.maksymalnyCzas;
            } while (parametry.maksymalnyCzas <= 0);
        default:
            std::cout << "Nie ma takiego parametru!\n";
    }
}

void poprawParametry(Parametry &parametry) {
    char ch;
    std::cout << "Podaj parametr do poprawy:\na - alfa\nb - beta\ng - gamma\nd - delta\ne - epsilon\n"
                 "c\nt\n1 - prawdopodobieństwo genu 1\n2 - prawdopodobieństwo genu 2\n"
                 "3 - prawdopodobienstwo genu 3\n4 - prawdopodobieństwo genu 4\n"
                 "m - maksymalny czas wykonania zadania" << std::endl;
    std::cin >> ch;
    poprawParametr(parametry, ch);
}

Parametry Interfejs::pobierzParametry() {
    Parametry parametry;
    parametry = pobierzWszystkieParametry();
    char ch;
    wyswietlParametry(parametry);
    std::cout << "Poprawić parametry? t/N";
    std::cin >> ch;
    while (ch == 't') {
        poprawParametry(parametry);
        wyswietlParametry(parametry);
        std::cout << "Poprawić parametry? t/N";
        std::cin >> ch;
    }
    return parametry;
}
