#include "BasicShapesCollection.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Ellipse.h"



//help functions

void BasicShapesCollection::deleteDynamic()
{
	for (int i = 0; i < this->mCountShapes; i++)
	{
		delete this->mShapes[i];
	}
	delete[] this->mShapes;
}
void BasicShapesCollection::copy(const BasicShapesCollection& other)
{
	this->mShapes = new BasicShapes * [other.mCapacity];
	this->mCountShapes = other.mCountShapes;
	this->mCapacity = other.mCapacity;
	for (int i = 0; i < other.mCapacity; i++)
	{
		this->mShapes[i] = other.mShapes[i]->clone();
		
	}
}
void BasicShapesCollection::resize()
{
	BasicShapes** helpCollection = new BasicShapes * [this->mCapacity *=2];
	for (int i = 0; i < this->mCountShapes; i++)
	{
		helpCollection[i] = this->mShapes[i];
	}
	delete[] this->mShapes;
	this->mShapes = helpCollection;
}


//big 4 
BasicShapesCollection::BasicShapesCollection()
{
	this->mCountShapes = 0;
	this->mCapacity = 10;
	this->mShapes = new BasicShapes * [this->mCapacity];
}
BasicShapesCollection::BasicShapesCollection(BasicShapes** shapes, size_t countShapes, size_t capacity)
{
	this->mCountShapes = countShapes;
	this->mCapacity = capacity;
	this->mShapes = new BasicShapes * [this->mCountShapes];
	for (int i = 0; i < this->mCountShapes; i++)
	{
		this->mShapes[i] = shapes[i]->clone();
	}
}
BasicShapesCollection::BasicShapesCollection(const BasicShapesCollection& other)
{
	copy(other);
}
BasicShapesCollection& BasicShapesCollection::operator=(const BasicShapesCollection& other)
{
	if (this != &other)
	{
		deleteDynamic();
		copy(other);
	}
	return *this;
}
BasicShapesCollection::~BasicShapesCollection()
{
	deleteDynamic();
}


void BasicShapesCollection::addShape(BasicShapes* basicShape)
{
	if (this->mCountShapes == this->mCapacity)
	{
		resize();
	}
	this->mShapes[this->mCountShapes++] = basicShape;
}
void BasicShapesCollection::addRectangle(double x, double y, std::string color, double width, double height)
{
	Rectangle* rectangle = new Rectangle(x, y, color, width, height);
	addShape(rectangle);

}
void BasicShapesCollection::addCircle(double x, double y, std::string color, double radius)
{
	Circle* circle = new Circle(x, y, color, radius);
	addShape(circle);
}
void BasicShapesCollection::addLine(double x1, double y1, std::string color, double x2, double y2)
{
	Line* line = new Line(x1, y1, color, x2, y2);
	addShape(line);
}
void BasicShapesCollection::addEllipse(double x, double y, double rX, double rY, std::string color)
{
	Ellipse* ellipse = new Ellipse(x, y, rX, rY, color);
	addShape(ellipse);
}

void BasicShapesCollection::removeShapeByIndex(std::size_t index) //
{
	BasicShapes** currCollection = new BasicShapes * [this->mCapacity];


}

void BasicShapesCollection::printAll() const
{
	for (int i = 0; i < this->mCountShapes; i++)
	{
		this->mShapes[i]->print();
	}
}


