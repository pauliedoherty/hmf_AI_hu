#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cv::VideoCapture cap(0);             //open default camera
    if(!cap.isOpened())                  //check if camera opened
    {
        return -1;
    }
    cv::Mat* edges =  new cv::Mat;       //Create matrix object
    cv::namedWindow("edges", 1);
    cv::Mat* frame = new cv::Mat;

    while(cv::waitKey(0) != 27)          //loop each time a key is entered, exit if Esc entered
    {
        for(int i = 0; i < 6; i++)       //Hack to bypass internal camera buffer
        {                                //TODO implament this with seperate thread
            cap.read(*frame);
        }
        cv::cvtColor(*frame, *edges, cv::COLOR_BGR2GRAY);  //Convert image
        cv::GaussianBlur(*edges, *edges, cv::Size(7, 7), 1.5, 1.5);
        cv::Canny(*edges, *edges, 0, 30, 3);
        cv::imshow("edges", *edges);
    }

    cap.release();
    delete edges;
    delete frame;
    return 0;

}
