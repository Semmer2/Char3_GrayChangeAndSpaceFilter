#include"iostream"
#include<opencv2\opencv.hpp>
#include"GrayChange.h"
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;

int main()
{
	Mat OriImage;
	OriImage = imread("test.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	Mat RevImage = GrayLineage(OriImage, Reverse);

	imshow("OriImage", OriImage);
	imshow("RevImage", RevImage);

	waitKey();
	
	return 0;
}