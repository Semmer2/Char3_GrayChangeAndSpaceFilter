#pragma once
#include"iostream"
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

vector<Mat> CreateHisto(Mat image,int Code);

void showHisto(Mat image, int Code);
