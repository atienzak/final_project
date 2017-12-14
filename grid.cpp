/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

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
        throw 42;
    }
}

Grid::Grid(const Grid& other) : shooter (other.shooter)
{}

Grid& Grid::operator=(Grid rhs) // copy-swap functionality
{
    this->swap(rhs);
    return *this;
}

Grid::~Grid()
{
    delete shooter;
}

// to be used for copy-swap functionality
void Grid::swap(Grid &rhs)
{
    std::swap(shooter, rhs.shooter);
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

    //customizing rectangle to match the background
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

/**
 * @brief Grid::checkEnemyCollision deletes the shooter housed in the grid and the enemy when they meet
 * @return true if if enemy collides with grid, false otherwise
 */
bool Grid::checkEnemyCollision()
{
    //returns all the items colliding with the grid
    QList<QGraphicsItem*> colliding_list = collidingItems();

    //if the item is an enemy, then delete the bullet
    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item && shooter->parentItem() == this)
        {
           delete item;
           delete shooter;
           shooter = new Shooter(); // need to house another shooter again if the user wants to create
                                    // another shooter within the grid
           return true;
        }
        item = nullptr;
    }
    return false;
}

/**
 * @brief Grid::activate activates the shooter to shoot; this function is called upon by the scene because scene do not have access to shooter itself
 */
void Grid::activate()
{
    if (shooter->parentItem() != this) // shooter is not "built" in the grid yet
        return;

    shooter->activate();
}

/**
 * @brief Grid::deactivate adectivates the shooter from shooting; this function is called upon by the scene because scene do not have access to shooter itself
 */
void Grid::deactivate()
{
    if (shooter->parentItem() != this) // shooter is not "built" in the grid yet
        return;

    shooter->deactivate();
}

/**
 * @brief Grid::advance called upon by the scene to check for enemy collisions as set by scene's timer
 * @param phase 0 to get ready for scene change, 1 to run
 */
void Grid::advance(int phase)
{
    if (!phase)
        return;
    checkEnemyCollision();
}

/**
 * @brief Grid::mousePressEvent to create the shooter
 * @param event mouse press event
 */
void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (player->getMoney() < 50) // can't build of player doesn't have enough money
        return;

    // shooter already exists on the heap, just needs to show up on the grid
    if (shooter->parentItem() != this)
    {
        shooter->setParentItem(this);
        shooter->setPos(-10,0); // centering the shooter within the bounds
    }

    player->subtractMoney(50); // subtracts money from player once created

    QGraphicsItem::mousePressEvent(event);
}

