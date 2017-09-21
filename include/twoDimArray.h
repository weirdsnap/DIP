#pragma once
class twoDimArray {
private:
	int width;
	int height;
	int **a;
	int** createTwoDimArray(int width, int height);
public:
	twoDimArray() {};
	twoDimArray(int, int);
	~twoDimArray();
	int getWidth()  const {
		return this->width;
	}
	int getHeight() const {
		return this->height;
	}
	int* operator[](int i);
	twoDimArray& scale(int height, int width);
	twoDimArray& scale(int times) {
		// uncomplete
	}
	twoDimArray& quantize(int level);
	void print();
};

