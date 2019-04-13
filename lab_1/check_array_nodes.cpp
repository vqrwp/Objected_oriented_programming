#include "check_array_nodes.h"

int check_points(points &points_s, FILE *file)
{
    int count;
    int err = read_size(&count, file);
    if (err)
    {
        return err;
    }

    err = points_alloc(points_s, count);
    if (err)
    {
        return err;
    }

    err = read_points(points_s.array_points, file, count);
    if (err)
    {
        clear_points(points_s);
    }

    return err;
}

int check_edges(edges &edges_s, FILE* file)
{
    int count;
    int err = read_size(&count, file);
    if (err) return err;

    err = edges_alloc(edges_s, count);

    err = read_edges(edges_s.array_edges, file, count);
    if (err)
    {
        clear_edges(edges_s);
    }
    return err;
}
