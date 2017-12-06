#include "enemy.h"


Enemy::Enemy(QGraphicsItem *parent) :
    QGraphicsItem(parent),
    currentFrame(0),
    enemyPixmap(QPixmap(":/images/zombiesprite").scaled(1002,162))
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

    setPos(x()-20,y());

    if (x() <= 0)
    {
        qDebug() << "enemy deleted";
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

}

