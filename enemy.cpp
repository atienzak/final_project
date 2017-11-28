#include "enemy.h"

Enemy::Enemy(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/zombie.png").scaled(153,153));
    setPos(100,100);
    move_timer = new QTimer;
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move_enemy()));
    move_timer->start(700);

}

void Enemy::move_enemy()
{
   setPos(x()-20,y());
}
