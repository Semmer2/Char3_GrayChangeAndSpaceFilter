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
	OriImage = imread("people.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	Mat RevImage = GrayLineage(OriImage, Reverse);
	Mat LogImage = GrayChange(OriImage, LOG);
	Mat PowImage = GrayChange(OriImage, POW);
	Mat ExpImage = GrayLineage(OriImage, Expend);

	imshow("OriImage", OriImage);
	imshow("RevImage", RevImage);
	imshow("LogImage", LogImage);
	imshow("PowImage", PowImage);
	imshow("ExpImage", ExpImage);

	imwrite("ExpImage.jpg", ExpImage);

	waitKey();

	return 0;
}