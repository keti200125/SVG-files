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



	void printAll() const;

	void removeShapeByIndex(std::size_t index);
	void addRectangle(int x, int y, std::string fill, int width, int height);
	void addCircle(int x, int y, std::string fill, int radius);
	void addLine(int x1, int y1, std::string fill, int x2, int y2);
	void addEllipse(int x, int y, int rX, int rY, std::string fill);
	void translate(size_t index, int newX, int newY);

	BasicShapesCollection();
	BasicShapesCollection(BasicShapes** shapes, size_t shapesNumber, size_t capacity);
	BasicShapesCollection(const BasicShapesCollection& other);
	BasicShapesCollection& operator=(const BasicShapesCollection& other);
	~BasicShapesCollection();


	void freeAllSpace();
	void writeInFile(std::ostream&);

};








#endif // !__BASICSHAPESCOLLECTION_H

