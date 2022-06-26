#include "Commands.h"
#include<fstream>
#include "BasicShapesCollection.h"
#include<cstring>
#pragma warning(disable: 4996)
#define MAX_SIZE 5000


std::fstream SVGFile;
std::fstream SVGRecovoryFile;
std::string fileNameCopy;

int readNumber(size_t index,size_t helper, char* readFromFile)
{
	size_t indexCopy = index;
	int num = 0;
	int counter = 0;
	while ((int)readFromFile[indexCopy] >=48 && (int)readFromFile[indexCopy] <=57)
	{
		counter++; // 3 (for 3 digits)
		indexCopy++;  // "
		helper *= 10; // 1000
	}
	helper /= 10; //100
	for (int i = 0; i < counter; i++)
	{
		num += ((int)readFromFile[index + i] -'0') * helper;
		helper /= 10;
	}

	return num;

}
size_t count(int num)
{
	size_t counter = 1;
	while (num>9)
	{
		num /= 10;
		counter++;

	}

	return counter;

}

void Commands::extraFileFunction()
{
	SVGRecovoryFile.open("recovery.svg", std::ios::out);
	SaveAs("recovery.svg");
	std::cout<<"in recovery";
	std::cout << std::endl;
}

void Commands::open(std::string fileName)
{
	SVGFile.open(fileName, std::ios::in);
	fileNameCopy = fileName;

	if (!SVGFile)
	{
		SVGFile.open(fileName, std::ios::out);

		if (!SVGFile.is_open())
		{
			throw "File isn't opened";
		}
		else
		{
			SVGFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << '\n';
			SVGFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << '\n';
			SVGFile << "</svg>";
			std::cout << "Successfully created new file " << fileName << std::endl;
			SVGFile.close();
		}

	}
	else
	{
		std::cout << "Successfully opened " << fileName << std::endl;
	}


	
	//now we put what we read from the file in char
	while (!SVGFile.eof())
	{
		char readFromFile[MAX_SIZE];
		SVGFile.getline(readFromFile, MAX_SIZE, '\n');
		size_t index = 0;
		std::cout << readFromFile;
		std::cout << '\n';
		if (readFromFile[index] == '<')
		{
			//in case of rectangle
			if (readFromFile[1] == 'r' && readFromFile[2] == 'e' && readFromFile[3] == 'c' && readFromFile[4] == 't')
			{
				char fill[20] = {};
				int x = 0;
				int y = 0;
				int width = 0;
				int height = 0;

				size_t helper = 1;

				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for x 
				x = readNumber(index, helper, readFromFile);

				index += count(x);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for y 
				y = readNumber(index, helper, readFromFile);

				index += count(y);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for width
				width = readNumber(index, helper, readFromFile);
				index += count(width);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for height
				height = readNumber(index, helper, readFromFile);
				index += count(height);

				while (readFromFile[index] != 'f')
				{
					index++;
				}
				while (readFromFile[index] != '"')
				{
					index++;
				}
				index++;

				//for color
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;
				}

				mBasicShapesCollection.addRectangle(x, y, fill, width, height);
			}

			//in case of circle
			if (readFromFile[1] == 'c' && readFromFile[2] == 'i' && readFromFile[3] == 'r' && readFromFile[4] == 'c' &&
				readFromFile[5] == 'l' && readFromFile[6] == 'e')
			{

				char fill[20] = {};
				int x = 0;
				int y = 0;
				int radius = 0;

				size_t helper = 1;

				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for x 
				x = readNumber(index, helper, readFromFile);

				index += count(x);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for y 
				y = readNumber(index, helper, readFromFile);

				index += count(y);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for r 
				radius = readNumber(index, helper, readFromFile);
				index += count(radius);

				while (readFromFile[index] != 'f')
				{
					index++;
				}
				while (readFromFile[index] != '"')
				{
					index++;
				}
				index++;

				//for fill
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;
				}


				mBasicShapesCollection.addCircle(x, y, fill, radius);


			}

			if (readFromFile[1] == 'e' && readFromFile[2] == 'l' && readFromFile[3] == 'l' && readFromFile[4] == 'i' &&
				readFromFile[5] == 'p' && readFromFile[6] == 's' && readFromFile[7] == 'e')
			{

				char fill[20] = {};
				int x = 0;
				int y = 0;
				int r1 = 0;
				int r2 = 0;

				size_t helper = 1;

				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for x 
				x = readNumber(index, helper, readFromFile);

				index += count(x);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for y 
				y = readNumber(index, helper, readFromFile);

				index += count(y);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}


				//for r1
				r1 = readNumber(index, helper, readFromFile);
				index += count(r2);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for r2
				r2 = readNumber(index, helper, readFromFile);
				index+= count(r2);

				while (readFromFile[index] != 'f')
				{
					index++;
				}
				while (readFromFile[index] != '"')
				{
					index++;
				}
				index++;

				//for color
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;
				}

				mBasicShapesCollection.addEllipse(x, y, r1, r2, fill);


			}

			//in case of line
			if (readFromFile[index + 1] == 'l' && readFromFile[index + 2] == 'i' && readFromFile[index + 3] == 'n' && readFromFile[index + 4] == 'e')
			{

				char fill[20] = {};
				int x = 0;
				int y = 0;
				int x2 = 0;
				int y2 = 0;
				index += 10; // num <line x1="  300  " y1="300" x2="500" y2="100" fill="none"/>

				size_t helper = 1;

				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for x 
				x = readNumber(index, helper, readFromFile);

				index += count(x);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for y 
				y = readNumber(index, helper, readFromFile);

				index += count(y);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}
				//for x2
				x2 = readNumber(index, helper, readFromFile);

				index += count(x2);
				while ((int)readFromFile[index] < 48 || (int)readFromFile[index]>57)
				{
					index++;
				}

				//for y2
				y2 = readNumber(index, helper, readFromFile);
				index += count(y2);

				while (readFromFile[index] != 'f')
				{
					index++;
				}
				while (readFromFile[index] != '"')
				{
					index++;
				}
				index++;

				//for color
				int iF = 0;
				while (readFromFile[index] != '"')
				{
					fill[iF] = readFromFile[index];
					iF++;
					index++;
				}

				mBasicShapesCollection.addLine(x, y, fill, x2, y2);
			}
		}
	}


	SVGFile.close();

}






