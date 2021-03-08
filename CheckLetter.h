/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - To check if the Guessed Charater is a Character from the SecretWord. If the char is in the secret word then it's added to the EmptiedString and score is added to current score
* Assignment 6
* Date - 3/08/2021
*
*/

#pragma once
#include <string>
using namespace std;

#ifndef CHECKLETTER_H_
#define CHECKLETTER_H_

class CheckLetter{
public:
	string CreateEmptiedString(string);
	string Checkletter(char, string, string);
	int CheckCorrect(string, string);
	string GiveHint(string, string);
private:
	char cPreviousGuess;
	string sPreviousEmptiedString;
};

#endif
