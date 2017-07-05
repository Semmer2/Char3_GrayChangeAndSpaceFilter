#include"iostream"
#include<opencv2\opencv.hpp>
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

void ImageBlurTest(Mat image)
{
	Mat BlurOutImage(image.rows, image.cols, CV_8UC1);
	Mat GuassOutImage(image.rows, image.cols, CV_8UC1);
	Mat MedianOutImage(image.rows, image.cols, CV_8UC1);
	Mat BilOutImage(image.rows, image.cols, CV_8UC1);

	cout << "Blur and Filter Test:" << endl;

	for (int i = 1;; i++)
	{
		int j = i * 2 + 1;
		blur(image, BlurOutImage, Size(j, j));
		imshow("Blur", BlurOutImage);
		GaussianBlur(image, GuassOutImage, Size(j, j), 0, 0);
		imshow("GaussBlur", GuassOutImage);
		medianBlur(image, MedianOutImage, j);
		imshow("MedianBlur", MedianOutImage);
		bilateralFilter(image, BilOutImage, j, j * 2, j / 2);
		imshow("BilBlur", BilOutImage);
		cout << " i: " << j << endl;
		waitKey();
	}
}

void UnsharpMasking(Mat image)
{
	Mat BlurOutImage(image.rows, image.cols, CV_8UC1);
	Mat GuassOutImage(image.rows, image.cols, CV_8UC1);
	Mat OutImage(image.rows, image.cols, CV_8UC1);
	for (int i = 1;; i++)
	{
		int j = i * 2 + 1;
		blur(image, BlurOutImage, Size(j, j));
		GaussianBlur(image, GuassOutImage, Size(j, j), 0, 0);
		GuassOutImage = image - GuassOutImage;
		BlurOutImage = image - BlurOutImage;
		imshow("OriImage", image);
		imshow("GaussOutImage", GuassOutImage);
		imshow("Gauss Unsharp", GuassOutImage + image);
		imshow("Gauss High", GuassOutImage*3 + image);
		imshow("BlurOutImage", BlurOutImage);
		imshow("Blur Unsharp", BlurOutImage + image);
		imshow("Blur High", BlurOutImage * 3 + image);

		cout << "i: " << i;

		waitKey();
	}
}