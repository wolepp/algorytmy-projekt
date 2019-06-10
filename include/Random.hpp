#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random {
public:

private:
    static std::mt19937 m_mt;

public:
    /**
     * Losuje liczbę całkowitą z podanego przedziału.
     * Podane liczby zawierają się w przedziale. Używa
     * generatora liczb pseudolosowych Mersenne Twister.
     * @param min początek przedziału
     * @param max koniec przedziału
     * @return losowa liczba całkowita
     */
    static int losujInt(int min, int max);

    /**
     * Losuje liczbę rzeczywistą z podanego przedziału.
     * Podane liczby zawierają się w przedziale. Używa
     * generatora liczb pseudolosowych Mersenne Twister.
     * @param min początek przedziału
     * @param max koniec przedziału
     * @return losowa liczba rzeczywista
     */
    static double losujDouble(double min, double max);
};


#endif //RANDOM_HPP
