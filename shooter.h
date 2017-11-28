#ifndef SHOOTER_H
#define SHOOTER_H
#include <QGraphicsPixmapItem>
#include "bullet.h"

class Shooter : public QGraphicsPixmapItem
{
public:
    Shooter(QGraphicsItem * parent = 0);

protected slots:
    //void shoot()

private:
    Bullet * bullet;

};
#endif