void Commands::close()
{
	if (SVGFile.is_open())
	{
		SVGFile.close();
	}

	this->mBasicShapesCollection.freeAllSpace();
	
	std::cout << "Successfully closed file"<< std::endl;
}

void Commands::help() const
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
	std::cout << "within <option>   displays all shapes that are completely contained in a given region.The user can specify by <option>" << std::endl;
}

void Commands::print() const
{
	this->mBasicShapesCollection.printAll();
	std::cout << std::endl;
}

void Commands::save(std::string fileName)
{
	std::fstream SVGFile;
	SVGFile.open(fileName, std::ios::out);
	if (!SVGFile.is_open())
	{
		throw "Imppossible to be saved";
	}

	this->mBasicShapesCollection.writeInFile(SVGFile);
	std::cout << "Successfully saved" << std::endl;
}
void Commands::SaveAs(std::string fileName)
{
	std::ofstream newFile;
	newFile.open(fileName,std::ios::out);

	if (!newFile.is_open())
	{
		throw "File isnt opened";
	}

	this->mBasicShapesCollection.writeInFile(newFile);
	std::cout << "Successfully saved" << std::endl;


}
void Commands::exit(std::string fileName)
{
	std::cout << "You have an open file with unsaved changes, please select close-1 or save-2 first." << std::endl;
	size_t decision;
	std::cin >> decision;
	if (decision == 1)
	{
		close();
	}
	else
	{
		save(fileName);
	}

}
void Commands::create() 
{
	char color[50];
	char figureName[100];
    std::cout << "Figure name? ";
	std::cin.getline(figureName, 100);

	//verification
	if (figureName[0] != 'r' && figureName[0] != 'c' && figureName[0] != 'e' && figureName[0] != 'l')
	{
		std::cout << "Wrong Input! Try rectangle, circle, ellipse or line :)";
		std::cin.getline(figureName, 100);
	}
	std::cout << "Color? ";
	std::cin.getline(color, 100);
	int x, y;
	std::cout<<"X? ";
	std::cin >> x;
	std::cout << "y? ";
	std::cin >> y;
	if (figureName[0] == 'r')
	{
		std::cout << "width? ";
		int width;
		std::cin >> width;
		std::cout << "height? ";
		int height;
		std::cin >> height;

		this->mBasicShapesCollection.addRectangle(x, y, color, width, height);
	}
	if (figureName[0] == 'c')
	{
		std::cout << "r? ";
		int r;
		std::cin >> r;

		this->mBasicShapesCollection.addCircle(x, y, color, r);
	}
	if (figureName[0] == 'e')
	{
		int r1, r2;
		std::cout << "r1? ";
		std::cin >> r1;
		std::cout << "r2? ";
		std::cin >> r2;

		this->mBasicShapesCollection.addEllipse(x, y, r1, r2, color);
	}
	if (figureName[0] == 'l')
	{
		int x2, y2;
		std::cout << "x2? ";
		std::cin >> x2;
		std::cout << "y2? ";
		std::cin >> y2;

		this->mBasicShapesCollection.addLine(x, y, color, x2, y2);
	}
}
void Commands::erase(size_t n)
{
	this->mBasicShapesCollection.removeShapeByIndex(n);
	extraFileFunction(); //
}
//void translate(size_t n);
void Commands::withinCircle(int x,int y, int r )
{

}
void Commands::withinRectangle(int x, int y, int width, int height)
{

}

