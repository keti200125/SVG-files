#include "Rectangle.h"



//constructors
Rectangle::Rectangle() : BasicShapes()
{
	this->mWidth = 0;
	this->mHeight = 0;
}
Rectangle::Rectangle(int x, int y, std::string fill, int width, int height) :BasicShapes(x,y,fill)
{
	if (x < 0 || y < 0)
	{
		throw "Invalid input";
	}
	this->mWidth = width;
	this->mHeight = height;
}

//getters
int Rectangle::getX() const
{
	return this->mX;
}
int Rectangle::getY() const
{
	return this->mY;
}
const std::string Rectangle::getFill() const
{
	return this->mFill;
}


BasicShapes* Rectangle::clone() const
{
	BasicShapes* copy = new Rectangle(*this);
	return copy;
}

void Rectangle::print() const
{
	std::cout << "rectangle " << this->mX << " " << this->mY << " " << this->mWidth << " " << this->mHeight << " " << this->mWidth << " " << this->mFill;
}

std::ostream& Rectangle::operator<<(std::ostream& os)
{
	os << "<rect x=" << '"' << this->mX << '"' << ' ' << "y=" << '"' << this->mY << '"' << ' ' << "width=" << '"' << this->mWidth << '"' << ' ' << "height=" << '"' << this->mHeight << '"' << ' ' << "fill=" << '"' << this->mFill << '"' << ' ' << '/' << '>' << '\n';
	return os;
}