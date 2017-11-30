#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "grid.h"
#include <QGraphicsGridLayout>
#include "enemy.h"


class Scene : public QGraphicsScene
{
public:
    Scene();
    //~Scene();

protected:
    Enemy* en;

private:

    //background item
    QGraphicsPixmapItem* background;

    //objects needed to form the board
    QVector<Grid*> grid_vector;
    QGraphicsWidget* form;
    QGraphicsGridLayout* board_layout;





};


#endif // SCENE_H
