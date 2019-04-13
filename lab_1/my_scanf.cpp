#include <error_codes.h>
#include <points_and_edges.h>
#include <iostream>

errors my_scanf_double(double* num, FILE* file)
{
    errors err = NO_ERRORS;
    char tmp;
    if (fscanf(file, "%lf%c", num, &tmp) != 2 || (tmp != 13 && tmp != 10 && tmp != ' '))
    {
        err = CONTENT_ERROR;
    }
    return err;
}


errors my_scanf_int(int* num, FILE* file)
{
    errors err = NO_ERRORS;
    char tmp;
    if (fscanf(file, "%d%c", num, &tmp) != 2 || (tmp != 13 && tmp != 10 && tmp != ' '))
    {
        err = CONTENT_ERROR;
    }
    return err;
}
