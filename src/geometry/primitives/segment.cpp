#include "segment.hpp"

using namespace kojuelo::diorama;

bool kojuelo::diorama::Segment::equals(const Segment &other)
{
    return a.equals(other.a) && b.equals(other.b);
}

bool kojuelo::diorama::Segment::equalsApprox(const Segment &other)
{
    return a.equalsApprox(other.a) && b.equalsApprox(other.b);
}

void kojuelo::diorama::Segment::translate(float x, float y)
{
    a.translate(x, y);
    b.translate(x, y);
}

void kojuelo::diorama::Segment::rotateRadians(float radians)
{
    a.rotateRadians(radians);
    b.rotateRadians(radians);
}

void kojuelo::diorama::Segment::rotateRadiansAtPivot(const Point &pivot, float radians)
{
    a.rotateRadiansAtPivot(pivot, radians);
    b.rotateRadiansAtPivot(pivot, radians);
}

void kojuelo::diorama::Segment::rotateDegrees(float degrees)
{
    a.rotateDegrees(degrees);
    b.rotateDegrees(degrees);
}

void kojuelo::diorama::Segment::rotateDegreesAtPivot(const Point &pivot, float degrees)
{
    a.rotateDegreesAtPivot(pivot, degrees);
    b.rotateDegreesAtPivot(pivot, degrees);
}

void kojuelo::diorama::Segment::scale(float x, float y)
{
    a.scale(x, y);
    b.scale(x, y);
}

Bounds kojuelo::diorama::Segment::getBounds() const
{
    Bounds bounds;

    // X and width.
    if (a.x < b.x)
    {
        bounds.xMin = a.x;
        bounds.xMax = b.x;
    }
    else
    {
        bounds.xMin = b.x;
        bounds.xMax = a.x;
    }

    // Y and height.
    if (a.y < b.y)
    {
        bounds.yMin = a.y;
        bounds.yMax = b.y;
    }
    else
    {
        bounds.yMin = b.y;
        bounds.yMax = a.y;
    }

    return bounds;
}