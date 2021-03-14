#include "mainwindow.h"
#include <iostream>
#include <locale>
#include <cctype>
#include "CheckLetter.h"
#include "Read.h"
#include "Assignment2.h"
#include "Score.h"
#include "Log.h"

using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
