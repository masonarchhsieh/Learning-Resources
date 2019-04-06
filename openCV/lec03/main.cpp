/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Learn how to change the size of window
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
    
    Mat image, gray_image;
    image = imread(imageName, IMREAD_UNCHANGED);
    gray_image = imread(imageName, IMREAD_GRAYSCALE);

    namedWindow(imageName, WINDOW_AUTOSIZE);
    namedWindow("Gray image", WINDOW_FREERATIO);

    imshow(imageName, image);
    imshow("Gray image", gray_image);

    //resizeWindow("Color", image.cols/2, image.rows/2);
    //resizeWindow("Fixed", gray_image.cols/2, gray_image.rows/2);

    moveWindow("Color", 1000, 800);
    moveWindow("fixed", 1600, 800);


    waitKey(0);

    return 0;
}
