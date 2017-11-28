#include "grid.h"

Grid::Grid(QGraphicsWidget *parent) : QGraphicsWidget(parent), shooter_id(0), testshooter(nullptr)
{
    pic = QPixmap(":/images/Cute Brown Monster-256x256 (1)");
    pic = pic.scaled(133,133);

}

/*QRectF Grid::boundingRect() const
{
    return QRectF(0,0,40,41); // changed something
}*/

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QRectF(-15,-17,153,153);
    //painter->drawPixmap(-10,0,pic);
    QRectF bounds = QRectF(-15,-17,153,153);
    QColor c(215,215,193);
    QBrush cst(c, Qt::SolidPattern);
    QPen pen = QPen(cst, 1, Qt::SolidLine, Qt::RoundCap);
    //painter->setPen(Qt::DashDotLine);
    painter->setPen(pen);
    painter->drawRect(bounds);

    setTransformOriginPoint(boundingRect().center());
}

void Grid::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF Grid::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    //pic.size() + QSize(11, 10);
    switch (which) {
       case Qt::MinimumSize:
       case Qt::PreferredSize:
           // Do not allow a size smaller than the pixmap with two frames around it.
           //return QSize(90,90);
            //return QSize(153,153);
          return pic.size() + QSize(11, 10);
       case Qt::MaximumSize:
           return QSizeF(1000,1000);
       default:
           break;
       }
       return constraint;

}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (testshooter == nullptr){
    QGraphicsItem::mousePressEvent(event);
    testshooter = new Shooter();
    testshooter->setParentItem(this);
    testshooter->setPos(-10,0);
    update();
    qDebug() << "item clicked";
    }

}


