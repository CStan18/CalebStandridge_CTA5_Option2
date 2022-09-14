/*
Name: Caleb Standridge
Date: 9/14/2022

Pseudo:
	Open file
	Get input from user
	Append input to secondary file
	Search file for my name
		If name found return found
		else return name not found
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	// Open file
	std::fstream file;
	file.open("CSC450_CT5_mod5.txt", std::ios_base::app);

	// Get input from user
	std::vector<std::string> names;
	std::string userInput;

	std::cout << "Enter list of names separated by whitespace";
	std::getline(std::cin, userInput);

	// Parse input
	std::stringstream ss(userInput);

	while (ss.good())
	{
		std::string substr;
		getline(ss, substr, ' ');
		names.push_back(substr);
	}

	// Append input to secondary file
	for (std::string name : names)
	{
		file << name << std::endl;
		std::cout << name;
	}

	file.close();

	// Search file for name
	std::string myName = "Caleb";
	std::string line;
	int offset;

	std::ifstream ifStreamFile;
	ifStreamFile.open("CSC450_CT5_mod5.txt");

	if (ifStreamFile.is_open())
	{
		while(!ifStreamFile.eof())
		{
			getline(ifStreamFile, line);
			if ((offset = line.find(myName, 0)) != std::string::npos)
			{
				std::cout << "\nName has been found.\n";
			}
		}
		ifStreamFile.close();
	}
	else
	{
		std::cout << "File opening error\n";
		system("pause");
	}





	
}