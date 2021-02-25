/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#include <iostream>
#include <string>
#include "Assignment2.h"

std::string Show::getWord(int userInput) {
	return Show::sWords[userInput - 1];
}