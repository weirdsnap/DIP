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
    const getWidth(){
        return this->width;
    }
    const getHeight() {
        return this->height;
    }
    int* operator[](int i);
    void print();
};

Tarray& scale(Tarray src, int height, int width);

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




Tarray& scale(Tarray src, int height, int width) {
    //计算放大倍数
    //float scaleH = height / src.getHeight();
    //float scaleW = width / src.getWidth();
    float scaleH = height - 1 / src.getHeight() - 1;
    float scaleW = width - 1 / src.getWidth() - 1;
    
    //创建新二维数组
    Tarray* dst = new Tarray(height, width);
    //遍历新数组进行赋值
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //i行j列的像素
            dst[i][j];
            int X,Y;
            float srcX, srcY, u,v;
            //求出对应的虚拟像素
            srcX = (float)j / scale;
            srcY = (float)i / scaleH;
            X = srcX;
            Y = srcY;
            u = srcX - X;
            v = srcY - Y;
            //通过(X,Y),(X,Y+1),(X+1,Y),(X+1,Y+1)四点确定目标点像素
            dst[i][j] = src[X][Y] * (1-u) * (1-v) + 
                        src[X+1][Y] * u * (1-v) +
                        src[X][Y+1] * (1-u) * v +
                        src[X+1][Y+1] * u * v;
        }
    }
}

twoDimArray::twoDimArray(int height,int width) {
    this->width = width;
    this->height = height;
    this->a = createTwoDimArray(this->height, this->width);
}

int** twoDimArray::createTwoDimArray(int height, int width) {
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