/*
*	Author: Raish Allan, 40316824
*	Last Modified: 15/04/2018
*	
*	Built for Linux x64, programmed on Kubuntu 17.10 and Linux Mint.
*	This is the main codefile for a program that spellchecks an input file against an input dictionary
*	then displays the result to the display. It is a console based application. This is the main that calls functions
*	and also reads in the arguments.
*/
#include <iostream>
#include <string>
#include "funcs.h"
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	BinarySearchTree *tree = new BinarySearchTree();
	read_dictionary(tree);
	
	string data;
	string filename;
	//Checks if the argument is to be enter after excutable call or in-line.
	if (argc > 1)
		filename = argv[1];
	else
	{
		cout << "Enter the filename: ";
		cin >> filename;
	}
	
	read_input(data, filename);
	vector<string> tokens = split(data);

	cout << endl << "--Misspelled words--" << endl; 
	misspell(tokens, tree);

	delete tree;
	return 0;
}