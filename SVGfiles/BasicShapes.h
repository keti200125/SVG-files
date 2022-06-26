#ifndef __BASICSHAPES_H
#define __BASICSHAPES_H
#include<iostream>
#include<string>


class BasicShapes
{
protected:

	std::string mFill;
	int mX;
	int mY;


public:

	//pure virtual functions 
	//this class is abstract
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual const std::string getFill() const = 0;
	virtual BasicShapes* clone() const = 0;
	virtual void print() const = 0;
	virtual void translate(int newX, int newY) = 0;

	BasicShapes();
	BasicShapes(int, int, std::string);
	virtual ~BasicShapes() = default;

	virtual std::ostream& operator<<(std::ostream& write) = 0;
};





#endif
