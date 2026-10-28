#include "circle.hpp"

#include "../../macros.hpp"

#include <cmath>

using namespace kojuelo::diorama;

bool kojuelo::diorama::Circle::equals(const Circle &other) const
{
    return center.equals(other.center) && (radius == other.radius);
}

bool kojuelo::diorama::Circle::equalsApprox(const Circle &other) const
{
    return center.equalsApprox(other.center) && (std::abs(radius - other.radius) < EQUALS_APROX_EPSILON);
}

void kojuelo::diorama::Circle::translate(float x, float y)
{
    center.translate(x, y);
}

void kojuelo::diorama::Circle::rotateRadians(float radians)
{
    center.rotateRadians(radians);
}

void kojuelo::diorama::Circle::rotateRadiansAtPivot(const Point &pivot, float radians)
{
    center.rotateRadiansAtPivot(pivot, radians);
}

void kojuelo::diorama::Circle::rotateDegrees(float degrees)
{
    center.rotateDegrees(degrees);
}

void kojuelo::diorama::Circle::rotateDegreesAtPivot(const Point &pivot, float degrees)
{
    center.rotateDegreesAtPivot(pivot, degrees);
}

void kojuelo::diorama::Circle::scale(float x, float y, float radius)
{
    center.scale(x, y);

    Circle::radius *= radius;
}

Bounds kojuelo::diorama::Circle::getBounds() const
{
    return Bounds(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}
