#include <iostream>
#include <iomanip>
#include "twoDimArray.h"
#define Tarray twoDimArray

Tarray& scale(Tarray src, int height, int width);

int main() {
    Tarray a(5,5);
    float ** b = new float*[5];

    for (int i = 0; i < 5; i++) {
        b[i] = new float[5];
        for (int j = 0; j < 5; j++) {
            a[i][j] = i + j;
            b[i][j] = 1.0 / 25;
        }
    }
    a.print();
    a.jj(5, b);
    a.print();
    return 0;
}

