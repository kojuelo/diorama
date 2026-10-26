#include "capsule.hpp"

#include "../../macros.hpp"

#include <math.h>

using namespace kojuelo::diorama;

bool kojuelo::diorama::Capsule::equals(const Capsule &other) const
{
    return segment.equals(other.segment) && (radius == other.radius);
}

bool kojuelo::diorama::Capsule::equalsApprox(const Capsule &other) const
{
    return segment.equals(other.segment) && (std::abs(radius - other.radius) < EQUALS_APROX_EPSILON);
}

void kojuelo::diorama::Capsule::translate(float x, float y)
{
    segment.translate(x, y);
}

void kojuelo::diorama::Capsule::rotateRadians(float radians)
{
    segment.rotateRadians(radians);
}

void kojuelo::diorama::Capsule::rotateRadiansAtPivot(const Point &pivot, float radians)
{
    segment.rotateRadiansAtPivot(pivot, radians);
}

void kojuelo::diorama::Capsule::rotateDegrees(float degrees)
{
    segment.rotateDegrees(degrees);
}

void kojuelo::diorama::Capsule::rotateDegreesAtPivot(const Point &pivot, float degrees)
{
    segment.rotateDegreesAtPivot(pivot, degrees);
}

void kojuelo::diorama::Capsule::scale(float x, float y, float radius)
{
    segment.scale(x, y);

    Capsule::radius *= radius;
}

Bounds kojuelo::diorama::Capsule::getBounds() const
{
    Bounds bounds = segment.getBounds();

    bounds.xMin -= radius;
    bounds.yMin -= radius;

    bounds.xMax += radius;
    bounds.yMax += radius;

    return bounds;
}