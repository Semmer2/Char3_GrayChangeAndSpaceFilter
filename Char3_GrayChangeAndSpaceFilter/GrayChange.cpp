#include"iostream"
#include<opencv2\opencv.hpp>
#include"MyNSp.h"

using namespace std;
using namespace cv;
using namespace MyNSP;


Mat GrayLineage(Mat image, int OpCode)
{
	CV_Assert(image.depth() == CV_8U);
	Mat Result;
	switch (OpCode)
	{
		case Reverse:
		{
			Result.create(image.rows, image.cols, image.type());
			MatIterator_<uchar> it = image.begin<uchar>();
			MatIterator_<uchar> end = image.end<uchar>();
			MatIterator_<uchar> itout = Result.begin<uchar>();
			for (; it != end; it++, itout++)
			{
				(*itout) = 255 - (*it);
			}
			break;
		}
	}



	return Result;
}