
/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#include <iostream>
#include <string>
#include "CheckGuess.h"
using namespace std;



int Check::CheckGuess(string sGuess, string sSecretWord)
{
int iSecretWordLength = sSecretWord.length();

//iterate through the secret words and guess word to compare the characters
    for (int i = 0; i < iSecretWordLength; i++)
    {
        if (i >= sGuess.length())
        break;

        if (sGuess[i] != sSecretWord[i])
        {
            cout << "\nThat is incorrect\n";
            return 1;
        }

        else if (sGuess[i] == sSecretWord[i])
        {
            cout << "\nThat is correct!\n";

            if (sGuess == sSecretWord) {
                cout << "\nGreat job, you win!\n\n";
                return 0;
            }
        }
    }
    return 1;
}