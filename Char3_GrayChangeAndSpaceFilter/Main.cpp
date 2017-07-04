#include"iostream"
#include<opencv2\opencv.hpp>
#include"GrayChange.h"
#include"HistogramProcess.h"
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

int main()
{

	Mat image = imread("test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	showHisto(image, GrayImage);
	

	Mat OutImage(image.rows, image.cols, CV_8U);

	equalizeHist(image, OutImage);
	waitKey();
	showHisto(OutImage, GrayImage);

	waitKey();
	return 0;
}