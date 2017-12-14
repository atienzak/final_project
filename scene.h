#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "grid.h"
#include <QGraphicsGridLayout>
#include "enemy.h"
#include <QTimer>
#include <QObject>
#include <cstdlib>
#include <QGraphicsLineItem>
#include "player.h"
#include <QGraphicsProxyWidget>
#include <QLCDNumber>
#include <QMessageBox>

extern Player* player;
class Scene :public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    Scene(const Scene& other) = delete; // there can only be one scene
    Scene& operator=(Scene rhs) = delete;
    ~Scene();


protected:
    void activateShooters(int row);

protected slots:
    void spawnEnemies();
    void updateData();


private:

    void constructBoard();

    //background item
    QPixmap background;

    //objects needed to form the board
    QVector<Grid*> gridVector;
    QGraphicsWidget* form;
    QGraphicsGridLayout* boardLayout;

    //timer for animation
    QTimer* tmove;

    //needed to spawn zombies
    int spawnDelay;
    int randomPos;
    QVector<Enemy*> zombies;
    int zombieCounter;

    QVector<QGraphicsLineItem*> zombieChecker; // to check if zombie is in any of the rows

    //for the displays that hover above the game
    QGraphicsTextItem* label1;
    QLCDNumber* zombiesKilledDisplay;
    QGraphicsProxyWidget* zombiesKilled;

    QGraphicsTextItem* label2;
    QLCDNumber* moneyLeftDisplay;
    QGraphicsProxyWidget* moneyLeft;

    QGraphicsTextItem* label3;
    QLCDNumber* livesLeftDisplay;
    QGraphicsProxyWidget* livesLeft;

    QMessageBox* gameOver;
};



#endif // SCENE_H
