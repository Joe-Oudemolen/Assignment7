/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#include <string>
#include <iostream>
#include <locale>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

#ifndef READ_H_
#define READ_H_

class Read
{

public:
    // function definiton
    vector<string> ReadWordList();
};

#endif

