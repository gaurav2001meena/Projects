#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// warp images

float w = 250, h = 350;
Mat matrix, imgWarp;


void main()
{
	string image = "Resources/cards.jpg";
	Mat img = imread(image);
	
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));


	imshow("pfp", img);
	imshow("warp",imgWarp);
	waitKey(0);

}


