#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "grid.h"
#include <QGraphicsGridLayout>
#include "enemy.h"


class Scene :public QGraphicsScene
{

public:
    Scene();
    //~Scene();
    void timerEvent(QTimerEvent* event);

protected:
    Enemy* en;
    Enemy* en1;
    Enemy* en2;
    Enemy* en3;
    Enemy* en4;

private:

    //background item
    QGraphicsPixmapItem* background;

    //objects needed to form the board
    QVector<Grid*> grid_vector;
    QGraphicsWidget* form;
    QGraphicsGridLayout* board_layout;

    //timer for animation
    QTimer* tmove;
    int timerId;





};


#endif // SCENE_H
