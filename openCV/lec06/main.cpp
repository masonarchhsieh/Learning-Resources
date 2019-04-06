/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *                  1.) Taking the DFT of a Grayscale Image 
 *                  2.) Visualize the DFT
 *                  3.) Recenter the DFT
 *                  4.) Inverting the DFT
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

using namespace cv;
using namespace std;

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

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("No image data\n");
        return -1; 
    }

    char* imageName = argv[1];
    Mat original = imread(imageName, IMREAD_GRAYSCALE);

    Mat originalFloat;

    original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);

    Mat dftOfOriginal;
    takeDFT(originalFloat, dftOfOriginal);    

    showDFT(dftOfOriginal);
    
    Mat invertedDFT;
    invertDFT(dftOfOriginal, invertedDFT);

    imshow("The invertedDFT", invertedDFT);
    waitKey(0);

    return 0;
}
