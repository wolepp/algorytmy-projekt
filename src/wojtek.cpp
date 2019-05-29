#include <iostream>
#include "Graf.hpp"
#include "PrzydzialZasobow.hpp"

int main() {
    using namespace std;

    std::map<int, Info> grafik;
    Info info = {{10},
                 {10},
                 {1, 2, 3}};
    grafik[0] = info;

    info.times = {20};
    info.cost= {5};
    info.dzieci = {4,5};
    grafik[1] = info;

    info.times = {60};
    info.cost= {60};
    info.dzieci = {};
    grafik[2] = info;

    info.times = {5};
    info.cost= {10};
    info.dzieci = {6,7};
    grafik[3] = info;

    info.times = {10};
    info.cost= {5};
    info.dzieci = {};
    grafik[4] = info;

    info.times = {20};
    info.cost= {4};
    info.dzieci = {};
    grafik[5] = info;

    info.times = {15};
    info.cost= {10};
    info.dzieci = {};
    grafik[6] = info;

    info.times = {25};
    info.cost= {20};
    info.dzieci = {};
    grafik[7] = info;

    PrzydzialZasobow przydzial;
    for (int i = 0; i <= 7; i++) {
        przydzial.przydzielZasobZadaniu(0, i);
    }
}
