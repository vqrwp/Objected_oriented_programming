#include "math.h"
#include "turn_xyz.h"

int turn_points(points points_s, double angle, point (*turn)(point, double))
{
    for (int i = 0; i < points_s.count; i++)
    {
        points_s.array_points[i] = turn(points_s.array_points[i], angle);
    }
    return 0;
}

int turn_xyz(frame fr, arguments args)
{
    double angle_radians = args.turn.angle * M_PI / 180;
    if (args.act == X_TURN)
    {
        turn_points(fr.points_s, angle_radians, turn_x);
    }
    if (args.act == Y_TURN)
    {
        turn_points(fr.points_s, angle_radians, turn_y);
    }
    if (args.act == Z_TURN)
    {
        turn_points(fr.points_s, angle_radians, turn_z);
    }
    return 0;
}

