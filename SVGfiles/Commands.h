#ifndef __COMMANDS_H
#define __COMMANDS_H
#include<iostream>
#include<string>
#include "BasicShapesCollection.h"


class Commands
{
private:
	BasicShapesCollection& basicShapesCollection;

public:

	void open(std::string fileName);
	void close(std::string fileName);
	void save();
	void saveAs();
	void help();
	void exit();
	void print() const;
	void create();
	void erase(size_t n);
	void translate(size_t n);
	void within(); // <option> ??

};






#endif
