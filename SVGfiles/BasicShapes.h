#ifndef __BASICSHAPES_H
#define __BASICSHAPES_H
#include<iostream>
#include<string>

#include "Point.h"


class BasicShapes
{
private:
	/*Point* mPoints;
	size_t mNumberOfPoints;*/
	std::string mColor;
	double mX;
	double mY;

	////help functions
	//void copy(const BasicShapes& other);
	//void deleteDynamic();
public:

	virtual double getX() const = 0;
	virtual double getY() const = 0;
	virtual const std::string getColor() const = 0;

	virtual ~BasicShapes() {}


	////big 4
	//BasicShapes();
	//BasicShapes(size_t numberOfPoints);
	//BasicShapes(const BasicShapes& other);
	//BasicShapes& operator=(const BasicShapes& other);
	//virtual~BasicShapes();

};












#endif
