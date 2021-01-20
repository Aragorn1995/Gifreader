#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>
#include <QLabel>
#include <QIODevice>
#include <QFile>

//QSplashScreen





namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void opengif();
    void pausee();
    void startt();

    void info();



private:

    QMovie  *movie;
  //  QString fileGIF;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
