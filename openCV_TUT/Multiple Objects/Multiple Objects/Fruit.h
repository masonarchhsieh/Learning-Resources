#pragma once
#include <string>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>

class Fruit
{
private:
	int xPos, yPos;
	std::string type;
	cv::Scalar HSVmin, HSVmax;
	cv::Scalar colour;

public:
	Fruit();
	~Fruit();
	
	Fruit(std::string name);

	void setX(int x);
	void setY(int y);
	int getXPos();
	int getYPos();

	std::string getType() { return type;  }
	void setType(std::string t) { type = t;  }

	cv::Scalar getHSVmin();
	cv::Scalar getHSVmax();
	void setHSVmin(cv::Scalar min);
	void setHSVmax(cv::Scalar max);
	
	cv::Scalar getColour() { return colour;  }
	void setColour(cv::Scalar c) { colour = c; }
};

