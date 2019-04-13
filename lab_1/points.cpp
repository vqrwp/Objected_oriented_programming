#include "points.h"

point new_point(point *point_3d, drawing win)
{
    point new_point;
    new_point.x = win.width + point_3d->x * win.length / (point_3d->z + win.length) ;
    new_point.y = win.height - point_3d->y * win.length / (point_3d->z + win.length);

    return new_point;
}

point *invert_points(points pts, drawing draw)
{
    point *inverted_points = new point [(unsigned long long)pts.count];
    for (int i = 0; i < pts.count; i++)
    {
        inverted_points[i] = new_point(&pts.array_points[i], draw);
    }

    return inverted_points;
}
