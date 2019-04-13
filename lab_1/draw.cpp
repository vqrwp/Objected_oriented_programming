#include "draw.h"
#include "check_len.h"
#include "points.h"

int draw_figure(drawing draw, points points_s, edges edges_s)
{
    graphics graph;
    int err = init_graph(graph, draw.gV);
    if (err)
        return err;

    point *inverted_points = invert_points(points_s, draw);

    int len_connections_mas = edges_s.count;
    edge *mas_connections = edges_s.array_edges;
    for (int i = 0; i < len_connections_mas; i++)
    {
       addLine(graph, inverted_points[mas_connections[i].begin], inverted_points[mas_connections[i].end]);
    }

    delete_dyn_mem(inverted_points);
    set_scene(draw, graph);

    return err;
}

int update_scene(frame frame_s, drawing draw)
{
    int err = check_len(frame_s.points_s.count);
    if (err)
        return err;

    clear_scene(draw);
    err = draw_figure(draw, frame_s.points_s, frame_s.edges_s);

    return err;
}