void Commands::run() //enter
{
	int helpMe = 0;
	while (helpMe != 1)
	{
		std::cout << "> ";
		char userWishes[100] = {};
		char fileNameForOpen[100] = {};
		char fileNameForSaveAs[100] = {};
		std::cin.getline(userWishes, 100);
		size_t len = std::strlen(userWishes);

		//open
		if (userWishes[0]=='o')
		{
			std::cout << "File name? ";
			std::cin.getline(fileNameForOpen, 100);
			open(fileNameForOpen);
		}

		//close
		if (userWishes[0]=='c' && userWishes[1] == 'l')
		{
			close();
		}

		//Help
		if (userWishes[0] == 'h') 
		{
			help();
		}

		//Print
		if (userWishes[0] == 'p')
		{
			print();
		}

		//Exit
		if (userWishes[0] == 'e'&&userWishes[1]=='x')
		{
			exit(fileNameCopy);
			helpMe = 1;
			std::cout << "Exit";
		}
		//Save && SaveAs
		if (userWishes[0] == 's')
		{
			if (strlen(userWishes) > 5)
			{
				std::cin.getline(fileNameForSaveAs, 100);
				SaveAs(fileNameForSaveAs);
			}
			else
			{
				save(fileNameCopy);
			}
		}

		//Erase <n>
		if (userWishes[0] == 'e'&&userWishes[1]=='r')
		{
			size_t n;
			std::cin >> n;
			erase(n);
			
		}

		//Create
		if (userWishes[0] == 'c' && userWishes[1] == 'r') //color is first 
		{
			create();
			extraFileFunction(); //
		}

		/*if (figureName[0] == 'w')
		{
			char whichFigure[100];
			std::cin.getline(whichFigure, 100, ' ');
			int x, y;
			std::cin >> x;
			std::cin >> y;

			if (whichFigure[0] == 'c')
			{
				int r;
				std::cin >> r;
				withinCircle(x, y, r);
			}
			if (whichFigure[0] == 'r')
			{
				int w, h;
				std::cin >> w;
				std::cin >> h;
				withinRectangle(x, y, w, h);
			}
		}*/
	}

	
}