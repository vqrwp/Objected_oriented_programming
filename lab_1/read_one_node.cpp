#include "read_one_node.h"
#include "my_scanf.h"

errors read_size(int* count, FILE* file)
{
    errors err = my_scanf_int(count, file);
    return err;
}

errors read_point(point* point_s, FILE* file)
{
    errors err = NO_ERRORS;
    err = my_scanf_double(&point_s->x, file);
    if (err) return err;
    err = my_scanf_double(&point_s->y, file);
    if (err) return err;
    err = my_scanf_double(&point_s->z, file);
    return err;
}

errors read_edge(edge* edge_s, FILE* file)
{
    errors err = NO_ERRORS;
    err = my_scanf_int(&edge_s->begin, file);
    if (err) return err;
    err = my_scanf_int(&edge_s->end, file);
    return err;
}
