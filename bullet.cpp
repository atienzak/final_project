#include "bullet.h"

Bullet::Bullet(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/957-large-blue-circle.png").scaled(20,20));
    move_timer = new QTimer();
    connect(move_timer, SIGNAL(timeout()), this, SLOT (move_bullet()));
    move_timer->start(100);
    setPos(70,50);

}

void Bullet::move_bullet()
{
    setPos(x()+30, y());
    colliding_list = collidingItems();

    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
           delete item;
           delete this;
        }

    }

    if (this->x() >= 1800)
    {
        delete this;
        qDebug() << "bullet deleted";
    }
}
