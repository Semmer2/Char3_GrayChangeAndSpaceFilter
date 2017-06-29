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

	Mat image = imread("test.jpg");

	Mat his = CreateHisto(image);

	imshow("Histogram", his);

	waitKey();

	return 0;
}