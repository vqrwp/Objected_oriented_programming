#ifndef LIFTCAB_H
#define LIFTCAB_H

#include <QObject>
#include <QString>
#include "constants.h"
#include "doors.h"

class Lift_cabin : public QObject
{
    Q_OBJECT
    enum cabin_state
    {
        MOVING,
        GOT_TARGET,
        WAITING_CALL,
        WAITING_ENTRANCE
    };

public:
    explicit Lift_cabin(QObject *parent = nullptr);

signals:
    void pre_moving();
    void crossing_floor(int floor, direction d);
    void reached_target(int floor);
    void cabin_stopped(int floor);

public slots:
    void cabin_moving();
    void cabin_stopping();
    void cabin_set_target(int floor);


private:
    int current_floor;
    int target;
    cabin_state current_state;
    direction current_direction;
    Lift_doors doors;
    QTimer crossing_floor_timer;
};

#endif // LIFTCAB_H
