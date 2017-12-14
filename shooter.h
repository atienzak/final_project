/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#ifndef SHOOTER_H
#define SHOOTER_H
#include <QGraphicsPixmapItem>
#include "bullet.h"

class Shooter : public QGraphicsPixmapItem
{
public:

    Shooter(QGraphicsItem * parent = 0);
    Shooter(const Shooter& other);
    Shooter& operator=(Shooter rhs);
    ~Shooter();
    void swap(Shooter& rhs);


    void spawnBullet(bool shoot);
    void advance(int phase);
    bool isShooting();
    void activate();
    void deactivate();


private:
    QVector<Bullet*> bullets;
    int bulletTimeDelay;
    int shooting;


};
#endif
