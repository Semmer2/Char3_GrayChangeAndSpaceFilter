#include"iostream"
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;


Mat CreateHisto(Mat image)
{
	int hist_size = 256;
	float range[] = { 0,255 };
	float* ranges[] = { range };
	CvHistogram* GrayHist = cvCreateHist(image.dims, &hist_size, CV_HIST_ARRAY, ranges, 1);//创建一维直方图
	cvCalcHist(&image, GrayHist, 0, 0);
	calcHist
	Mat his=CreateHis(image);
	imshow("Histogram", his);
}
