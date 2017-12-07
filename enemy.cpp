#include "enemy.h"


Enemy::Enemy(QGraphicsItem *parent) :
    QGraphicsItem(parent),
    currentFrame(0),
    enemyPixmap(QPixmap(":/images/zombiesprite").scaled(1002,162)),
    moveSpeed(10)
{
    setFlag(ItemClipsToShape);
    timer.start(); // for debugging purposes only
}


QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,167,167);
}

 void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget)
{
     //draw Pixmap on its current frame
     painter->drawPixmap(0,0,enemyPixmap,currentFrame, 0, 167,167);
     setTransformOriginPoint(boundingRect().center());

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

    setPos(x()-moveSpeed,y());

    if (x() <= 0)
    {       
        qDebug() << "enemy deleted";
        player->subtractLives();
        qDebug() << "lives left " << player->getLives();
        delete this;
    }

    //to repaint with the next frame; pixmap is a sprite
    currentFrame+=167;
    if (currentFrame >= 1002)
        currentFrame = 0;

    //for debugging puposes only
    int nMilliseconds = timer.elapsed();
    //qDebug() << "moving enemy: " << nMilliseconds;
    timer.restart();

    increaseMoveSpeed(player->getZombiesKilled());

}

void Enemy::increaseMoveSpeed(int zombieskilled)
{

    if (player->getZombiesKilled() >= 10 && player->getZombiesKilled() < 20 && moveSpeed == 10)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 20 && player->getZombiesKilled() < 30 && moveSpeed == 15)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 30 && player->getZombiesKilled() < 40 && moveSpeed == 20)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 40 && player->getZombiesKilled() < 50 && moveSpeed == 25)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 50 && player->getZombiesKilled() < 60 && moveSpeed == 30)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 60 && player->getZombiesKilled() < 70 && moveSpeed == 35)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 70 && player->getZombiesKilled() < 80 && moveSpeed == 40)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 80 && player->getZombiesKilled() < 90 && moveSpeed == 45)
        moveSpeed +=5;
    else if (player->getZombiesKilled() >= 90 && player->getZombiesKilled() < 100 && moveSpeed == 50)
        moveSpeed +=5;
}

