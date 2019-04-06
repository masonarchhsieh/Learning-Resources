/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *                  1.) Webcam & Video Capture 
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
#include <stdint.h>
#include <opencv2/gapi/own/types.hpp>

using namespace cv;
using namespace std;

const int fps = 20;

void takeDFT(Mat& source, Mat& destination)
{
    Mat originalComplex[2] = {source, Mat::zeros(source.size(), CV_32F)};

    Mat dftReady;
    merge(originalComplex, 2, dftReady);

    dft(dftReady, destination, DFT_COMPLEX_OUTPUT);
}

void recenterDFT(Mat& source)
{
    int centerX = source.cols / 2;
    int centerY = source.rows / 2;

    Mat q1(source, Rect(0, 0, centerX, centerY));
    Mat q2(source, Rect(centerX, 0, centerX, centerY));
    Mat q3(source, Rect(0, centerY, centerX, centerY));
    Mat q4(source, Rect(centerX, centerY, centerX, centerY));

    Mat swapMap;
    
    q1.copyTo(swapMap);
    q4.copyTo(q1);
    swapMap.copyTo(q4);

    q2.copyTo(swapMap);
    q3.copyTo(q2);
    swapMap.copyTo(q3);
}

void showDFT(Mat& source)
{
    Mat splitArray[2] = {Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F)};
    
    split(source, splitArray);

    Mat dftMagnitude;

    magnitude(splitArray[0], splitArray[1], dftMagnitude);

    dftMagnitude += Scalar::all(1);

    log(dftMagnitude, dftMagnitude);

    //CV_MINMAX = 32
    normalize(dftMagnitude, dftMagnitude, 0, 1, 32);
    
    //recenter our DFTimage
    recenterDFT(dftMagnitude);

    imshow("DFT", dftMagnitude);
    waitKey(0);
}

void invertDFT(Mat& source, Mat& destination)
{
    Mat inverse;

    dft(source, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
    
    destination = inverse;

}

void createGaussian(Size size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude = 1.0f)
{
    Mat temp = Mat(size, CV_32F);

    for (int r=0; r<size.height; r++)
    {
        for (int c=0; c<size.width; c++)
        {
            float x = ((c - uX) * ((float)c - uX)) / (2.0f * sigmaX * sigmaX);
            float y = ((r - uY) * ((float)r - uY)) / (2.0f * sigmaY * sigmaY);
            float value = amplitude * exp(-(x+y));
            temp.at<float>(r, c) = value;
        }
    }

    normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX);
    output = temp;
}

int main(int argc, char** argv)
{
    Mat frame;

    // Streaming the video through VLC stream
    // test rtp stream address
    VideoCapture vid("rtp://127.0.0.1:5004");
    
    if (!vid.isOpened())
        return -1;

    while (vid.read(frame))
    {
        imshow("Webcam", frame);

        if (waitKey(1000 / fps) >= 0)
            break;

    }

    return 0;
}
