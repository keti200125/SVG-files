#ifndef __ELLIPSE_H
#define __ELLIPSE_H
#include "BasicShapes.h"

class Ellipse : public BasicShapes
{
	int mRx;
	int mRy;
public:
	Ellipse();
	Ellipse(int, int,int,int, std::string);
	int getX() const override;
	int getY() const override;
	const std::string getFill() const override;
	BasicShapes* clone() const override;
	void print() const override;

	std::ostream& operator<<(std::ostream&) override;

};









#endif
