#include "grafics.h"

int init_graph(graphics &a, QGraphicsView *gV)
{
    a.scene = new QGraphicsScene(gV);
    if (!a.scene)
    {
        return MEMORY_ALLOCATION;
    }
    a.pen = QPen(Qt::black);
    return NO_ERRORS;
}

void set_scene(drawing draw, graphics graph)
{
    draw.gV->setScene(graph.scene);
}

void clear_scene(drawing draw)
{
    delete (draw.gV->scene());
}
