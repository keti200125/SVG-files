#include "Circle.h"


//constructors
Circle::Circle() : BasicShapes()
{
	this->mRadius = 0;
}
Circle::Circle(int x, int y, std::string fill, int radius): BasicShapes(x,y,fill)
{
	if (radius < 0)
	{
		throw "Invalid input";
	}
	this->mRadius = radius;
}

//getters
int Circle::getX() const
{
	return this->mX;
}
int Circle::getY() const
{
	return this->mY;
}
const std::string Circle::getFill() const
{
	return this->mFill;
}


BasicShapes* Circle::clone() const
{
	BasicShapes* copy = new Circle(*this);
	return copy;
}

void Circle::print() const
{
	std::cout << "circle " << this->mX << " " << this->mY << " " << this->mRadius << " " << this->mFill;
}

 
