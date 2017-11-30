#include "enemy.h"


Enemy::Enemy(QGraphicsItem *parent)
{
    timer.start();

    setPixmap(QPixmap(":/images/zombie.png").scaled(153,153));
    setPos(100,100);
    move_timer = new QTimer;
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move_enemy()));
    move_timer->start(1000);


}

void Enemy::move_enemy()
{
    //QTime timer;

   setPos(x()-50,y());

   int nMilliseconds = timer.elapsed();
   qDebug() << "moving enemy: " << nMilliseconds;
   timer.restart();

}
