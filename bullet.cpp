#include "bullet.h"

Bullet::Bullet(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent),
    bulletPixmap(QPixmap(":/images/957-large-blue-circle.png").scaled(35,35))
{
    setPixmap(bulletPixmap);
    setPos(70,50);
}

/**
 * @brief Bullet::advance called by the scene to advance items to the next frame
 * @param phase called by scene with 0 to prepare for scene change, and then 1 to move the objects
 */
void Bullet::advance(int phase)
{
    if (!phase)
        return;

    setPos(x()+20, y()); // move bullet

    //if it already collides with an enemy
    if (checkEnemyCollision())
        return;

    if (x() >= 1800)
    {
        delete this;
        qDebug() << "bullet deleted";
    }
    return;
}


/**
 * @brief Bullet::checkEnemyCollision called upon by Bullet::advance to check if colliding with any enemy
 * @return true if colliding with an enemy, false otherwise
 */
bool Bullet::checkEnemyCollision()
{
    //returns all the items colliding with the bullet
    QList<QGraphicsItem*> colliding_list = collidingItems();

    //if the item is an enemy, then delete the bullet
    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
           player->addZombiesKilled();
           qDebug() << "killed " << player->getZombiesKilled();
           delete item;
           delete this;
           player->addMoney();
           return true;
        }
    }
    return false;
}
