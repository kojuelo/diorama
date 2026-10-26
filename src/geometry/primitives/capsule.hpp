#pragma once

#include "segment.hpp"
#include "../boundings/bounds.hpp"

namespace kojuelo::diorama
{
    class Capsule
    {
    public:
        Segment segment;
        float radius;

        Capsule() {};
        Capsule(const Segment &segment, float radius)
        {
            Capsule::segment = segment;
            Capsule::radius = radius;
        }

        bool equals(const Capsule &other) const;
        bool equalsApprox(const Capsule &other) const;

        void translate(float x, float y);

        void rotateRadians(float radians);
        void rotateRadiansAtPivot(const Point &pivot, float radians);

        void rotateDegrees(float degrees);
        void rotateDegreesAtPivot(const Point &pivot, float degrees);

        void scale(float x, float y, float radius);

        Bounds getBounds() const;
    };
}