#ifndef __COMMANDS_H
#define __COMMANDS_H
#include<iostream>
#include<string>


class Commands
{
public:

	void open(std::string fileName);
	void close(std::string fileName);
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
