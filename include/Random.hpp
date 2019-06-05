#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random {
public:

private:
    static std::mt19937 m_mt;

public:
    static int losujInt(int min, int max);
    static double losujDouble(double min, double max);
};


#endif //RANDOM_HPP
