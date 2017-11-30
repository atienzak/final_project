#include "grid.h"
#include <QCoreApplication>
Grid::Grid(QGraphicsWidget *parent) : QGraphicsWidget(parent), shooter(nullptr), monster_size(QSize())
{
    // the monster size is determined through the size of the monster pictures
    monster_size = QPixmap(":/images/Cute Brown Monster-256x256 (1)").scaled(133,133).size();



}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //making the size of the grid, with an offset to match the background coordinates
    QRectF bounds = QRectF(-13,-15,152,152);

    QColor c(215,215,193); // grayish-white
    QBrush cst(c, Qt::SolidPattern);
    QPen pen = QPen(cst, 1, Qt::SolidLine, Qt::RoundCap);
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

    switch (which) {
       case Qt::MinimumSize:
       case Qt::PreferredSize:
           // Do not allow a size smaller than the pixmap with two frames around it.
          return monster_size + QSize(10, 10);
       case Qt::MaximumSize:
           return QSizeF(1000,1000);
       default:
           break;
       }
       return constraint;
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

   // try
     //   {
            if (shooter == nullptr)
            {
                shooter = new Shooter();
                shooter->setParentItem(this);
                shooter->setPos(-10,0);
                qDebug() << "grid clicked";
                update();
                QGraphicsItem::mousePressEvent(event);

            }
       // }
/*
   catch(std::exception &e )
        {
            qDebug() << "exception occurs";
            delete shooter;
            shooter = nullptr;
            throw;
        }

    shooter->activate();
*/
}

