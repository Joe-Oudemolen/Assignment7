#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbtnArrayWord_clicked();

    void on_pbtnTextWord_clicked();

    void on_pbtnPlayGame_clicked();

    void on_btnSaveName_clicked();

    void on_pbtnGuess_clicked();

    void on_rdbtnArrayWord_clicked();

    void on_rdbtnTextWord_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
