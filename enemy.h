#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QTime>
#include <QPainter>
#include <QDebug>

class Enemy : public QGraphicsItem
{

public:

    Enemy(QGraphicsItem * parent = 0);

    //reimplementing virtual functions
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget);

    //moves enemy forward
    void advance(int phase);

    //painter to draw the next frame
    void nextFrame();

private:

    //to paint the pixmap
    int currentFrame;
    QPixmap enemyPixmap;

    QTime timer; // for debugging purposes only

};

#endif // ENEMY_H
