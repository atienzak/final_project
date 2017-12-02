#include "bullet.h"

Bullet::Bullet(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/957-large-blue-circle.png").scaled(35,35));
    move_timer = new QTimer();
    setFlag(ItemIsMovable);
    //connect(move_timer, SIGNAL(timeout()), this, SLOT (move_bullet()));
    move_timer->start(100);
    setPos(70,50);


}

void Bullet::begin_move()
{
    //connect(move_timer, SIGNAL(timeout()), this, SLOT (move_bullet()));
}

void Bullet::advance(int phase)
{
    if (!phase)
        return;
    setPos(x()+20, y());
    /*colliding_list = collidingItems();

    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
           delete item;
           delete this;
        }
    }*/

    if (this->x() >= 1800)
    {
        delete this;
        qDebug() << "bullet deleted";
    }
}
