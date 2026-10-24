#pragma once

#include "primitives/point.hpp"

namespace kojuelo::diorama::geometry
{
    float radiansToDegrees(float radians);
    float degreesToRadians(float degrees);

    float pointDistanceSquared(const Point &a, const Point &b);
    float pointDistance(const Point &a, const Point &b);

    Point pointInterpolate(const Point &a, const Point &b, float interpolant);
}