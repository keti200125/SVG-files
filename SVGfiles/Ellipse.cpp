#include "Ellipse.h"


Ellipse::Ellipse() :BasicShapes()
{
	this->mRx = 0;
	this->mRy = 0;

}
Ellipse::Ellipse(int x, int y, int rX, int rY, std::string fill) :BasicShapes(x,y,fill)
{
	if (rX < 0 || rY < 0)
	{
		throw "Invalid input";
	}
	this->mRx = rX;
	this->mRy = rY;

}
int Ellipse::getX() const
{
	return this->mX;
}
int Ellipse::getY() const
{
	return this->mY;
}
const std::string Ellipse::getFill() const
{
	return this->mFill;
}
BasicShapes* Ellipse::clone() const
{
	BasicShapes* copy = new Ellipse(*this);
	return copy;
}
void Ellipse::print() const
{
	std::cout << "ellipse " << this->mX << " " << this->mY << " " << this->mRx << " " << this->mRy << " " << this->mFill;
}