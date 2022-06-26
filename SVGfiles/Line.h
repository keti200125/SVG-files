#ifndef __LINE_H
#define __LINE_H
#include "BasicShapes.h"


class Line : public BasicShapes
{
private:
	int mX2;
	int mY2;
public:

	Line();
	Line(int, int, std::string, int, int);
	int getX() const override;
	int getY() const override;
	const std::string getFill() const override;
	BasicShapes* clone() const override;
	void print() const override;
	void translate(int newX, int newY) override;


	std::ostream& operator<<(std::ostream&) override;
};










#endif
