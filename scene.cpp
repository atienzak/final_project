#include "scene.h"

Scene::Scene() :
    background(QPixmap(":/images/mainBackground.png")),
    gridVector({}),
    form(nullptr),
    boardLayout(nullptr),
    tmove(nullptr),
    zombies({}),
    zombieCounter(0),
    spawnDelay(19),
    randomPos(0)
{
    srand(time(nullptr));

    //initializing values through try-catch
    try
    {
        boardLayout = new QGraphicsGridLayout;
        form = new QGraphicsWidget;
        tmove = new QTimer;
        spawnTimer = new QTimer;

        for (int i = 0; i < 50; i++) // for a 10x5 board
        {
            gridVector.push_back(new Grid);
        }

        for (int i = 0; i < 100; i++) // number of enemies
        {
            zombies.push_back(new Enemy);
        }
        for (int i = 0; i < 5; i++)
        {
            zombieChecker.push_back(new QGraphicsLineItem);
        }
    }

    catch (std::exception &e)
    {
        delete boardLayout;
        delete form;
        delete tmove;
        delete spawnTimer;

        for (int i = 0, n = gridVector.size(); i < n; i++)
        {
            delete gridVector[i];
        }

        boardLayout = nullptr;

        for (int i = 0, n = gridVector.size(); i < n; i++)
        {
            gridVector[i] = nullptr;
        }

        throw;
    }


    //sceneRect has the same aspect ratio as the background image
    setSceneRect(0,0,1900,1000);
    setBackgroundBrush(background);

    constructBoard();

    tmove->setTimerType(Qt::PreciseTimer);
    connect(tmove, SIGNAL(timeout()), this, SLOT(advance()));
    // connect (tmove, SIGNAL(timeout()), this, SLOT(working()));
    tmove->start(100);

    //spawnTimer->setTimerType(Qt::PreciseTimer);
    connect(tmove, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    //spawnTimer->start(1000);

    //to activate the shooters when zombies are entering the rows
    for (int i = 0; i < 5; i++)
    {
        zombieChecker[i]->setLine(0,0,1450,0);
        zombieChecker[i]->setPen(QPen(QColor(0,0,0)));
        zombieChecker[i]->setPos(200,270 + 150*i);
        addItem(zombieChecker[i]);
    }
}

void Scene::spawnEnemies()
{
    spawnDelay++;
    if (spawnDelay % 20 != 0)
        return;
    if (zombieCounter == 99)
        return;

    randomPos = rand() % 5 + 1;
    addItem(zombies[zombieCounter]);

    if (randomPos == 1)
        zombies[zombieCounter]->setPos(1800,185);
    else if (randomPos == 2)
         zombies[zombieCounter]->setPos(1800,339);
    else if (randomPos == 3)
         zombies[zombieCounter]->setPos(1800,491);    
    else if (randomPos == 4)
         zombies[zombieCounter]->setPos(1800,644);
    else if (randomPos == 5)
         zombies[zombieCounter]->setPos(1800,796);

    activateShooters(0);
    activateShooters(1);
    activateShooters(2);
    activateShooters(3);
    activateShooters(4);


    zombieCounter++;
    spawnDelay = 0;
}

void Scene::constructBoard()
{
    int j = 0;
    int k = 0;
    int i = 0;

        while (j < 5)
        {
            while (k < 10)
            {
                boardLayout->addItem(gridVector[i],j,k);
                i++;
                k++;
            }

            j++;
            k = 0;
        }

    form->setLayout(boardLayout);
    addItem(form);
    form->setPos(170,197);
}

void Scene::activateShooters(int row)
{
    //returns all the items colliding with the zombieChecker line in each row
    QList<QGraphicsItem*> colliding_list = zombieChecker[row]->collidingItems();


    foreach(QGraphicsItem * i , colliding_list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
            for (int i = (0 + 10*row), n = (i+10); i < n; i++)
                gridVector[i]->activate(); // the grid already has a checker in this function in case no shooter exists
           return;
        }
    }

    for (int i = (0 + 10*row), n = (i+10); i < n; i++)
       gridVector[i]->deactivate();
       return;
}

