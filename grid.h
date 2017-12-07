#ifndef GRID_H
#define GRID_H
#include <QPainter>
#include <QGraphicsWidget>
#include <QDebug>
#include "shooter.h"

extern Player* player;


class Grid : public QGraphicsWidget
{
public:
    Grid(QGraphicsWidget *parent = 0);

    //reimplementing virtual functions
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;
    bool checkEnemyCollision();
    void activate();
    void deactivate();
    void advance(int phase);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

private:

    //shooter housed within the grid
    Shooter* shooter;
};








#endif
