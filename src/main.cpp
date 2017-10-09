#include <iostream>
#include <iomanip>
#include "twoDimArray.h"
#define Tarray twoDimArray

Tarray& scale(Tarray src, int height, int width);

int main() {
    Tarray a(3,3);
    float ** b = new float*[3];

    for (int i = 0; i < 3; i++) {
        b[i] = new float[3];
        for (int j = 0; j < 3; j++) {
            a[i][j] = i + j;
            b[i][j] = 1.0 / 9;
        }
    }
    a.print();
    a.jj(3, b);
    a.print();
    return 0;
}

