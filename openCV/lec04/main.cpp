/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2019 10:35:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("No image data\n");
        return -1;
    }

    char* imageName = argv[1];
    Mat original = imread(imageName, IMREAD_COLOR);
    Mat modified = imread(imageName, IMREAD_COLOR);

    
    for (int r=0; r<modified.rows; r++)
    {
        
        for (int c=0; c<modified.cols; c++)
        {
            modified.at<cv::Vec3b>(r, c)[0] = modified.at<cv::Vec3b>(r, c)[0] * 0;
        }
    }

    imshow("Original", original);
    imshow("Modified", modified);

    waitKey(0);

    return 0;
}
