#ifndef GRID_H
#define GRID_H
#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QPainter>
#include <QGraphicsWidget>
#include <QDebug>
#include "shooter.h"

class Grid : public QGraphicsWidget
{
public:
    Grid(QGraphicsWidget *parent = 0);
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

private:
    QSize monster_size;
    Shooter * shooter;


};








#endif
