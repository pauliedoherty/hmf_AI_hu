#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/cvconfig.h>

using namespace std;
//using namespace cv;

int main(int argc, char* argv[])
{
    char* imageName = argv[1];

    cv::Mat image;
    image = cv::imread(imageName, 1);

    if(argc != 2 || !image.data)
    {
        printf("No image data\n");
        return -1;
    }

    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY );

    cv::imwrite( "../../images/Gray_Image.jpg", grayImage );

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::namedWindow("Gray Image", cv::WINDOW_AUTOSIZE);

    cv::imshow("Display Image", image);
    cv::imshow("Gray Image", grayImage);

    cv::waitKey(0);
    return 0;
}
