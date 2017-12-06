#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "grid.h"
#include <QGraphicsGridLayout>
#include "enemy.h"
#include <QTimer>
#include <QObject>
#include <cstdlib>
#include <QGraphicsLineItem>
class Scene :public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void constructBoard();

protected:
    void activateShooters(int row);

protected slots:
    void spawnEnemies();


private:

    //background item
    QPixmap background;

    //objects needed to form the board
    QVector<Grid*> gridVector;
    QGraphicsWidget* form;
    QGraphicsGridLayout* boardLayout;

    //timer for animation
    QTimer* tmove;

    //timer to spawn zombies
    QTimer* spawnTimer;
    int spawnDelay;
    int randomPos;

    QVector<Enemy*> zombies;
    int zombieCounter;

    QVector<QGraphicsLineItem*> zombieChecker;

};



#endif // SCENE_H
