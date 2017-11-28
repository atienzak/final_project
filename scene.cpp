#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent), scene(nullptr)
{
    //scene = new QGraphicsScene;
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

    QGraphicsPixmapItem * se = new QGraphicsPixmapItem();
    se->setPixmap(QPixmap(":/images/mainBackground.png"));

    addItem(se);
    //scene->addWidget(test);
    //scene->addWidget(test1);
    //test->setPos(100,100);

    QGraphicsGridLayout* mb = new QGraphicsGridLayout();

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
    form->mapToItem(se,0,0);
    addItem(form);
    form->setPos(170,197);

    en = new Enemy();
    addItem(en);
    en->setPos(1800,185);

    //setSceneRect(itemsBoundingRect());
}

