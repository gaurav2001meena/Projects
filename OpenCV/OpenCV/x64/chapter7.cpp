#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



/// shapes

//vector<vector<point>> contours
//vector<Vec4i> hierechy
void getContours(Mat imgDilate,Mat img)

{
	vector<vector<Point>> contours;
	vector<Vec4i> hierechy;
	string objectType;
	
	findContours(imgDilate, contours, hierechy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img,contours,-1,Scalar(255,0,255),5);

	for (int i = 0; i < contours.size(); i++)
	{

		int area = contourArea(contours[i]);
		cout << area << endl;
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect>boundRect(contours.size());
		if (area > 1000)
		{
			float peri = arcLength(contours[i],true);
			approxPolyDP(contours[i], conPoly[i],0.02*peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;
			boundRect[i]=boundingRect(conPoly[i]);
			
			int objcor = (int)conPoly[i].size();

			if (objcor == 3) { objectType = "Tri"; }
			if (objcor == 4) {
				float aspRatio = (float)boundRect[i].width / boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05)
				{
					objectType = "Sqaure";
				}
				else
				{
					objectType = "Rect";
				}
				if (objcor > 4) { objectType = "Circle"; }
			}
			
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, {boundRect[i].x,boundRect[i].y- 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);



		}
	
	
	}



}



void main()
{
	string image = "Resources/shapes.png";
	Mat img = imread(image);
	Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode;
	
	//preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kernel);
	getContours(imgDilate,img);
	
	imshow("pfp", img);
	/*imshow("image_gray", imgGray);
	imshow("image_blur", imgBlur);
	imshow("image_canny", imgCanny);
	imshow("image_Dilate", imgDilate);*/
	
	waitKey(0);

}


