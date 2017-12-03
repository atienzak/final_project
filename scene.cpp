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
    tmove->start(8);

    //spawnTimer->setTimerType(Qt::PreciseTimer);
    connect(tmove, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    //spawnTimer->start(1000);
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

