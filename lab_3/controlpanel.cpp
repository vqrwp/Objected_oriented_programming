#include "controlpanel.h"

// начальное состояние контрольной панели
Control_panel::Control_panel(QObject *parent) : QObject(parent)
{
    current_state = FREE;
    cur_direction = STAY;
    cur_floor = 0;

    for (int i = 0; i < NUM_FLOORS; i++)
        calls[i] = false;
}

void Control_panel::set_new_target(int floor)
{
    current_state = BUSY;
    calls[floor - 1] = true;
    next_target(floor); // выбор следующей цели
    emit set_target(floor); // передача цели кабине
}

void Control_panel::achieved_floor(int floor)
{
    if (current_state == BUSY)
    {
        cur_floor = floor;
        cur_direction = STAY;
        calls[floor - 1] = false; // данный этаж больше не цель

        if (next_target(floor)) // если существует еще какой-то вызов
        {
            emit set_target(floor);
        }
        else
        {
            current_state = FREE;
        }
    }
}

void Control_panel::passed_floor(int floor)
{
    qDebug() << "Лифт преодолел" << floor << "этаж.";
}

// выбирается следующий этаж, на который поедет лифт
bool Control_panel::next_target(int &floor)
{
    int step = -1; // сначала просматриваем направление, в котором ехал лифт
    if (cur_direction == UP)
    {
        step = 1;
    }
    for (int i = cur_floor; i <= NUM_FLOORS && i > 0; i += step)
    {
        if (calls[i - 1])
        {
            floor = i; // выбрали этаж
            return true;
        }
    }
    step = -step;
    for (int i = cur_floor; i <= NUM_FLOORS && i > 0; i+= step)
    {
        if (calls[i - 1])
        {
            floor = i; // выбрали этаж
            return true;
        }
    }
    return false;
}
