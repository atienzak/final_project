#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsGridLayout>
#include "grid.h"


class Board : public QGraphicsGridLayout
{

public:
    Board(QGraphicsGridLayout * parent = 0);

/*
private:

    QGraphicsLayoutItem* test;
    QGraphicsLayoutItem* test1;
    QGraphicsLayoutItem* test2;

    Grid *t;
    Grid *t1;
    Grid *t2;
*/

};




#endif // BOARD_H
