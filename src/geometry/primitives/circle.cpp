#include "circle.hpp"

#include "../../macros.hpp"

#include <math.h>

using namespace kojuelo::diorama;

bool kojuelo::diorama::Circle::equals(const Circle &other) const
{
    return point.equals(other.point) && (radius == other.radius);
}

bool kojuelo::diorama::Circle::equalsApprox(const Circle &other) const
{
    return point.equalsApprox(other.point) && (std::abs(radius - other.radius) < EQUALS_APROX_EPSILON);
}

void kojuelo::diorama::Circle::translate(float x, float y)
{
    point.translate(x, y);
}

void kojuelo::diorama::Circle::rotateRadians(float radians)
{
    point.rotateRadians(radians);
}

void kojuelo::diorama::Circle::rotateRadiansAtPivot(const Point &pivot, float radians)
{
    point.rotateRadiansAtPivot(pivot, radians);
}

void kojuelo::diorama::Circle::rotateDegrees(float degrees)
{
    point.rotateDegrees(degrees);
}

void kojuelo::diorama::Circle::rotateDegreesAtPivot(const Point &pivot, float degrees)
{
    point.rotateDegreesAtPivot(pivot, degrees);
}

void kojuelo::diorama::Circle::scale(float x, float y, float radius)
{
    point.scale(x, y);

    Circle::radius *= radius;
}
