#include <opencv2/opencv.hpp>
#include <iostream>
#include "twoDimArray.h"

#define Tarray twoDimArray
#define LEVEL 2
#define WIDTH 40
#define HEIGHT 40

using namespace cv;

int main(int argc, char** argv) {
	//读入图像。
	Mat src = imread("E:/image/57.png");//注意分隔符！！！
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	//转化为灰度图像
	cvtColor(src, src, CV_RGB2GRAY);
	//读取像素信息到二维数组
	uchar *p = src.data;
	//自己定义的二维数组类
	Tarray source(src.rows, src.cols);
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			source[i][j] = *p;
			p++;
		}
	}

	//调用二维数组类的缩放函数
	Tarray &dst = source.scale(HEIGHT, WIDTH);

	//调用二维数组的量化函数
	dst.quantize(LEVEL);
	dst.print();
	//初始化Mat数据结构，为了使用opencv的输出
	Mat output_image(dst.getHeight(), dst.getWidth(), CV_8UC1);
	//对Mat进行遍历赋值
	p = output_image.data;
	for (int i = 0; i < output_image.rows; i++) {
		for (int j = 0; j < output_image.cols; j++) {
			*p = dst[i][j];
			p++;
		}
	}
	//显示
	namedWindow("output windows", CV_WINDOW_AUTOSIZE);
	imshow("output windows", output_image);

	//创建窗口，自动大小。
	namedWindow("test opencv setup", CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	//写出图像。
	imwrite("E:/image/output.png", output_image);

	waitKey(0);//键盘按任意键，关闭。
	return 0;
}

/*
//Mat安全迭代器
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
//修改图像：转换色彩空间。
//namedWindow("output windows", CV_WINDOW_AUTOSIZE);
//Mat output_image;
//cvtColor(src, output_image, CV_BGR2HSV);//源和目标彩色空间定义。
//imshow("output windows", output_image);