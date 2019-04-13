#include "transfer.h"

int transfer_points(frame fr, transfering transfer)
{

    for (int i = 0; i < fr.points_s.count; i++)
    {
        fr.points_s.array_points[i].x += transfer.x;
        fr.points_s.array_points[i].y += transfer.y;
    }
    return 0;
}
