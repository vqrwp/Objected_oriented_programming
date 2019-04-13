#include "turn_by_coords.h"
#include "math.h"

point turn_z(point point_s, double angle_radians)
{
    point temp_point;
    double cos_angle = cos(angle_radians);
    double sin_angle = sin(angle_radians);

    double x_tmp = point_s.x * cos_angle + point_s.y * sin_angle;
    double y_tmp = -point_s.x * sin_angle + point_s.y * cos_angle;

    temp_point.x = x_tmp;
    temp_point.y = y_tmp;
    temp_point.z = point_s.z;

    return temp_point;
}

point turn_x(point point_s, double angle_radians)
{
    point temp_point;

    double cos_angle = cos(angle_radians);
    double sin_angle = sin(angle_radians);

    double y_tmp = point_s.y * cos_angle + point_s.z * sin_angle;
    double z_tmp = -point_s.y * sin_angle + point_s.z * cos_angle;

    temp_point.y = y_tmp;
    temp_point.z = z_tmp;
    temp_point.x = point_s.x;

    return temp_point;
}

point turn_y(point point_s, double angle_radians)
{
    point temp_point;
    double cos_angle = cos(angle_radians);
    double sin_angle = sin(angle_radians);

    double x_tmp = point_s.x * cos_angle - point_s.z * sin_angle;
    double z_tmp = point_s.x * sin_angle + point_s.z * cos_angle;

    temp_point.x = x_tmp;
    temp_point.y = point_s.y;
    temp_point.z = z_tmp;

    return temp_point;
}
