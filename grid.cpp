#include "grid.h"

Grid::Grid(QGraphicsWidget *parent) : QGraphicsWidget(parent), shooter(nullptr)
{
    try
    {
        shooter = new Shooter();
    }
    catch(std::exception &e )
    {
        delete shooter;
        shooter = nullptr;
        throw;
    }
}

/**
 * @brief Grid::paint for paint events
 * @param painter to draw the grid
 * @param option unused
 * @param widget unused
 */
void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //making the size of the grid, with an offset to match the background coordinates -
    QRectF bounds = QRectF(-13,-15,152,152);

    //customizing rectangle
    QColor color = QColor(215,215,193); // grayish-white color
    QBrush cst = QBrush(color, Qt::SolidPattern);
    QPen pen = QPen(cst, 1, Qt::SolidLine, Qt::RoundCap);

    painter->setPen(pen);
    painter->drawRect(bounds);

    setTransformOriginPoint(boundingRect().center());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

/**
 * @brief Grid::setGeometry to determine size relative to parent
 * @param geom rectangle that houses the item
 */
void Grid::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

/**
 * @brief Grid::sizeHint for window resizing purposes
 * @param which recommended size
 * @param constraint max size
 * @return the size of the whole widget
 */
QSizeF Grid::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
       case Qt::MinimumSize:
       case Qt::PreferredSize:
           // can't be larger than the pixmap item itself
          return QSize(133,133) + QSize(10, 10);
       case Qt::MaximumSize:
           return QSizeF(1000,1000);
       default:
           break;
       }
    return constraint;
}

bool Grid::checkEnemyCollision()
{
    //returns all the items colliding with the bullet
    QList<QGraphicsItem*> colliding_list = collidingItems();

    //if the item is an enemy, then delete the bullet
    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item && shooter->parentItem() == this)
        {
           delete item;
           delete shooter;
           shooter = new Shooter();
           return true;
        }
    }
    return false;
}

void Grid::activate()
{
    if (shooter->parentItem() != this) // shooter is not built in the grid yet
        return;

    shooter->activate();
}

void Grid::deactivate()
{
    if (shooter->parentItem() != this)
        return;

    shooter->deactivate();
}

void Grid::advance(int phase)
{
    checkEnemyCollision();
}
/**
 * @brief Grid::mousePressEvent to create the shooters
 * @param event mouse press event
 */
void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     // to "show" the shooter that has already been allocated on the heap
    if (shooter->parentItem() != this)
    {
     shooter->setParentItem(this);
     shooter->setPos(-10,0); // centering the shooter within the bounds
     // for debugging purposes only
     qDebug() << "grid clicked";
    }

     QGraphicsItem::mousePressEvent(event);
}

