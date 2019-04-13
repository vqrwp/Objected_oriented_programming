#include "draw_edges.h"

points_for_draw get_point(point* array_point, int i)
{
    points_for_draw point = {array_point[i].x, array_point[i].y};
    return point;
}

//st_line_to_draw* get_edges(point* array_points, edge* array_edges, int count_edges, drawing draw, graphics a)
//{
//    st_line_to_draw *line_to_draw = new st_line_to_draw [count_edges];
//    for (int i = 0; i < count_edges; i++)
//    {
//        line_to_draw[i].begin = get_point(array_points, array_edges[i].begin);
//        line_to_draw[i].end = get_point(array_points, array_edges[i].end);

//    }

//    return line_to_draw;
//}
