#include "stdafx.h"
#include "Fruit.h"


void Fruit::setX(int x) 
{
	this->xPos = x;
}

void Fruit::setY(int y)
{
	this->yPos = y;
}

int Fruit::getXPos() 
{
	return this->xPos;
}

int Fruit::getYPos()
{
	return this->yPos;
}

cv::Scalar Fruit::getHSVmin()
{
	return this->HSVmin;
}
cv::Scalar Fruit::getHSVmax()
{
	return this->HSVmax;
}

void Fruit::setHSVmin(cv::Scalar min)
{
	this->HSVmin = min;
}
void Fruit::setHSVmax(cv::Scalar max)
{
	this->HSVmax = max;
}

Fruit::Fruit()
{
}

Fruit::Fruit(std::string name)
{
	setType(name);

	if (name == "apple") {
		setHSVmin(cv::Scalar(30, 59, 50));
		setHSVmax(cv::Scalar(79, 158, 171));

		setColour(cv::Scalar(0, 255, 0));
	}
	else if (name == "banana") {
		setHSVmin(cv::Scalar(0, 100, 117));
		setHSVmax(cv::Scalar(29, 160, 184));

		setColour(cv::Scalar(0, 255, 0));
	}
	else if (name == "orange") {
		setHSVmin(cv::Scalar(11, 115, 102));
		setHSVmax(cv::Scalar(48, 256, 256));

		setColour(cv::Scalar(0, 255, 0));
	}
}

Fruit::~Fruit()
{
}
