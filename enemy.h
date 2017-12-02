#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDebug>
#include <cstdlib>
class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Enemy(int num = 0, QGraphicsItem * parent = 0);
    void advance(int phase);
    void move();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget);

private:
    QTime timer;
    QPixmap pic;
    int randomnum;

};

#endif // ENEMY_H
