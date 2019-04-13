#include "read_from_file.h"
#include "stdlib.h"
#include "iostream"
#include "stdio.h"

int read_content(frame &fr, FILE* file)
{
    int err;
    if ((err = check_points(fr.points_s, file)) == 0)
    {
        if ((err = check_edges(fr.edges_s, file)) != 0)
        {
            clear_points(fr.points_s);
        }
    }
    return err;
}

int read_from_file(frame &fr, loading_file filename)
{
    FILE *file;
    int err = fopen_s(&file, filename.filename, "r");

    if (err) return err;

    frame fr_tmp = init();
    err = read_content(fr_tmp, file);

    fclose(file);

    if (!err)
    {
        clear(fr);
        fr = fr_tmp;
    }

    return err;
}
