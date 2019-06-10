#include <iostream>

#include "PrzydzialZasobow.hpp"

int main() {
    using namespace std;
    
    PrzydzialZasobow p = PrzydzialZasobow::losowyPrzydzial(25,119);
    cout << p;

    return 0;
}
