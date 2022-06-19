#include "Commands.h"
#include<fstream>
#include "BasicShapesCollection.h"
#include<cstring>
#pragma warning(disable: 4996)

void Commands::open(std::string fileName)
{
	std::ifstream SVGFileOne(fileName, std::ios::in);


	if (!SVGFileOne)
	{
		std::ofstream SVGFileTwo(fileName, std::ios::out);

		if (!SVGFileTwo.is_open())
		{
			throw "File isn't opened";
		}
		else
		{
			SVGFileTwo << "<?xml version=" << '"' << "1.0" << '"' << " standalone =" << '"' << "no" << '"' << "?>"<< '\n';
			SVGFileTwo << "<!DOCTYPE svg PUBLIC " << '"' << " -//W3C//DTD SVG 1.1//EN" << '"' << '\n';
			SVGFileTwo << '"' << "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd" << '"' << '>' << '\n';
			SVGFileTwo << "<svg>" << '\n';
			SVGFileTwo << "</svg>";
			std::cout << "Successfully created new file " << fileName << std::endl;
			SVGFileTwo.close();
		}

	}
	else
	{
		std::cout << "Successfully opened " << fileName << std::endl;
	}


	//we get the size of the file
	size_t current = SVGFileOne.tellg();
	SVGFileOne.seekg(0, std::ios::end);
	size_t size = SVGFileOne.tellg();
	SVGFileOne.seekg(current);

	//now we put what we read from the file in char
	char* readFromFile;
	SVGFileOne.read(readFromFile, size);
	readFromFile[size]= '\0';

	SVGFileOne.close();
	//dont forget to delete readFromFile

	int index = 0;
	while (readFromFile[index] != '<')
	{
		if (readFromFile[index] == '<')
		{
			if (readFromFile[index + 1] == 'r' && readFromFile[index + 2] == 'e' && readFromFile[index + 3] == 'c' && readFromFile[index + 4] == 't')
			{
				std::string color;
				double x;
				double y;
				double width;
				double height;
				index += 9; // num
				x = (double)readFromFile[index] - (double)'0'; //think if the number is more than one digit
				index += 6;
				y = (double)readFromFile[index] - (double)'0';

			}

			if (readFromFile[index + 1] == 'c' && readFromFile[index + 2] == 'i' && readFromFile[index + 3] == 'r' && readFromFile[index + 4] == 'c' &&
				readFromFile[index + 5] == 'l' && readFromFile[index + 6] == 'e')
			{

				std::string color;
				double x;
				double y;
				double width;
				double height;
				index += 12; // num
				x = (double)readFromFile[index] - (double)'0'; //think if the number is more than one digit
				index += 6;
				y = (double)readFromFile[index] - (double)'0';

			}


		}

		index++;
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
	this->basicShapesCollection.printAll();
}

void Commands::save()
{

}
void saveAs();
void help();
void exit();
void Commands::create()
{

}
void erase(size_t n);
void translate(size_t n);