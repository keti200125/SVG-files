#include "Commands.h"
#include<fstream>



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
	std::cout << "open <file>     opens <file>" << std::endl;
	std::cout << "close           closes currently opened file" << std::endl;
	std::cout << "save            saves the currently open file" << std::endl;
	std::cout << "saveas <file>   saves the currently open file in <file>" << std::endl;
	std::cout << "help            prints this information" << std::endl;
	std::cout << "exit            exists the program" << std::endl;
}

void Commands::print()
{

}