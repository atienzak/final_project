#ifndef GRID_H
#define GRID_H
#include <QPainter>
#include <QGraphicsWidget>
#include "shooter.h"

extern Player* player; // contaisn the game data

class Grid : public QGraphicsWidget
{

public:
    Grid(QGraphicsWidget *parent = 0); // default constructor
    Grid (const Grid& other); // copy constructor
    Grid& operator=(Grid rhs); // copy assignment operator using copy-swap idiom
    ~Grid(); // default constructor

    //reimplementing virtual functions
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    bool checkEnemyCollision(); // to delete shooter when collides with enemy

    //make shooters active
    void activate();
    void deactivate();

    void advance(int phase) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override; // to make shooters

private:
    //shooter housed within the grid
    Shooter* shooter;
    void swap(Grid& rhs); // for copy-swap functionality
};

#endif
