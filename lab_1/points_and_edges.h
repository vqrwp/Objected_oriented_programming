#ifndef POINTS_AND_EDGES_H
#define POINTS_AND_EDGES_H

struct point
{
    double x;
    double y;
    double z;
};

struct points
{
    point* array_points;
    int count;
};

struct edge
{
    int begin;
    int end;
};

struct edges
{
    edge *array_edges;
    int count;
};


#endif // POINTS_AND_EDGES_H
