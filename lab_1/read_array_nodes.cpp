#include "read_array_nodes.h"

int read_points(point *dots, FILE *file, int num)
{
    int err = 0;
    for (int i = 0; i < num && !err; i++)
    {
        if (read_point(&dots[i], file))
        {
            err = CONTENT_ERROR;
        }
    }
    return err;
}

int read_edges(edge* edges, FILE *file, int count)
{
    int err = NO_ERRORS;
    for (int i = 0; i < count && !err; i++)
    {
        if (read_edge(&edges[i], file))
        {
            err = CONTENT_ERROR;
        }
    }
    return err;
}
