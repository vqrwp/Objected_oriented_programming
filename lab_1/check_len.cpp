#include "check_len.h"

int check_len(int count)
{
    int err = 0;
    if (count <= 0)
    {
        err = NO_DOTS;
    }
    return err;
}
