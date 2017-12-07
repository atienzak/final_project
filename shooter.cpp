#include "shooter.h"

Shooter::Shooter(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent),
    bullets({}),
    bulletTimeDelay(49),//,
    shooting(false)
{
    setPixmap(QPixmap(":/images/Cute Brown Monster-256x256 (1)").scaled(133,130));
    /*
    for (int i = 0; i < 7; i++)
    {
        bullets.push_back(new Bullet);
    }*/
}

void Shooter::spawnBullet(bool shoot)
{
    if (shoot)
    {
        bulletTimeDelay++;
        if (bulletTimeDelay % 50 != 0)
        {
            return;
        }

        //Bullet newbullet;
        //newbullet.setParentItem(this);
        //bulletTimeDelay = 0;

        bullets.push_back(new Bullet);
        bullets[bullets.size() - 1]->setParentItem(this);
        bulletTimeDelay = 0; // have to parent these items
    }
}

void Shooter::advance(int phase)
{
    if (!phase)
        return;
    //if (checkEnemyCollision())
      //  return;
    spawnBullet(shooting);//shooting);
}

bool Shooter::isShooting()
{
    return shooting;
}

void Shooter::activate()
{
    shooting = true;
}

void Shooter::deactivate()
{
    shooting = false;
}
/*
bool Shooter::checkEnemyCollision()
{


        //returns all the items colliding with the bullet
        QList<QGraphicsItem*> colliding_list = collidingItems();

        //if the item is an enemy, then delete the bullet
        foreach(QGraphicsItem * i , colliding_list)
        {
            Enemy * item= dynamic_cast<Enemy *>(i);
            if (item)
            {
               delete item;
               delete this;
               return true;
            }
        }
        return false;


}*/


