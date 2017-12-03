#ifndef SHOOTER_H
#define SHOOTER_H
#include <QGraphicsPixmapItem>
#include "bullet.h"

class Shooter : public QGraphicsPixmapItem
{
public:
    Shooter(QGraphicsItem * parent = 0);
    void spawnBullet();
    void advance(int phase);

private:
    QVector<Bullet*> bullets;
    int bulletTimeDelay;

};
#endif
