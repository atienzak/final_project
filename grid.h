
#ifndef GRID_H
#define GRID_H
#include <QPainter>
#include <QGraphicsWidget>
#include <QDebug>
#include "shooter.h"

class Grid : public QGraphicsWidget
{
public:
    Grid(QGraphicsWidget *parent = 0);

    //reimplementing virtual functions
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    void activate();
    void deactivate();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

private:

    //shooter housed within the grid
    Shooter* shooter;
};








#endif
