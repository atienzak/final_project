#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include "grid.h"
#include <QGraphicsGridLayout>
#include "enemy.h"


class Scene : public QGraphicsScene
{
public:
    Scene(QObject * parent = 0);

protected:
    QGraphicsScene * scene;
    QGraphicsWidget * form;

    Enemy* en;





};


#endif // SCENE_H
