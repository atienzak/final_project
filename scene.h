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
    Grid * test00;
    Grid * test01;
    Grid * test02;
    Grid * test03;
    Grid * test04;
    Grid * test05;
    Grid * test06;
    Grid * test07;
    Grid * test08;
    Grid * test09;
    Enemy* en;





};


#endif // SCENE_H
