#include "Commands.h"
#include<fstream>
#include "BasicShapesCollection.h"


void Commands::open(std::string fileName)
{
	std::ofstream SVGfileOne(fileName, std::ios::app);


	if (!SVGfileOne.is_open())
	{
		throw "Error while opening file!";
	}
	else
	{
		std::cout << "Successfully opened " << fileName << std::endl;
	}

}

void Commands::close(std::string fileName)
{
	
	
}

void Commands::help()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open <file>       opens <file>" << std::endl;
	std::cout << "close             closes currently opened file" << std::endl;
	std::cout << "save              saves the currently open file" << std::endl;
	std::cout << "saveas <file>     saves the currently open file in <file>" << std::endl;
	std::cout << "help              prints this information" << std::endl;
	std::cout << "exit              exists the program" << std::endl;
	std::cout << "print             displays all figures on the screen" << std::endl;
	std::cout << "create            creates a new figure" << std::endl;
	std::cout << "erase <n>         deletes a figure with sequence number <n>" << std::endl;
	std::cout << "translate [<n>]   translates the figure with sequence number <n> or all figures, if <n> not specified" << std::endl;
	std::cout << "within <option>   displays all shapes that are completely contained in a given region.The user can specify by <option>"<<std::endl;
}

void Commands::print() const
{

}