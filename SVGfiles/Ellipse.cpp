#include "Ellipse.h"


Ellipse::Ellipse() :BasicShapes()
{
	this->mRx = 0;
	this->mRy = 0;

}
Ellipse::Ellipse(double x, double y, double rX, double rY, std::string color) :BasicShapes(x,y,color)
{
	this->mRx = rX;
	this->mRy = rY;

}
double Ellipse::getX() const
{
	return this->mX;
}
double Ellipse::getY() const
{
	return this->mY;
}
const std::string Ellipse::getColor() const
{
	return this->mColor;
}
BasicShapes* Ellipse::clone() const
{
	BasicShapes* copy = new Ellipse(*this);
	return copy;
}
void Ellipse::print() const
{

}