#include"iostream"
#include<opencv2\opencv.hpp>
#include"MyNSp.h"
#include"cmath"

using namespace std;
using namespace cv;
using namespace MyNSP;

uchar MinGray(Mat image);
uchar MaxGray(Mat image);

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
		case Expend:
		{
			Result.create(image.rows, image.cols, image.type()); 
			MatIterator_<uchar> it = image.begin<uchar>();
			MatIterator_<uchar> end = image.end<uchar>();
			MatIterator_<uchar> itout = Result.begin<uchar>();
			for (; it != end; it++, itout++)
			{
				uchar val = (int)(*it);
				if (val > 100 && val < 155)
				{
					(*itout) = (int)(((*it)-81)*2.8);
				}
				else if(val<=100)
				{
					(*itout) = (int)0.5* (*it);
					//cout << "<100 ";
				}
				else if(val>=150)
				{
					(*itout) = (int)0.5* (*it)+128;
				}
			}
			cout << "MinGray: "<<(int)MinGray(Result) << endl;
			cout << "MaxGray: " <<(int)MaxGray(Result) << endl;
			break;
		}
	}



	return Result;
}

Mat GrayChange(Mat image, int OpCode)
{
	CV_Assert(image.depth() == CV_8U);
	Mat Result;
	switch (OpCode)
	{
		case LOG:
		{
			Result.create(image.rows, image.cols, image.type());
			MatIterator_<uchar> it = image.begin<uchar>();
			MatIterator_<uchar> end = image.end<uchar>();
			MatIterator_<uchar> itout = Result.begin<uchar>();
			for (; it != end; it++, itout++)
			{
				(*itout) =(int) 255*log10(((*it)/255.0)+1);
			}
			break;
		}
		case POW:
		{
			Result.create(image.rows, image.cols, image.type());
			MatIterator_<uchar> it = image.begin<uchar>();
			MatIterator_<uchar> end = image.end<uchar>();
			MatIterator_<uchar> itout = Result.begin<uchar>();
			for (; it != end; it++, itout++)
			{
				(*itout) = (int)255 * pow((*it)/255.0,3);
			}
			break;
		}
		default:
			break;
	}
	return Result;
}

uchar MinGray(Mat image)
{
	uchar value = 255;
	MatIterator_<uchar> it = image.begin<uchar>();
	MatIterator_<uchar> end = image.end<uchar>();
	for (; it != end; it++)
	{
		value = value < (*it) ? value : (*it);
		//cout << ((int)(*it));
	}
	return value;
}
uchar MaxGray(Mat image)
{
	uchar value = 0;
	MatIterator_<uchar> it = image.begin<uchar>();
	MatIterator_<uchar> end = image.end<uchar>();
	for (; it != end; it++)
	{
		value = value > (*it) ? value : (*it);
	}
	return value;
}