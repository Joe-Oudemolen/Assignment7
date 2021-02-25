/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#pragma once
#include <string>

#ifndef ASSIGNMENT2_H_
#define	ASSIGNMENT2_H_

class Show {

private:
	// The array of values for the user to select
	std::string sWords[12] = { "Cat", "Fireplace", "Baseball", "Cube", "Fork", "Book", "Computer", "Game", "Paper", "Number", "Phone", "Movie" };

public:
	// Function definitions
	std::string getWord(int);
};
#endif