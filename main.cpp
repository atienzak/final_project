#include "mainwindow.h"
#include <QApplication>
#include "player.h"

Player* player = new Player();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();


    return a.exec();
}
