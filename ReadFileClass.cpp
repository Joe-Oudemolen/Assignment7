/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a letter guessing game that allows a user to randomly pick a word and then play a guessing game.  The user will earn points for guessing correctly.
* Assignment 6
* CIS 227.6800.W21
* Date - 3/09/2021
*
*/

#include <iostream>
#include <locale>
#include <cctype>
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
#include "Read.h"

using namespace std;

//create function of class Read to be a vector of strings
vector<string> Read::ReadWordList()
{
    vector<string> vRandWords;
    string sLine;
    ifstream MyFile;

    QFile File("C:\\Users\\jhamm\\Desktop\\GRCC\\CIS 227 C++ 2\\Assign7\\RandomWords.txt");

    QString qsLine;

    if (File.open(QIODevice::ReadOnly))
    {
        QTextStream in(&File);
        while (!in.atEnd())
        {
             qsLine = in.readLine();
             sLine = qsLine.toStdString();
             vRandWords.push_back(sLine);

        }
        File.close();
    }


    //for testing - prints out the words from the vector - don't delete
    /*for (auto i = vRandWords.begin(); i != vRandWords.end(); ++i)

        cout << *i << ' ';*/

    return vRandWords;
}

