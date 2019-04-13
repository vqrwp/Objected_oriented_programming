#ifndef DRAW_LINE_H
#define DRAW_LINE_H

#include "points_and_edges.h"
#include "entering_point.h"
#include "frame.h"
#include "grafics.h"

struct points_for_draw
{
    double x;
    double y;
};

void addLine(graphics window, point point1, point point2);

#endif // DRAW_LINE_H
