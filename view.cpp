#include "view.h"
#include "scene.h"
View::View(Scene *nscene) : scene(nscene)
{

   setScene(scene);
   //setFixedSize(1400,736);
   //fitInView(scene->sceneRect());

}

void View::resizeEvent(QResizeEvent* event)
{

    fitInView(scene->sceneRect());
    QGraphicsView::resizeEvent(event);
}
/*
View::View()
{
    scene = new Scene();

    scene = new QGraphicsScene;

    Grid * test = new Grid();
    Grid * test1 = new Grid();

    QGraphicsPixmapItem * se = new QGraphicsPixmapItem();
    se->setPixmap(QPixmap(":/images/background.jpg"));

    //scene->addItem(se);
    //scene->addWidget(test);
    //scene->addWidget(test1);
    //test->setPos(100,100);


    QGraphicsGridLayout* mb = new QGraphicsGridLayout();


    mb->addItem(test,100,100);
    mb->addItem(test1, 200, 200);

    form = new QGraphicsWidget;
    form->setLayout(mb);
    scene->addItem(form);


    setScene(scene);
}
*/
