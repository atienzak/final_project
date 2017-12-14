/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#include "enemy.h"

Enemy::Enemy(QGraphicsItem *parent) :
    QGraphicsItem(parent),
    currentFrame(0),
    enemyPixmap(QPixmap(":/images/zombiesprite").scaled(1002,162)) // sprite png image
{
    setFlag(ItemClipsToShape); // to set up shape of the enemy
}

Enemy::Enemy(const Enemy &other) : currentFrame(other.currentFrame), enemyPixmap(other.enemyPixmap)
{
    setFlag(ItemClipsToShape);
}


/**
 * @brief Enemy::boundingRect sets the boundaries of the moving Enemy
 * @return the size of its rectangular boundaries
 */
QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,162,162);
}

/**
  * @brief Enemy::paint drawing the enemy using painter
  * @param painter to set the pixmap image of the enemy
  * @param option unused
  * @param widget unused
  */
 void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget)
{
     //draw Pixmap on its current frame
     painter->drawPixmap(0,0,enemyPixmap,currentFrame, 0, 167,167);
     setTransformOriginPoint(boundingRect().center()); // center item in bounds

     Q_UNUSED(widget);
     Q_UNUSED(option);
}

/**
 * @brief Enemy::advance called upon by the scene to move the enemy forward
 * @param phase called twice by scene, 0 to prepare for scene change, 1 to move
 */
void Enemy::advance(int phase)
{
    if (!phase)
        return;

    // need zombie speed outside of class because enemies spawn at different times, so need to keep speed
    setPos(x()-(player->getzombieSpeed()),y());

    if (x() <= 0)
    {       
        player->subtractLives();
        delete this;
    }

    nextFrame();

    player->increaseZombieSpeed(); // will only trigger once every 10 zombies killed, per player class implementation
}

/**
 * @brief Enemy::nextFrame paints onto the next frame of the zombie png image
 */
void Enemy::nextFrame()
{
    //to repaint with the next frame; pixmap is a sprite
    currentFrame+=167;
    if (currentFrame >= 1002)
        currentFrame = 0;
}



