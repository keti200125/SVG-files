#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include "BasicShapes.h"


class Rectangle: public BasicShapes
{
private:

	int mWidth;
	int mHeight;
public:

	Rectangle();
	Rectangle(int, int, std::string, int, int);

	BasicShapes* clone() const override;

	int getX() const override;
	int getY() const override;
	const std::string getFill() const override;

	void print() const override;
	
	std::ostream& operator<<(std::ostream&) override;
};








#endif
