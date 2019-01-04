/*
* Author: Raish Allan, 40316824
* Last Modified: 15/04/2018
* 
* This code file is used for tokenising and counting mispelled words against a dictionary
*/
#include "funcs.h"
#include "bst.h"
#include <sstream>
#include <string>
#include <vector>

//split: takes in a string of data and tokenises it with a punctuation delimiter.
std::vector<std::string> split(std::string &data)
{
	//convert input string into a stringstream
	std::stringstream ss(data);
	std::string buffer;
	std::vector<std::string> tokens;
	//on every new line read into buffer
	while(std::getline(ss, buffer))
	{
		//x is position of delimiter
		std::size_t x = 0;
		//y is position in the line 
		std::size_t y;
		//while delimiter location in line not the end of the string
		while((y = buffer.find_first_of(" ,.-'?!/0123456789\r\n\t\"", x)) != std::string::npos)
		{
			//pushes back the part of the token that doesn't contain a delimiter
			if (y > x)
				tokens.push_back(buffer.substr(x, y-x));
			//increment prevents it from reading in same line of punctuation again
			x = y+1;
		}
		//pushes back the rest of the line
		if (x < buffer.length())
			tokens.push_back(buffer.substr(x, std::string::npos));
	}

	return tokens;
}

//mispell: counts the amount of mispelled words by searching the dictionary tree and prints the mispelled words and count.
void misspell(std::vector<std::string> &tokens, BinarySearchTree *tree)
{
	int count = 0;
	//for every string in tokens
	for (auto &t : tokens)
	{
		//if word misspelled, print to console
		if (!tree->exists(t))
		{
			std::cout << t << std::endl;
			count++;
		}
	}
	if (count == 0)
		std::cout << "No misspelt words found!" << std::endl;
	else
		std::cout << std::endl << "(" << count << " misspelled words)" << std::endl;
}