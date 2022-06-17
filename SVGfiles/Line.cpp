#include "Line.h"


Line::Line(): BasicShapes()
{
	this->mX2 = 0;
	this->mY2 = 0;
}
Line::Line(double x1, double y1, std::string color, double x2, double y2) :BasicShapes(x1,y1,color)
{
	this->mX2 = x2;
	this->mY2 = y2;

}
double Line::getX() const 
{
	return this->mX;
}
double Line::getY() const
{
	return this->mY;
}
const std::string Line::getColor() const
{
	return this->mColor;
}
BasicShapes* Line::clone() const
{
	BasicShapes* copy = new Line(*this);
	return copy;
}
void Line::print() const
{
	std::cout << "line " << this->mX << " " << this->mY << " " << this->mX2 << " " << this->mY2 << " " << this->mColor;

}