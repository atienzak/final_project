#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QGraphicsItem * parent = 0);

public slots:
    void move_enemy();
private:
    QTimer * move_timer;


};

#endif // ENEMY_H
