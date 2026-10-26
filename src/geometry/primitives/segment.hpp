#pragma once

#include "point.hpp"
#include "../boundings/bounds.hpp"

namespace kojuelo::diorama
{
    class Segment
    {
    public:
        Point a;
        Point b;

        Segment() {};
        Segment(const Point &a, const Point &b)
        {
            Segment::a = a;
            Segment::b = b;
        }

        bool equals(const Segment &other) const;
        bool equalsApprox(const Segment &other) const;

        void translate(float x, float y);

        void rotateRadians(float radians);
        void rotateRadiansAtPivot(const Point &pivot, float radians);

        void rotateDegrees(float degrees);
        void rotateDegreesAtPivot(const Point &pivot, float degrees);

        void scale(float x, float y);

        Bounds getBounds() const;
    };
}