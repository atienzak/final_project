#include "scene.h"
#include <QTime>

Scene::Scene() :  background(nullptr), grid_vector({}), form(nullptr)
{

    QTime timer;
    timer.start();
    //initializing values through try-catch
   // try
    //{
        background = new QGraphicsPixmapItem;
        board_layout = new QGraphicsGridLayout;
        form = new QGraphicsWidget;
        for (int i = 0; i < 50; i++)
        {
            grid_vector.push_back(new Grid);
        }

    //}
    /*
    catch (std::exception &e)
    {
        delete background;
        delete board_layout;
        for (int i = 0, n = grid_vector.size(); i < n; i++)
        {
            delete grid_vector[i];
        }

        background = nullptr;
        board_layout = nullptr;
        for (int i = 0, n = grid_vector.size(); i < n; i++)
        {
            grid_vector[i] = nullptr;
        }

        throw;
    }
    */

    //sceneRect has the same aspect ratio as the background image
    setSceneRect(0,0,1900,1000);
    setBackgroundBrush(QPixmap(":/images/mainBackground.png"));
    //adding background
    //background->setPixmap(QPixmap(":/images/mainBackground.png"));
    //addItem(background);
    ///*
    //adding grid vectors in a board layout for (int i = 0; i < 25; i++)

    int j = 0;
    int k = 0;
    int i = 0;

        while (j < 5)
        {
            while (k < 10)
            {
                board_layout->addItem(grid_vector[i],j,k);
                i++;
                k++;
            }

            j++;
            k = 0;
        }
    //QCoreApplication::processEvents();
    //*/
    /*
    board_layout->addItem(grid_vector[0],0,1);
    board_layout->addItem(grid_vector[1],0,2);
    board_layout->addItem(grid_vector[2],0,3);
    board_layout->addItem(grid_vector[3],0,4);
    board_layout->addItem(grid_vector[4],0,5);
    board_layout->addItem(grid_vector[5],0,6);
    board_layout->addItem(grid_vector[6],0,7);

    //*/

    form->setLayout(board_layout);
    form->mapToItem(background,0,0);
    addItem(form);
    form->setPos(170,197);

    en = new Enemy(100);
    en1 = new Enemy(74);
    en2 = new Enemy(32);
    en3 = new Enemy(78);
    en4 = new Enemy(3);

    addItem(en);
    addItem(en1);
    addItem(en2);
    addItem(en3);
    addItem(en4);

    en->setPos(1800,185);
    en1->setPos(1800,370);
    en2->setPos(1800,555);
    en3->setPos(1800,740);
    en4->setPos(1800,925);

    //tmove = new QTimer();
    //tmove->setTimerType(Qt::PreciseTimer);
    //connect(tmove, SIGNAL(timeout()), this, SLOT(advance()));
   // connect (tmove, SIGNAL(timeout()), this, SLOT(working()));
   // tmove->start(100);

    int ml = timer.elapsed();
    qDebug() << "building scene: " << ml;
    timerId = startTimer(100, Qt::PreciseTimer);


}

void Scene::timerEvent(QTimerEvent *event)
{
    //qDebug() << "Timer ID:" << event->timerId();
    en->move();
    en1->move();
    en2->move();
    en3->move();
    en4->move();

}

/*
{

    try
    {
        background = new QGraphicsPixmapItem;
        board_layout = new QGraphicsGridLayout;
        for (size_t = 0; size_t < 25; ++size_t)
        {
            grid_list.push_back(new Grid);
        }

    }


    //sceneRect has the same aspect ratio as the background image
    setSceneRect(0,0,1900,1000);



    Grid * test01 = new Grid();
    Grid * test02 = new Grid();
    Grid * test03 = new Grid();
    Grid * test04 = new Grid();
    Grid * test05 = new Grid();
    Grid * test06 = new Grid();
    Grid * test07 = new Grid();
    Grid * test08 = new Grid();
    Grid * test09 = new Grid();
    Grid * test00 = new Grid();


    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/mainBackground.png"));

    addItem(background);

    board_layout = new QGraphicsGridLayout();

    mb->addItem(test00, 0, 0);
    mb->addItem(test01, 0, 1);
    mb->addItem(test02, 0, 2);
    mb->addItem(test03, 0, 3);
    mb->addItem(test04, 0, 4);
    mb->addItem(test05, 0, 5);
    mb->addItem(test06, 0, 6);
    mb->addItem(test07, 0, 7);
    mb->addItem(test08, 0, 8);
    mb->addItem(test09, 0, 9);


    form = new QGraphicsWidget;
    form->setLayout(mb);
    form->mapToItem(background,0,0);
    addItem(form);
    form->setPos(170,197);

    en = new Enemy();
    addItem(en);
    en->setPos(1800,185);

}

*/
