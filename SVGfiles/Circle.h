#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "BasicShapes.h"




class Circle : public BasicShapes
{
private:

	double mRadius;

public:

	Circle();
	Circle(double, double, std::string, double);

	double getX() const override;
	double getY() const override;
	const std::string getColor() const override;
	BasicShapes* clone() const override;
	virtual void print() const override;



};







#endif
