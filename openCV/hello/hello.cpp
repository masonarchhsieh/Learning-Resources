// command: g++ hello.cpp -o hello `pkg-config --cflags --libs opencv4` -std=c++14

#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat test;
    test = imread(argv[1], 1);
    if (!test.data) 
    {
        std::cout << "Couldn't open/find the image" << std::endl;
        return -1;    
    }

    namedWindow("Hello OpenCV", WINDOW_AUTOSIZE);
    imshow("Display Image", test);

    waitKey(0);

    return 0;
}
