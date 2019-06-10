#include <iostream>

#include "Random.hpp"

int main() {
    using namespace std;

    int dd = Random::losujInt(50, 100);
    double af = Random::losujDouble(0, 3);

    for (int i = 0; i < 10; i++) {
        cout << Random::losujInt(1, 10) << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << Random::losujDouble(5, 10) << " ";
    }

    return 0;
}
