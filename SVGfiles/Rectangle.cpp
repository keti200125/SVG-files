#include "Rectangle.h"



//constructors
Rectangle::Rectangle() : BasicShapes()
{
	this->mWidth = 0;
	this->mHeight = 0;
}
Rectangle::Rectangle(double x, double y, std::string color, double width, double height) :BasicShapes(x,y,color)
{
	this->mWidth = width;
	this->mHeight = height;
}

//getters
double Rectangle::getX() const
{
	return this->mX;
}
double Rectangle::getY() const
{
	return this->mY;
}
const std::string Rectangle::getColor() const
{
	return this->mColor;
}




BasicShapes* Rectangle::clone() const
{
	BasicShapes* copy = new Rectangle(*this);
	return copy;
}