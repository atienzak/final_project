#include "bullet.h"

/**
 * @brief Bullet::Bullet default constructor with optional parent parameter
 *        needed to make the shooter object the parent of the item
 * @param parent parent item of the bullet
 */
Bullet::Bullet(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent),
    bulletPixmap(QPixmap(":/images/957-large-blue-circle.png").scaled(35,35))
{
    setPixmap(bulletPixmap);
    setPos(70,50);
}

/**
 * @brief Bullet::Bullet copy constructor
 * @param other copy parameter
 */
Bullet::Bullet(const Bullet& other) :
    bulletPixmap(other.bulletPixmap)
{
    setPixmap(other.bulletPixmap);
    setParentItem(other.parentItem());
}

/**
 * @brief Bullet::advance called by the scene to advance items to the next frame
 * @param phase called by scene with 0 to prepare for scene change, and then 1 to move the objects
 */
void Bullet::advance(int phase)
{
    if (!phase || checkEnemyCollision()) // stops function if not ready for next frame or if it already collides with the enemy
        return;

    setPos(x()+15, y()); // moves the bullet 15 px forward

    if (x() >= 1800) // once bullet is out of bounds
    {
        delete this;
    }

    return;
}

/**
 * @brief Bullet::checkEnemyCollision called upon by Bullet::advance to check if colliding with any enemy
 * @return true if colliding with an enemy, false otherwise
 */
bool Bullet::checkEnemyCollision() const
{

    //returns all the items colliding with the bullet
    QList<QGraphicsItem*> colliding_list = collidingItems();

    //if the item is an enemy, then delete the bullet, and delete the enemy
    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
           player->addZombiesKilled();
           player->addMoney(10);
           delete item;
           delete this;
           return true;
        }
        item = nullptr;
    }
    return false;
}
