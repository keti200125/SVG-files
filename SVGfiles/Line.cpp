#include "Line.h"


Line::Line(): BasicShapes()
{
	this->mX2 = 0;
	this->mY2 = 0;
}
Line::Line(int x1, int y1, std::string fill, int x2, int y2) :BasicShapes(x1,y1,fill)
{
	this->mX2 = x2;
	this->mY2 = y2;

}
int Line::getX() const 
{
	return this->mX;
}
int Line::getY() const
{
	return this->mY;
}
const std::string Line::getFill() const
{
	return this->mFill;
}
BasicShapes* Line::clone() const
{
	BasicShapes* copy = new Line(*this);
	return copy;
}
void Line::print() const
{
	std::cout << "line " << this->mX << " " << this->mY << " " << this->mX2 << " " << this->mY2 << " " << this->mFill;

}


std::ostream& Line::operator<<(std::ostream& os)   //<line x1="30" y1="300" x2="500" y2="100" fill="none"/>
{
	os << "<line x1=" << '"' << this->mX << '"' << ' ' << "y1=" << '"' << this->mY << '"' << ' ' << "x2=" << '"' << this->mX2 << '"' << ' ' << "y2=" << '"' << this->mY2 << '"' << ' ' << "fill=" << '"' << this->mFill << '"' << ' ' << '/' << '>' << '\n';
	return os;

}