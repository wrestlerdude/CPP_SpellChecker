/*
* Author: Raish Allan, 40316824
* Last Modified: 15/04/2018
* 
* Header file for program
*/
#pragma once
#include "bst.h"
#include <string>
#include <vector>

void read_dictionary(BinarySearchTree *tree);
void read_input(std::string &data, std::string &filename);
std::vector<std::string> split(std::string &data);
void misspell(std::vector<std::string> &tokens, BinarySearchTree *tree);