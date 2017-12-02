#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "enemy.h"
class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem * parent = 0);
    void begin_move();
    void advance(int phase);
   /*
public slots:
    void move_bullet();
    */
private:
    QTimer* move_timer;
   // QList<QGraphicsItem*> colliding_list;


};



#endif // BULLET_H
