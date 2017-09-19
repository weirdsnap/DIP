#include <iostream>
#include <iomanip>
#define Tarray twoDimArray

class twoDimArray{
private:
    int width;
    int height;
    int **a;
    int** createTwoDimArray(int width, int height);
public:
    twoDimArray();
    twoDimArray(int,int);
    ~twoDimArray();
    int* operator[](int i);
    void print();
};



int main() {
    Tarray a(3,3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = i + j;
        }
    }
    a.print();
    return 0;
}




twoDimArray::twoDimArray(int w,int h) {
    this->width = w;
    this->height = h;
    this->a = createTwoDimArray(this->width, this->height);
}

int** twoDimArray::createTwoDimArray(int width, int height) {
    int **a;
    a = new int* [height];
    for (int i = 0; i < height; i++) {
        a[i] = new int [width] ();
    }
    return a;
}

int* twoDimArray::operator[](int i) {
    if (i >= 0 && i < height) {
        return a[i];
    }
}

void twoDimArray::print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            std::cout << std::setw(4) <<(*this)[i][j] << "|";
        }
        std::cout << std::endl;
    }
}

twoDimArray::~twoDimArray() {
    for (int i = 0; i < height; i++) {
        delete [] a[i];
    }
    delete [] a;
}