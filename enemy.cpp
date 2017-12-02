#include "enemy.h"


Enemy::Enemy(int num, QGraphicsItem *parent)
{
    timer.start();

    //setPixmap(QPixmap(":/images/zombie.png").scaled(153,153));
    //setPos(100,100);
    pic = QPixmap(":/images/zombie.png");
    pic = pic.scaled(153,153);
    //srand(time(NULL));
    randomnum = num;
}

void Enemy::advance(int phase)
{

    if (!phase)
        return;
   setPos(x()-10,y());
   int nMilliseconds = timer.elapsed();
   qDebug() << "moving enemy: " << nMilliseconds;
   timer.restart();

}

void Enemy::move()
{
    setPos(x()-10,y());
    int nMilliseconds = timer.elapsed();
    qDebug() << "moving enemy: " << nMilliseconds;
    timer.restart();

}

QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,153,153);
}

 void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget)
 {
     //painter->drawPixmap(0,0,QPixmap(":/images/zombie.png").scaled(153,153)));

     painter->drawPixmap(0,0, pic);
 }
