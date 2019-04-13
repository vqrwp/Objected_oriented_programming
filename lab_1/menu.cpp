#include <stdio.h>
#include <cstdlib>

#include "menu.h"
#include "turn_xyz.h"
#include "draw_frame.h"
#include "read_from_file.h"
#include "scale.h"
#include "transfer.h"

int menu(arguments args)
{
    static frame fr = init();
    int err = NO_ERRORS;
    switch (args.act)
    {
        case LOAD_FILE:
            err = read_from_file(fr, args.load_file);
            break;

        case DRAW:
            err = draw_frame(fr, args.draw);
            break;

        case X_TURN:
            err = turn_xyz(fr, args);
            break;

        case Y_TURN:
            err = turn_xyz(fr, args);
            break;

        case Z_TURN:
            err = turn_xyz(fr, args);
            break;

        case TRANSFER:
            err = transfer_points(fr, args.transfer);
            break;

        case SCALE:
            err = scale_points(fr, args.scale);
            break;

        case QUIT:
            clear(fr);
            break;

        default:
            err = UNKNOWN_ERROR;
    }
    return err;
}

