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
};

class Interfejs {
public:
    Parametry pobierzParametry();

private:
    Parametry m_parametry;

};


#endif //INTERFEJS_HPP
