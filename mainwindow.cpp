#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    tests = new Scene();
    testv = new View(tests);
    setCentralWidget(testv);
    setFixedSize(1200,769);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete tests;
    delete testv;
}
