#include "point.hpp"

#include "../geometry.hpp"
#include "../../macros.hpp"

#include <cmath>

using namespace kojuelo::diorama;

bool kojuelo::diorama::Point::equals(const Point &other) const
{
    return (x == other.x) && (y == other.y);
}

bool kojuelo::diorama::Point::equalsApprox(const Point &other) const
{
    return (std::abs(x - other.x) < EQUALS_APROX_EPSILON) && (std::abs(y - other.y) < EQUALS_APROX_EPSILON);
}

void kojuelo::diorama::Point::translate(float x, float y)
{
    Point::x += x;
    Point::y += y;
}

void kojuelo::diorama::Point::rotateRadians(float radians)
{
    float sin = std::sin(radians);
    float cos = std::cos(radians);

    float xTemp = x;
    float yTemp = y;

    x = (cos * xTemp) - (sin * yTemp);
    y = (sin * xTemp) + (cos * yTemp);
}

void kojuelo::diorama::Point::rotateRadiansAtPivot(const Point &pivot, float radians)
{
    Point temp(x - pivot.x, y - pivot.y);

    temp.rotateRadians(radians);

    x = pivot.x + temp.x;
    y = pivot.y + temp.y;
}

void kojuelo::diorama::Point::rotateDegrees(float degrees)
{
    rotateRadians(geometry::degreesToRadians(degrees));
}

void kojuelo::diorama::Point::rotateDegreesAtPivot(const Point &pivot, float degrees)
{
    rotateRadiansAtPivot(pivot, geometry::degreesToRadians(degrees));
}

void kojuelo::diorama::Point::scale(float x, float y)
{
    Point::x *= x;
    Point::y *= y;
}