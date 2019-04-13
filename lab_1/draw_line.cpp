#include "draw_line.h"

void addLine(graphics window, point point1, point point2)
{
    window.scene->addLine(QLine(int(point1.x), int(point1.y), int(point2.x), int(point2.y)));
}
