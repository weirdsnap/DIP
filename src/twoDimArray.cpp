#include "twoDimArray.h"
#include <iostream>
#include <iomanip>

twoDimArray& twoDimArray::scale(int height, int width) {
	twoDimArray &src = *(this);
	int X, Y;
	float srcX, srcY, u, v;
	//����Ŵ���
	//float scaleH = height / src.getHeight();
	//float scaleW = width / src.getWidth();
	float scaleH = (float)(height - 1) / (src.getHeight() - 1);
	float scaleW = (float)(width - 1) / (src.getWidth() - 1);
	//�����¶�ά����
	twoDimArray& dst = *(new twoDimArray(height, width));
	//������������и�ֵ
	for (int i = 0; i < height; i++) {
		//����Ŀ�����ض�Ӧ������Դ����yλ��
		srcY = (float)i / scaleH;
		Y = srcY;
		v = srcY - Y;
		for (int j = 0; j < width; j++) {
			//����Ŀ�����ض�Ӧ������Դ����xλ��
			srcX = (float)j / scaleW;
			X = srcX;
			u = srcX - X;
			//ͨ��(X,Y),(X,Y+1),(X+1,Y),(X+1,Y+1)�ĵ�ȷ��Ŀ�������
			//����Եʱ����Խ������ж�
			dst[i][j] = src[Y][X] * (1.0 - u) * (1.0 - v)
				+ src[Y][X + 1] * u * (1.0 - v)
				+ ((Y + 1) != src.getHeight() ? src[Y + 1][X] : src[Y][X]) * (1.0 - u) * v
				+ ((Y + 1) != src.getHeight() ? src[Y + 1][X + 1] : src[Y][X + 1]) * u * v;

		}
	}
	return dst;
}

twoDimArray& twoDimArray::quantize(int level) {
	twoDimArray &src = *(this);
	int times = 256 / (level - 1);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			src[i][j] = (src[i][j] + (times / 2)) / times * (times-1);
		}
	}
	return src;
}

twoDimArray::twoDimArray(int height, int width) {
	this->width = width;
	this->height = height;
	this->a = createTwoDimArray(this->height, this->width);
}

int** twoDimArray::createTwoDimArray(int height, int width) {
	int **a;
	a = new int*[height];
	for (int i = 0; i < height; i++) {
		a[i] = new int[width]();
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
			std::cout << std::setw(4) << (*this)[i][j] << "|";
		}
		std::cout << std::endl;
	}
}

twoDimArray::~twoDimArray() {
	for (int i = 0; i < height; i++) {
		delete[] a[i];
	}
	delete[] a;
}
