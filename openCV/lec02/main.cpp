/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: In this tutorial you will learn how to:
 *                      Load an image using cv::imread
 *                      Transform an image from BGR to Grayscale format by using cv::cvtColor
 *                      Save your transformed image in a file on disk (using cv::imwrite ) 
 *
 *        Version:  1.0
 *        Created:  02/02/2019 12:00:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("No image data\n");
        return -1; 
    }

    char* imageName = argv[1];
    
    Mat image;
    image = imread(imageName, 1);
    
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    imwrite("./Gray_Image.jpg", gray_image);

    namedWindow(imageName, WINDOW_AUTOSIZE);
    namedWindow("Gray image", WINDOW_AUTOSIZE);

    imshow(imageName, image);
    imshow("Gray image", gray_image);
    waitKey(0);

    return 0;
}
