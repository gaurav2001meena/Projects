#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// color detection
Mat imgHSV,mask;
int hmin = 0, smin = 110, vmin = 0;
int hmax = 179, smax = 255 ,vmax = 255;
void main()
{
	string image = "Resources/shapes.png";
	Mat img = imread(image);
	//first convert image into hsv space huge stauration value
 cvtColor(img, imgHSV, COLOR_BGR2HSV);
 namedWindow("trackbars", (640, 200));
 createTrackbar("Hue Min", "trackbars", &hmin, 179);
 createTrackbar("Hue Max", "trackbars", &hmax, 179);
 createTrackbar("Sat Min", "trackbars", &smin, 255);
 createTrackbar("Sat Max", "trackbars", &smax, 255);
 createTrackbar("Val Min", "trackbars", &vmin, 255);
 createTrackbar("Val Max", "trackbars", &vmax, 255);
 while (true)
 {


	 Scalar lower(hmin, smin, vmin);
	 Scalar upper(hmax, smax, vmax);
	 inRange(imgHSV, lower, upper, mask);


	 imshow("img", img);
	 imshow("hsv_img", imgHSV);
	 imshow("mask", mask);
	 waitKey(1);


 }
}

