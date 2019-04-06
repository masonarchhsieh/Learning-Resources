/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Learning spllit/merge 
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
    
    Mat splitChannels[3];

    split(original, splitChannels);

    imshow("B", splitChannels[0]);
    imshow("G", splitChannels[1]);
    imshow("R", splitChannels[2]);

    waitKey(0);
    
    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);

    Mat output;

    merge(splitChannels, 3, output);
    imshow("Merged", output);

    waitKey(0);

    return 0;
}
