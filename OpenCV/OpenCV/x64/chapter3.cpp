#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// resize and crop


void main()
{
	string image = "Resources/pfp.jpg";
	Mat img = imread(image);
	Mat Resize;
	Mat imgcrop;
	

	//cout << img.size() << endl;
	//resize(img, Resize, Size(200,200));
	resize(img, Resize, Size(),0.5,0.5 );
	
	Rect roi(100,100,300,250);
	
	imgcrop = img(roi);


	imshow("pfp", img);
	imshow("resize", Resize);
	imshow("crop", imgcrop);


	waitKey(0);

}


