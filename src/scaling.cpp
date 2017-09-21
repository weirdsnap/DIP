#include <opencv2/opencv.hpp>
#include <iostream>
#include "twoDimArray.h"

#define Tarray twoDimArray
#define LEVEL 2
#define WIDTH 40
#define HEIGHT 40

using namespace cv;

int main(int argc, char** argv) {
	//����ͼ��
	Mat src = imread("E:/image/57.png");//ע��ָ���������
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	//ת��Ϊ�Ҷ�ͼ��
	cvtColor(src, src, CV_RGB2GRAY);
	//��ȡ������Ϣ����ά����
	uchar *p = src.data;
	//�Լ�����Ķ�ά������
	Tarray source(src.rows, src.cols);
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			source[i][j] = *p;
			p++;
		}
	}

	//���ö�ά����������ź���
	Tarray &dst = source.scale(HEIGHT, WIDTH);

	//���ö�ά�������������
	dst.quantize(LEVEL);
	dst.print();
	//��ʼ��Mat���ݽṹ��Ϊ��ʹ��opencv�����
	Mat output_image(dst.getHeight(), dst.getWidth(), CV_8UC1);
	//��Mat���б�����ֵ
	p = output_image.data;
	for (int i = 0; i < output_image.rows; i++) {
		for (int j = 0; j < output_image.cols; j++) {
			*p = dst[i][j];
			p++;
		}
	}
	//��ʾ
	namedWindow("output windows", CV_WINDOW_AUTOSIZE);
	imshow("output windows", output_image);

	//�������ڣ��Զ���С��
	namedWindow("test opencv setup", CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	//д��ͼ��
	imwrite("E:/image/output.png", output_image);

	waitKey(0);//���̰���������رա�
	return 0;
}

/*
//Mat��ȫ������
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
// accept only char type matrices
CV_Assert(I.depth() != sizeof(uchar));
const int channels = I.channels();
switch (channels)
{
case 1:
{
MatIterator_<uchar> it, end;
for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
*it = table[*it];
break;
}
case 3:
{
MatIterator_<Vec3b> it, end;
for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
{
(*it)[0] = table[(*it)[0]];
(*it)[1] = table[(*it)[1]];
(*it)[2] = table[(*it)[2]];
}
}
}
return I;
}
*/
//�޸�ͼ��ת��ɫ�ʿռ䡣
//namedWindow("output windows", CV_WINDOW_AUTOSIZE);
//Mat output_image;
//cvtColor(src, output_image, CV_BGR2HSV);//Դ��Ŀ���ɫ�ռ䶨�塣
//imshow("output windows", output_image);