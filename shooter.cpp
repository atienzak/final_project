#include "shooter.h"

Shooter::Shooter(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/Buck Teeth Monster-256x256").scaled(133,130));
    bullet = new Bullet();
    bullet->setParentItem(this);
}

void Shooter::activate()
{
    bullet->begin_move();

}

