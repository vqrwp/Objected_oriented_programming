#include "doors.h"

Lift_doors::Lift_doors(QObject *parent) : QObject(parent)
{
    current_state = CLOSED;

    doors_stay_open_timer.setInterval(WAITING_TIME);
    doors_stay_open_timer.setSingleShot(true);

    //doors_open_timer.setInterval(OPENING_N_CLOSING);
    doors_open_timer.setSingleShot(true);

    //doors_close_timer.setInterval(OPENING_N_CLOSING);
    doors_close_timer.setSingleShot(true);

    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(close()));

    // когда двери открыты, начать режим ожидания
    QObject::connect(this, SIGNAL(opened_doors()), &doors_stay_open_timer, SLOT(start()));

    // когда истечет таймер режима ожидания - начать закрываться
    QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this, SLOT(start_closing()));
}

void Lift_doors::start_openning()
{
    if (current_state == CLOSED)
    {
        current_state = OPENNING;
        qDebug() << "Двери открываются.";
        doors_open_timer.start(OPENING_N_CLOSING);
    }
    if (current_state == CLOSING)
    {
        current_state = OPENNING;
        qDebug() << "Двери открываются.";
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(OPENING_N_CLOSING - t);
    }
}

void Lift_doors::start_closing()
{
    if (current_state == OPENED)
    {
        current_state = CLOSING;
        qDebug() << "Двери закрываются.";
        doors_close_timer.start(OPENING_N_CLOSING);
    }
    else if (current_state == CLOSED)
        emit closed_doors();
}

void Lift_doors::open()
{
    if (current_state == OPENNING)
    {
        current_state = OPENED;
        qDebug() << "Двери открыты.\nЛифт ожидает выхода и входа пассажиров.";
        emit opened_doors();
    }
}

void Lift_doors::close()
{
    if (current_state == CLOSING)
    {
        current_state = CLOSED;
        qDebug() << "Двери закрыты.";
        emit closed_doors();
    }
}
