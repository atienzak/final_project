/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tests(nullptr),
    testv(nullptr)
{
    ui->setupUi(this);

    tests = new Scene();
    testv = new View(tests);
    setCentralWidget(testv);
    //setFixedSize(1200,769);

    setWindowTitle(QString("DEFEND THE DEN"));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tests;
    delete testv;
}
