#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int wigth = 1;
Mat src,src_mode,src_mode2, dst;
void Call_back(int, void*);
int main(int argc, char** argv) {
	

	src = imread("Image1.jpg");
	if (!src.data) {
		cout << "文件为空！";
		return -1;
	}
	cvtColor(src,src_mode,CV_RGBA2GRAY);
	adaptiveThreshold(src_mode,src_mode2,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,11,5);
	//bitwise_not(src_mode2,src_mode2);
	//erode(src_mode2, src_mode2, getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1)));
	//blur(src_mode2,src_mode2,Size(5,5),Point(-1,-1));
	//medianBlur(src_mode2,src_mode2,1);
	Mat X_axix, Y_axix,tmp;

	X_axix = getStructuringElement(MORPH_RECT,Size(src_mode2.cols/10,1),Point(-1,-1));
	Y_axix = getStructuringElement(MORPH_RECT,Size(1,src_mode2.rows/10),Point(-1,-1));
	/*dilate(src_mode2,dst, X_axix);
	erode(dst,tmp, X_axix);*/
	morphologyEx(src_mode2,tmp,MORPH_CLOSE, X_axix,Point(-1,-1));
	namedWindow("src",WINDOW_AUTOSIZE);
	imshow("src",src);
	
	imshow("src_mode1",src_mode);	
	//createTrackbar("变化wigth","src",&wigth,100,Call_back);

	imshow("src_mode2", src_mode2);
	//imshow("dst",dst);
	imshow("tmp",tmp);
	waitKey(0);


	return 0;
}
void Call_back(int, void*) {
	Mat X_axix, Y_axix, tmp;

	X_axix = getStructuringElement(MORPH_RECT, Size(wigth+1, 3), Point(-1, -1));
	Y_axix = getStructuringElement(MORPH_RECT, Size(5, 16), Point(-1, -1));
	erode(src_mode2, dst, Y_axix);
	dilate(src_mode2, tmp, X_axix);

}