#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "grid.h"
#include "view.h"
#include "scene.h"


namespace Ui {
class MainWindow;
}

//houses the graphics view and the game

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();




private:
    Ui::MainWindow *ui; // unused
    Scene * tests;
    View * testv;



};

#endif // MAINWINDOW_H

