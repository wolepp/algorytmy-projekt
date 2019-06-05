//
// Created by wojtek on 06.06.19.
//

#include "Random.hpp"

std::mt19937 Random::m_mt{(std::random_device())()};

int Random::losujInt(int min, int max) {
    static std::uniform_int_distribution<int> dist{min, max};
    return dist(m_mt);
}

double Random::losujDouble(double min, double max) {
    static std::uniform_real_distribution<double> dist{min, max};
    return dist(m_mt);
}
