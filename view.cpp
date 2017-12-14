/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

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
