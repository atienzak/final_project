/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QList>
#include "enemy.h"
#include "player.h"

extern Player* player; // contains the game data

class Bullet :  public QGraphicsPixmapItem
{

public:
    Bullet(QGraphicsItem * parent = 0); // default constructor
    Bullet(const Bullet& other); // copy constructor
    Bullet& operator=(Bullet& rhs) = default;
    ~Bullet() = default; // destructor

    void advance(int phase);// moves the bullet forward
    bool checkEnemyCollision() const; //check collision against zombies

private:
    QPixmap bulletPixmap; // holds the image of the bullet

};

#endif // BULLET_H
