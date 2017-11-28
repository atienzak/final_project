#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "grid.h"
#include "view.h"
#include "scene.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    View * testv;
    Scene * tests;



private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H

