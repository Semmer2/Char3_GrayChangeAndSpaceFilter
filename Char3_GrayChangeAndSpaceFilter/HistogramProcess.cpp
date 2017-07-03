#include"iostream"
#include<opencv2\opencv.hpp>
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

Mat Hist2Image(MatND &dstHist);

Mat CreateHisto(const Mat image,int Code)
{
	MatND dstHist;
	switch (Code)
	{
	case GrayImage:
	{
		int hist_size = 256;
		const int channels = 0;
		float range[] = { 0,255 };
		const float* ranges[] = { range };
		const int histSize[] = { 256 };
		calcHist(&image, 1, &channels, Mat(), dstHist, 1, histSize, ranges, true, false);
		break;
	}
	case RGBImage:
	{
		//RGB图像代码未完成

	}
	default:
		break;
	}
	return Hist2Image(dstHist);
}

Mat Hist2Image(MatND &dstHist)
{
	double maxValue = 0;
	double minValue = 0;
	minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
	int histSize = dstHist.rows;
	Mat image(histSize,histSize,CV_8U,Scalar(255));//构造全白图
	
	int hpt = static_cast<int>(0.9*histSize);
	for (int h = 0; h < histSize; h++)
	{
		float binVal = dstHist.at<float>(h);
		cout << binVal << " ";
		int intensity = static_cast<int>(binVal*hpt / maxValue);
		//line(image, Point(h, histSize), Point(h, histSize - intensity), Scalar::all(0));
		line(image, Point(histSize,h), Point(histSize - intensity,h), Scalar::all(130));
	}

	return image;
}
