#ifndef TURN_H
#define TURN_H

#include "frame.h"
#include "points_and_edges.h"
#include "entering_point.h"

    point turn_x(point point_s, double angle_radians);
    point turn_y(point point_s, double angle_radians);
    point turn_z(point point_s, double angle_radians);

#endif // TURN_H
