/*program to load image, covert it to grayscale, and write */
/*image file using openCV library                          */
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    /*Color space Reduction*/
    int divideWith = 0;                     //Convert input sting to number
    stringstream s;
    s << argv[3];
    s >> divideWith;

    if(!s || !divideWith)
    {
        std::cout << "Invalide number entered for dividing" << std::endl;
        return -1;
    }

    uchar table[256];

    for(int i = 0; i < 256; ++i)
        table[i] = (uchar)(divideWith * (i/divideWith));

    /*Time measurement in openCV*/
    double t = (double) cv::getTickCount();     //returns number of CPU cycles since last called
    //Do something ....
    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    std::cout << "Time passed in seconds " << t << std::endl;

    char* imageName = argv[1];                                 //Read user input arg

    cv::Mat image;                                             //Create object
    image = cv::imread(imageName, 1);                          //Read image file

    if(argc != 2 || !image.data)                               //Check file was read successfully
    {
        printf("No image data\n");
        return -1;
    }

    std::cout << "Line added to test git branch" << std::endl;  //added for git branch test

    cv::Mat grayImage;                                         //Create object to hold gray image
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY );       //Convert the graymap and copy

    std::cout << "M = " << std::endl << " " << grayImage << std::endl;  //Display pixel valus  of image


    cv::imwrite( "../../images/Gray_Image.jpg", grayImage );   //Write gray image to location

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );    //Create display windows for images
    cv::namedWindow("Gray Image", cv::WINDOW_AUTOSIZE);

    cv::imshow("Display Image", image);                        //Display images
    cv::imshow("Gray Image", grayImage);

    cv::waitKey(0);                                            //Wait for user to enter key
    return 0;
}
