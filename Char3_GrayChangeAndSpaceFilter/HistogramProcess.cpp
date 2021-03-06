#include"iostream"
#include<opencv2\opencv.hpp>
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

Mat Hist2Image(MatND &dstHist,int Color);

vector<Mat> CreateHisto(const Mat image,int Code)
{
	vector<Mat> ResultImages;
	switch (Code)
	{
	case GrayImage:
	{
		MatND dstHist;
		int hist_size = 256;
		const int channels = 0;
		float range[] = { 0,255 };
		const float* ranges[] = { range };
		const int histSize[] = { 256 };
		calcHist(&image, 1, &channels, Mat(), dstHist, 1, histSize, ranges, true, false);
		ResultImages.push_back(Hist2Image(dstHist,GRAY));
		break;
	}
	case RGBImage:
	{
		vector<Mat> RGB_planes;
		split(image, RGB_planes);//将图片分为RGB三个颜色的图
		int hist_size = 256;
		const int channels = 0;
		float range[] = { 0,255 };
		const float* ranges[] = { range };
		const int histSize[] = { 256 };
		MatND R_hist;
		MatND G_hist;
		MatND B_hist;
		calcHist(&RGB_planes[0], 1, &channels, Mat(), B_hist, 1, histSize, ranges, true, false);
		calcHist(&RGB_planes[1], 1, &channels, Mat(), G_hist, 1, histSize, ranges, true, false);
		calcHist(&RGB_planes[2], 1, &channels, Mat(), R_hist, 1, histSize, ranges, true, false);

		RGB_planes[0] = Hist2Image(R_hist,RED);
		RGB_planes[1] = Hist2Image(G_hist,GREEN);
		RGB_planes[2] = Hist2Image(B_hist,BLUE);

		ResultImages = RGB_planes;
		break;
	}
	default:
		break;
	}
	return ResultImages;
}

Mat Hist2Image(MatND &dstHist,int Color)
{
	double maxValue = 0;
	double minValue = 0;
	minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
	int histSize = dstHist.rows;
	Mat image(histSize,histSize,CV_8UC3,Scalar(255,255,255));//构造全白图
	
	Scalar S = Scalar(0, 0, 0);
	switch (Color)//更改显示颜色
	{
	case WHITE:
	{
		S = Scalar(255, 255, 255);
		break;
	}
	case RED:
	{
		S = Scalar(0, 0, 255);
		break;
	}
	case BLUE:
	{
		S = Scalar(255, 0, 0);
		break;
	}
	case GREEN:
	{
		S = Scalar(0, 255, 0);
		break;
	}
	case GRAY:
		S = Scalar(100, 100, 100);
	default:
		break;
	}

	int hpt = static_cast<int>(0.9*histSize);
	for (int h = 0; h < histSize; h++)
	{
		float binVal = dstHist.at<float>(h);
		cout << binVal << " ";
		int intensity = static_cast<int>(binVal*hpt / maxValue);

		line(image, Point(h,histSize), Point(h,histSize - intensity), S);
	}

	return image;
}

void showHisto(Mat image,int Code)
{
	vector<Mat> his;
	if (image.data)
	{
		imshow("OriImage", image);
		his = CreateHisto(image, Code);
	}
	for (int i = 0; i < his.size(); i++)
	{
		char HistName[50];
		if (his.size() > 1 && i == 0)
			sprintf(HistName, "Histgram %s", "RED");
		else if (i == 0)
			sprintf(HistName, "Histgram %s", "GRAY");
		else if (i == 1)
			sprintf(HistName, "Histgram %s", "GREEN");
		else if (i == 2)
			sprintf(HistName, "Histgram %s", "BLUE");
		imshow(HistName, his[i]);
	}
}