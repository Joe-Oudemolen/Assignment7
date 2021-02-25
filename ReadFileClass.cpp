#include <iostream>
#include <locale>
/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#include <cctype>
#include <fstream>
#include <string>
#include "Read.h"

using namespace std;

//create function of class Read to be a vector of strings
vector<string> Read::ReadWordList()
{
    vector<string> vRandWords;
    string sLine;
    ifstream MyFile;

    //open the file
    MyFile.open("RandomWords.txt");

    if (MyFile.is_open())
    {
        while (getline(MyFile, sLine))
        {
            vRandWords.push_back(sLine);//puts words from the file into the vector
        }
        MyFile.close();
    }


    //for testing - prints out the words from the vector - don't delete
    /*for (auto i = vRandWords.begin(); i != vRandWords.end(); ++i)

        cout << *i << ' ';*/

    return vRandWords;
}

