#include "Point.hpp"

Fixed abs(Fixed x)
{
    if (x < 0)
        return x * -1;
    return x;
}

Fixed calculateArea(Point v1, Point v2, Point v3)
{
    return 0.5f * abs((v1.getX() * (v2.getY() - v3.getY()) + v2.getX() * (v3.getY() - v1.getY()) + v3.getX() * (v1.getY() - v2.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    return (area == area1 + area2 + area3);
}