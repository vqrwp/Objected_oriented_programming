#ifndef ENTER_POINT_H
#define ENTER_POINT_H

#include "QGraphicsView"
#include "error_codes.h"
#include "frame.h"

enum action
{
    LOAD_FILE,
    TRANSFER,
    X_TURN,
    Y_TURN,
    Z_TURN,
    DRAW,
    SCALE,
    QUIT
};

struct drawing
{
    QGraphicsView *gV;
    int width;
    int heigh;
};

struct turning
{
    int angle;
};

struct transfering
{
    double x;
    double y;
    double z;
};

struct scaling
{
    double scale;
};

struct input_file
{
    const char* filename;
};

struct arguments
{
    action act;
    union
    {
        drawing draw;
        turning turn;
        transfering transfer;
        scaling scale;
        input_file load_file;
    };
};

int menu(arguments args);

#endif // ENTER_POINT_H
