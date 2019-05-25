#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>
#include <QVector>
#include "constants.h"
#include "qdebug.h"

class Control_panel : public QObject
{
    Q_OBJECT

    enum panel_state
    {
        FREE,
        BUSY
    };

public:
    explicit Control_panel(QObject *parent = nullptr);
    void set_new_target(int floor);

signals:
    void set_target(int floor);

public slots:
    void achieved_floor(int floor);
    void passed_floor(int floor);

private:
    int cur_floor;
    bool calls[NUM_FLOORS];
    panel_state current_state;
    direction cur_direction;
    bool next_target(int &floor);
};

#endif // CONTROLPANEL_H
