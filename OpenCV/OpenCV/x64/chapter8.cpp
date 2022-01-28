#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// images importing


void main()
{
	string image = "Resources/a.png";
	Mat img = imread(image);
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);


	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img,faces[i].tl(),faces[i].br() , Scalar(255, 255, 255), 3);


	}
	//Mat is matrix datatype  introduces by opencv to handle all the images
	imshow("pfp", img);
	waitKey(0);
	
}



