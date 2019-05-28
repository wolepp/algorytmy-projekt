#include <iostream>
#include "PrzydzialZasobow.hpp"

int main() {
    using namespace std;

    PrzydzialZasobow pz;
    pz.przydzielZasobZadaniu(3, 2);
    cout << pz.zasobZadania(2) << endl;
}
