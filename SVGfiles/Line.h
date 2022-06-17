#ifndef __LINE_H
#define __LINE_H
#include "BasicShapes.h"


class Line :BasicShapes
{
private:
	double mX2;
	double mY2;
public:

	Line();
	Line(double, double, std::string, double, double);
	double getX() const override;
	double getY() const override;
	const std::string getColor() const override;
	BasicShapes* clone() const override;
	void print() const override;

};










#endif
