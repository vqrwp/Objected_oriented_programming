#ifndef READ_ARRAY_NODES_H
#define READ_ARRAY_NODES_H

#include "read_one_node.h"

int read_points(point *dots, FILE *file, int num);
int read_edges(edge* edges, FILE *file, int count);

#endif // READ_ARRAY_NODES_H
