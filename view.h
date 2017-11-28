
#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "board.h"
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
