/* Names - Joe Barron, Joe Oudemolen, Jesse Hamman
* Purpose - 
* Assignment 6
* Date - 3/08/2021
*
*/

#pragma once
#include <string>
#include <map>
using namespace std;

#ifndef SCORE_H_
#define SCORE_H_

class Score{
public:
    Score();
    int HighScore(string, int);
    int ModifyScore(int);
    int GetScore();
    int GetHighScore(string);
    void ResetCurrentScore();
private:

};

#endif
