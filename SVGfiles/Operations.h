#ifndef __OPERATIONS_H
#define __OPERATIONS_H
#include<string>


class Operations
{
public:

	void open(std::string fileName);
	void close();
	void save();
	void SaveAs();
	void help();
	void exit();
	void print();
	void create();
	void erase(size_t n);
	void translate(size_t n);
	void within(); // <option> ??


};




#endif