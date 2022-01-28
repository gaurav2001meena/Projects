#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// Basic functions


void main()
{
	string image = "Resources/pfp.jpg";
	Mat img = imread(image);
	Mat imgGray, imgBlur,imgCanny,imgDilate,imgErode;

	//Mat is matrix datatype  introduces by opencv to handle all the images

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur,Size(7,7),5,0);
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate,kernel );
	erode(imgDilate, imgErode, kernel);


	imshow("pfp", img);
	imshow("image_gray", imgGray);
	imshow("image_blur", imgBlur);
	imshow("image_canny", imgCanny);
	imshow("image_Dilate", imgDilate);
	imshow("image_Erode", imgErode);
	waitKey(0);
	
}


