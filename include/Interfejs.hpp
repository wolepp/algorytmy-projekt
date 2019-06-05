#ifndef INTERFEJS_HPP
#define INTERFEJS_HPP

struct Parametry {
    int alfa;
    double beta;
    double gamma;
    double delta;
    int epsilon;
    int c;
    int t;
    double P_gen1;
    double P_gen2;
    double P_gen3;
    double P_gen4;
};

class Interfejs {
public:
    Parametry pobierzParametry();

private:
    Parametry m_parametry;

};


#endif //INTERFEJS_HPP
