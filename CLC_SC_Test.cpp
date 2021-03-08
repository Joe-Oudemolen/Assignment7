
#include <iostream>
#include <string>
#include "score.h"
#include "CheckLetter.h"
using namespace std;

int main(){
    CheckLetter check;
    Score score;

    string nameTest = "Joe";
    string testword = "redbull";
    char rTest = 'r';
    char llTest = 'l';
    char incorrectTest = 't';
    string emptiedStringTest = check.CreateEmptiedString(testword);
    cout << "Emptied String Test: " << emptiedStringTest << endl;

    emptiedStringTest = check.CheckGuess(rTest, testword, emptiedStringTest);
    cout << "should have an R: " << emptiedStringTest << endl;
    check.CheckCorrect(testword, emptiedStringTest);
    cout << "Score Test: " << score.GetScore() << endl;

    emptiedStringTest = check.CheckGuess(llTest, testword, emptiedStringTest);
    cout << "should have an R and two L's: " << emptiedStringTest << endl;
    check.CheckCorrect(testword, emptiedStringTest);\
    
    cout << "Score Test: " << score.GetScore() << endl;

    emptiedStringTest = check.CheckGuess(incorrectTest, testword, emptiedStringTest);
    cout << "should not have changes: " << emptiedStringTest << endl;


}