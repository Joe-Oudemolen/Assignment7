/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - Create a list of words and ask the user to enter a number to display a word from the array.
*           Use a command line argument to display information about th program.
* Assignment 3
* Date - 2/07/2021
*
*/

#include <iostream>
#include <locale>
#include <cctype>
#include "CheckGuess.h"
#include "Read.h"
#include "Assignment2.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "There are " << argc << " argument(s):\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ": " << argv[count] << "\n\n";
    }

    Show showWord;
    Read readFile;
    Check checkGuess;

    //run in loop to continue asking for a choice
    bool bRun = true;
    bool bGame = true;
    int iGuessCorrect=0;
    int iGameMatches=0;
    string sLine = "";
    string sSecretWord = "";
    string strWord;
    
    // Ask for username
    while (bRun)
    {
        int iChoice = 1;
        cout << "1: Select word from array" << endl;
        cout << "2: Select word from text file" << endl;
        // Add highscore display from file
        cout << "3: Play letter Guess" << endl;
        // Change username
        cout << "0: Exit" << endl;
        cout << "Please Select an Option\n";
        cin >> iChoice;

        if (iChoice == 1) {
            //ask for a number from the user
            cout << "\nPlease enter a number 1 - 12, or 0 to exit.\n";
            cin >> iChoice;
            //check the number that was entered
            if (iChoice > 0 && iChoice <= 12) {
                //cout << showWord.getWord(iChoice) << "\n";
                sSecretWord = showWord.getWord(iChoice); 
            }

            else if (iChoice < 0 || iChoice > 12) {
                cout << "That is not a valid choice.\n";
            }

            else if (iChoice == 0) {
                exit(0);
            }
        }

        else if (iChoice == 2) {
            int iPick=0;
            
            vector<string> vWords = readFile.ReadWordList();

            cout << "\nPick a number from the word list 1-4\n";
            cin >> iPick;
            //gets word from the vector and makes that the secret word

            sSecretWord = vWords[iPick - 1];
        }

        else if (iChoice == 3) {
            if (sSecretWord == "") {
                cout << "\nYou must select a word first\n" << endl;
            }
            else {
                while (bGame) {
                    string sGuess;
                    // Add hint prompt and guess limit check
                    cout << "\nEnter a letter or guess the word: \n";
                    cin >> sGuess;
                    bGame = checkGuess.CheckGuess(sGuess, sSecretWord);
                }
            }
        }
        else if (iChoice == 0) {
            bRun = false;
        }
    }
    //This will create a log and say the date and time when the program was terminated.
    //Logger("Program was terminated");
    
    return 0;
}
