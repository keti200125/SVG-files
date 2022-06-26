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

	void open(std::string fileName);
	void close(); 
	void save(std::string);  
	void SaveAs(std::string fileName);
	void help() const; 
	void exit(std::string); 
	void print() const; 
	void create(); 
	void erase(size_t n);  
	void translate(); 
	/*void withinCircle(int,int,int); 
	void withinRectangle(int, int, int, int); */

	void extraFileFunction();

	void run();

};






#endif
