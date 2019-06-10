#ifndef INTERFEJS_HPP
#define INTERFEJS_HPP

struct Parametry {
    int alfa;
    int epsilon;
    int c;
    int t;
    int maksymalnyCzas;
    double beta;
    double gamma;
    double delta;
    double P_gen1;
    double P_gen2;
    double P_gen3;
    double P_gen4;
};

class Interfejs {
public:
    static Parametry pobierzParametry();
};


#endif //INTERFEJS_HPP
