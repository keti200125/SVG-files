#include "BasicShapes.h"





double BasicShapes::getX() const
{
	return this->mX;
}
double BasicShapes::getY() const
{
	return this->mY;
}
const std::string BasicShapes::getColor() const
{
	return this->mColor;
}





////help functions
//void BasicShapes::copy(const BasicShapes& other)
//{
//	this->mNumberOfPoints = other.mNumberOfPoints;
//
//	if (this->mPoints)
//	{
//		delete[] this->mPoints;
//	}
//
//	this->mPoints = new Point[other.mNumberOfPoints];
//	for (int i = 0; i < other.mNumberOfPoints; i++)
//	{
//		this->mPoints[i] = other.mPoints[i];
//	}
//}
//void BasicShapes::deleteDynamic()
//{
//	delete[] this->mPoints;
//}
//
////big 4
//BasicShapes::BasicShapes()
//{
//	this->mNumberOfPoints = 0;
//	this->mPoints = new Point[mNumberOfPoints];
//}
//BasicShapes::BasicShapes(size_t numberOfPoints)
//{
//	this->mNumberOfPoints = numberOfPoints;
//	this->mPoints = new Point[mNumberOfPoints];
//}
//BasicShapes::BasicShapes(const BasicShapes& other)
//{
//	copy(other);
//}
//BasicShapes& BasicShapes::operator=(const BasicShapes& other)
//{
//	if (this != &other)
//	{
//		deleteDynamic();
//		copy(other);
//	}
//
//	return* this;
//}
//BasicShapes::~BasicShapes()
//{
//	deleteDynamic();
//}
//
//
