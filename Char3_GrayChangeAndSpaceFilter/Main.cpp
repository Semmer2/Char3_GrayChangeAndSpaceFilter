#include"iostream"
#include<opencv2\opencv.hpp>
#include"GrayChange.h"
#include"HistogramProcess.h"
#include"BlurAndFilter.h"
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

Mat Unsharp(Mat image)
{
	return image;
}

int main()
{

	Mat image = imread("Blur.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	
	//ImageBlurTest(image);
	UnsharpMasking(image);

	return 0;
}