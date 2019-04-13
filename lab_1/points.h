#ifndef POINTS_H
#define POINTS_H

#include "points_and_edges.h"
#include "draw.h"

point new_point(point *point_3d, drawing win);
point *invert_points(points pts, drawing draw);

#endif // POINTS_H
