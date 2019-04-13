#ifndef FRAME_H
#define FRAME_H

#include "points_and_edges.h"

struct frame
{
    points points_s;
    edges edges_s;
};

frame &init();
int points_alloc(points &points_s, int count);
int edges_alloc(edges &edges_s, int count);
void clear(frame &fr);
void clear_points(points &points_s);
void clear_edges(edges &points_s);
void delete_dyn_mem(void *ptr);

#endif // FRAME_H




