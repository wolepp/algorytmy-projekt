#include "Random.hpp"

std::mt19937 Random::m_mt{(std::random_device())()};

int Random::losujInt(int min, int max) {
    if (min > max) {
        return 0;
    }
    using dist = std::uniform_int_distribution<int>;
    static dist uid{};
    return uid(m_mt, dist::param_type{min, max});
}

double Random::losujDouble(double min, double max) {
    if (min > max) {
        return 0;
    }
    using dist = std::uniform_real_distribution<double>;
    static dist urd{};
    return urd(m_mt, dist::param_type{min, max});
}
