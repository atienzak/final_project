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


}

MainWindow::~MainWindow()
{
    delete ui;
}
