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
#include "CheckLetter.h"
#include "Read.h"
#include "Assignment2.h"
#include "Score.h"

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
    CheckLetter checkLetter;
    //CheckLetter CheckGuess, CreateEmptiedString, CheckCorrect, GiveHint;
    Score GetHighScore;

    //run in loop to continue asking for a choice
    bool bRun = true;
    bool bGame = true;
    int iGuessCorrect=0;
    int iGameMatches=0;
    int iGuesses = 0;
    int iGuessLimit=10;
    string sLine = "";
    string sSecretWord = "";
    string sInput;
    string sUsername;
    string sEmptiedString = "";

    // Ask for username
    cout << "Please enter a username" << endl;
    cin >> sUsername;

    while (bRun)
    {
        int iChoice = 1;
        cout << "1: Select word from array" << endl;
        cout << "2: Select word from text file" << endl;
        // Add highscore display from file
        cout << "3: Display Highscore" << endl;
        cout << "4: Play letter Guess" << endl;
        // Change username
        cout << "5: Change username" << endl;
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
            cout << Score().GetHighScore(sUsername) << endl;
        }
        else if (iChoice == 4) {
            if (sSecretWord == "") {
                cout << "\nYou must select a word first\n" << endl;
            }
            else{
                //Display blank word and process first guess of the game
                Score().ResetCurrentScore();
                sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);
                cout << "Enter a letter to guess it" << endl << "Enter 'hint' to get a free letter and lose some points" << endl << "The game ends when you have guessed every letter." << endl << "You only get 10 incorrect guesses." <<endl<<endl;
                cout << sEmptiedString << endl;
                cin >> sInput;

                if (sInput == "hint") {
                    sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
                }
                else {
                    sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
                }

                while (bRun) {
                    if (iGuesses != iGuessLimit) {
                        int iCheckReturn = checkLetter.CheckCorrect(sSecretWord, sEmptiedString);
                        if (iCheckReturn == 0) {
                            cout << "That is not a letter" << endl;
                            iGuesses++;
                        }
                        else if (iCheckReturn == 1) {
                            cout << "You guess all the letters!" << endl << "You win!" << endl << "Final score: " << GetHighScore.HighScore(sUsername, GetHighScore.GetScore()) << endl;
                            bRun = false;
                        }
                        else if (iCheckReturn == 2) {
                            cout << "Thats correct. Score: " << GetHighScore.GetScore() << endl;
                        }

                        cout << sEmptiedString << endl;
                        cin >> sInput;

                        if (sInput == "hint") {
                            sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
                        }
                        else {
                            sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
                        }
                    }
                    else {
                        bRun = false;
                        cout << "You are out of guesses" << endl << "Game over" << endl << "Final score: " << GetHighScore.HighScore(sUsername, GetHighScore.GetScore()) << endl;
                    }
                }
                //Reset bRun to allow the main menu to continue functioning
                bRun = true;
            }
        }
        else if (iChoice == 5) {
            cout << "Enter a new username" << endl;
            cin >> sUsername;
        }
        else if (iChoice == 0) {
            bRun = false;
        }
    }
    //This will create a log and say the date and time when the program was terminated.
    //Logger("Program was terminated");
    
    return 0;
}
