#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "BasicShapes.h"




class Circle : public BasicShapes
{
private:

	int mRadius;

public:

	Circle();
	Circle(int, int, std::string,int);

	int getX() const override;
	int getY() const override;
	const std::string getFill() const override;
	BasicShapes* clone() const override;
	void print() const override;
	void translate(int newX, int newY) override;

	std::ostream& operator<<(std::ostream&) override;



};







#endif
