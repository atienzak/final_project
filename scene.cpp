/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#include "scene.h"

Scene::Scene() :
    background(QPixmap(":/images/mainBackground.png")),
    gridVector({}),
    form(nullptr),
    boardLayout(nullptr),
    tmove(nullptr),
    spawnDelay(0),
    randomPos(0),
    zombies({}),
    zombieCounter(0),
    zombieChecker({}),
    label1(nullptr),
    zombiesKilledDisplay(nullptr),
    zombiesKilled(nullptr),
    label2(nullptr),
    moneyLeftDisplay(nullptr),
    moneyLeft(nullptr),
    label3(nullptr),
    livesLeftDisplay(nullptr),
    livesLeft(nullptr),
    gameOver(nullptr)

{
    srand(time(nullptr)); // seeed for the timer

    //initializing values through try-catch
    try
    {
        boardLayout = new QGraphicsGridLayout;
        form = new QGraphicsWidget;
        tmove = new QTimer;
        label1 = new QGraphicsTextItem("");
        label2 = new QGraphicsTextItem("");
        label3 = new QGraphicsTextItem("");
        zombiesKilledDisplay = new QLCDNumber();
        moneyLeftDisplay = new QLCDNumber();
        livesLeftDisplay = new QLCDNumber();

        for (int i = 0; i < 50; i++) // for a 10x5 board
        {
            gridVector.push_back(new Grid);
        }

        for (int i = 0; i < 100; i++) // number of enemies
        {
            zombies.push_back(new Enemy);
        }
        for (int i = 0; i < 5; i++) // row zombies checker
        {
            zombieChecker.push_back(new QGraphicsLineItem);
        }
    }

    catch (std::exception &e)
    {
        delete boardLayout;
        delete form;
        delete tmove;
        delete label1;
        delete label2;
        delete label3;
        delete zombiesKilledDisplay;
        delete livesLeftDisplay;
        delete moneyLeftDisplay;

        for (int i = 0, n = gridVector.size(); i < n; i++)
        {
            delete gridVector[i];
        }
        for (int i = 0, n = zombies.size(); i < n; i++)
        {
            delete zombies[i];
        }
        for (int i = 0, n = zombieChecker.size(); i < n; i++)
        {
            delete zombieChecker[i];
        }

        boardLayout = nullptr;
        form = nullptr;
        tmove = nullptr;
        label1 = nullptr;
        label2 = nullptr;
        label3 = nullptr;
        zombiesKilledDisplay = nullptr;
        livesLeftDisplay = nullptr;
        moneyLeftDisplay = nullptr;

        for (int i = 0, n = gridVector.size(); i < n; i++)
        {
            gridVector[i] = nullptr;
        }
        for (int i = 0, n = zombies.size(); i < n; i++)
        {
            zombies[i] = nullptr;
        }
        for (int i = 0, n = zombieChecker.size(); i < n; i++)
        {
            zombieChecker[i] = nullptr;
        }

        throw;
    }


    //sceneRect has the same aspect ratio as the background image
    setSceneRect(0,0,1900,1000);
    setBackgroundBrush(background);

    constructBoard();

    //to activate the shooters when zombies are entering the rows
    for (int i = 0; i < 5; i++)
    {
        zombieChecker[i]->setLine(0,0,1450,0);
        zombieChecker[i]->setPen(QPen(QColor(0,0,0,0)));
        zombieChecker[i]->setPos(200,270 + 150*i);
        addItem(zombieChecker[i]);
    }

    //zombies killed display
    label1->setHtml(QString("<div style='color:rgba(255, 255, 255, 100%); font-size: 35px'>" + QString("Zombies Killed: ") + QString("</div>") ));
    addItem(label1);
    label1->setPos(200,70);
    zombiesKilledDisplay->setSegmentStyle(QLCDNumber::Flat);
    zombiesKilledDisplay->setFixedSize(QSize(100,50));
    zombiesKilled = addWidget(zombiesKilledDisplay);
    zombiesKilled->setPos(450,70);
    zombiesKilledDisplay->display(player->getZombiesKilled());

    //money left display
    label2->setHtml(QString("<div style='color:rgba(255, 255, 255, 100%); font-size: 35px'>" + QString("Money Left: ") + QString("</div>") ));
    addItem(label2);
    label2->setPos(700,70);
    moneyLeftDisplay->setSegmentStyle(QLCDNumber::Flat);
    moneyLeftDisplay->setFixedSize(QSize(100,50));
    moneyLeft = addWidget(moneyLeftDisplay);
    moneyLeft->setPos(900,70);
    moneyLeftDisplay->display(player->getZombiesKilled());

    //lives left display
    label3->setHtml(QString("<div style='color:rgba(255, 255, 255, 100%); font-size: 35px'>" + QString("Lives Left: ") + QString("</div>")));
    addItem(label3);
    label3->setPos(1200,70);
    livesLeftDisplay->setSegmentStyle(QLCDNumber::Flat);
    livesLeftDisplay->setFixedSize(QSize(100,50));
    livesLeft = addWidget(livesLeftDisplay);
    livesLeft->setPos(1400,70);
    livesLeftDisplay->display(player->getLives());

    tmove->setTimerType(Qt::PreciseTimer);
    connect(tmove, SIGNAL(timeout()), this, SLOT(advance()));
    connect(tmove, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    connect(tmove, SIGNAL(timeout()), this, SLOT(updateData()));
    tmove->start(100);


}

Scene::~Scene()
{
    delete tmove;
    delete label1;
    delete label2;
    delete label3;
    delete zombiesKilledDisplay;
    delete livesLeftDisplay;
    delete moneyLeftDisplay;

    for (int i = 0, n = gridVector.size(); i < n; i++)
    {
        delete gridVector[i];
    }
    for (int i = 0, n = zombies.size(); i < n; i++)
    {
        delete zombies[i];
    }
    for (int i = 0, n = zombieChecker.size(); i < n; i++)
    {
        delete zombieChecker[i];
    }
}


/**
 * @brief Scene::spawnEnemies makes enemy and puts them in random place in the board
 *  and activates the appropriate shooters in which the zombies are coming through
 */
void Scene::spawnEnemies()
{
    spawnDelay++;
    if (spawnDelay % 20 != 0) // to delay the enemies spawning every call to advance
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

/**
 * @brief Scene::constructBoard sets up the board
 */
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

/**
 * @brief Scene::activateShooters if the
 * @param row the row to activate the shooters
 */
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
        item = nullptr;
    }

    for (int i = (0 + 10*row), n = (i+10); i < n; i++)
       gridVector[i]->deactivate();
    return;
}

/**
 * @brief Scene::updateData updates the data displays above the game
 */
void Scene::updateData()
{
    zombiesKilledDisplay->display(player->getZombiesKilled());
    moneyLeftDisplay->display(player->getMoney());
    livesLeftDisplay->display(player->getLives());
    if (player->getLives() == 0)
    {

        disconnect(tmove, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
        disconnect(tmove, SIGNAL(timeout()), this, SLOT(updateData()));

        gameOver = new QMessageBox();
        gameOver->setText("Game Over!");
        gameOver->show();
    }
}

