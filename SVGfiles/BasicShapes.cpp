#include "BasicShapes.h"





//constructors
BasicShapes::BasicShapes()
{
	this->mX = 0;
	this->mY = 0;
	this->mFill = "none";
}
BasicShapes::BasicShapes(int x, int y, std::string fill)
{
	this->mX = x;
	this->mY = y;
	this->mFill = fill;
}









