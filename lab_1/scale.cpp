#include "scale.h"

int scale_points(frame fr, scaling scale)
{
    for (int i = 0; i < fr.points_s.count; i++)
    {
        fr.points_s.array_points[i].x *= scale.scale;
        fr.points_s.array_points[i].y *= scale.scale;
        fr.points_s.array_points[i].z *= scale.scale;
    }
    return 0;
}
