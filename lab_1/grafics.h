#ifndef GRAFICS_H
#define GRAFICS_H

#include "error_codes.h"
#include "frame.h"
#include "QGraphicsView"
#include "entering_point.h"

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

int init_graph(graphics &a, QGraphicsView *gV);
void set_scene(drawing draw, graphics graph);
void clear_scene(drawing draw);

#endif // GRAFICS_H
