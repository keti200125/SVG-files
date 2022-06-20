#include "Commands.h"
#include<fstream>
#include "BasicShapesCollection.h"
#include<cstring>
#pragma warning(disable: 4996)

std::fstream SVGFile;


void readNumber(size_t indexCopy,size_t index, size_t counter,size_t helper, char* readFromFile, int num)
{
	while ((int)readFromFile[indexCopy] >= (int)'0' && (int)readFromFile[indexCopy] <= (int)'9')
	{
		counter++; // 3 (for 3 digits)
		indexCopy++;  // "
		helper *= 10; // 1000
	}
	helper /= 10; //100
	for (int i = 0; i < counter; i++)
	{
		num += ((int)readFromFile[index + i] - (int)'0') * helper;
		helper /= 10;
	}

}


void Commands::open(std::string fileName)
{
	SVGFile.open(fileName, std::ios::in);


	if (!SVGFile)
	{
		SVGFile.open(fileName, std::ios::out);

		if (!SVGFile.is_open())
		{
			throw "File isn't opened";
		}
		else
		{
			SVGFile << "<?xml version=" << '"' << "1.0" << '"' << " standalone =" << '"' << "no" << '"' << "?>"<< '\n';
			SVGFile << "<!DOCTYPE svg PUBLIC " << '"' << " -//W3C//DTD SVG 1.1//EN" << '"' << '\n';
			SVGFile << '"' << "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd" << '"' << '>' << '\n';
			SVGFile << "<svg>" << '\n';
			SVGFile << "</svg>";
			std::cout << "Successfully created new file " << fileName << std::endl;
			SVGFile.close();
		}

	}
	else
	{
		std::cout << "Successfully opened " << fileName << std::endl;
	}


	//we get the size of the file
	size_t current = SVGFile.tellg();
	SVGFile.seekg(0, std::ios::end);
	size_t size = SVGFile.tellg();
	SVGFile.seekg(current);

	//now we put what we read from the file in char
	char* readFromFile;
	SVGFile.read(readFromFile, size);
	readFromFile[size]= '\0';

	SVGFile.close();
	//dont forget to delete readFromFile

	
	

	size_t index = 0;

	while (index<size)
	{
		if (readFromFile[index] == '<')
		{
			//in case of rectangle
			if (readFromFile[index + 1] == 'r' && readFromFile[index + 2] == 'e' && readFromFile[index + 3] == 'c' && readFromFile[index + 4] == 't')
			{
				std::string fill;
				int x = 0;
				int y = 0;
				int width = 0;
				int height = 0;
				index += 9; // num <rect x="   5   " y="5" width="10" height="10" fill="green" />

				//for x 
				int indexCopy = index;
				int counter = 0;
				int helper = 1;

				readNumber(indexCopy, index, counter, helper, readFromFile,x);
			
				index += counter + 5; //3-1 +6
				counter = 0;
				indexCopy = index;

				//for y 
				readNumber(indexCopy, index, counter, helper, readFromFile,y);

				index += counter + 9; //3-1 +10
				counter = 0;
				indexCopy = index;

				//for width
				readNumber(indexCopy, index, counter, helper, readFromFile,width);

				index += counter + 10; //3-1 +11
				counter = 0;
				indexCopy = index;

				//for height
				readNumber(indexCopy, index, counter, helper, readFromFile,height);
				index += counter + 8;
				counter = 0;
				indexCopy = index;
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;

				}
				fill[iF + 1] = '/0';

				mBasicShapesCollection.addRectangle(x, y, fill, width, height);
			}

			//in case of circle
			if (readFromFile[index + 1] == 'c' && readFromFile[index + 2] == 'i' && readFromFile[index + 3] == 'r' && readFromFile[index + 4] == 'c' &&
				readFromFile[index + 5] == 'l' && readFromFile[index + 6] == 'e')
			{

				std::string fill;
				int x = 0;
				int y = 0;
				int radius = 0;
				index += 12; // num <circle cx="   5   " cy="5" r="10" fill="blue" />

				int indexCopy = index;
				int counter = 0;
				int helper = 1;

				//for x
				readNumber(indexCopy, index, counter, helper, readFromFile, x);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for y
				readNumber(indexCopy, index, counter, helper, readFromFile, y);

				index += counter + 5; //3-1 +6
				counter = 0;
				indexCopy = index;

				//for r 
				readNumber(indexCopy, index, counter, helper, readFromFile,radius);

				index += counter + 8; //3-1 +9
				counter = 0;
				indexCopy = index;

				//for fill
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;

				}
				fill[iF + 1] = '/0';


				mBasicShapesCollection.addCircle(x, y, fill, radius);
			

			}

			//in case of ellipse
			if (readFromFile[index + 1] == 'e' && readFromFile[index + 2] == 'l' && readFromFile[index + 3] == 'l' && readFromFile[index + 4] == 'i' &&
				readFromFile[index + 5] == 'p' && readFromFile[index + 6] == 's'&& readFromFile[index + 7] == 'e')
			{

				std::string fill;
				int x = 0;
				int y = 0;
				int r1 = 0;
				int r2 = 0;
				index += 13; // num  <ellipse cx="  100  " cy="50" rx="100" ry="50" fill="red"/>

				int indexCopy = index;
				int counter = 0;
				int helper = 1;

				//for x
				readNumber(indexCopy, index, counter, helper, readFromFile, x);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for y
				readNumber(indexCopy, index, counter, helper, readFromFile, y);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for r1
				readNumber(indexCopy, index, counter, helper, readFromFile, r1);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for r2
				readNumber(indexCopy, index, counter, helper, readFromFile, r2);

				index += counter + 8; //3-1 +9
				counter = 0;
				indexCopy = index;

				//for fill
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;

				}
				fill[iF + 1] = '/0';


				mBasicShapesCollection.addEllipse(x, y, r1, r2, fill);


			}

			//in case of line
			if (readFromFile[index + 1] == 'l' && readFromFile[index + 2] == 'i' && readFromFile[index + 3] == 'n' && readFromFile[index + 4] =='e')
			{

				std::string fill;
				int x = 0;
				int y = 0;
				int x2 = 0;
				int y2 = 0;
				index += 10; // num <line x1="  300  " y1="300" x2="500" y2="100" fill="none"/>

				int indexCopy = index;
				int counter = 0;
				int helper = 1;

				//for x
				readNumber(indexCopy, index, counter, helper, readFromFile, x);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for y
				readNumber(indexCopy, index, counter, helper, readFromFile, y);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for x2
				readNumber(indexCopy, index, counter, helper, readFromFile, x2);

				index += counter + 6; //3-1 +7
				counter = 0;
				indexCopy = index;

				//for y2
				readNumber(indexCopy, index, counter, helper, readFromFile, y2);

				index += counter + 8; //3-1 +9
				counter = 0;
				indexCopy = index;

				//for fill
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;

				}
				fill[iF + 1] = '/0';


				mBasicShapesCollection.addLine(x, y, fill,x2,y2);


			}


		}

		index++;
	}

	delete[] readFromFile;

}



void Commands::close()
{
	if (SVGFile.is_open())
	{
		SVGFile.close();
	}


	
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
	this->mBasicShapesCollection.printAll();
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