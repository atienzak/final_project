#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QPainter>
#include "player.h"

extern Player* player; // contains the game data

class Enemy : public QGraphicsItem
{

public:
    Enemy(QGraphicsItem * parent = 0); // constructor
    Enemy (const Enemy& other); // copy constructor
    Enemy& operator=(Enemy& rhs) = default; // assignment operator
    ~Enemy() = default; // destructor

    //reimplementing virtual functions
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget);

    void advance(int phase); //moves enemy forward

    void nextFrame(); //painter to draw the next frame

private:

    //to paint the pixmap
    int currentFrame;
    QPixmap enemyPixmap;

};

#endif // ENEMY_H
