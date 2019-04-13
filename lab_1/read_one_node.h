#ifndef READ_ONE_NODE_H
#define READ_ONE_NODE_H

#include "stdio.h"
#include "error_codes.h"
#include "points_and_edges.h"

errors read_size(int* count, FILE* file);
errors read_point(point* dot, FILE* file);
errors read_edge(edge* node, FILE* file);

#endif // READ_ONE_NODE_H
