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

void Circle::translate(int newX, int newY)
{
	this->mX += newX;
	this->mY += newY;
}

 
std::ostream& Circle::operator<<(std::ostream& os)  //<circle cx="5" cy="5" r="10" fill="blue" />
{
	os << "<circle cx=" << '"' << this->mX << '"' << ' ' << "cy=" << '"' << this->mY << '"' << ' ' << "r=" << '"' << this->mRadius<< '"' <<' '<<"fill=" << '"' << this->mFill << '"' << ' ' << '/' << '>' << '\n';
	return os;

}