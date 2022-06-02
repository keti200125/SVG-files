#ifndef __BASICSHAPES_H
#define __BASICSHAPES_H
#include<iostream>
#include<string>


class BasicShapes
{
protected:

	std::string mColor;
	double mX;
	double mY;


public:

	//pure virtual functions 
	//this class is abstract
	virtual double getX() const = 0;
	virtual double getY() const = 0;
	virtual const std::string getColor() const = 0;
	virtual BasicShapes* clone() const = 0;

	BasicShapes();
	BasicShapes(double, double, std::string);
	virtual ~BasicShapes() {}
};





#endif
