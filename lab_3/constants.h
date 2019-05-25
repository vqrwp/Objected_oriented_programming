#ifndef COMMON_H
#define COMMON_H

#include <QTextEdit>
#include <QTimer>

#define CROSSING_FLOOR 1500
#define OPENING_N_CLOSING 2000
#define WAITING_TIME 2000
#define NUM_FLOORS 10

enum direction
{
    UP = 1,
    DOWN = -1,
    STAY = 0
};

#endif // COMMON_H
