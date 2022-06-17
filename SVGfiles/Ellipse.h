#ifndef __ELLIPSE_H
#define __ELLIPSE_H
#include "BasicShapes.h"

class Ellipse : BasicShapes
{
	double mRx;
	double mRy;
public:
	Ellipse();
	Ellipse(double, double,double,double, std::string);
	double getX() const override;
	double getY() const override;
	const std::string getColor() const override;
	BasicShapes* clone() const override;
	void print() const override;

};









#endif
