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

	Mat image = imread("test.jpg",CV_LOAD_IMAGE_COLOR);
	Mat his;
	if (image.data)
	{
		imshow("test image", image);
		his = CreateHisto(image,RGBImage);
		//imshow("Histogram", his);
	}
	waitKey();

	return 0;
}