#ifndef SHOOTER_H
#define SHOOTER_H
#include <QGraphicsPixmapItem>
#include "bullet.h"

class Shooter : public QGraphicsPixmapItem
{
public:
    Shooter(QGraphicsItem * parent = 0);
    void spawnBullet(bool shoot);
    void advance(int phase);
    bool isShooting();
    void activate();
    void deactivate();
   // bool checkEnemyCollision();

private:
    QVector<Bullet*> bullets;
    int bulletTimeDelay;
    int shooting;
    //Bullet newbullet;

};
#endif
