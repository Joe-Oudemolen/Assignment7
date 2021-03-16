#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <cctype>
#include <string>
#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "Assignment2.h"
#include "CheckLetter.h"
#include "Log.h"
#include "Read.h"
#include "Score.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txtName->setPlaceholderText("Enter Name");

}

MainWindow::~MainWindow()
{
    delete ui;
}

    bool bRun = true;
    bool bGame = true;
    int iGuessCorrect = 0;
    int iGameMatches = 0;
    int iGuesses = 0;
    int iGuessLimit = 10;
    string sLine = "";
    string sSecretWord = "";
    string sInput;
    string sUsername;
    string sEmptiedString = "";

Show showWord;
Read readFile;
CheckLetter checkLetter;
Score GetHighScore;


void MainWindow::on_rdbtnArrayWord_clicked()
{
    int iValue;

    QString qsNumber = this->ui->txtNumber->toPlainText();

    iValue = qsNumber.toInt();

    sSecretWord = showWord.getWord(iValue);

    this->ui->lblSecretWord -> setText(QString::fromStdString(sSecretWord));

    sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);

}

void MainWindow::on_rdbtnTextWord_clicked()
{

    int iValue;

    QString qsNumber = this->ui->txtNumber->toPlainText();

    iValue = qsNumber.toInt();

    vector<string> vWords = readFile.ReadWordList();

    sSecretWord = vWords[iValue - 1];

    this->ui->lblSecretWord -> setText(QString::fromStdString(sSecretWord));

    sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);
}

void MainWindow::on_pbtnPlayGame_clicked()
{
    Score().ResetCurrentScore();
}

void MainWindow::on_btnSaveName_clicked()
{
    this->ui->lblName->setText(this->ui->txtName->toPlainText());

    QString qsName = this->ui->txtName->toPlainText();

    sUsername = qsName.toStdString();

    this->ui->txtName->setText("");
}

void MainWindow::on_pbtnGuess_clicked()
{

    this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));

    QString qsInput = this->ui->txtGuessedLetter->toPlainText();

    sInput = qsInput.toStdString();

    if (sInput == "hint") {
      sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
      this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));
    }
    else {
     sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
     this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));
    }


    //while (bGame) {
        if (iGuesses != iGuessLimit) {
            int iCheckReturn = checkLetter.CheckCorrect(sSecretWord, sEmptiedString);

            QString score = QString::number(GetHighScore.GetScore());
            QString highscore = QString::number(GetHighScore.HighScore(sUsername, GetHighScore.GetScore()));

            if (iCheckReturn == 0) {
                this->ui->lblCheck->setText("That is incorrect!");
                iGuesses++;
            }
            else if (iCheckReturn == 1) {
                this->ui->lblCheck->setText("You guessed all the letters, You Win! Final Score: "+ highscore);
                //Logger("Game Won.");

                QFile LogFile("C:\\Users\\jhamm\\Desktop\\GRCC\\CIS 227 C++ 2\\Assign7\\LogFile.txt");

                  if(LogFile.open(QFile::WriteOnly | QFile::Text)){

                  QTextStream out(&LogFile);

                  QString qsLogMessage = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + "Game Won";
                  out << qsLogMessage;
                  LogFile.flush();

                  LogFile.close();
                  }

            }
            else if (iCheckReturn == 2) {
                this->ui->lblCheck->setText("Thats correct. Score: " + score);
            }

            //cout << sEmptiedString << endl;
            //cin >> sInput;

            if (sInput == "hint") {
                sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
            }
            else {
                sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
            }
            this->ui->txtGuessedLetter->setText("");
        }
        else {
            this->ui->lblCheck->setText("You are out of guesses. Game Over. Final Score: " +
               QString::number(GetHighScore.HighScore(sUsername, GetHighScore.GetScore())));
        }
    }

//}

