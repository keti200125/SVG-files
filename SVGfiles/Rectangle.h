#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include "BasicShapes.h"


class Rectangle: public BasicShapes
{
private:

	double mWidth;
	double mHeight;
public:

	Rectangle();
	Rectangle(double x, double y, std::string color, double width, double height);

	BasicShapes* clone() const override;

	double getX() const override;
	double getY() const override;
	const std::string getColor() const override;
};








#endif
