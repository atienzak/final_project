/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>

#include "grid.h"
#include "scene.h"


class View : public QGraphicsView
{
public:
    explicit View(Scene * nscene);
    //View();

protected:

    void resizeEvent(QResizeEvent* event);

private:
    QGraphicsScene * scene;


};


#endif
