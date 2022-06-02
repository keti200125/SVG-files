#include "Circle.h"


//constructors
Circle::Circle() : BasicShapes()
{
	this->mRadius = 0;
}
Circle::Circle(double x, double y, std::string color, double radius): BasicShapes(x,y,color)
{
	this->mRadius = radius;
}

//getters
double Circle::getX() const
{
	return this->mX;
}
double Circle::getY() const
{
	return this->mY;
}
const std::string Circle::getColor() const
{
	return this->mColor;
}


BasicShapes* Circle::clone() const
{
	BasicShapes* copy = new Circle(*this);
	return copy;
}

 
