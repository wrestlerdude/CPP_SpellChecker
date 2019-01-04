/*
* Author: Raish Allan, 40316824
* Last Modified: 15/04/2018
* 
* This code file is used for input stream manipulation
*/
#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "funcs.h"
#include <algorithm>

//read_dictionary: reads in the dictionary into a binary tree and converts all to lowercase
void read_dictionary(BinarySearchTree *tree)
{
	std::ifstream input;
	std::string data;

	input.open("dictionary.txt");
	if (!input)
	{
		std::cerr << "Dictionary file does not exist!" << std::endl;
		exit(0);
	}
	//on every newline encountered, convert it to lowercase and insert into tree.
	while (input)
	{
		input >> data;
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		tree->insert(data);
	}


	input.close();
}

//read_input: opens the user-specified input file into a string and converts it to lowercase
void read_input(std::string &data, std::string &filename)
{
	std::ifstream input;
	input.open(filename);
	if (!input)
	{
		std::cerr << "File does not exist!" << std::endl;
		exit(0);
	}
	std::string buffer;

	while (std::getline(input, buffer))
	{
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		data += (buffer + '\n');
	}

	input.close();
}
