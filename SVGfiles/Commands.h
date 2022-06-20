#ifndef __COMMANDS_H
#define __COMMANDS_H
#include<iostream>
#include<string>
#include "BasicShapesCollection.h"


class Commands
{
private:
	BasicShapesCollection mBasicShapesCollection;

public:

	void open(std::string fileName); //ok 
	void close(); //ok
	void save();  // ok ?
	void saveAs(std::string fileName); //ok ?
	void help(); //ok
	void exit(); //ok ???
	void print() const; //ok
	/*void create(char* figure);*/  //realized in run
	void erase(size_t n); // ok  ?
	void translate(size_t n);
	void within(); // <option> ??
	void extraFileFunction();

	void run();

};






#endif
