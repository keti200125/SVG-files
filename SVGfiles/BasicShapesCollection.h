#ifndef __BASICSHAPESCOLLECTION_H
#define __BASICSHAPESCOLLECTION_H
#include "BasicShapes.h"


class BasicShapesCollection
{
private:
	BasicShapes** mShapes;
	size_t mCountShapes;
	size_t mCapacity;

	void deleteDynamic();
	void copy(const BasicShapesCollection& other);
	void resize();

	void addShape(BasicShapes* basicShape);
public:

	void removeShapeByIndex(std::size_t index);
	void addRectangle(double x, double y, std::string color, double width, double height);
	void addCircle(double x, double y, std::string color, double radius);
	void addLine(double x1, double y1, std::string color, double x2, double y2);
	void addEllipse(double x, double y, double rX, double rY, std::string color);

	BasicShapesCollection();
	BasicShapesCollection(BasicShapes** shapes, size_t shapesNumber, size_t capacity);
	BasicShapesCollection(const BasicShapesCollection& other);
	BasicShapesCollection& operator=(const BasicShapesCollection& other);
	~BasicShapesCollection();
};








#endif // !__BASICSHAPESCOLLECTION_H

