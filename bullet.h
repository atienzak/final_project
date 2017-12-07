#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QList>
#include <QDebug>
#include "enemy.h"
#include "player.h"

extern Player* player;

class Bullet :  public QGraphicsPixmapItem
{

public:

    Bullet(QGraphicsItem * parent = 0);

    // moves the bullet
    void advance(int phase);

    //check collision against zombies
    bool checkEnemyCollision();

private:
    QPixmap bulletPixmap;

};



#endif // BULLET_H
