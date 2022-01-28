#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// images importing


//void main()
//{
//	string image = "Resources/pfp.jpg";
//	Mat img = imread(image);
//	//Mat is matrix datatype  introduces by opencv to handle all the images
//	imshow("pfp", img);
//	waitKey(0);
//	
//}

// video importing
//void main()
//{
//	String vidpath = "Resources/test_video.mp4";
//	VideoCapture cap(vidpath);
//	Mat vidimg;
//
//	while (true)
//	{
//		cap.read(vidimg);
//
//		imshow("video", vidimg);
//		waitKey(20);
//
//
//	}
//
//
//}

// webcam importing

void main()
{

	VideoCapture cap(0);
	Mat img;

	while (true)
	{
		cap.read(img);

		imshow("video", img);
		waitKey(1);


	}
}

