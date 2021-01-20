#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label_2->setStyleSheet("color: #00BFFF");
    connect(ui->actionNew_file,SIGNAL(triggered()),this,SLOT(opengif()));
    connect(ui->menu_GIFREADER,SIGNAL(triggered(QAction*)),this,SLOT(info()));
}

MainWindow::~MainWindow()
{delete ui;}

void MainWindow::opengif()
{
   QString fileGIF = QFileDialog::getOpenFileName(this,
         tr("Open"),
         "C://",
         tr("Файлы изображения (*.GIF)"));
     QFile file(fileGIF);
     if(file.open((QIODevice::ReadOnly)))
     {


    movie= new QMovie(fileGIF);
    QFileInfo   *info = new QFileInfo(fileGIF);
    ui->label_3->setStyleSheet("color: #00BFFF");
    ui->label_3->setText("Имя файла:"+info->fileName());
    ui->label->setMovie(movie);
    ui->label->resize(size());
    ui->lcdNumber->display(movie->frameCount());

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),movie,SLOT(setSpeed(int)));
    connect(ui->actionStop,SIGNAL(triggered()),movie,SLOT(stop()));
    connect(ui->actionStart,SIGNAL(triggered()),this,SLOT(startt()));
    connect(ui->actionPause,SIGNAL(triggered()),this,SLOT(pausee()));
}else
     {
         QMessageBox::warning(this,"ERROR","File not open!!!      ","OK");
         return;
     }

}

void MainWindow::pausee()
{
   movie->setPaused(true);

}

void MainWindow::startt()
{
    movie->setPaused(false);
    movie->start();

}

void MainWindow::info()
{
    QMessageBox::about(0, "GIFREADER", "Евгений Павлов © 2014 v 1.0");

}



