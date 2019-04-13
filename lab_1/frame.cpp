#include "stdio.h"
#include "stdlib.h"
#include "frame.h"
#include "error_codes.h"

frame &init()
{
    static frame fr;

    fr.points_s.count = 0;
    fr.points_s.array_points = nullptr;

    fr.edges_s.count = 0;
    fr.edges_s.array_edges = nullptr;

    return fr;
}

int edges_alloc(edges &edges_s, int count)
{
    edges_s.count = count;

    edges_s.array_edges = (edge*)calloc(count, sizeof(edge));
    if (!edges_s.array_edges)
    {
        return MEMORY_ALLOCATION;
    }
    return NO_ERRORS;
}

int points_alloc(points &points_s, int count)
{
    points_s.count = count;
    points_s.array_points = (point*)calloc(count, sizeof(point));
    if (!points_s.array_points)
    {
        return MEMORY_ALLOCATION;
    }
    return NO_ERRORS;
}

void clear(frame &fr)
{
    fr.points_s.count = 0;
    if (fr.points_s.array_points)
    {
        free(fr.points_s.array_points);
    }

    fr.edges_s.count = 0;
    if (fr.edges_s.array_edges)
    {
        free(fr.edges_s.array_edges);
    }
}

void clear_points(points &points_s)
{
    if (points_s.array_points)
    {
        free(points_s.array_points);
    }
}

void clear_edges(edges &edges_s)
{
    if (edges_s.array_edges)
    {
        free(edges_s.array_edges);
    }
}

void delete_dyn_mem(void *ptr)
{
    if (ptr)
    free(ptr);
}
